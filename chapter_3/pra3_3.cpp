/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-19 10:22:00
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-19 13:57:42
 * @FilePath: \c++\chapter_3\pra3_3.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//#define PRACTICE_3_16 0
#define PRACTICE_3_17 0
#define PRACTICE_3_18 0
#define PRACTICE_3_19 0
#define PRACTICE_3_20 1
int main()
{
#ifdef PRACTICE_3_16

    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};
    vector<string> v7{10,"hi"};

/* �������һ�� vector�Ĵ�С�������������ĳ�Ա */
    vector<vector<int>> v{v1,v2,v3,v4,v5};  
    vector<vector<string>> vs{v6,v7};

/* for�ڱ������������ڽ���forѭ�� */
    for (decltype(v.size()) index = 0; index <5;index++){
        cout << "v" << index+1 <<"�Ĵ�СΪ" << v[index].size()<<endl;
        cout << "v" << index+1 <<" ��ֵΪ ";
        for(auto c:v[index])
            cout << c ;
        cout << endl;
    }

/* ����ķ�Χ������ vs ���������� �����������Χ�������ͨ����
   �������лᱨ what(): std::bad_alloc ����*/
    for (decltype(vs.size()) index = 0; index <2;index++){
        cout << "v" << index+6 <<"�Ĵ�СΪ" << vs[index].size()<<endl;
        cout << "v" << index+6 <<" ��ֵΪ ";
        for(auto c:vs[index])
            cout << c ;
        cout << endl;
    }

#elif  PRACTICE_3_17

    vector<string> vec;
    string s; /* ���ڽ��������ַ��Ļ��� */
    while(cin>>s){
        vec.push_back(s); /* ���ַ���ѹ������ */
        for(auto &c : vec){ /* �õ������е�ÿ����Ա���� */
            for (auto &i:c){/* �õ���Ӧ��Ա������ÿ���ַ� */
                i = toupper(i); /* ��Ϊ��д ����Ϊȫ�����õ����ã����ԭ�������ֵҲ�ı��� */
            }
        }
        if(cin.get() == '\n') break; /* ���س����˳�while */
    }
    for(auto i:vec)
        cout << i << endl;
    
#elif  PRACTICE_3_18
/* �𣺲��Ϸ� */
    vector<int> ivec;
    ivec.push_back(42);
    cout << ivec[0];

#elif  PRACTICE_3_19
    vector<int> v1(10,42); /* ��� */
    vector<int> v2{42,42,42,42,42,42,42,42,42,42};
    vector<int> v3;
    for(int i=0;i<10;i++){
        v3.push_back(42);
    }

#elif  PRACTICE_3_20

    vector<int> ivec;
    int i=0; /* ���ڽ����������ݵĻ��� */
    while(cin>>i){
        ivec.push_back(i);
        if(cin.get() == '\n') break;
    }
/* ����������������ĺ� */
    for(decltype(ivec.size()) index = 0 ;index < (ivec.size()-1);index++)
        cout<< ivec[index]+ivec[index+1] <<endl;
    cout<<"***********************�ָ���**************************"<<endl;
/* ����Գ����������ĺ� */
    for(decltype(ivec.size()) index = 0 ;index < (ivec.size()/2);index++){
        if(ivec.size()%2 ==0){
            cout<< ivec[index]+ivec[ivec.size()-index-1] <<endl;
        }
        else{
            cout << "������ż��������" <<endl;
            break;
        }
    }
#endif
    return 0;
}