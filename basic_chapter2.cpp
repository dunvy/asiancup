// //2장 프로그래밍 연습
// #include <iostream>
// using namespace std;

// // 1번
// int main(void){
//     char name[50];
//     char addr[50];
//     cout<<"이름을 입력하시오: ";
//     cin>>name;
//     cout<<"주소를 입력하시오: ";
//     cin>>addr;

//     cout<<"이름: "<<name<<endl<<"주소: "<<addr<<endl;
//     return 0;
// }


// //2번
// int main(void){
//     double mile, km;
//     cout<<"마일 단위로 입력하시오: ";
//     cin>>mile;
//     km = mile*1.60934;
//     cout<<"킬로미터 환산: "<<km<<endl;
//     return 0;
// }


// //3번
// void CallOne(void);
// void CallTwo(void);

// int main(void){
//     CallOne();
//     CallOne();
//     CallTwo();
//     CallTwo();
//     return 0;
// }

// void CallOne(void){
//     cout<<"Three blind mice"<<endl;
// }
// void CallTwo(void){
//     cout<<"See how they run"<<endl;
// }


// // 4번
// int main(void){
//     int num, num2;
//     char name[50];

//     cout<<"Enter your age: ";
//     cin>>num;
//     num2 = num*12;
//     cout<<"당신의 나이를 월수로 나타낼 경우 "<<num2<<"입니다.\n";
//     return 0;
// }


// // 5번
// void Fa(int);

// int main(void){
//     int n1, n2;

//     cout<<"섭씨 온도를 입력하고 Enter 키를 누르십시오: ";
//     cin>>n1;
//     Fa(n1);
//     return 0;
// }

// void Fa(int n){
//     double a = 1.8*n+32.0;
//     cout<<"섭씨 "<<n<<"도는 화씨로 "<<a<<"도 입니다.\n";
// }


// // 6번
// void distance(double);

// int main(void){
//     double num;

//     cout<<"광년 수를 입력하고 Enter 키를 누르십시오: ";
//     cin>>num;
//     distance(num);
//     return 0;
// }

// void distance(double n){
//     double n2 = n*63240;
//     cout<<n<<" 광년은 "<<n2<<" 천문 단위입니다. \n";
// }


// // 7번
// void time(int);
// void min(int);

// int main(void){
//     int n1, n2;
//     cout<<"시간 값을 입력하시오: ";
//     cin>>n1;
//     cout<<"분 값을 입력하시오: ";
//     cin>>n2;
//     time(n1);
//     min(n2);
//     return 0;
// }

// void time(int n){
//     cout<<"시각: "<<n;
// }
// void min(int n){
//     cout<<":"<<n<<endl;
// }