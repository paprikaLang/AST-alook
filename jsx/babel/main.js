'use strict';

/** @jsx h */

var ITEMS = 'Vue React Angular Eggjs Laravel'.split(' ');

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

var dom = render(vdom);

document.body.appendChild(dom);

var json = JSON.stringify(vdom, null, '  ');

console.log(json);

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
