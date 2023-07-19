/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-19 14:48:49
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-19 14:58:52
 * @FilePath: \c++\chapter_3\eg3_4.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s("some thing");
    
    if(s.begin() != s.end()){ /* 确保s非空 */
        auto it = s.begin(); /* it指向s的第一个字符 */
        *it = toupper(*it);  /*将当前的字符改成大写形式 */  
    }
    cout << s << endl;
    cout << "***********************************" << endl;
    for(auto it = s.begin();it != s.end() && !isspace(*it);++it)
        *it = toupper(*it);
    cout << s << endl;
/**ps: c++11 引入了 cbegin 和 cend 在只读时可以使用 */

    auto mid = s.begin() + s.size()/2; /* 计算得到中间元素的一个迭代器 */

    return 0;
}
