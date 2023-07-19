/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-19 10:22:00
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-19 13:57:42
 * @FilePath: \c++\chapter_3\pra3_3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
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

/* 便于输出一堆 vector的大小和里面所包含的成员 */
    vector<vector<int>> v{v1,v2,v3,v4,v5};  
    vector<vector<string>> vs{v6,v7};

/* for内变量的生命周期仅在for循环 */
    for (decltype(v.size()) index = 0; index <5;index++){
        cout << "v" << index+1 <<"的大小为" << v[index].size()<<endl;
        cout << "v" << index+1 <<" 的值为 ";
        for(auto c:v[index])
            cout << c ;
        cout << endl;
    }

/* 这里的范围索引是 vs 容器的索引 ，如果超出范围编译可以通过，
   但是运行会报 what(): std::bad_alloc 错误*/
    for (decltype(vs.size()) index = 0; index <2;index++){
        cout << "v" << index+6 <<"的大小为" << vs[index].size()<<endl;
        cout << "v" << index+6 <<" 的值为 ";
        for(auto c:vs[index])
            cout << c ;
        cout << endl;
    }

#elif  PRACTICE_3_17

    vector<string> vec;
    string s; /* 用于接收输入字符的缓存 */
    while(cin>>s){
        vec.push_back(s); /* 将字符串压入容器 */
        for(auto &c : vec){ /* 得到容器中的每个成员变量 */
            for (auto &i:c){/* 得到相应成员变量的每个字符 */
                i = toupper(i); /* 改为大写 ，因为全部是用的引用，因此原容器里的值也改变了 */
            }
        }
        if(cin.get() == '\n') break; /* 按回车键退出while */
    }
    for(auto i:vec)
        cout << i << endl;
    
#elif  PRACTICE_3_18
/* 答：不合法 */
    vector<int> ivec;
    ivec.push_back(42);
    cout << ivec[0];

#elif  PRACTICE_3_19
    vector<int> v1(10,42); /* 最好 */
    vector<int> v2{42,42,42,42,42,42,42,42,42,42};
    vector<int> v3;
    for(int i=0;i<10;i++){
        v3.push_back(42);
    }

#elif  PRACTICE_3_20

    vector<int> ivec;
    int i=0; /* 用于接收输入数据的缓存 */
    while(cin>>i){
        ivec.push_back(i);
        if(cin.get() == '\n') break;
    }
/* 输出相邻两个整数的和 */
    for(decltype(ivec.size()) index = 0 ;index < (ivec.size()-1);index++)
        cout<< ivec[index]+ivec[index+1] <<endl;
    cout<<"***********************分割线**************************"<<endl;
/* 输出对称两个整数的和 */
    for(decltype(ivec.size()) index = 0 ;index < (ivec.size()/2);index++){
        if(ivec.size()%2 ==0){
            cout<< ivec[index]+ivec[ivec.size()-index-1] <<endl;
        }
        else{
            cout << "请输入偶数个整数" <<endl;
            break;
        }
    }
#endif
    return 0;
}