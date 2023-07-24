/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-24 14:57:33
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-24 15:49:37
 * @FilePath: \c++\chapter_5\eg5_6.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>
using namespace std;

int main()
{
/* throw���ʽ */
    int i,j;
    cin >> i >> j ;
    // if(i != j)
    //     throw runtime_error("Data must refer to same num");
    // else    
    //     cout << i << endl;
    
    while(cin >> i >> j){
        try{
            //ִ�������������
            //������ʧ�ܣ������׳�һ�� runtime_error �쳣
        } catch(runtime_error err){
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if(!cin || c=='n')
                break;
        }
    }
    return 0;
}