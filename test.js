const esprima = require('esprima');
const estraverse = require('estraverse');
const escodegen = require("escodegen");

let code = 'var a = 1';
const ast = esprima.parseScript(code);
estraverse.traverse(ast, {
    enter: function (node) {
        node.kind = "let";
    }
});
const transformCode = escodegen.generate(ast)

console.log(transformCode);
// console.log(ast);
