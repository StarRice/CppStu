/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-20 10:48:55
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-20 11:25:07
 * @FilePath: \c++\chapter_3\eg3_5.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    int arr[3]= {1,2,3};
    int * p =&arr[2]; 
    cout << p[-1] <<endl; /* p[-1] �൱�� *��p-1��*/
    const char ca[] = {'h','e','l','l','o'};

/* ʹ�������ʼ��vector���� */
    int int_arr[] = {1,2,3,4,5,6};
    vector<int> ivec(begin(int_arr),end(int_arr));

    for(auto c:ivec){
        cout << c << endl;
    }  
/* ��vector ���󿽱����������� */
    int arr_temp[6];
    for(int i =0;i<6;++i){
        arr_temp[i] = ivec[i];
    }
    cout << arr_temp[2];
    return 0;

}
