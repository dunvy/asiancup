// #include <iostream>

// int main(void){
//     int num = 20;
//     std::cout << "Hello World!" << std::endl;
//     std::cout<<"Hello "<<"World!"<<std::endl;
//     std::cout<<num<<' '<<'A';
//     std::cout<<' '<<3.14<<std::endl;
//     return 0;
// }



// //17p sacnf를 대신하는 데이터의 입력
// #include <iostream>

// int main(void){
//     double val1;
//     std::cout<<"첫 번째 숫자입력: ";
//     std::cin>>val1;

//     double val2;
//     std::cout<<"두 번째 숫자 입력: ";
//     std::cin>>val2;

//     double result = val1+val2;
//     std::cout<<"덧셈결과: "<<result<<std::endl;
//     return 0;
// }



// //19p
// #include <iostream>

// int main(void){
//     int val1, val2;
//     int result = 0;
//     std::cout<<"두 개의 숫자 입력: ";
//     std::cin>>val1>>val2;       // 두 개의 정수를 입력받아서 val1, val2에 순서대로 저장

//     if(val1<val2){
//         for(int i = val1+1; i<val2; i++)
//             result += i;
//     }
//     else{
//         for (int i = val2+1; i < val1; i++)
//             result += i;
//     }

//     std::cout<<"두 수 사이의 정수 합: "<<result<<std::endl;
//     return 0;
// }


// //21p
// #include <iostream>

// int main(void){
//     char name[100];
//     char lang[200];

//     std::cout<<"이름은 무엇입니까? ";
//     std::cin>>name;

//     std::cout<<"좋아하는 프로그래밍 언어는 무엇인가요? ";
//     std::cin>>lang;

//     std::cout<<"내 이름은 "<<name<<"입니다.\n";
//     std::cout<<"제일 좋아하는 언어는 "<<lang<<"입니다."<<std::endl;
// }



// //연습문제 1-1
// //문제1
// #include <iostream>

// int main(void){
//     int n1,n2,n3,n4,n5;
//     int result;

//     std::cout<<1<<"번째 정수 입력: ";
//     std::cin>>n1;

//     std::cout<<2<<"번째 정수 입력: ";
//     std::cin>>n2;

//     std::cout<<3<<"번째 정수 입력: ";
//     std::cin>>n3;

//     std::cout<<4<<"번째 정수 입력: ";
//     std::cin>>n4;

//     std::cout<<5<<"번째 정수 입력: ";
//     std::cin>>n5;

//     result = n1+n2+n3+n4+n5;

//     std::cout<<"합계: "<<result<<std::endl;
//     return 0;
// }


// //문제2
// #include <iostream>

// int main(void){
//     char name[10];      // 이름
//     char num[20];       // 번호
    
//     std::cout<<"이름: ";
//     std::cin>>name;

//     std::cout<<"전화번호: ";
//     std::cin>>num;

//     std::cout<<"이름은 "<<name<<" 전화번호는 "<<num<<" 입니다.\n";
//     return 0;
// }


// //문제3
// #include <iostream>

// int main(void){
//     int num;
//     int result;

//     std::cout<<"숫자를 입력하시오: ";
//     std::cin>>num;

//     for (int i = 1; i < 10; i++)
//     {
//         result = num*i;
//         std::cout<<num<<" * "<<i<<" = "<<result<<std::endl;
//     }
//     return 0;
    
// }




//1228
// //문제4
// #include <iostream>

// int main(void){
//     int num = 0;
//     double total;

//     while(1){
//         std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
//         std::cin>>num;
        
//         if (num >=0){
//             total = 50 + num*0.12;
//             std::cout<<"이번 달 급여: "<<total<<"만원"<<std::endl;
//         }
//         else{
//             std::cout<<"프로그램을 종료합니다.\n";
//             break;
//         }
//     }
// }



// //1-2 함수 오버로딩(function Overloading)
// //25p
// #include <iostream>

// void MyFunc(void){
//     std::cout<<"MyFunc(void) called"<<std::endl;
// }

// void MyFunc(char c){
//     std::cout<<"MyFunc(char c) called"<<std::endl;
// }

// void MyFunc(int a, int b){
//     std::cout<<"MyFunc(int a, int b) called"<<std::endl;
// }

// int main(void){
//     MyFunc();
//     MyFunc('A');
//     MyFunc(12, 13);
//     return 0;
// }


// //연습문제 1-2
// #include <iostream>

// void swap(int num1, int num2){
//     std::cout<<num1<<' '<<num2<<std::endl;
// }

// void swap(char ch1, char ch2){
//     std::cout<<ch1<<' '<<ch2<<std::endl;
// }

// void swap(double dbl1, double dbl2){
//     std::cout<<dbl1<<' '<<dbl2<<std::endl;
// }

// int main(void){
//     swap(30,20);
//     swap('Z', 'A');
//     swap(5.555, 1.111);
//     return 0;
// }



// //1-3 매개변수의 디폴트 값(Default Value)
// #include <iostream>

// int Adder(int num1 = 1, int num2 = 2);

// int main(void){
//     std::cout<<Adder()<<std::endl;
//     std::cout<<Adder(5)<<std::endl;
//     std::cout<<Adder(3,5)<<std::endl;
//     return 0;
// }

// int Adder(int num1, int num2){
//     return num1+num2;
// }



// #include <iostream>
// int BoxVolume(int length, int width = 1, int height = 1);

// int main(void){
//     std::cout<<"[3,3,3] : "<<BoxVolume(3, 3, 3)<<std::endl;
//     std::cout<<"[5, 5, D] : "<<BoxVolume(5, 5)<<std::endl;
//     std::cout<<"[7, D, D] : "<<BoxVolume(7)<<std::endl;
//     // std::cout<<"[D, D, D] : "<<BoxVolume()<<std::endl;
//     return 0;
// }

// int BoxVolume(int length, int width, int height){
//     return length*width*height;
// }



// //1-4 인라인(inline) 함수
// #include <iostream>

// inline int SQUARE(int x){
//     return x*x;
// }

// int main(void){
//     std::cout<<SQUARE(5)<<std::endl;
//     std::cout<<SQUARE(12)<<std::endl;
//     return 0;
// }


// #include <iostream>

// template <typename T>
// inline T SQUARE(T x){
//     return x*x;
// }

// int main(void){
//     std::cout<<SQUARE(5.5)<<std::endl;
//     std::cout<<SQUARE(12)<<std::endl;
//     return 0;
// }



// 이름공간
// 38p
#include <iostream>

namespace BestComImpl{
    void SimpleFunc(void){
        std::cout<<"BestCom이 정의한 함수"<<std::endl;
    }
}

namespace ProgComImpl{
    void SimpleFunc(void){
        std::cout<<"ProgCom이 정의한 함수"<<std::endl;
    }
    
}