#include<stdio.h>
#include<stdlib.h>
/*
C 程序是由函数组成的，我们写的代码都是由主函数 main()开始执行的。
函数是 C 程序的基本模块，是用于完成特定任务的程序代码单元。
函数的使用可以省去重复代码的编写,是程序更加的模块化,有利于阅读、修改和改善
程序就像一个大工厂，而里面的函数就像一个个的车间，对原料加工成对应的成品或者半成品。

函数的定义格式跟main函数一样，如下所示
返回类型 函数名(形式参数列表)
	{
		数据定义部分;
		执行语句部分;
}
1、函数名：理论上是可以随意起名字，最好起的名字见名知意，
应该让用户看到这个函数名字就知道这个函数的功能。
注意，函数名的后面有个圆换号()，代表这个为函数，不是普通的变量名。
2、形参：在定义函数时指定的形参，在未出现函数调用时，
它们并不占内存中的存储单元，因此称它们是形式参数或虚拟参数，
简称形参，表示它们并不是实际存在的数据，所以，形参里的变量不能赋值。
在定义函数时指定的形参，可有可无，根据函数的需要来设计，如果没有形参，
圆括号内容为空，或写一个void关键字：
3、函数体：就是函数的实现过程，跟以前写的主函数中的内容没什么区别
4、返回值：函数的返回值是通过函数中的return语句获得的，
return后面的值也可以是一个表达式。如果函数返回的类型和return语句中表达式的值不一致，
而它又无法自动进行类型转换，程序则会报错。如果函数带返回值，return后面必须跟着一个值，
如果函数没有返回值，函数名字的前面必须写一个void关键字，这时候，
我们写代码时也可以通过return中断函数(也可以不用)
*/
/*
形参和实参:
1形参出现在函数定义中，在整个函数体内都可以使用，离开该函数则不能使用。
2实参出现在主调函数中，进入被调函数后，实参也不能使用。
3实参变量对形参变量的数据传递是“值传递”，即单向传递，只由实参传给形参，
而不能由形参传回来给实参。
4在调用函数时，编译系统临时给形参分配存储单元。调用结束后，形参单元被释放。
5实参单元与形参单元是不同的单元。调用结束后，形参单元被释放，
函数调用结束返回主调函数后则不能再使用该形参变量。实参单元仍保留并维持原值。
因此，在执行一个被调用函数时，形参的值如果发生改变，并不会改变主调函数中实参的值。
*/
//定义一个简单的加法函数
int add(int x, int y){
    return x+y;
}

int main(){//函数进入主函数开始执行
    int a = 10;
    int b = 23;
    //运行到此处，向前寻找add函数，然后查看参数类型是否匹配
    //如果匹配就把a,b两个数交给add（生产车间进行处理）,
    //a，b分别一一对应x,y ,然后开始执行print_test()函数，这时候，
    //main()函数里面的执行会阻塞( 停 )在int c = add(a, b);这一行代码，等待add()函数的执行。
    //add执行完毕，main函数继续向下执行，直到return退出程序
    int c = add(a, b);//定义相同类型的变量c(类型必须和返回值匹配),来接收add处理过的数据结果
    printf("a + b = %d\n", c);

    return 0;
}