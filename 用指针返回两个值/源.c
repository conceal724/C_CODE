#include<stdio.h>
void f1(int* p,int* q)
{
	*p = 111;
	*q = 222;
}
int f2(int a,int b)
{
	a = 1;
    b = 2;
}
/*
f2中修改形参a，b的值对主函数中实参a，b的值没有影响
*/
int main()
{
	int a = 0, b = 0;
	a = 11;
	b = 22;
	f2(a,b);
	f1(&a, &b);
	printf("a=%d b=%d",a,b);   //结果为a=11 b=22
	return 0;
}/*
 通常被调函数只能返回一个值 且被调函数内的形参不能直接修改主调函数中实参的值
 只能通过返回一个值 再将这个值赋值给主调函数内的实参 但是一个函数只能返回一个值
 要想被调函数同时反返回多个值就行必须通过指针 
 将主调函数内实参的地址发送给被调函数的形参
 被点函数的形参必须是int*类型的指针变量（当实参是int类型的时候）
 然后通过   *形参变量名=……（要修改的值）就可以修改驻点函数内实参的值
 */