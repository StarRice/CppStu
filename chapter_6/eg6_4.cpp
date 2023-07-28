/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-28 10:57:55
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-28 11:07:06
 * @FilePath: \c++\chapter_6\eg6_4.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
/* const_cast ������ */
/* ��������string �����н϶̵��Ǹ������������� */
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
/* ʵ���Ƿǳ������ַ��� */
string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string &>(s1),
                             const_cast<const string &>(s2)); /* ���ǳ���ǿ��ת���ɶ�const������ */
    return const_cast<string &>(r);
}
int main()
{
    /* �����Ƿ�����ͬһ������� */
}