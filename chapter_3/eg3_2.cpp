/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-13 14:45:25
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-14 17:28:08
 * @FilePath: \c++\hello.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
/* ʹ��Ԥ���������Ե���������*/

// #define STRING_1 1  /* ������1����0����ִ��STRING_1 */
#define STRING_2 0     /* 1--> ��Ч 0-->��Ч*/
#define STRING_3 0
#define STRING_4 1
int main()
{
#ifdef STRING_1
/* �ж��ַ���������ŵ����� */
    string  s("hello, world");
    decltype (s.size()) punct_cnt = 0;  /* punct_cnt �����;��� string::size_type */
    for (auto c : s)
        if(ispunct(c))
            ++punct_cnt;
    cout << punct_cnt
         << " punctuation characters in " << s <<endl;
#elif STRING_2
/* ���ַ�������ȫ����д */
    string s("hello world"); 
    for (auto& c :s)
        c = toupper(c);
    cout << s <<endl;
#elif STRING_3
/* ����ǰ���ʸ�д�ɴ�д��ʽ */
    string s("hello world"); 
    for (decltype(s.size()) index = 0;
        index != s.size() && !isspace(s[index]);++index)
        s[index] = toupper(s[index]); /* ��׼�⺯��������һ����ĸ��������д��ĸ */
    cout << s <<endl;
#elif STRING_4
    const string hexdigits = "12346789ABCDEF";
    string result; /* ���ڱ���ʮ�����Ƶ��ַ��� */
    string::size_type n;/* ���ڱ������������ȡ���� */
    while(cin >> n){
        if(n < hexdigits.size())
            result+=hexdigits[n];   
        if(cin.get() == '\n') break; /* �����Ϊ��׼������cin����Կհ��ַ������½�����ѭ�������� */
    }
    cout << result << endl;
#endif
    return 0;
}
//asd
