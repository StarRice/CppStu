/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-19 14:48:49
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-19 14:58:52
 * @FilePath: \c++\chapter_3\eg3_4.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s("some thing");
    
    if(s.begin() != s.end()){ /* ȷ��s�ǿ� */
        auto it = s.begin(); /* itָ��s�ĵ�һ���ַ� */
        *it = toupper(*it);  /*����ǰ���ַ��ĳɴ�д��ʽ */  
    }
    cout << s << endl;
    cout << "***********************************" << endl;
    for(auto it = s.begin();it != s.end() && !isspace(*it);++it)
        *it = toupper(*it);
    cout << s << endl;
/**ps: c++11 ������ cbegin �� cend ��ֻ��ʱ����ʹ�� */

    auto mid = s.begin() + s.size()/2; /* ����õ��м�Ԫ�ص�һ�������� */

    return 0;
}
