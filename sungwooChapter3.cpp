// #include <iostream>
// using namespace std;

// // 구조체 Car와 관련된 각종 정보를 상수화
// #define ID_LEN      20
// #define MAX_SPD     200
// #define FUEL_STEP   2
// #define ACC_STEP    10
// #define BRK_STEP    10

// struct Car{
//     char gamerID[ID_LEN];   // 소유자 ID
//     int fuelGauge;          // 연료량
//     int curSpeed;           // 현재속도
// };

// void ShowCarState(const Car &car){      // 차의 정보를 출력하는 기능(정보 출력을 위해 const 참조자)
//     cout<<"소유자ID: "<<car.gamerID<<endl;
//     cout<<"연료량: "<<car.fuelGauge<<"%"<<endl;
//     cout<<"현재속도: "<<car.curSpeed<<"km/s"<<endl<<endl;
// }

// void Accel(Car &car){           // 차의 가속을 위해 엑셀 밟는 상황(엑셀 밟을 때마다 연료가 줄어들고 스피드가 올라감)
//     if(car.fuelGauge<=0)   
//         return;
//     else
//         car.fuelGauge -= FUEL_STEP;

//     if (car.curSpeed+ACC_STEP >= MAX_SPD){
//         car.curSpeed = MAX_SPD;
//         return;
//     }
//     car.curSpeed += ACC_STEP;
// }

// void Break(Car &car){           // 브레이크 밟는 상황(속도가 감속)
//     if (car.curSpeed < BRK_STEP){
//         car.curSpeed = 0;
//         return;
//     }
//     car.curSpeed -= BRK_STEP;
// }

// int main(void){
//     // 구조체 변수의 선언 및 초기화 진행
//     Car run99 = {"run99", 100, 0};

//     // 엑셀과 블레이크를 밟은 상황 연출
//     Accel(run99);
//     Accel(run99);
//     ShowCarState(run99);
//     Break(run99);
//     ShowCarState(run99);

//     // 구조체 변수의 선언 및 초기화 진행
//     Car sped77 = {"sped77", 100, 0};
//     Accel(sped77);
//     Break(sped77);
//     ShowCarState(sped77);
//     return 0;    
// }



// // 114p 연습문제 3-1
// #include <iostream>
// using namespace std;

// struct Point{
//     int xpos;
//     int ypos;

//     void MovePos(int x, int y){
//         xpos += x;
//         ypos += y;
//     }
//     void AddPoint(const Point &pos){
//         xpos += pos.xpos;
//         ypos += pos.ypos;
//     }
//     void ShowPosition(){
//         cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
//     }
// };

// int main(void){
//     Point pos1 = {12, 4};
//     Point pos2 = {20, 30};

//     pos1.MovePos(-7, 10);
//     pos1.ShowPosition();        // [5, 14] 출력

//     pos1.AddPoint(pos2);
//     pos1.ShowPosition();        // [25, 44] 출력
//     return 0;
// }



// //123p
// #include <iostream>
// #include <cstring>
// using namespace std;

// namespace CAR_CONST{
//     enum{
//         ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2, ACC_STEP = 10, BRK_STEP = 10
//     };
// }

// class Car
// {
// private:        // 변수와 함수는 private에 해당하는 범위 내에서(클래스 내에서만) 접근 가능
//     char gamerID[CAR_CONST::ID_LEN];   
//     int fuelGauge;          
//     int curSpeed;           
// public:         // 변수와 함수는 public에 해당하는 범위 내에서(어디서든) 접근 가능
//     void InitMemebers(char* ID, int fuel);
//     void ShowCarState();
//     void Accel();
//     void Break();
// };

// // 변수가 private에 선언돼서 main 함수에 접근 불가능
// // 함수는 동일 클래스 내 정의된 함수이므로 접근이 가능함
// // 함수는 public 선언이라서 main 함수에서 호출이 가능함
// // 이 함수 호출을 통해서 클래스 안에 선언된 변수 초기화
// void Car::InitMemebers(char* ID, int fuel){
//     strcpy(gamerID, ID);
//     fuelGauge = fuel;
//     curSpeed = 0;
// }

// void Car::ShowCarState(){
//     cout<<"소유자ID: "<<gamerID<<endl;
//     cout<<"연료량: "<<fuelGauge<<"%"<<endl;
//     cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl;
// }

// void Car::Accel(){
//     if(fuelGauge<=0)   
//         return;
//     else
//         fuelGauge -= CAR_CONST::FUEL_STEP;

//     if (curSpeed+CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD){
//         curSpeed = CAR_CONST::MAX_SPD;
//         return;
//     }
//     curSpeed += CAR_CONST::ACC_STEP;
// }

// void Car::Break(){           // 브레이크 밟는 상황(속도가 감속)
//     if (curSpeed < CAR_CONST::BRK_STEP){
//         curSpeed = 0;
//         return;
//     }
//     curSpeed -= CAR_CONST::BRK_STEP;
// }

// int main(void){
//     Car run99;
//     run99.InitMemebers("run99", 100);       // 초기화 목적으로 InitMembers 함수 호출
//     run99.Accel();
//     run99.Accel();
//     run99.Accel();
//     run99.ShowCarState();
//     run99.Break();
//     run99.ShowCarState();
//     return 0;
// }



// // 142p 사과장수
// #include <iostream>
// using namespace std;

// // 과일 판매자
// class FruitSeller
// {
// private:                // 변수 선언
//     int APPLE_PRICE;    // 과일 한 개의 가격
//     int numOfApples;    // 과일의 총 개수
//     int myMoney;        // 판매자의 총 금액

// public:                 // 메서드 정의
//     // 멤버 변수 초기화시키는 메서드
//     void InitMembers(int price, int num, int money){
//         APPLE_PRICE = price;        // 과일 한 개 가격 price의 값으로 초기화
//         numOfApples = num;          // 과일 총 개수 num의 값으로 초기화
//         myMoney = money;            // 판매자의 총 금액 money의 값으로 초기화
//     }
//     // 사과 판매하고 판매한 과일 개수 반환하는 메서드
//     int SaleApples(int money){       // 과일 구매액이 메서드의 인자로 전달(메서드의 매개변수)
//         int num = money/1000;        // 과일는 개당 1000원이라고 가정
//         numOfApples -= num;          // 과일의 수 줄어들고,
//         myMoney += money;            // 판매 수익 발생
//         return num;                  // 판매한 과일의 수 반환
//     }
//     // 남은 사과 개수와 총 판매 수익을 출력하는 메서드
//     void ShowSalesResult(){
//         cout<<"남은 사과: "<<numOfApples<<endl; // 남은 사과 개수 출력
//         cout<<"판매 수익: "<<myMoney<<endl;     // 판매 수익 출력
//     }
// };

// // 과일 구매자
// class FruitBuyer
// {
// private:                // 상태
//     int myMoney;        // 구매자의 총 금액
//     int numOfApples;    // 구매한 사과 개수

// public:                 // 메서드 정의
//     // 멤버 변수 초기화시키는 메서드
//     void InitMembers(int money){
//         myMoney = money;        // 구매자의 총 금액 money의 값으로 초기화
//         numOfApples = 0;        // 사과 구매 전
//     }
//     // 과일 판매자에게 과일을 구매하는 메서드
//     int BuyApples(FruitSeller &seller, int money){   // 메서드 매개변수로 판매자 클래스의 객체를 참조로 전달 받음
//         numOfApples += seller.SaleApples(money);     // 과일의 구매를 목적으로 SaleApples 메서드 호출
//         myMoney -= money;                            // 구매자의 총 금액에서 구매금액 차감
//     }
//     // 남은 금액과 구매한 사과의 총 개수를 출력하는 메서드    
//     void ShowSalesResult(){
//         cout<<"현재 잔액: "<<myMoney<<endl;     // 남은 금액 출력
//         cout<<"사과 개수: "<<numOfApples<<endl; // 구매한 사과의 총 개수 출력
//     }
// };

// int main(void){
//     // 객체 생성 및 초기화
//     FruitSeller seller;                     // 판매자 객체 seller 생성
//     seller.InitMembers(1000, 20, 0);        // seller 객체 초기화(APPLE_PRICE = 1000, numOfApples = 20, myMoney = 0)
//     FruitBuyer buyer;                       // 구매자 객체 buyer 생성
//     buyer.InitMembers(5000);                // buyer 객체 초기화(myMoney = 5000)

//     // 과일 구매
//     buyer.BuyApples(seller, 2000);          // 과일의 구매 기능을 담당하는 메서드 BuyApples
//                                             // 구매자 객체의 메서드 인자로 판매자 객체 전달
//                                             // FruitBuyer 클래스 안에 존재하지 않지만 필요한 구매대상, 구매금액을 인자로 전달

//     // 현황 출력
//     cout << "과일 판매자의 현황" << endl;
//     seller.ShowSalesResult();
//     cout<<"과일 구매자의 현황" << endl;
//     buyer.ShowSalesResult();
//     return 0;
// }




#include <iostream>
using namespace std;

int main(void){
//     // 경기 기본 정보(경기 일정, 개최지, 중계 등)
//     cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
//     cout<<"│                          AFC 아시안 컵 정보                          │" << endl;
//     cout<<"├──────────┬───────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│  기  간  │   2024년 1월 12일 (금) ~ 2월 10일 (일) (현지기준)         │" << endl;
//     cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│  개최지  │   카타르 도하, 알 와크라, 알 라이얀, 알 코르              │" << endl;
//     cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│  중  계  │   tvN, tvN SPORTS, 쿠팡플레이                             │" << endl;
//     cout<<"└──────────┴───────────────────────────────────────────────────────────┘"<<endl;

//     cout<<endl<<endl;

//     // 참가국 및 조별 정보
//     cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
//     cout<<"│                         AFC 아시안 컵 조편성                         │" << endl;
//     cout<<"├─────────┬────────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    A    │   카타르  중국  타지키스탄  레바논                         │" << endl;
//     cout<<"├─────────┼────────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    B    │   호주  우즈베키스탄  시리아  인도                         │" << endl;
//     cout<<"├─────────┼────────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    C    │   이란  아랍에미리트  홍콩  팔레스타인                     │" << endl;
//     cout<<"├─────────┼────────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    D    │   일본  인도네시아  이라크  베트남                         │" << endl;
//     cout<<"├─────────┼────────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    E    │   대한민국  말레이시아  요르단  바레인                     │" << endl;
//     cout<<"├─────────┼────────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    F    │   사우디아라비아  태국  키르기스스탄  오만                 │" << endl;
//     cout<<"└─────────┴────────────────────────────────────────────────────────────┘"<<endl;

//     // E조 경기 일정
//     cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
//     cout<<"│                      AFC 아시안 컵 E조 경기일정                      │" << endl;
//     cout<<"├────────────────────────────┬─────────────────────────────────────────┤"<<endl;
//     cout<<"│            일시            │              대진 및 결과               │" << endl;
//     cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
//     cout<<"│  2024.1.15.(월) 오후 8:30  │            대한민국 VS 바레인           │" << endl;
//     cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
//     cout<<"│  2024.1.16.(화) 오전 2:30  │          말레이시아 VS 요르단           │" << endl;
//     cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
//     cout<<"│  2024.1.20.(토) 오후 8:30  │           요르단 VS 대한민국            │" << endl;
//     cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
//     cout<<"│  2024.1.20.(토) 오후 11:30 │          바레인 VS 말레이시아           │" << endl;
//     cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
//     cout<<"│  2024.1.25.(목) 오후 8:30  │         대한민국 VS 말레이시아          │" << endl;
//     cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
//     cout<<"│  2024.1.25.(목) 오후 8:30  │            요르단 VS 바레인             │" << endl;
//     cout<<"└────────────────────────────┴─────────────────────────────────────────┘"<<endl;


//     // 한국 선수단 정보
//     // E조 경기 일정
//     cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
//     cout<<"│                  AFC 아시안 컵 대한민국 선수단 정보                  │" << endl;
//     cout<<"├──────────┬───────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    HC    │   위르켄 클린스만                                         │" << endl;
//     cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    CH    │   차두리  파올로  베르너  안드레아스                      │" << endl;
//     cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    FW    │   오현규  정우영  조규성                                  │" << endl;
//     cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    MF    │   문선민  박용우  손흥민  양현준                          │" << endl;
//     cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    DF    │   김민재  김영권  김주성  김지수                          │" << endl;
//     cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│    GK    │   김승규  송범근  조현우                                  │" << endl;
//     cout<<"└──────────┴───────────────────────────────────────────────────────────┘"<<endl;


    // cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
    // cout<<"│                                                                      │"<<endl;
    // cout<<"│                               GOLD                                   │"<<endl;
    // cout<<"│                                                                      │"<<endl;
    // cout<<"├───────────────┬──────────────────────────────────────┬───────────────┤"<<endl;
    // cout<<"│               │                                      │               │"<<endl;
    // cout<<"│               │                                      │               │"<<endl;
    // cout<<"│               │                                      │               │"<<endl;
    // cout<<"│     MVIP      │                                      │      VIP      │"<<endl;
    // cout<<"│               │                                      │               │"<<endl;
    // cout<<"│               │                                      │               │"<<endl;
    // cout<<"│               │                                      │               │"<<endl;
    // cout<<"├───────────────┴──────────────────────────────────────┴───────────────┤"<<endl;
    // cout<<"│                                                                      │"<<endl;
    // cout<<"│                               SILVER                                 │"<<endl;
    // cout<<"│                                                                      │"<<endl;
    // cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl<<endl;
    // cout<<"┌──────────────────────────── 구역 선택 ───────────────────────────────┐"<<endl;
    // cout<<"│                                                                      │"<<endl;
    // cout<<"│             1. MVIP     2. VIP     3. GOLD     4. SILVER             │" << endl;
    // cout<<"│                                                                      │"<<endl;
    // cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl;

    // cout<<"┌──────────────────────────── 구역 선택 ───────────────────────────────┐"<<endl;
    // cout<<"│                                                                      │"<<endl;
    // cout<<"│            1. MVIP(₩150,000)         2. VIP(₩100,000)                │"<<endl;
    // cout<<"│                                                                      │"<<endl;
    // cout<<"│            3. GOLD(₩80,000)          4. SILVER(₩50,000)              │"<<endl;
    // cout<<"│                                                                      │"<<endl;
    // cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl;

//     char arr[25][25] = {
//         {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,'a',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,'b',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,'c',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,'d',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,'e',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5}

//     };

//     for (int i = 0; i < 25; i++){
//         for (int j = 0; j < 25; j++){
//             if (arr[i][j] == 0)
//                 cout<<"  ";
//             if (arr[i][j] == 1)
//                 cout<<"──";
//             if (arr[i][j] == 2)
//                 cout<<" ┌─";
//             if (arr[i][j] == 3)
//                 cout<<"─┐";
//             if (arr[i][j] == 4)
//                 cout<<" └─";
//             if (arr[i][j] == 5)
//                 cout<<"─┘";
//             if (arr[i][j] == 6)
//                 cout<<" │";
//             if (arr[i][j] == 7)
//                 cout<<"  │ ";
//             if (arr[i][j] == 'a')
//                 cout<<"A ";
//             if (arr[i][j] == 'b')
//                 cout<<"B ";
//             if (arr[i][j] == 'c')
//                 cout<<"C ";
//             if (arr[i][j] == 'd')
//                 cout<<"D ";
//             if (arr[i][j] == 'e')
//                 cout<<"E ";
//             if (arr[i][j] == 'f')
//                 cout<<"□ ";
//         }
//         cout<<endl;
//     }
    

//     cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
//     cout<<"│                                                                      │"<<endl;
//     cout<<"├──────────────────────────────────────────────────────────────────────┤"<<endl;
//     cout<<"│                                                                      │"<<endl;
//     cout<<"│     A      □    □    □    □    □     │     □    □    □    □    □     │ "<<endl;
//     cout<<"│     B      □    □    □    □    □     │     □    □    □    □    □     │ "<<endl;
//     cout<<"│     C      □    □    □    □    □     │     □    □    □    □    □     │ "<<endl;
//     cout<<"│     D      □    □    □    □    □     │     □    □    □    □    □     │ "<<endl;
//     cout<<"│     E      □    □    □    □    □     │     □    □    □    □    □     │ "<<endl;
//     cout<<"│                                                                      │"<<endl;
//     cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl;

    // cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
    // cout<<"┌────────────────────────────── 예매내역 ──────────────────────────────┐"<<endl;
    // cout<<" "<<endl;
    // cout<<"                회원님의 예매내역이 존재하지 않습니다.                "<<endl;
    // cout<<" "<<endl;
    // cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl<<endl;                                    


                cout<<"┌───────────────────────────────────────────────────────────────────────┐"<<endl;
                cout<<"│                 엔터 키를 누르면 이전으로 돌아갑니다.                 │" << endl;
                cout<<"└───────────────────────────────────────────────────────────────────────┘"<<endl;                


    return 0;
}


// #include <iostream>
// #include <fstream>      // 파일
// #include <string>       // string
// #include <unistd.h>     // sleep 함수
// #include <sstream>      // stringstream
// #include <vector>       // vector 함수
// using namespace std;


// // 예매 및 결제, 예약 내역 확인
// class BockTicketPayment
// {
//     int userChoice2;            // 사용자 선택
//     int ticketMoney;            // 선택한 구역의 금액
//     int ticketTotal = 0;        // 총 금액
//     vector<char> pickRow;
//     vector<int> pickColumn;
//     string scheduleDay;         // 경기 일시 선택
//     string pickCountry;         // 대진 선택

// public:
//     char arr[16][25] = {
//         {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,0,0,0,'i',0,0,'j',0,0,'k',0,0,'l',0,0,'m',0,0,'n',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,'a',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,'b',0,0,'g',0,0,'g',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,'c',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,'d',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,'e',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'g',0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//         {4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5}
//     };
//     const string day[6] ={"2024.1.15.(월) 오후 8:30",
//                           "2024.1.16.(화) 오전 2:30",
//                           "2024.1.20.(토) 오후 8:30",
//                           "2024.1.20.(토) 오후 11:30",
//                           "2024.1.25.(목) 오후 8:30",
//                           "2024.1.25.(목) 오후 8:30"}; 
//     const string country[6]={"대한민국 VS 바레인",
//                              "말레이시아 VS 요르단",
//                              "요르단 VS 대한민국",
//                              "바레인 VS 말레이시아",
//                              "대한민국 VS 말레이시아",
//                              "요르단 VS 바레인"};
//     const char rowSeat[5] = {'A', 'B', 'C', 'D', 'E'};
//     const int columnSeat[6] = {1,2,3,4,5,6};
//     const int money[4] = {150000,100000,80000,50000};

//     char row;                   // 행
//     int column;                 // 열

//     void ChoiceSchedule();
//     void ChoiceArea();
//     void ChoiceSeat();
//     void ChoiceRow(int* xpos);
//     void ChoiceColumn(int* xpos);
//     void SeatMap(char (*arr)[25]);
//     void SaleTicket();
// };

// void BockTicketPayment::SeatMap(char (*arr)[25]){
//     for (int i = 0; i < 16; i++)
//     {
//         for (int j = 0; j < 25; j++)
//         {
//             if (arr[i][j] == 0) cout<<"  ";
//             if (arr[i][j] == 1) cout<<"──";
//             if (arr[i][j] == 2) cout<<" ┌─";
//             if (arr[i][j] == 3) cout<<"─┐";
//             if (arr[i][j] == 4) cout<<" └─";
//             if (arr[i][j] == 5) cout<<"─┘";
//             if (arr[i][j] == 6) cout<<" │";
//             if (arr[i][j] == 7) cout<<"  │ ";
//             if (arr[i][j] == 'a') cout<<"A ";
//             if (arr[i][j] == 'b') cout<<"B ";
//             if (arr[i][j] == 'c') cout<<"C ";
//             if (arr[i][j] == 'd') cout<<"D ";
//             if (arr[i][j] == 'e') cout<<"E ";
//             if (arr[i][j] == 'f') cout<<"□ ";
//             if (arr[i][j] == 'g') cout<<"■ ";
//             if (arr[i][j] == 'h') cout<<"▣ ";
//             if (arr[i][j] == 'i') cout<<"1 ";
//             if (arr[i][j] == 'j') cout<<"2 ";
//             if (arr[i][j] == 'k') cout<<"3 ";
//             if (arr[i][j] == 'l') cout<<"4 ";
//             if (arr[i][j] == 'm') cout<<"5 ";
//             if (arr[i][j] == 'n') cout<<"6 ";
//         }
//         cout<<endl;
//     }
//     if(!pickColumn.empty()){
//         cout<<"┌──────────────────────────────────────────────────┐"<<endl<<endl;
//         for (int i = 0; i < pickRow.size(); i++)
//         {
//             cout<<"           선택하신 좌석은 "<<pickRow[i]<<"-"<<pickColumn[i]<<"입니다."<<endl;
//         }
//         cout<<endl<<"└──────────────────────────────────────────────────┘"<<endl;
//     }
// }

// void BockTicketPayment::ChoiceSeat(){
//     system("clear");
//     int xpos = 0, ypos = 0;
//     bool choice = true;
//     int seatCount = 0;
//     SeatMap(arr);

//     while(choice)
//     {
//         ChoiceRow(&xpos);
//         ChoiceColumn(&ypos);

//         if (arr[xpos][ypos] == 'g' || arr[xpos][ypos] == 'h')
//         {
//             cout<<"이미 선택된 좌석입니다."<<endl<<"다시 선택해주십시오."<<endl;
//             sleep(2);
//         }
//         else
//         {
//             pickRow.push_back(row);
//             pickColumn.push_back(column);
//             arr[xpos][ypos] = 'h';
//             system("clear");
//             SeatMap(arr);
//         }
//     }
// }

// // 행 선택
// void BockTicketPayment::ChoiceRow(int* xpos)
// {
//     system("clear");
//     SeatMap(arr);
//     cout<<"┌──────────────────────────────────────────────────┐"<<endl;
//     cout<<"│                 행을 선택하시오                  │"<<endl;
//     cout<<"│                 (A, B, C, D, E)                  │"<<endl;
//     cout<<"└──────────────────────────────────────────────────┘"<<endl;
//     cin>>row;

//     while(row != 'A' && row != 'a' && row != 'B' && row != 'b' && row != 'C' && row != 'c'
//         && row != 'D' && row != 'd' && row != 'E' && row != 'e')
//     {
//         cout<<"잘못 입력하셨습니다."<<endl;
//         cin.clear();
//         cin.ignore(100, '\n');
//         sleep(1);
//         system("clear");
//         SeatMap(arr);        
//         cout<<"┌──────────────────────────────────────────────────┐"<<endl;
//         cout<<"│                 행을 선택하시오                  │"<<endl;
//         cout<<"│                 (A, B, C, D, E)                  │"<<endl;
//         cout<<"└──────────────────────────────────────────────────┘"<<endl;
//         cin>>row;
//     }
//     if(row == 'a') row = 'A';
//     else if(row == 'b') row = 'B';
//     else if(row == 'c') row = 'C';
//     else if(row == 'd') row = 'D';
//     else if(row == 'e') row = 'E';    
//     cout<<row<<"행을 선택하셨습니다."<<endl<<endl;
//     sleep(1);

//     if(row == 'A') *xpos = 4;
//     else if(row == 'B') *xpos = 6;        
//     else if(row == 'C') *xpos = 8;
//     else if(row == 'D') *xpos = 10;
//     else if(row == 'E') *xpos = 12;
// }

// void BockTicketPayment::ChoiceColumn(int* ypos){
//     system("clear");
//     SeatMap(arr);
//     cout<<"┌──────────────────────────────────────────────────┐"<<endl;
//     cout<<"│                 열을 선택하시오                  │"<<endl;
//     cout<<"│                (1, 2, 3, 4, 5, 6)                │"<<endl;
//     cout<<"└──────────────────────────────────────────────────┘"<<endl;
//     while (!(cin>>column) || column > 6 || column < 1)
//     {
//         cout<<"잘못 입력하셨습니다."<<endl;
//         cin.clear();
//         cin.ignore(100, '\n');
//         sleep(1);
//         cout<<"┌──────────────────────────────────────────────────┐"<<endl;
//         cout<<"│                 열을 선택하시오                  │"<<endl;
//         cout<<"└──────────────────────────────────────────────────┘"<<endl;
//     }
//     if(column == 1) *ypos = 6;
//     else if(column == 2) *ypos = 9;
//     else if(column == 3) *ypos = 12;
//     else if(column == 4) *ypos = 15;
//     else if(column == 5) *ypos = 18;
//     else if(column == 6) *ypos = 21;
// }




// int main(void)
// {
//     BockTicketPayment ticket;
//     ticket.ChoiceSeat();
// }
