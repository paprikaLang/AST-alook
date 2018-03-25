### JavaScript

JS引擎在分词,解析,生成语法树 **AST** 之后, 像 `var a = 2` 这样的表达式会被处理成:
```
  var a;  //左子树: 声明.
  a = 2;  //右子树: 赋值.
```
Esprima 可以将 AST 进行转换并重新生成代码, var a = 2 变成了 let a = 2.   [查看demo](https://github.com/paprikaLang/AST-stickies/tree/master/Esprima)

<img src="https://paprika-dev.b0.upaiyun.com/n7j8KDa05xTZZokUEX0s2fLFHk75ShBrWHVwP54g.jpeg" width="800"/>

掌握这个流程, 我们还可以做很多具体的优化和设计.

> 瘦身

 - UglifyJS 和 Babili 压缩器本质上也是一个编译器, Babili 采用的就是 Babel 插件提供的编译工具链. 
 - 对于不同模块下的文件, Rollup 工具可以利用 Treeshaking 把它们打包到同一文件下的同一作用域,方便后续的压缩工作. 
 - webpack3.0 通过 webpack.optimize.ModuleConcatenationPlugin 也实现了Treeshaking.


> 加速

  - React 在渲染 Virtual DOM 时会比对前后差异, babel 插件可以把静态元素提取出来变成常量而不必参与比对,提高了渲染速度.

<img src="https://paprika-dev.b0.upaiyun.com/HzsuYMarm1cnfEvSpn9TlDwdnzmq4UpnY2P6wEoA.jpeg" width="600"/>

  - Relay Morden 为解决运行时分析 GraphQL query 的低效,提前在编译时就生成了 query 信息 即 Runtime Artifacts.


### OC

OC 在 C 语言的基础上, 引入了 Smalltalk 的**消息机制** , 即通过 runtime 函数包重新翻译 AST , 如  ObjCMessageExpr 翻译成相应版本的 @objc_msgSend ; ObjCAutoreleasePoolStmt 翻译成 @Objc_autoreleasePoolPush/Pop.

```
  #import <Foundation/Foundation.h>
  
  int main() {
     @autoreleasepool {
        id obj = [NSOject new];
        NSLog(@"Hello world: %@",obj);
     }
     return 0;
  }
```

```
clang -fmodules -fsyntax-only -Xclang -ast-dump main.m
```

<img src="https://paprika-dev.b0.upaiyun.com/tLVpRp2JzmfM2jYTP1acyiSvwyjzxd2HPBsxVWbp.jpeg" width="500"/>

```
clang -S -fobjc-arc -emit-llvm main.m -o main.ll
```

<img src="https://paprika-dev.b0.upaiyun.com/Xm3oB63wj5fxjbf1OIO3YkmBZVnB4MB4wB7DcFM2.jpeg" width="500"/>

<img src="https://paprika-dev.b0.upaiyun.com/MTdbpkkdbT99xpmqmu5gPBGLnAgnMqGy01gjkzmW.jpeg" width="500" />

PluginASTAction 是基于 consumer 的 AST 前端 Action 抽象基类
ASTConsumer     用于客户读取AST的抽象基类
RecursiveASTVisitor 深度优先搜索整个 AST，并访问每一个节点的基类

根据需要重载相应的方法:
- PluginASTAction::CreateASTConsumer
- PluginASTAction::ParseArgs
- ASTConsumer::HandleTranslationUnit
- RecursiveASTVisitor::VisitDecl
- RecursiveASTVisitor::VisitStmt

<img src="https://paprika-dev.b0.upaiyun.com/PcPuAKd9vUBtOIFT4PY5MdWUJhZ6coEreRlgT5Ep.jpeg" width="600" />

访问节点只需要重写该类型节点的Visit方法，比如重写VisitCXXRecordDecl方法，就可以访问所有 C++ 的类定义了.
```
class MyVisitor : public RecursiveASTVisitor<FindNamedClassVisitor> {
public:
    bool VisitCXXRecordDecl(CXXRecordDecl *decl) {
        decl->dump();
        return true; // 返回true继续遍历，false则直接停止
    }
};
```

具体参考这篇[[clang 插件的编写]](http://kangwang1988.github.io/tech/2016/10/31/write-your-first-clang-plugin.html) 和 [[clang-mapper 的原理]](https://www.jianshu.com/p/e19aafbaddca)
<br>

### Antlr4

对比一下 Antlr4 的 [demo](https://github.com/paprikaLang/AST-stickies/tree/master/Antlr4-compiler) 如何实现:

<img src="https://paprika-dev.b0.upaiyun.com/dLFqYKtwjcLnyxbd20xF4jkIAnZ5hUcBvtFGbbhJ.jpeg" width="400" />

<img src="https://paprika-dev.b0.upaiyun.com/ae65aeV1rD8qvzUmF3zvJD0AKLtQ6S3CScFGDMuJ.jpeg" width="500"/>


### Swift
SourceKitten

>SourceKitten links and communicates with sourcekitd.framework to parse the Swift AST, extract comment docs for Swift or Objective-C projects, get syntax data for a Swift file and lots more

Projects Built With SourceKitten:

- SwiftLint: A tool to enforce Swift style and conventions.
- Jazzy:     Soulful docs for Swift & Objective-C.
- Sourcery:  Meta-programming for Swift, stop writing boilerplate code.


<img src="https://paprika-dev.b0.upaiyun.com/TnwOl42tGUGeyhxDrnA1uM9aoW1wQBDgnruWpsFy.jpeg" width="750"/>

[查看 sourcery demo](https://github.com/paprikaLang/AST-stickies/tree/master/Sourcery)

### JSX

如何不借助 React 实现 JSX ?  [查看demo](https://github.com/paprikaLang/AST-stickies/tree/jsx)

` @jsx h ` 在 `babel/index.js` 中用于提示 babel-preset-react ,将 JSX 转换成 h 函数:

```
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

我们可以自己实现 h 函数, 将它的参数转换为一个 VNode 的三个 property , 并形成 Virtual DOM Tree .

```
function h(nodeName, attributes, ...args) {
  let children = args.length ? [].concat(...args) : null;
  return { nodeName, attributes, children };
}
```


再将 Virtual DOM 转换为 Real DOM .

```
function render(vnode) {
  if (typeof vnode==='string') return document.createTextNode(vnode);
  let n = document.createElement(vnode.nodeName);
  Object.keys(vnode.attributes || {}).forEach( k => n.setAttribute(k, vnode.attributes[k]) );
  (vnode.children || []).forEach( c => n.appendChild(render(c)) );
  return n;
}
```

<img src="https://paprika-dev.b0.upaiyun.com/s1QdYeCxGkhRdnGtYLJvGxSU50GkbmcZMWpiKKeq.jpeg" width="400"/>

最后呈现的效果:

<img src="https://paprika-dev.b0.upaiyun.com/EWRwKTRSBPU9ZLsaqnUZ0spWwdEPx0M9Li1wCuAo.jpeg" width="500" />

<br>

