/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-21 11:42:24
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-24 15:50:11
 * @FilePath: \c++\chapter_4\eg4_11.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

/* 用于测试 const_cast 的使用场景 
*@param：val 需要打印的值
*/
void printer(int *val){
    cout << *val << endl;
}
int main()
{
/* 强制类型转换 cast-name<type>(expression) */
/*cast-name:
*static_cast 只要具有明确定义的类型转换，并且不包含底层const 即可使用
*/
    int i = 1,j = 1;
    double slope = static_cast<double>(i) /j; /* 相当于告诉程序的读者和编译器，我们知道并且不在乎潜在的精度损失*/
    cout << slope << endl;
/* const_cast 
**只能改变运算对象的底层const（指针指向的对象是一个常量） eg：const int * p = &i;
**                 顶层const（指针本身是一个常量）eg:int *const p =&j;
**                 ps：用于声明引用的const都是 底层const
*/
    const int temp = 1;
    const int *pc = &temp ; /* 底层const */
    int *p = const_cast<int *>(pc);
    *p = 9; 
    cout << temp << endl; /* 打印出来的 temp 值不变 */
/* 疑问：那这个转换符还有什么意义呢 ?
*  答：我们可能调用了一个参数不是const的函数，而我们要传进去的实际参数确实const的，但是我们知道这个函数是不会对参数做修改的。
*      于是我们就需要使用const_cast去除const限定，以便函数能够接受这个实际参数。 
*/
/* eg :                                                                        */
    const int t =10;
    printer(const_cast<int *>(&t));
    return 0;
}