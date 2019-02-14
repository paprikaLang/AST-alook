<img src="/img/sourcery.jpg" width="750"/>

SourceKitten

>SourceKitten links and communicates with sourcekitd.framework to parse the Swift AST, extract comment docs for Swift or Objective-C projects, get syntax data for a Swift file and lots more

JSON array of syntax highlighting information:

```
[
  {
    "offset" : 0,
    "length" : 6,
    "type" : "source.lang.swift.syntaxtype.keyword"
  },
  {
    "offset" : 7,
    "length" : 10,
    "type" : "source.lang.swift.syntaxtype.identifier"
  },
  {
    "offset" : 18,
    "length" : 14,
    "type" : "source.lang.swift.syntaxtype.comment"
  }
]
```

Projects Built With SourceKitten:

- jazzy: docs for Swift & Objective-C.
- SwiftyMocky: As Swift doesn't support reflections well enough to allow building mocks in runtime, library depends on Sourcery.
- Sourcery:  Meta-programming for Swift, stop writing boilerplate code.

[查看 sourcery demo](https://github.com/paprikaLang/AST-alook/tree/master/sourcery)

 **Sourcery** 这样的手法同样可以应用到 **JSX** 中. 

  1. babel-preset-react 代替 SourceKit 的职责, 通过 `/** @jsx h */` 的方式将 JSX 转换成 `h(nodeName, attributes, ...args)` 这样的语法结构.

```javascript
let vdom = (
	<div id="foo">
		<p>Happy Hacking!</p>
		<ul>{ foo(ITEMS) }</ul>
	</div>
);
```

```javascript
var vdom = h(
  'div',
  { id: 'foo' },
  h(
    'p',
    null,
    'Happy Hacking!'
  ),
  h(
    'ul',
    null,
    foo(ITEMS)
  )
);
```

 2. 将 h 转换成 vdom , 再 JSON.stringify 转成 json, 就能实现自己的 **'SourceKitten'** 了.

```javascript
function h(nodeName, attributes, ...args) {
  let children = args.length ? [].concat(...args) : null;
  return { nodeName, attributes, children };  //返回的是一个 vdom
}
```

```javascript
let json = JSON.stringify(vdom, null, '  ');
```

```
{ 
  "nodeName": "div",
  "attributes": {
    "id": "foo"
  },
  "children": [
    {
      "nodeName": "p",
      "attributes": null,
      "children": [
        "Happy Hacking!"
      ]
    },
    {
      "nodeName": "ul",
      "attributes": null,
      "children": [
        {
          "nodeName": "li",
          "attributes": null,
          "children": [
            " ",
            "Vue",
            " "
          ]
        },
        ... ...
      ]
    }
  ]
}
```

 3. 接下来将 vdom 转成 real dom , 实现 **'Sourcery'**.

```javascript
function render(vnode) {
	if (typeof vnode==='string') return document.createTextNode(vnode);
	let n = document.createElement(vnode.nodeName);
	Object.keys(vnode.attributes || {}).forEach( k => n.setAttribute(k, vnode.attributes[k]) );
	(vnode.children || []).forEach( c => n.appendChild(render(c)) );
	return n;
}
```

```javascript
let dom = render(vdom);
document.body.appendChild(dom);
```

*不借助 React 解析 JSX 最终呈现的效果:* 

<img src="https://paprika-dev.b0.upaiyun.com/EWRwKTRSBPU9ZLsaqnUZ0spWwdEPx0M9Li1wCuAo.jpeg" width="500" />

[查看 jsx demo](https://github.com/paprikaLang/AST-alook/tree/master/jsx)

<br>

<br>

第二部分, 我们尝试直接修改 AST 的语法结构来进一步扩展编程语言的表达能力, 大体思路一般都是这样的:

 1. 把源码转换为 AST (esprima)
 2. 遍历并更新 AST (estraverse)
 3. 将 AST 重新生成源码 (escodegen)

<img src="https://paprika-dev.b0.upaiyun.com/n7j8KDa05xTZZokUEX0s2fLFHk75ShBrWHVwP54g.jpeg" width="600"/>

玩儿过狼人杀的朋友一定也打过丘比特人狼恋的板子, 狼人同伴可以穿神同伴的衣服逃过查验, 反过来好人同伴也可以替狼同伴挡下一验. 所以如果你是丘比特, 你手上的代码是狼人还是好人呢?

```javascript
let code = 'var a = 1';
const ast = esprima.parseScript(code);
estraverse.traverse(ast, {
    enter: function (node) {
        node.kind = "let";
    }
});
const transformCode = escodegen.generate(ast)
// result: let a = 1
```


Elixir 通过 quote 和 unquote 构建起的宏系统也可以提供我们操作 AST 的环境, 并直接影响编译的结果. 对比上张图你可能会猜出 quote 的作用

<img src="/img/elixir.jpg" width="500"/>

quote:

```
iex(2)> expr = quote do: Sample.hello("tiyo", 500)
{{:., [], [{:__aliases__, [alias: false], [:Sample]}, :hello]}, [],
 ["tiyo", 500]}
```

unquote: 

```
iex> number = 13
iex> Macro.to_string(quote do: 11 + number)
"11 + number"
iex> Macro.to_string(quote do: 11 + unquote(number))
"11 + 13"
```

下面我们想实现当 @async 为 true 时异步执行 hello() ; @async 为 false 时同步执行, 如果 sleep 超过 @timeout 返回 @timeout_response

```elixir
defmodule Sample do
	import AsyncTask
	@async true
	@timeout 1000
	@timeout_response "no response"             // 以上都是 header; sample(header, do: body)是宏; sample 之后是 do: body
	sample hello(name, timer \\ 10_000) do      // \\ 代表默认值
		:timer.sleep(timer)      // 延迟返回
		"hello, #{name}"         // 这里代表返回值
	end
end
```

```elixir
defmodule AsyncTask do
	defmacro sample(header, do: body) do
		quote do
			def unquote(header) do                        
				case @async do
					true -> spawn(fn -> unquote(body) end)  // 模式匹配: 如果 @async true 另开一个 process 
					_  ->                                   // 模式匹配: 如果 @async 不为 true
						caller = self()
						spawn(fn -> send(caller, unquote(body)) end)  // 将消息传递给自己所在的 process 

						receive do
							message -> message                        // 收到消息并返回
						after
							@timeout -> @timeout_response             // 超时返回 @timeout_response 的值
						end
				end
			end
		end
	end
end
```

[查看 elixir demo](https://github.com/paprikaLang/AST-alook/tree/master/marco)








