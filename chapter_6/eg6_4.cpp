/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-28 10:57:55
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-28 11:07:06
 * @FilePath: \c++\chapter_6\eg6_4.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
/* const_cast 与重载 */
/* 挑出两个string 对象中较短的那个，返回其引用 */
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
/* 实参是非常量的字符串 */
string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string &>(s1),
                             const_cast<const string &>(s2)); /* 将非常量强制转换成对const的引用 */
    return const_cast<string &>(r);
}
int main()
{
    /* 重载是发生在同一作用域的 */
}