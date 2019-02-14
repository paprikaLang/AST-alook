'use strict';

/** @jsx h */
// '@jsx h' 是告诉 transpiler, jsx 要转换为 h 函数 , 否则会以 React 创建虚拟DOM.
//利用 babel-preset-react , 将 JSX 转为 h()函数 , h的三个参数 h(nodeName, attributes, ...args)对应vnode对象的三个property, 类似 '语法分析' 的过程
var ITEMS = 'Vue React Angular Eggjs Laravel'.split(' ');
//jsx 实例
function foo(items) {
	return items.map(function (p) {
		return h(
			'li',
			null,
			' ',
			p,
			' '
		);
	});
}

// virtual DOM 会被 transpiled 为类似语法树的结构
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
//virtual DOM 转换为 real DOM
var dom = render(vdom);

document.body.appendChild(dom);

//接过 h 函数 , 将其返回一个包含三个 property 的 VNode 对象: { nodeName, attributes, [ ... ] } . 
// virtual DOM 对象转成 json 打印出来.
var json = JSON.stringify(vdom, null, '  ');

console.log(json);

//查看 DOM 语法树
document.body.appendChild(render(h(
	'pre',
	null,
	json
)));

function render(vnode) {
	if (typeof vnode === 'string') return document.createTextNode(vnode);
	var n = document.createElement(vnode.nodeName);
	Object.keys(vnode.attributes || {}).forEach(function (k) {
		return n.setAttribute(k, vnode.attributes[k]);
	});
	(vnode.children || []).forEach(function (c) {
		return n.appendChild(render(c));
	});
	return n;
}

function h(nodeName, attributes) {
	var _ref;

	for (var _len = arguments.length, args = Array(_len > 2 ? _len - 2 : 0), _key = 2; _key < _len; _key++) {
		args[_key - 2] = arguments[_key];
	}

	var children = args.length ? (_ref = []).concat.apply(_ref, args) : null;
	return { nodeName: nodeName, attributes: attributes, children: children };
}
