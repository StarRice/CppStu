/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-28 14:54:40
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-28 16:03:11
 * @FilePath: \c++\chapter_6\eg6_5.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
/* Ĭ��ʵ�� */
/*!ע��㣺һ��ĳ���βα�������Ĭ��ֵ��������������βζ�������Ĭ��ֵ */
int sum(int a = 1,int b = 2)
{
    return (a+b);
}
int main()
{
/* ʹ��Ĭ��ʵ�� */
    cout << sum() << endl; /* ��� 3 */
    cout << sum(5) << endl;/* ��� 7 */
//   cout << sum(,3) << endl; /* ����ֻ��ʡ��β����ʵ�� */
    return 0;
}