// #include <iostream>
// using namespace std;

// template <typename T>   // 템플릿 A
// void ShowArray(T arr[], int n);

// template <typename T>   // 템플릿 B
// void ShowArray(T* arr[], int n);

// struct debts
// {
//     char name[50];
//     double amount;
// };

// int main(void){
//     int things[6] = {13, 31, 103, 301, 310, 130};
//     struct debts mr_E[3] =          // 구조체 배열
//     {
//         {"Ima Wolfe", 2400.0},
//         {"Ura Foxe", 1300.0},
//         {"Iby Stout", 1800.0},
//     };
//     double* pd[3];

//     // 포인터들을 배열 mr_E에 있는 구조체들의 amount 멤버로 설정
//     for(int i = 0; i<3; i++)
//         pd[i] = &mr_E[i].amount;
//     cout << "Mr.E이 재산 목록:\n";

//     // thing는 int형의 배열
//     ShowArray(things, 6);       // 템플릿 A를 사용
//     cout << "Mr. E의 채무 목록: \n";
    
//     // pd는 double형을 지시하는 포인터들의 배열
//     ShowArray(pd, 3);           // 더 특수화된 템플릿 B를 사용
//     return 0;
// }

// template <typename T>
// void ShowArray(T arr[], int n){
//     cout <<"템플릿 A\n";
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << ' ';
//     cout << endl;    
// }

// template <typename T>
// void ShowArray(T* arr[], int n){
//     cout << "템플릿 B\n";
//     for (int i = 0; i < n; i++)
//         cout << *arr[i] <<' ';
//     cout << endl;
// }



// 템플릿 선택
#include <iostream>
using namespace std;

template <class T>      // 또는 템플릿<typename T>
T lesser(T a, T b)      // #1
{
    return a < b ? a : b;
}

int lesser(int a, int b)        // #2
{
    a = a < 0 ? -a:a;
    b = b < 0 ? -b:b;
    return a < b ? a : b;
}

int main(void){
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;      // #2 사용
    cout << lesser(x, y) << endl;      // double과 함께 #1 사용
    cout << lesser<>(m,n) << endl;     // int와 함께 #1을 사용
    cout << lesser<int>(x,y) << endl;  // int와 함께 #1을 사용

    return 0;
}