/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-25 11:27:59
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-26 17:13:53
 * @FilePath: \c++\chapter_6\eg6_2.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
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
/*ָ���� ��ʼ������ */
void reset(int *ip){
    *ip = 0;
    ip = 0;
}
/* ������ ��ʼ������*/
void reset(int &i){
    i = 0;
}
/*
 *@brif:�Ƚ��ַ����ĳ��� 
 *@param:str1 ���Ƚϵ��ַ���1
 *@param:str2 ���Ƚϵ��ַ���2
 *@return: str1 < str2 ʱ����1
*/
bool isShorter(const string &str1,const string &str2){
    return str1.size() < str2.size();
}
/*
 *@brif:�����ַ�����ĳ���ַ��״γ��ֵ�λ�� �� ���ֵ��ܴ���
 *@param: s ������ַ���
 *@param: c Ŀ�����ַ�
 *@param��occurs Ŀ���ַ����ַ������ܹ������˼���
 *@return: ret Ŀ�����ַ����ַ����е�һ�γ��ֵ�����λ 
*/
string::size_type find_char(const string &s , char c,string::size_type &occurs){

    auto ret = s.size(); /* ��һ�γ��ֵ�λ�� */
    occurs = 0;          /* ��ʼ�����ִ�����ֵ */
   for(decltype(ret) i = 0;i != s.size(); ++i){
        if(s[i] == c){
            if(ret == s.size()) /* ֻ��¼��һ�γ��ֵ�λ�ã������ֵڶ���ʱ ret �Ͳ����� s.size() */
                ret = i;
            ++occurs; /* ���ֵĴ���+1 */
        }
   }
   return ret; /* ���￴ֻ������һ��ֵ������ occurs ����ʽ�ط�����*/
}
/********************************************************************/
/* ��������Ϊ�β� */
/* 1.ʹ�ñ��ָ�����鳤�� */
void print(const char * cp)
{
    if(cp) /* ������һ����ָ��*/
        while(*cp)/* ָ����ָ���ַ����ǿ��ַ� */
            cout << *cp++; /* �����ǰ�ַ�����ָ����ǰ�ƶ�һ��λ�� */
}
/* 2.ʹ�ñ�׼��淶 */
void print(const int *beg,const int *end)
{
    while(beg != end)
        cout << *beg++ <<endl;
}
/* 3.��ʽ����һ�������С���β� */
void print(const int ia[],size_t size)
{
    for (size_t i = 0;i != size;++i ){
        cout << ia[i] << endl;
    }
}
/* 4.���������β� */
void print(int (&arr)[10]) 
{/* ֻ�ܴ���10������������ */
    for(auto elem :arr)
        cout << elem << endl;
}
/* 5.���ݶ�ά���� */
void print(int (*matrix)[10], int rowSize)
{
    /* */
}
/****************************************************************/
/* ���пɱ��βεĺ��� */
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end();++beg)
        cout << *beg << " ";
    cout << endl;
}
/* ��׼�Ⲣû��ErrCode�࣬���ڿ�ͷ�Լ�������һ�� */
void error_msg(ErrCode e,initializer_list<string> il)
{
    cout << e.msg() << ":";
    for(auto elem : il)
        cout << elem << " ";
    cout << endl;
}
int main(int argc, char *argv[])
{   /* argc�� ������������� argv ��ָ��char *�� ��ָ�� */
    const string s("hello world");
    string::size_type sum = 0;
    auto index = find_char(s,'r',sum);

    cout << index << endl;
    cout << sum <<endl;

/******************************************************************/
    int i = 1 ;
    const int ci = i;
    string::size_type ctr = 0;

    reset(&i); /* �������ص����β�������int *�� reset ����*/
//    reset(&ci);/* ���󣺲�����const int �����ָ���ʼ�� ��int *�� */
    reset(i);  /* ���� int& ��reset ���� */
//    reset(ci); /* ���󣺲��ܰ���ͨ���ð󶨵�const ���� ci ��*/
//    reset(ctr); /* ����ctr ���޷������� ����������Ҫһ�� */

/******************************************************************/
    int j[] = {0,1};
    print(begin(j),end(j));
    print(j,end(j) - begin(j));
/* ���Դ��ε� main ���÷�*/
    while(argc-- > 0){
        printf("argv[%d]:%s\n",argc,argv[argc]);
    }
/******************************************************************/
    string expected("hello");
    string actual;
    cin >> actual;
    if(expected != actual)
       // error_msg({"functionX",expected, actual}); /* ��������ʵ�� */
        error_msg(ErrCode(42),{"functionX",expected, actual}); 
    else
       // error_msg({"functionX","okay"}); /* ����2��ʵ�� */
        error_msg(ErrCode(0),{"functionX","okay"}); 
    
    return 0;
}