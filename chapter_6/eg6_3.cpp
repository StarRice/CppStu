#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
/* 果如 ctr 的值大于1，返回 word 的复数形式 */
string make_plural(size_t ctr, const string &word,const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
/* 挑出两个string 对象中较短的那个，返回其引用 */
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
/* 引用返回的左值 */
char &get_val(string &str, string::size_type ix)
{
    return str[ix] ;
}
/* 列表初始化返回值 */
vector<string> process(string expected,string actual)
{
    if(expected.empty())
        return {};
    else if (expected == actual)
        return {"functionX","okay"};
    else
        return {"functionX",expected,actual};
}

/* 递归：函数调用本身 */
int factorial(int val)
{
    if(val > 1)
        return factorial(val-1) * val;
    return 1;
}
/* 返回数组指针 */
typedef  int arrT[10]; /* arrT 是一个类型别名，他表示的类型是含有10个整数的数组 */
using arrT1 = int[10]; /* arrT1的等价声明 */
arrT* func(int i); /* func 返回一个指向10个整数的数组的 指针 */
int main()
{
/* !!!不要返回局部变量的引用 */
/* 调用运算符 ‘.’ */
    const string s1("hello"),s2("hello_1");
    auto sz = shorterString(s1,s2).size();
    cout << sz << endl;
/*****************************************************************************/
    string s("hello");
    get_val(s,0) = 'H';/* get_val 所得的返回值就是s【0】的引用，所以可以作为左值 */
    cout << s << endl;
/*****************************************************************************/
    cout << factorial(3) << endl; /* 调用递归 */
/* */
}
