#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// #define STRING_1 1 
#define STRING_2 0 
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
        s[index] = toupper(s[index]); /* 标准库函数，接收一个字符输出其大写形式*/
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
