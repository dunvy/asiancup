#ifndef AsianUser_h
#define AsianUser_h
#include <iostream>
#include <vector>

class BockTicketUser
{
    // 변수 선언
    int userChoice;
public:
    std::string userID;                  // 현재 접속한 유저 ID
    std::string userPW;                  // 현재 접속한 유저 PW
    std::string userNum;                 // 현재 접속한 유저 고유번호
    
    void StartLogoFile();           // 로고 아스키코드(시작페이지)
    void MainLogoFile();            // 로고 아스키코드(메인페이지)
    void Start();                   // 시작화면 (로고 출력)
    void PrintStart();               // 시작 화면 초기화
    void LoginChoice();             // 로그인 및 ID/PW 찾기 선택
    void Login();                   // 로그인
    void Join();                    // 회원가입
    void FindId();                  // 아이디 찾기
    void FindPw();                  // 비번 찾기

    int PrintMain();                // 메인 페이지
    void ChoiceInformation();        // 경기 정보 선택
    void PrintInformation(int n);         // 선택한 경기 정보 출력
    void InvalidInput();            // 잘못된 입력
};


// 예매 및 결제
class BockTicketPayment
{
    int userChoice2;            // 사용자 선택
    int ticketMoney;            // 선택한 구역의 금액
    std::string scheduleDay;         // 경기 일시 선택
    std::string choiceCountry;       // 대진 선택
    std::string choiceArea;          // 구역 선택
    char row;                   // 행 선택
    int column;                 // 열 선택

    char arr[16][25] = {
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3},
        {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
        {6,0,0,0,0,0,'i',0,0,'j',0,0,'k',0,0,'l',0,0,'m',0,0,'n',0,0,7},
        {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
        {6,0,0,'a',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
        {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
        {6,0,0,'b',0,0,'g',0,0,'g',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
        {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
        {6,0,0,'c',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
        {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
        {6,0,0,'d',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,7},
        {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
        {6,0,0,'e',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'f',0,0,'g',0,0,7},
        {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
        {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
        {4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5}
    };
    const std::string day[6] ={"2024.1.15.(월) 오후 8:30",
                          "2024.1.16.(화) 오전 2:30",
                          "2024.1.20.(토) 오후 8:30",
                          "2024.1.20.(토) 오후 1:30",
                          "2024.1.25.(목) 오후 8:30",
                          "2024.1.25.(목) 오후 8:30"}; 
    const std::string country[6]={"대한민국 VS 바레인",
                             "말레이시아 VS 요르단",
                             "요르단 VS 대한민국",
                             "바레인 VS 말레이시아",
                             "대한민국 VS 말레이시아",
                             "요르단 VS 바레인"};
    const std::string area[5] = {"MVIP", "VIP", "GOLD", "SILVER"};
    const char rowSeat[5] = {'A', 'B', 'C', 'D', 'E'};
    const int columnSeat[6] = {1,2,3,4,5,6};
    const int money[4] = {150000,100000,80000,50000};
    int ticketTotal = 0;        // 총 금액
    
public:
    // 예매내역
    std::vector<std::string> pickscheduleDay;     // 일정 선택
    std::vector<std::string> pickCountry;         // 대진 선택
    std::vector<std::string> pickArea;            // 자리 선택(구역)
    std::vector<char> pickRow;               // 자리 선택(행)
    std::vector<int> pickColumn;             // 자리 선택(열)
    int memCount = 1;           // 추가 예매

    void InvalidInput2();            
    void ChoiceSchedule();
    void ChoiceArea();
    void ChoiceSeat(int area);
    void ChoiceRow(int* xpos);
    void ChoiceColumn(int* xpos);
    void SeatMap(char (*arr)[25]);
    void SaleTicket(const BockTicketUser & user);
};

#endif