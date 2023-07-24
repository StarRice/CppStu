/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-21 11:42:24
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-24 15:50:11
 * @FilePath: \c++\chapter_4\eg4_11.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

/* ���ڲ��� const_cast ��ʹ�ó��� 
*@param��val ��Ҫ��ӡ��ֵ
*/
void printer(int *val){
    cout << *val << endl;
}
int main()
{
/* ǿ������ת�� cast-name<type>(expression) */
/*cast-name:
*static_cast ֻҪ������ȷ���������ת�������Ҳ������ײ�const ����ʹ��
*/
    int i = 1,j = 1;
    double slope = static_cast<double>(i) /j; /* �൱�ڸ��߳���Ķ��ߺͱ�����������֪�����Ҳ��ں�Ǳ�ڵľ�����ʧ*/
    cout << slope << endl;
/* const_cast 
**ֻ�ܸı��������ĵײ�const��ָ��ָ��Ķ�����һ�������� eg��const int * p = &i;
**                 ����const��ָ�뱾����һ��������eg:int *const p =&j;
**                 ps�������������õ�const���� �ײ�const
*/
    const int temp = 1;
    const int *pc = &temp ; /* �ײ�const */
    int *p = const_cast<int *>(pc);
    *p = 9; 
    cout << temp << endl; /* ��ӡ������ temp ֵ���� */
/* ���ʣ������ת��������ʲô������ ?
*  �����ǿ��ܵ�����һ����������const�ĺ�����������Ҫ����ȥ��ʵ�ʲ���ȷʵconst�ģ���������֪����������ǲ���Բ������޸ĵġ�
*      �������Ǿ���Ҫʹ��const_castȥ��const�޶����Ա㺯���ܹ��������ʵ�ʲ����� 
*/
/* eg :                                                                        */
    const int t =10;
    printer(const_cast<int *>(&t));
    return 0;
}