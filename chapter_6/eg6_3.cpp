#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
/* ���� ctr ��ֵ����1������ word �ĸ�����ʽ */
string make_plural(size_t ctr, const string &word,const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
/* ��������string �����н϶̵��Ǹ������������� */
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
/* ���÷��ص���ֵ */
char &get_val(string &str, string::size_type ix)
{
    return str[ix] ;
}
/* �б��ʼ������ֵ */
vector<string> process(string expected,string actual)
{
    if(expected.empty())
        return {};
    else if (expected == actual)
        return {"functionX","okay"};
    else
        return {"functionX",expected,actual};
}

/* �ݹ飺�������ñ��� */
int factorial(int val)
{
    if(val > 1)
        return factorial(val-1) * val;
    return 1;
}
/* ��������ָ�� */
typedef  int arrT[10]; /* arrT ��һ�����ͱ���������ʾ�������Ǻ���10������������ */
using arrT1 = int[10]; /* arrT1�ĵȼ����� */
arrT* func(int i); /* func ����һ��ָ��10������������� ָ�� */
int main()
{
/* !!!��Ҫ���ؾֲ����������� */
/* ��������� ��.�� */
    const string s1("hello"),s2("hello_1");
    auto sz = shorterString(s1,s2).size();
    cout << sz << endl;
/*****************************************************************************/
    string s("hello");
    get_val(s,0) = 'H';/* get_val ���õķ���ֵ����s��0�������ã����Կ�����Ϊ��ֵ */
    cout << s << endl;
/*****************************************************************************/
    cout << factorial(3) << endl; /* ���õݹ� */
/* */
}
