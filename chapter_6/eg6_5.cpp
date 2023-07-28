/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-28 14:54:40
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-28 16:03:11
 * @FilePath: \c++\chapter_6\eg6_5.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
/* 默认实参 */
/*!注意点：一旦某个形参被赋予了默认值，它后面的所有形参都必须有默认值 */
int sum(int a = 1,int b = 2)
{
    return (a+b);
}
int main()
{
/* 使用默认实参 */
    cout << sum() << endl; /* 输出 3 */
    cout << sum(5) << endl;/* 输出 7 */
//   cout << sum(,3) << endl; /* 错误：只能省略尾部的实参 */
    return 0;
}