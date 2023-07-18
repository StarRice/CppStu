/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-18 10:04:42
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-18 11:09:30
 * @FilePath: \c++\chapter_3\pra3_2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
//#define PRACTICE_3_6 0
#define PRACTICE_3_7 0
#define PRACTICE_3_8 0
#define PRACTICE_3_9 0
#define PRACTICE_3_10 0
#define PRACTICE_3_11 1
int main()
{
#ifdef PRACTICE_3_6
    string s1("hello world");
    for(auto &c : s1){
        c = 'X';
    }
    cout << s1 << endl;

#elif PRACTICE_3_7
/* 解答：输出结果不变 */
    string s1("hello world");
    for(char &c : s1){
        c = 'X';
    }
    cout << s1 << endl;

#elif PRACTICE_3_8
    string s1("hello world");
    decltype(s1.size()) index = 0;
/* 使用while() */
    // while(s1[index] != '\0'){ 
    //     s1[index] = 'X';
    //     index ++ ;
    // }
    // cout << s1 << endl;
/* 使用传统for（）*/
    for(;s1[index] != '\0';index++)
    {
        s1[index] = 'X';
    }
    cout << s1 << endl;

#elif PRACTICE_3_10
    string s1("hello,world!!!");
    for(auto &c : s1){
        if(ispunct(c)) /* 对字符的处理时，记得包含头文件cctype */
            c = ' ';
    }
    cout << s1 << endl;

#elif PRACTICE_3_11
    const string s1 = "Keep out!";
    for (auto &c:s1){} /* c 字符型 */
#endif
    return 0;
}