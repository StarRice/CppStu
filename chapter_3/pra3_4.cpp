/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-19 10:22:00
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-19 16:28:54
 * @FilePath: \c++\chapter_3\pra3_3.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//#define PRACTICE_3_21 0
#define PRACTICE_3_22 0
#define PRACTICE_3_23 0
#define PRACTICE_3_24 0
#define PRACTICE_3_25 1
int main()
{
#ifdef PRACTICE_3_21
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};
    vector<string> v7{10,"hi"};

/* �������һ��vector�Ĵ�С�������������ĳ�Ա */
    vector<vector<int>> v{v1,v2,v3,v4,v5};  
    vector<vector<string>> vs{v6,v7};

/* for�ڱ������������ڽ���forѭ�� */
    int i = 0; /* �������������Ϣ������ */
    for(auto it = v.cbegin();it !=v.cend();++it){
        cout << "v" << i+1 <<"�Ĵ�СΪ" << it->size()<<endl;
        cout << "v" << i+1 <<" ��ֵΪ ";
        for(auto c:(*it))
            cout << c ;
        cout << endl;
        i++;
    }
    int dex=0; /* �������������Ϣ������ */
    for(auto it = vs.cbegin();it !=vs.cend();++it){
        cout << "v" << dex+6 <<"�Ĵ�СΪ" << it->size()<<endl;
        cout << "v" << dex+6 <<" ��ֵΪ ";
        for(auto c:(*it))
            cout << c ;
        cout << endl;
        dex++;
    }
#elif  PRACTICE_3_22
    string text("some thing");
    for(auto it = text.begin();it !=text.end() && !isspace((*it));++it)
        (*it) = toupper((*it));
    cout << text << endl;

#elif  PRACTICE_3_23
    vector<int> v(10,1);
    for(auto it = v.begin();it!=v.end();++it){
        (*it) *= 2;
    }
    for(auto c:v)
        cout << c <<endl;

#elif  PRACTICE_3_24

    vector<int> ivec;
    int i=0; /* ���ڽ����������ݵĻ��� */
    while(cin>>i){
        ivec.push_back(i);
        if(cin.get() == '\n') break;
    }
/* ����������������ĺ� */
    for(auto it = ivec.begin(); it!= (ivec.end()-1);++it) /* endָ�����������һ��Ԫ�صĺ�һ��λ�ã����Ҫ��1 */
        cout<< (*it) + (*(it+1)) <<endl;
    cout<<"***********************�ָ���**************************"<<endl;
/* ����Գ����������ĺ� */
    int dex = 0; /* �����ƶ������� */
    auto mid = ivec.begin() + ivec.size()/2;
    for(auto it = ivec.begin(); it!= mid; ++it){
        if(ivec.size()%2 ==0){
            cout<< *it + *(ivec.end()-dex-1)  << endl;
            dex++;
        }
        else{
            cout << "������ż��������" <<endl;
            break;
        }
    }   

#elif  PRACTICE_3_25
    /* ���ַ����� */
    vector<unsigned> scores(11,0);
    unsigned grade;
    auto it = scores.begin();
    while(cin >> grade){
        if(grade<=100){
            ++*(it+grade/10);
        }
        if(cin.get() == '\n') break;
    }
    for(auto c:scores)
        cout << c << endl;
#endif
    return 0;
}