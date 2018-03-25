

一个JS引擎在执行任何例如Demo 中 var a = 2;  语句时,都会把编译和生成指令(Code-Generation)的工作交给Compiler,Compiler再分词,解析生成语法树(左:声明 var a, 右:赋值 a = 2),声明变量之前Compiler要询问Scope作用域内是否存在变量a, 这样查询的作用在于 对于 a = 2; 这样作用域中没有声明的变量,引擎就会在全局作用域内创建一个(strict模式除外).


不同的JS引擎如 Esprima 和 Acron(babel的前身fork的 Acron)都需要对AST进行生成,遍历,转换再重新生成源码的流程. Demo以Esprima为例将 var a = 2; 重新生成 let a = 2;


![](https://paprika-dev.b0.upaiyun.com/n7j8KDa05xTZZokUEX0s2fLFHk75ShBrWHVwP54g.jpeg)

babel经过相同的流程可以将 [5,6,7].map(n => n*n); 转换成
```
[1, 2, 3].map(function (n) {
  return n * n;
});
```

eslint可以检测代码风格,提示错误. IDE的高亮和自动补全; 打包工具webpack; UglifyJS的代码压缩... 都是一样的思路.




OC在C语言的基础上, 赋予了它类似Smalltalk消息发送的机制,其实也是LLVM前端(clang)将代码语法分析成AST之后再被runtime函数包重新翻译的结果.如 ObjCMessageExpr 翻译成相应版本的 @objc_msgSend ; ObjCAutoreleasePoolStmt 转译成 @Objc_autoreleasePoolPush/Pop.

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

![](https://paprika-dev.b0.upaiyun.com/tLVpRp2JzmfM2jYTP1acyiSvwyjzxd2HPBsxVWbp.jpeg)

```
clang -S -fobjc-arc -emit-llvm main.m -o main.ll
```

![](https://paprika-dev.b0.upaiyun.com/Xm3oB63wj5fxjbf1OIO3YkmBZVnB4MB4wB7DcFM2.jpeg)

[了解libclang , libTooling , clangPlugin对语法树的控制和应用](http://www.starming.com/2017/03/01/deeply-analyse-llvm/)


![](https://paprika-dev.b0.upaiyun.com/MTdbpkkdbT99xpmqmu5gPBGLnAgnMqGy01gjkzmW.jpeg)

RecursiveASTVisitor 是一个深度优先遍历 AST 和访问节点的抽象类,创建一个子类通过  TraverseDecl() 调用对应类型的访问函数如 TraverseFunctionDecl() ,最终在回调函数   bool VisitFunctionDecl() 中可根据需要 统计一下函数个数或者直接转成 Swift  .





libSyntax 是 Swift 项目的一个工具库, 用于重构时提供结构化的代码. 除此之外,Swift编写的 命令行工具 Sourcery 可以通过 AST 将语法单元组合,对应上各个 Sourcery API 传递给 Stencil 模板,最后生成源码.





