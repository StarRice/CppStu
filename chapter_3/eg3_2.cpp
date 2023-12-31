/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-13 14:45:25
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-18 10:30:40
 * @FilePath: \c++\hello.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
/* 使用预编译来调试单独的例子*/

// #define STRING_1 1  /* 无论是1还是0都会执行STRING_1 */
#define STRING_2 0     /* 1--> 有效 0-->无效*/
#define STRING_3 0
#define STRING_4 1
int main()
{
#ifdef STRING_1
/* 判断字符串里标点符号的数量 */
    string  s("hello, world");
    decltype (s.size()) punct_cnt = 0;  /* punct_cnt 的类型就是 string::size_type */
    for (auto c : s)
        if(ispunct(c))
            ++punct_cnt;
    cout << punct_cnt
         << " punctuation characters in " << s <<endl;
#elif STRING_2
/* 将字符串对象全部大写 */
    string s("hello world"); 
    for (auto& c :s)
        c = toupper(c);
    cout << s <<endl;
#elif STRING_3
/* 将当前单词改写成大写新式 */
    string s("hello world"); 
    for (decltype(s.size()) index = 0;
        index != s.size() && !isspace(s[index]);++index)
        s[index] = toupper(s[index]); /* 标准库函数，接收一个字母，输出其大写字母 */
    cout << s <<endl;
#elif STRING_4
    const string hexdigits = "12346789ABCDEF";
    string result; /* 用于保存十六进制的字符串 */
    string::size_type n;/* 用于保存从输入流读取的数 */
    while(cin >> n){
        if(n < hexdigits.size())
            result+=hexdigits[n];   
        if(cin.get() == '\n') break; /* 解决因为标准输入流cin会忽略空白字符，导致进入死循环的问题 */
    }
    cout << result << endl;
#endif
    return 0;
}
//asd
