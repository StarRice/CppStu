#include <iostream>
#include <stdexcept>
using namespace std;

//#define PRACTICE_5_23 0
#define PRACTICE_5_24 0
#define PRACTICE_5_25 1

int main()
{
    int num1,num2;/*num1 ��������num2 ���� */
#ifdef PRACTICE_5_23
    cin >> num1 >> num2;
    cout << num1/num2 << endl;

#elif PRACTICE_5_24
    cin >> num1 >> num2;
    if(num2 == 0)
        throw runtime_error("raise error ");
    cout << "��������Ľ���ǣ� "<< num1/num2 << endl;

#elif PRACTICE_5_25
    while(cin >> num1 >> num2){
        try{
            if(num2 == 0)
                throw runtime_error("raise error "); /* �׳��쳣 */
            cout << "��������Ľ���ǣ� "<< num1/num2 << endl;

        } catch(runtime_error err) { /* ��⵽�쳣�Ķ��� */
            cout << err.what() /* ����쳣����Ϣ */
                <<"\nTry Again? Enter y/n "; 
            char c;
            cin >> c;
            if(c!='y' && c != 'Y')
                break; /* ����while()ѭ�� */
        }
    }
#endif
    return 0;
}