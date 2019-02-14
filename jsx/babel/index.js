/** @jsx h */
// '@jsx h' 是告诉 transpiler jsx 要转换为 h 函数 , 否则会以 React 创建虚拟DOM.
//利用 babel-preset-react , 将 JSX 转为 h()函数 , h得到的三个参数 h(nodeName, attributes, ...args)对应vnode对象的三个property, 类似 '语法分析' 的过程
const ITEMS = 'Vue React Angular Eggjs Laravel'.split(' ');
//jsx 实例
function foo(items) {
	return items.map( p => <li> {p} </li> );		
}

let vdom = (
	<div id="foo">
		<p>Happy Hacking!</p>
		<ul>{ foo(ITEMS) }</ul>
	</div>
);

//virtual DOM 转换为 real DOM
let dom = render(vdom);

document.body.appendChild(dom);

//接过 h 函数 , 将其返回一个包含三个 property 的 VNode 对象: { nodeName, attributes, [ ... ] } . 
// virtual DOM 对象转成 json .
let json = JSON.stringify(vdom, null, '  ');

//查看 DOM 语法树
document.body.appendChild(
	render( <pre>{ json }</pre> )
);

function render(vnode) {
	if (typeof vnode==='string') return document.createTextNode(vnode);
	let n = document.createElement(vnode.nodeName);
	Object.keys(vnode.attributes || {}).forEach( k => n.setAttribute(k, vnode.attributes[k]) );
	(vnode.children || []).forEach( c => n.appendChild(render(c)) );
	return n;
}


function h(nodeName, attributes, ...args) {
	let children = args.length ? [].concat(...args) : null;
	return { nodeName, attributes, children };
}


