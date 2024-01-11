// #include <iostream>
// #include <climits>      //구식 c++에는 limits.h를 사용함

// using namespace std;

// int main(){
//     int n_int = INT_MAX;
//     short n_short = SHRT_MAX;
//     long n_long = LONG_MAX;
//     long long n_llong = LLONG_MAX;

//     // sizeof 연산자는 데이터형이나 변수의 크기를 알아낸다
//     cout<<"int는 "<<sizeof(int)<<" 바이트이다."<<endl;
//     cout<<"short는 "<<sizeof n_short<<" 바이트이다."<<endl;
//     cout<<"long은 "<<sizeof n_long<<" 바이트이다."<<endl;
//     cout<<"long long은 "<<sizeof n_llong<<" 바이트이다."<<endl;
//     cout<<endl;

//     cout<<"최대값:"<<endl;
//     cout<<"int: "<<n_int<<endl;
//     cout<<"short: "<<n_short<<endl;
//     cout<<"long: "<<n_long<<endl;
//     cout<<"long long: "<<n_llong<<endl;
//     cout<<"int와 최소값 = "<<INT_MIN<<endl;
//     cout<<"char의 비트 수 =  "<<CHAR_BIT<<endl;
//     return 0;    
// }


// //82p 정수 한계값을 초과한다.
// #include <iostream>
// #define ZERO 0          // 값 0으로 대체될 기호 상수 ZERO를 정의함
// #include <climits>      // INT_MAX가 int형의 최대값으로 정의되어 있음
// using namespace std;

// int main(void){
//     short Dohee = SHRT_MAX;                         // 변수를 최대값으로 초기화
//     unsigned short Insuk = Dohee;                   // Dohee가 정의돼있음

//     cout<<"도희의 계좌에는 "<<Dohee<<"원이 들어있고, ";
//     cout<<"인숙이의 계좌에도 "<<Insuk<<"원이 들어 있다."<<endl;
//     cout<<"각각의 계좌에 1원씩 입금한다."<<endl<<"이제 ";
//     Dohee = Dohee + 1;
//     Insuk = Insuk + 1;
//     cout<<"도희의 잔고는 "<<Dohee<<"원이 되었고, ";
//     cout<<"인숙이의 잔고는 "<<Insuk<<"원이 되었다."<<endl;
//     cout<<"이럴 수가! 도희가 나 몰래 대출을 했니?"<<endl;
//     Dohee = ZERO;
//     Insuk = ZERO;
//     cout<<"도희의 계좌에는 "<<Dohee<<"원이 들어있고, ";
//     cout<<"인숙이의 계좌에도 "<<Insuk<<"원이 들어있다."<< endl;
//     cout<<"각각의 계좌에서 1원씩 인출한다."<<endl<<"이제 ";
//     Dohee = Dohee -1;
//     Insuk = Insuk -1;
//     cout<<"도희의 잔고는 "<<Dohee<<"원이 되었고, ";
//     cout<<"인숙이의 잔고는 "<<Insuk<<"원이 되었다."<<endl;
//     cout<<"이럴 수가! 인숙이가 복권에 당첨되었나?"<<endl;
//     return 0;
// }



// //16진 정수형 상수와 8진 정수형 상수를 보여줌
// #include <iostream>
// using namespace std;
// int main(void){
//     int chest = 42;         // 10진 정수형 상수
//     int waist = 0x42;       // 16진 정수형 상수
//     int inseam = 042;       // 8진 정수형 상수

//     cout<<"손님 사이즈\n";
//     cout<<"가슴둘레 "<< chest<<"\n";
//     cout<<"허리둘레 "<<waist<<"\n";
//     cout<<"인심길이 "<<inseam<<"\n";
//     return 0;
// }



// // 값을 16진수와 8진수로 디스플레이 함
// #include <iostream>
// using namespace std;
// int main(void){
//     int chest = 42;
//     int waist = 42;
//     int inseam = 42;

//     cout<<"손님 사이즈"<<endl;
//     cout<<"가슴둘레 "<<chest<<" (10진수)"<<endl;
//     cout<<hex;      // 진법을 바꾸는 조정자
//     cout<<"허리둘레 "<<waist<<" (16진수)"<<endl;
//     cout<< oct;     // 진법을 바꾸는 조정자
//     cout<<"인심길이 "<<inseam<<" (8진수)"<<endl;
//     return 0;
// }



// // 90p
// // char형
// #include <iostream>
// using namespace std;

// int main(void){
//     char ch;

//     cout<<"원하는 문자 하나를 입력하시오: "<<endl;
//     cin>>ch;
//     cout<<"감사합니다. ";
//     cout<<"당신이 입력한 문자는 "<<ch<<" 입니다."<<endl;
//     return 0;
// }


// // 91p
// // char형과 int형의 비교
// #include <iostream>
// using namespace std;

// int main(void){
//     char ch = 'M';      // M에 해당하는 ASCII 코드를 char형 변수 ch에 대입
//     int i = ch;
//     cout<<ch<<"의 ASCII 코드는 "<< i<<"입니다."<<endl;

//     cout<<"이 문자 코드에 1을 더해보겠습니다."<<endl;
//     ch = ch + 1;            // ch에 있는 문자 코드를 변경한다
//     i = ch;
//     cout<<ch<<"의 ASCII 코드는"<<i<< "입니다."<<endl;

//     //cout.put() 멤버 함수를 사용하여 char형 변수 ch를 출력한다
//     cout<<"cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력: ";
//     cout.put(ch);

//     //cout.put()을 사용하여 문자 상수를 출력한다
//     cout.put('!');

//     cout<<endl<<"종료"<< endl;
//     return 0;
// }


// // 96p
// // 이스케이프 시퀀스 사용
// #include <iostream>
// using namespace std;
// int main(void){
//     cout<<"\a암호명 \"화려한외출\" 작전이 방금 개시되었습니다!\n";
//     cout<<"8자리 비밀번호를 입력하십시오: ________\b\b\b\b\b\b\b\b";        //\b: 백스페이스 문자
//     long code;
//     cin>>code;
//     cout<<"\a입력하신 비밀번호는 " <<code<<"입니다.\n";
//     cout<<"\a비밀번호가 맞습니다! z3 계획을 진행하십시오!\n";
//     return 0;
// }



// //107p
// #include <iostream>
// using namespace std;

// int main(void){
//     cout.setf(ios_base::fixed, ios_base::floatfield);   // 고정 소수점 형식으로 출력
//     float tub = 10.0/3.0;       // 유효 숫자 6개
//     double mint = 10.0/3.0;     // 유효 숫자 15개
//     const float million = 1.0e6;

//     cout<<"tub = "<<tub;
//     cout<<", a million tubs - "<< million * tub;
//     cout<<",\nten million tubs = ";
//     cout<<10*million *tub <<endl;

//     cout<<"mint = "<<mint << "and a million mints = ";
//     cout<< million*mint << endl;
//     return 0;
// }


// //109p
// //float형에서의 정밀도 손실문제
// #include <iostream>
// using namespace std;
// int main(){
//     float a = 2.34E+22f;
//     float b = a+1.0f;

//     cout<<"a = "<<a << endl;
//     cout<<"b-a ="<<b-1<<endl;
//     return 0;
// }



// //111p
// //c++의 산술 연산
// #include <iostream>
// using namespace std;
// int main(void){
//     float hats, heads;

//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     cout<<"수를 하나 입력하십시오: ";
//     cin>>hats;
//     cout<<"다른 수를 입력하십시오: ";
//     cin>>heads;

//     cout<<"hats = "<<hats<<"; heads = "<<heads << endl;
//     cout<<"hats + heads = "<<hats +heads << endl;
//     cout<<"hats - heads = "<<hats - heads << endl;
//     cout<<"hats * heads = "<<hats* heads<<endl;
//     cout<<"hats / heads = "<<hats/ heads<<endl;
//     return 0;
// }



// //114p
// // 정수 나눗셈과 부동 소수점수 나눗셈
// #include <iostream>
// using namespace std;

// int main(void){
//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     cout<<"정수 나눗셈: 9/5 = "<< 9/5 << endl;
//     cout<<"부동 소수점수 나눗셈: 9.0/5.0 = ";
//     cout<<9.0/5.0<<endl;
//     cout<<"혼합 나눗셈: 9.0/5 = "<<9.0/5<<endl;
//     cout<<"double형 상수: 1e7/9.0 = ";
//     cout<< 1.e7/9.0 << endl;
//     cout<<"float형 상수: 1e7f/9.0f = ";
//     cout<<1.e7f / 9.0f << endl;
//     return 0;
// }



// //116p
// // % 연산자를 사용하여 파운드를 스톤으로 변환함
// #include <iostream>
// using namespace std;
// int main(void){
//     const int Lbs_per_stn = 14;
//     int lbs;

//     cout<<"당신의 체중을 파운드 단위로 입력하십시오: ";
//     cin>>lbs;
//     int stone = lbs/Lbs_per_stn;            // 몫은 스톤으로
//     int pounds = lbs % Lbs_per_stn;         // 나머지는 파운드로
//     cout<< lbs << " 파운드는 "<<stone<<" 스톤, "<<pounds<<" 파운드입니다.\n";
//     return 0;
// }



// // 118p
// // 대입 구문에서 일어나는 데이터형 변환
// #include <iostream>
// using namespace std;

// int main(void){
//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     float tree = 3;                         // int형을 float형으로 변환
//     int guess = 3.9832;                     // float형을 int형으로 변환
//     int debt = 7.2E12;                      // 결과를 예측할 수 없다
//     cout<<"tree = "<<tree<<endl;
//     cout<<"guess = "<<guess<<endl;
//     cout<<"debt = "<<debt <<endl;
//     return 0;
// }




// 프로그래밍 연습
#include <iostream>
using namespace std;

// // 1번
// int main(void){
//     int num;

//     cout<<"키(cm)를 입력하시오: ___\b\b\b";
//     cin>>num;

//     const int m = num/100;
//     const int cm = num % 100;
    
//     cout<<m<<"m "<<cm<<"cm\n";
//     return 0;
// }


// // 2번
// int main(void){
//     int in;         // 인치
//     int ft;         // 피트
//     int lb;         // 파운드

//     cout<<"키(ft)를 입력하시오: ";
//     cin >> ft;
//     const int inft = ft*12;
//     const double m = double(inft*0.0254);

//     cout<<"키(in)를 입력하시오: ";
//     cin >> in;
//     const double m2 = double(inft*0.0254);

//     cout<<"체중(lb)를 입력하시오: ";
//     cin >> lb;
//     const double kg = lb*2.2;

//     const double bmi1 = kg / m*m;
//     const double bmi2 = kg / m2*m2;

//     cout<<bmi1<<endl<<bmi2<<endl;

//     return 0;
// }



// 3번
int main(void){
    int num, num2, num3;
    cout<<"위도를 도, 분, 초 단위로 입력하시오: "<<endl;
    cout<<"먼저, 도각을 입력하시오: ";
    cin>>num;
    cout<<"다음에, 분각을 입력하시오: ";
    cin>>num2;
    cout<<"끝으로, 초각을 입력하시오: ";
    cin>>num3;
    
    return 0;
}