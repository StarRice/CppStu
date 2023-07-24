#include <iostream>
#include <stdexcept>
using namespace std;

//#define PRACTICE_5_23 0
#define PRACTICE_5_24 0
#define PRACTICE_5_25 1

int main()
{
    int num1,num2;/*num1 被除数；num2 除数 */
#ifdef PRACTICE_5_23
    cin >> num1 >> num2;
    cout << num1/num2 << endl;

#elif PRACTICE_5_24
    cin >> num1 >> num2;
    if(num2 == 0)
        throw runtime_error("raise error ");
    cout << "两数相除的结果是： "<< num1/num2 << endl;

#elif PRACTICE_5_25
    while(cin >> num1 >> num2){
        try{
            if(num2 == 0)
                throw runtime_error("raise error "); /* 抛出异常 */
            cout << "两数相除的结果是： "<< num1/num2 << endl;

        } catch(runtime_error err) { /* 检测到异常的对象 */
            cout << err.what() /* 输出异常的信息 */
                <<"\nTry Again? Enter y/n "; 
            char c;
            cin >> c;
            if(c!='y' && c != 'Y')
                break; /* 跳出while()循环 */
        }
    }
#endif
    return 0;
}