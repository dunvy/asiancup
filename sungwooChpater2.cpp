// #include <iostream>
// using namespace std;

// int main(void){
//     int num = 10;
//     int i = 0;

//     cout << "true: " << true << endl;
//     cout << "false: " << false << endl;

//     while (true){
//         cout << i++ << ' ';
//         if(i>num){
//             break;
//         }
//     }
//     cout<<endl;

//     // 상수 1과 상수 0의 데이커 크기를 확인
//     cout << "sizeof 1: " << sizeof(1) << endl;
//     cout << "sizeof 0: " << sizeof(0) << endl;

//     // 참과 거짓을 의미하는 데이터 true와 false의 크기 확인
//     cout << "sizeof true: " << sizeof(true) << endl;
//     cout << "sizeof false: " << sizeof(false) << endl;
//     return 0;
// }



// //66p
// #include <iostream>
// using namespace std;

// bool IsPositive(int num){       // bool도 기본 자료형이라 반환형 선언 가능
//     if(num < 0)
//         return false;
//     else
//         return true;
// }

// int main(void){
//     bool isPos;     // bool형 변수 선언
//     int num;

//     cout << "Input number: ";
//     cin >> num;

//     isPos = IsPositive(num);        // 함수 InPositive가 반환하는 bool형 데이터 저장
//     if(isPos)
//         cout<<"Positive number" << endl;
//     else
//         cout<<"Negative number" << endl;

//     return 0;
// }



// // 69p
// #include <iostream>
// using namespace std;

// int main(void){
//     int num1 = 1020;
//     int &num2 = num1;   // num1에 대한 참조자 num2 선언 == num1, num2 동일한 메모리 공간 참조

//     num2 = 3047;
//     cout << "VAL: " << num1 << endl;
//     cout << "REF: " << num2 << endl;

//     cout << "VAL: " << &num1 << endl;
//     cout << "REF: " << &num2 << endl;
//     return 0;
// }



// // 72p
// #include <iostream>
// using namespace std;

// int main(void){
//     int arr[3] = {1,3,5};
//     int &ref1 = arr[0];
//     int &ref2 = arr[1];
//     int &ref3 = arr[2];

//     cout<<ref1<<endl;
//     cout<<ref2<<endl;
//     cout<<ref3<<endl;
//     return 0;
// }



// // 73p
// #include <iostream>
// using namespace std;

// int main(void){
//     int num = 12;
//     int *ptr = &num;
//     int **dptr = &ptr;

//     int &ref = num;

//     // 포인터 변수의 참조자 선언도 & 연산자를 하나 더 추가하는 형태로 진행
//     int*(&pref) = ptr;
//     int **(&dpref) = dptr;

//     cout << ref << endl;
//     cout << *pref << endl;      // pref는 포인터 변수 ptr의 참조자이므로, 변수 num에 저장된 값 출력
//     cout << **dpref << endl;    // dpref는 포인터 변수 dptr의 참조자이므로, 변수 num에 저장된 값 출력
//     return 0;
// }


// // 79p
// #include <iostream>
// using namespace std;

// // ref1, ref2에 저장된 값의 교환 과정 == main 함수의 변수 val1과 val2의 교환 성사
// void SwapByRef2(int &ref1, int &ref2){
//     int temp = ref1;
//     ref1 = ref2;
//     ref2 = temp;
// }

// int main(void){
//     int val1 = 10;
//     int val2 = 20;
    
//     // 매개변수로 참조자가 선언되었으므로, 참조의 대상이 될 변수를 인자로 전달
//     SwapByRef2(val1, val2);
//     cout << "val1: " << val1 << endl;
//     cout << "val2: " << val2 << endl;
//     return 0;
// }



// // 80p 연습문제 2-1
// // 문제1
// #include <iostream>
// using namespace std;
// // 인자로 전달된 int 변수의 값을 1씩 증가 시키는 함수
// void Add(int &num){
//     num += 1;
// }
// // 인자로 전달된 int형 변수의 부호를 바꾸는 함수
// void change(int &num){
//     num *= -1;
// }
// int main(void){
//     int a = 10, b = 20;
//     cout << "바뀌기 전\na: " << a << ", b: " << b << endl;
//     Add(a);
//     change(b);
//     cout<<"바뀐 후 \na: " << a << ", b: " << b << endl;
//     return 0;
// }

// // 문제3
// #include <iostream>
// using namespace std;
// void SwapPointer(int* &ptr, int* &ptr2){
//     int temp = *ptr;
//     *ptr = *ptr2;
//     *ptr2 = temp;
// }

// int main(void){
//     int num1 = 5;
//     int* ptr1 = &num1;
//     int num2 = 10;
//     int* ptr2 = &num2;
//     cout << "num1: "<< num1 << ", num2: " << num2 << endl;
//     SwapPointer(ptr1, ptr2);
//     cout << "num1: "<< num1 << ", num2: " << num2 << endl;
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int& RefRetFuncOne(int &ref){
//     ref++;
//     return ref;
// }

// int main(void){
//     int num1 = 1;
//     int &num2 = RefRetFuncOne(num1);

//     num1+=1;
//     num2+=100;
//     cout << "num1: " << num1 << endl;
//     cout << "num2: " << num2 << endl;
//     return 0;
// }


// // 90p 연습문제2-2
// // 포인터 변수를 선언해서 const int num = 12; 변수 가리키기
// #include <iostream>
// using namespace std;

// int main(void){
//     const int num = 12;
//     const int* ptr = &num;
//     const int* (&ptr2) = ptr;

//     cout << *ptr2 << endl;
// }



// // 93p
// #include <iostream>
// #include <string.h>
// #include <stdlib.h>
// using namespace std;

// char* MaskStrAdr(int len){
//     // char* str = (char*)malloc(sizeof(char)*len);    // 문자열 저장을 위한 배열을 힙 영역에 할당
//     char* str = new char[len];
//     return str;
// }

// int main(void){
//     char* str = MaskStrAdr(20);
//     strcpy(str, "I am so happy~");
//     cout << str << endl;
//     // free(str);       // 힙에 할당된 메모리 공간 소멸
//     delete []str;       // 배열의 형태로 할당된 메모리 공간의 해제
//     return 0;
// }

