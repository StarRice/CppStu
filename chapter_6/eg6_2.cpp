/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-25 11:27:59
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-26 17:13:53
 * @FilePath: \c++\chapter_6\eg6_2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;

class ErrCode{
    public:
        ErrCode(int i):num(i){}
        string msg(void);
    private:
        int num = 0;
};
string ErrCode::msg(void)
{
    if(num)
        return "InputError";
    else
        return "Success";
}
/*指针型 初始化函数 */
void reset(int *ip){
    *ip = 0;
    ip = 0;
}
/* 引用型 初始化函数*/
void reset(int &i){
    i = 0;
}
/*
 *@brif:比较字符串的长短 
 *@param:str1 待比较的字符串1
 *@param:str2 待比较的字符串2
 *@return: str1 < str2 时返回1
*/
bool isShorter(const string &str1,const string &str2){
    return str1.size() < str2.size();
}
/*
 *@brif:返回字符串中某个字符首次出现的位置 和 出现的总次数
 *@param: s 待检测字符串
 *@param: c 目标检测字符
 *@param：occurs 目标字符在字符串中总共出现了几次
 *@return: ret 目标检测字符在字符串中第一次出现的索引位 
*/
string::size_type find_char(const string &s , char c,string::size_type &occurs){

    auto ret = s.size(); /* 第一次出现的位置 */
    occurs = 0;          /* 初始化出现次数的值 */
   for(decltype(ret) i = 0;i != s.size(); ++i){
        if(s[i] == c){
            if(ret == s.size()) /* 只记录第一次出现的位置，当出现第二次时 ret 就不等于 s.size() */
                ret = i;
            ++occurs; /* 出现的次数+1 */
        }
   }
   return ret; /* 这里看只返回了一个值，但是 occurs 被隐式地返回了*/
}
/********************************************************************/
/* 以数组作为形参 */
/* 1.使用标记指定数组长度 */
void print(const char * cp)
{
    if(cp) /* 若不是一个空指针*/
        while(*cp)/* 指针所指的字符不是空字符 */
            cout << *cp++; /* 输出当前字符并将指针向前移动一个位置 */
}
/* 2.使用标准库规范 */
void print(const int *beg,const int *end)
{
    while(beg != end)
        cout << *beg++ <<endl;
}
/* 3.显式传递一个数组大小的形参 */
void print(const int ia[],size_t size)
{
    for (size_t i = 0;i != size;++i ){
        cout << ia[i] << endl;
    }
}
/* 4.数组引用形参 */
void print(int (&arr)[10]) 
{/* 只能传入10个整数的数组 */
    for(auto elem :arr)
        cout << elem << endl;
}
/* 5.传递多维数组 */
void print(int (*matrix)[10], int rowSize)
{
    /* */
}
/****************************************************************/
/* 含有可变形参的函数 */
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end();++beg)
        cout << *beg << " ";
    cout << endl;
}
/* 标准库并没有ErrCode类，故在开头自己定义了一个 */
void error_msg(ErrCode e,initializer_list<string> il)
{
    cout << e.msg() << ":";
    for(auto elem : il)
        cout << elem << " ";
    cout << endl;
}
int main(int argc, char *argv[])
{   /* argc： 传入命令的数量 argv ：指向（char *） 的指针 */
    const string s("hello world");
    string::size_type sum = 0;
    auto index = find_char(s,'r',sum);

    cout << index << endl;
    cout << sum <<endl;

/******************************************************************/
    int i = 1 ;
    const int ci = i;
    string::size_type ctr = 0;

    reset(&i); /* 函数重载调用形参类型是int *的 reset 函数*/
//    reset(&ci);/* 错误：不能用const int 对象的指针初始化 （int *） */
    reset(i);  /* 调用 int& 的reset 函数 */
//    reset(ci); /* 错误：不能把普通引用绑定到const 对象 ci 上*/
//    reset(ctr); /* 错误：ctr 是无符号类型 ，引用类型要一致 */

/******************************************************************/
    int j[] = {0,1};
    print(begin(j),end(j));
    print(j,end(j) - begin(j));
/* 测试传参的 main 的用法*/
    while(argc-- > 0){
        printf("argv[%d]:%s\n",argc,argv[argc]);
    }
/******************************************************************/
    string expected("hello");
    string actual;
    cin >> actual;
    if(expected != actual)
       // error_msg({"functionX",expected, actual}); /* 传入三个实参 */
        error_msg(ErrCode(42),{"functionX",expected, actual}); 
    else
       // error_msg({"functionX","okay"}); /* 传入2个实参 */
        error_msg(ErrCode(0),{"functionX","okay"}); 
    
    return 0;
}