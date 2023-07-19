/*
 * @Author: yw o 1622945822@qq.com
 * @Date: 2023-07-18 17:10:14
 * @LastEditors: yw o 1622945822@qq.com
 * @LastEditTime: 2023-07-19 14:00:55
 * @FilePath: \c++\chapter_3\eg3_3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> v2; /* 空vector对象 */
    for(int i = 0; i!= 100; i++)
        v2.push_back(i);
    /* 此时v2中包含 0~100 */
    return 0;
}
