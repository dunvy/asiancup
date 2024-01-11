#include <iostream>
#include <fstream>      // 파일
#include <string>       // string
#include <unistd.h>     // sleep 함수
#include <sstream>      // stringstream
#include <vector>       // vector 함수
using namespace std;

// // 상하좌우 상수값 설정
// namespace KEY_CONST{
//     enum{
//         LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80
//     };
// }

// 로그인 및 회원가입
class BockTicketUser
{
    // 변수 선언
    int userChoice;
public:
    string userID;                  // 현재 접속한 유저 ID
    string userPW;                  // 현재 접속한 유저 PW
    string userNum;                 // 현재 접속한 유저 고유번호
    
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
};

// 예매 및 결제
class BockTicketPayment
{
    int userChoice2;            // 사용자 선택
    int ticketMoney;            // 선택한 구역의 금액
    string scheduleDay;         // 경기 일시 선택
    string choiceCountry;       // 대진 선택
    string choiceArea;          // 구역 선택
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

    const string day[6] ={"2024.1.15.(월) 오후 8:30",
                          "2024.1.16.(화) 오전 2:30",
                          "2024.1.20.(토) 오후 8:30",
                          "2024.1.20.(토) 오후 1:30",
                          "2024.1.25.(목) 오후 8:30",
                          "2024.1.25.(목) 오후 8:30"}; 
    const string country[6]={"대한민국 VS 바레인",
                             "말레이시아 VS 요르단",
                             "요르단 VS 대한민국",
                             "바레인 VS 말레이시아",
                             "대한민국 VS 말레이시아",
                             "요르단 VS 바레인"};
    const string area[5] = {"MVIP", "VIP", "GOLD", "SILVER"};
    const char rowSeat[5] = {'A', 'B', 'C', 'D', 'E'};
    const int columnSeat[6] = {1,2,3,4,5,6};
    const int money[4] = {150000,100000,80000,50000};
    int ticketTotal = 0;        // 총 금액
public:
    // 예매내역
    vector<string> pickscheduleDay;     // 일정 선택
    vector<string> pickCountry;         // 대진 선택
    vector<string> pickArea;            // 자리 선택(구역)
    vector<char> pickRow;               // 자리 선택(행)
    vector<int> pickColumn;             // 자리 선택(열)
    int memCount = 1;           // 추가 예매

    void ChoiceSchedule();
    void ChoiceArea();
    void ChoiceSeat(int area);
    void ChoiceRow(int* xpos);
    void ChoiceColumn(int* xpos);
    void SeatMap(char (*arr)[25]);
    void SaleTicket(const BockTicketUser & user);
};

// 시작 페이지 아스키 아트
void BockTicketUser::StartLogoFile(){
    system("clear");
    string line;
    ifstream mainLogo("logo2.txt");
    if (mainLogo.is_open()){            // 파일 열렸는지 확인
        while (!mainLogo.eof()){        // 파일 끝까지 읽었는지 확인
            getline(mainLogo, line);    // 한 줄씩 읽기
            cout << line << endl;   // 읽은 문자열 바로 출력
        }
    }
    mainLogo.close();
}

// 메인 페이지 아스키 아트
void BockTicketUser::MainLogoFile(){
    system("clear");
    string line;
    ifstream mainLogo("logo3.txt");
    if (mainLogo.is_open()){        
        while (!mainLogo.eof()){    
            getline(mainLogo, line);
            cout << line << endl;   
        }
    }
    mainLogo.close();
}

// 스플래시
void BockTicketUser::Start(){
    string line;
    ifstream startLogo("logo.txt");
    if (startLogo.is_open()){               // 파일 열렸는지 확인
        while (!startLogo.eof()){           // 파일 끝까지 읽었는지 확인
            getline(startLogo, line);       // 한 줄씩 읽기
            cout << line << endl;       // 읽은 문자열 바로 출력
        }
    }
    startLogo.close();
    // sleep(2);

    // 로그인 및 회원가입 고르는 페이지로 넘어감
    PrintStart();
}

// 시작 페이지
void BockTicketUser::PrintStart(){
    StartLogoFile();
    cout<<" 【 원하는 기능을 선택해주세요! 】"<<endl;
    cout<<"┌─────────────────────────────────┐"<<endl;
    cout<<"│          1. 로그인              │" << endl;
    cout<<"│          2. 회원가입            │" << endl;
    cout<<"└─────────────────────────────────┘"<<endl;

    cin >> userChoice;

    // 로그인
    if (userChoice == 1){
        LoginChoice();
    }
    // 회원가입
    if (userChoice == 2){
        Join();
    }
}

// 로그인 및 ID/PW 선택
void BockTicketUser::LoginChoice(){
    StartLogoFile();
    cout<<" 【 원하는 기능을 선택해주세요! 】"<<endl;
    cout<<"┌─────────────────────────────────┐"<<endl;
    cout<<"│          1. 로그인              │" << endl;
    cout<<"│          2. ID찾기              │" <<endl;
    cout<<"│          3. PW찾기              │" <<endl;
    cout<<"└─────────────────────────────────┘"<<endl;    
    cin >> userChoice;

    if (userChoice == 1){
        Login();
    }
    else if (userChoice == 2){
        FindId();
    }
    else if (userChoice == 3){
        FindPw();
    }
    
}

// 로그인
void BockTicketUser::Login(){
    system("clear");
    cout<<"┌─────────────────────────────────┐"<<endl;
    cout<<"│          로그인 진행중…         │" << endl;
    cout<<"└─────────────────────────────────┘"<<endl;
    string line;
    
    while(1){
        int a = 0;
        cout<<"ID를 입력해주세요: ";
        cin >> userID;
        cout<<"PW를 입력해주세요: ";
        cin >> userPW;

        ifstream inMember("member.csv");

        while (getline(inMember, line)){
            stringstream sline(line);
            string smemberNum, spw, sid, sphoneNum, semail;
            getline(sline, smemberNum, ',');        
            getline(sline, sid, ',');
            getline(sline, spw, ',');

            if (userID == sid && userPW == spw){
                cout<<"로그인 성공!"<<endl;
                a = 1;
                userNum = smemberNum;
                inMember.close();
                break;
            }
        }
        if (a == 1)
            break;
        cout<<"로그인 실패하셨습니다. ID와 PW를 다시 한번 확인해주세요."<<endl<<endl;
    }
}

// 회원가입
void BockTicketUser::Join(){
    system("clear");
    cout<<"┌─────────────────────────────────┐"<<endl;
    cout<<"│        회원가입 진행중…         │" << endl;
    cout<<"└─────────────────────────────────┘"<<endl;

    string id, pw, phoneNum, email, line;   // 회원id, 회원pw, 회원핸드폰번호, 회원email, 비교할 문자열
    int count = 1;                          // 회원번호

    // 아이디 입력 및 중복 검사
    while(1){
        int a = 0;

        ifstream inMember("member.csv");
        cout<< "사용할 ID를 입력해주세요: ";
        cin>>id;

        while (getline(inMember, line)){
            stringstream sline(line);                  // 한줄 읽어서 sline에 저장
            string smemberNum, sid;

            getline(sline, smemberNum, ',');           // ,를 기준으로 잘라서 smemberNum에 저장
            getline(sline, sid, ',');

            if (id == sid){
                cout<<"중복된 아이디입니다."<<endl;
                a = 1;
                inMember.close();
                break;
            }
        }
        if (a == 0){
            inMember.close();
            break;
        }
    }

    // 비밀번호
    while (1)
    {
        cout<< "사용할 PW를 입력해주세요(6자): ______\b\b\b\b\b\b";
        cin>>pw;
        if (pw.length() != 6){
            cout<<"다시 입력해주세요!\n";
            continue;
        }
        break;
    }

    // 핸드폰 번호 입력 및 중복 검사
    while(1){
        int a = 0;

        ifstream inMember("member.csv");
        cout<< "사용할 핸드폰 번호를 입력해주세요: ___________\b\b\b\b\b\b\b\b\b\b\b";
        cin>>phoneNum;

        if (phoneNum.length() != 11){
            cout<<"다시 입력해주세요!\n";
            continue;
        }

        while (getline(inMember, line)){
            stringstream sline(line); 
            string smemberNum, spw, sid, sphoneNum;
            getline(sline, smemberNum, ',');        
            getline(sline, sid, ',');
            getline(sline, spw, ',');
            getline(sline, sphoneNum, ',');

            if (phoneNum == sphoneNum){
                cout<<"중복된 핸드폰 번호입니다."<<endl;
                a = 1;
                inMember.close();
                break;
            }
        }
        if (a == 0){
            inMember.close();
            break;
        }
    }

    // 이메일 입력 및 중복 검사
    while(1){
        int a = 0;

        ifstream inMember("member.csv");        
        cout<< "사용할 e-mail을 입력해주세요: ";
        cin>>email;
        
        while (getline(inMember, line)){
            stringstream sline(line);   
            string smemberNum, spw, sid, sphoneNum, semail;

            getline(sline, smemberNum, ',');  
            getline(sline, sid, ',');
            getline(sline, spw, ',');
            getline(sline, sphoneNum, ',');
            getline(sline, semail, ',');

            if (email == semail){
                cout<<"중복된 e-mail입니다."<<endl;
                a = 1;
                inMember.close();
                break;
            }
        }
        if (a == 0){
            inMember.close();
            break;
        }
    }

    // 회원번호 부여
    ifstream inMember("member.csv");
    while (getline(inMember, line)){
        count++;
    }
    inMember.close();
    
    // 중복검사 끝나고 파일에 넣기
    ofstream outMember("member.csv", ios::app);
    outMember << count << "," << id << "," << pw << "," << phoneNum << "," << email << "," << "\n";
    outMember.close();

    cout<<"회원 가입 완료!" << endl;
    sleep(1);
    cout<<endl<<"반갑습니다 " << id<<"님! (3초 후 시작 화면으로 돌아갑니다.)\n";
    sleep(1);
    cout<<endl;
    for (int i = 3; i > 0; i--)
    {
        cout<<i<<"..."<<endl;
        sleep(1);
    }   
    PrintStart();
}

// 아이디 찾기
void BockTicketUser::FindId(){
    system("clear");
    cout<<"┌─────────────────────────────────┐"<<endl;
    cout<<"│         ID찾기 진행중…          │" << endl;
    cout<<"└─────────────────────────────────┘"<<endl;
    string emailFind, line;

    int a = 0;              // 판별
    
    ifstream inMember("member.csv");
    cout<<"e-mail을 입력해주세요: ";
    cin>>emailFind;

    while (getline(inMember, line)){
        stringstream sline(line);
        string smemberNum, spw, sid, sphoneNum, semail;

        getline(sline, smemberNum, ',');
        getline(sline, sid, ',');
        getline(sline, spw, ',');
        getline(sline, sphoneNum, ',');
        getline(sline, semail, ',');

        if (emailFind == semail){
            cout<<"회원님의 아이디는 "<<sid<<" 입니다."<<endl;
            a = 1;
            inMember.close();
            break;
        }
    }

    if (a == 0){
        cout<<"일치하는 e-mail 정보가 없습니다."<<endl;
        cout<<"┌─────────────────────────────────┐"<<endl;
        cout<<"│          1. 돌아가기            │" << endl;
        cout<<"│          2. 재입력              │" <<endl;
        cout<<"└─────────────────────────────────┘"<<endl;
        cin>>userChoice;
        if (userChoice == 1)
            LoginChoice();
        else if (userChoice == 2)
            FindId();        
    }

    else if(a == 1){
        cout<<"┌─────────────────────────────────┐"<<endl;
        cout<<"│          1. 로그인              │" << endl;
        cout<<"│          2. PW 찾기             │" <<endl;
        cout<<"└─────────────────────────────────┘"<<endl;
        cin>>userChoice;

        if (userChoice == 1)
            Login();
        else if (userChoice == 2)
            FindPw();
    }
}

// 비밀번호 찾기
void BockTicketUser::FindPw(){
    StartLogoFile();
    string idFind, emailFind, line;

    int a = 0;              // 판별
    
    ifstream inMember("member.csv");
    cout<<"ID를 입력해주세요: ";
    cin>>idFind;
    cout<<"e-mail을 입력해주세요: ";
    cin>>emailFind;

    while (getline(inMember, line)){
        stringstream sline(line);
        string smemberNum, spw, sid, sphoneNum, semail;

        getline(sline, smemberNum, ',');
        getline(sline, sid, ',');
        getline(sline, spw, ',');
        getline(sline, sphoneNum, ',');
        getline(sline, semail, ',');

        if (idFind == sid && emailFind == semail){
            cout<<"회원님의 비밀번호는 "<<spw<<" 입니다."<<endl;
            a = 1;
            inMember.close();
            break;
        }
    }

    if (a == 0){
        cout<<"일치하는 회원 정보가 없습니다."<<endl;
        cout<<"┌─────────────────────────────────┐"<<endl;
        cout<<"│          1. 로그인              │" << endl;
        cout<<"│          2. 재입력              │" <<endl;
        cout<<"└─────────────────────────────────┘"<<endl;
        cin>>userChoice;
        if (userChoice == 1)
            Login();
        else if (userChoice == 2)
            FindPw();        
    }

    else if(a == 1){
        cout<<"┌─────────────────────────────────┐"<<endl;
        cout<<"│          1. 로그인              │" << endl;
        cout<<"└─────────────────────────────────┘"<<endl;
        cin>>userChoice;

        if (userChoice == 1)
            Login();
    }

}

// 메인화면
int BockTicketUser::PrintMain(){
    MainLogoFile();
    cout<<"┌── 원하는 기능을 선택해주세요! ────────────────────────────────────────┐"<<endl;    
    cout<<"│                                                                       │" << endl;
    cout<<"│       1. 경기 정보                                                    │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       2. 예매하기                                                     │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       3. 예매 내역                                                    │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       4. 종료                                                         │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"└───────────────────────────────────────────────────────────────────────┘"<<endl;

    cin >> userChoice;

    return userChoice;
}

// 경기 정보 선택
void BockTicketUser::ChoiceInformation()
{
    system("clear");
    int userChoice;
    cout<<"┌── 원하는 정보를 선택해주세요! ────────────────────────────────────────┐"<<endl;    
    cout<<"│                                                                       │" << endl;
    cout<<"│       1. 2023 AFC 카타르 아시안컵 기본 정보                           │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       2. 2023 AFC 카타르 아시안컵 조편성                              │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       3. 2023 AFC 카타르 아시안컵 E조 경기일정                        │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       4. 2023 AFC 카타르 아시안컵 대한민국 감독/선수단                │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       5. 돌아가기                                                     │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"└───────────────────────────────────────────────────────────────────────┘"<<endl;
    cin >> userChoice;
    if (userChoice == 5)
        PrintMain();
    else
        PrintInformation(userChoice);
}

// 경기 정보 출력
void BockTicketUser::PrintInformation(int n)
{
    system("clear");
    int userChoice;
    switch (n)
    {
    case 1:
        cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
        cout<<"│                          AFC 아시안 컵 정보                          │" << endl;
        cout<<"├──────────┬───────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│  기  간  │   2024년 1월 12일 (금) ~ 2월 10일 (일) (현지기준)         │" << endl;
        cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│  개최지  │   카타르 도하, 알 와크라, 알 라이얀, 알 코르              │" << endl;
        cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│  중  계  │   tvN, tvN SPORTS, 쿠팡플레이                             │" << endl;
        cout<<"└──────────┴───────────────────────────────────────────────────────────┘"<<endl<<endl;
        break;
    case 2:
        cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
        cout<<"│                         AFC 아시안 컵 조편성                         │" << endl;
        cout<<"├─────────┬────────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    A    │   카타르  중국  타지키스탄  레바논                         │" << endl;
        cout<<"├─────────┼────────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    B    │   호주  우즈베키스탄  시리아  인도                         │" << endl;
        cout<<"├─────────┼────────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    C    │   이란  아랍에미리트  홍콩  팔레스타인                     │" << endl;
        cout<<"├─────────┼────────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    D    │   일본  인도네시아  이라크  베트남                         │" << endl;
        cout<<"├─────────┼────────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    E    │   대한민국  말레이시아  요르단  바레인                     │" << endl;
        cout<<"├─────────┼────────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    F    │   사우디아라비아  태국  키르기스스탄  오만                 │" << endl;
        cout<<"└─────────┴────────────────────────────────────────────────────────────┘"<<endl<<endl;        
        break;
    case 3:
        cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
        cout<<"│                      AFC 아시안 컵 E조 경기일정                      │" << endl;
        cout<<"├────────────────────────────┬─────────────────────────────────────────┤"<<endl;
        cout<<"│            일시            │              대진 및 결과               │" << endl;
        cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
        cout<<"│  2024.1.15.(월) 오후 8:30  │            대한민국 VS 바레인           │" << endl;
        cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
        cout<<"│  2024.1.16.(화) 오전 2:30  │          말레이시아 VS 요르단           │" << endl;
        cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
        cout<<"│  2024.1.20.(토) 오후 8:30  │           요르단 VS 대한민국            │" << endl;
        cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
        cout<<"│  2024.1.20.(토) 오후 11:30 │          바레인 VS 말레이시아           │" << endl;
        cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
        cout<<"│  2024.1.25.(목) 오후 8:30  │         대한민국 VS 말레이시아          │" << endl;
        cout<<"├────────────────────────────┼─────────────────────────────────────────┤"<<endl;
        cout<<"│  2024.1.25.(목) 오후 8:30  │            요르단 VS 바레인             │" << endl;
        cout<<"└────────────────────────────┴─────────────────────────────────────────┘"<<endl<<endl;   
        break; 
    case 4:
        cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
        cout<<"│                  AFC 아시안 컵 대한민국 선수단 정보                  │" << endl;
        cout<<"├──────────┬───────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    HC    │   위르켄 클린스만                                         │" << endl;
        cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    CH    │   차두리  파올로  베르너  안드레아스                      │" << endl;
        cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    FW    │   오현규  정우영  조규성                                  │" << endl;
        cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    MF    │   문선민  박용우  손흥민  양현준                          │" << endl;
        cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    DF    │   김민재  김영권  김주성  김지수                          │" << endl;
        cout<<"├──────────┼───────────────────────────────────────────────────────────┤"<<endl;
        cout<<"│    GK    │   김승규  송범근  조현우                                  │" << endl;
        cout<<"└──────────┴───────────────────────────────────────────────────────────┘"<<endl<<endl;    
        break;
    }
    cout<<"┌── 원하는 정보를 선택해주세요! ────────────────────────────────────────┐"<<endl;    
    cout<<"│                                                                       │" << endl;
    cout<<"│       1. 2023 AFC 카타르 아시안컵 기본 정보                           │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       2. 2023 AFC 카타르 아시안컵 조편성                              │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       3. 2023 AFC 카타르 아시안컵 E조 경기일정                        │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       4. 2023 AFC 카타르 아시안컵 대한민국 감독/선수단                │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"│       5. 돌아가기                                                     │" << endl;
    cout<<"│                                                                       │" << endl;
    cout<<"└───────────────────────────────────────────────────────────────────────┘"<<endl;
    cin >> userChoice;
    if(userChoice == 5)
        PrintMain();
    else
        PrintInformation(userChoice);
}

// 경기 일정 선택
void BockTicketPayment::ChoiceSchedule(){
    system("clear");
    cout<<"┌──────────────────────────── 일자 선택 ───────────────────────────────┐"<<endl<<endl;
    for (int i = 0; i < 6; i++){
        cout<<"      "<<i+1<< ". " << day[i]<<"       "<<country[i]<<endl;
    }
    cout<<endl<<"└──────────────────────────────────────────────────────────────────────┘"<<endl;
    cin>>userChoice2;

    scheduleDay = day[userChoice2-1];
    choiceCountry = country[userChoice2-1];

    ChoiceArea();
}

// 경기 구역 선택
void BockTicketPayment::ChoiceArea(){
    system("clear");
    cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
    cout<<"│                                                                      │"<<endl;
    cout<<"│                               GOLD                                   │"<<endl;
    cout<<"│                                                                      │"<<endl;
    cout<<"├───────────────┬──────────────────────────────────────┬───────────────┤"<<endl;
    cout<<"│               │                                      │               │"<<endl;
    cout<<"│               │                                      │               │"<<endl;
    cout<<"│               │                                      │               │"<<endl;
    cout<<"│     MVIP      │                                      │      VIP      │"<<endl;
    cout<<"│               │                                      │               │"<<endl;
    cout<<"│               │                                      │               │"<<endl;
    cout<<"│               │                                      │               │"<<endl;
    cout<<"├───────────────┴──────────────────────────────────────┴───────────────┤"<<endl;
    cout<<"│                                                                      │"<<endl;
    cout<<"│                               SILVER                                 │"<<endl;
    cout<<"│                                                                      │"<<endl;
    cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl<<endl;
    cout<<"┌──────────────────────────── 구역 선택 ───────────────────────────────┐"<<endl;
    cout<<"│                                                                      │"<<endl;
    cout<<"│            1. MVIP(₩150,000)         2. VIP(₩100,000)                │"<<endl;
    cout<<"│                                                                      │"<<endl;
    cout<<"│            3. GOLD(₩80,000)          4. SILVER(₩50,000)              │"<<endl;
    cout<<"│                                                                      │"<<endl;
    cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl;
    cin>>userChoice2;

    ticketMoney = money[userChoice2-1]; 
    choiceArea = area[userChoice2-1];

    ChoiceSeat(ticketMoney);
}

// 경기 좌석 맵 출력
void BockTicketPayment::SeatMap(char (*arr)[25]){
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            if (arr[i][j] == 0) cout<<"  ";
            if (arr[i][j] == 1) cout<<"──";
            if (arr[i][j] == 2) cout<<" ┌─";
            if (arr[i][j] == 3) cout<<"─┐";
            if (arr[i][j] == 4) cout<<" └─";
            if (arr[i][j] == 5) cout<<"─┘";
            if (arr[i][j] == 6) cout<<" │";
            if (arr[i][j] == 7) cout<<"  │ ";
            if (arr[i][j] == 'a') cout<<"A ";
            if (arr[i][j] == 'b') cout<<"B ";
            if (arr[i][j] == 'c') cout<<"C ";
            if (arr[i][j] == 'd') cout<<"D ";
            if (arr[i][j] == 'e') cout<<"E ";
            if (arr[i][j] == 'f') cout<<"□ ";
            if (arr[i][j] == 'g') cout<<"■ ";
            if (arr[i][j] == 'h') cout<<"▣ ";
            if (arr[i][j] == 'i') cout<<"1 ";
            if (arr[i][j] == 'j') cout<<"2 ";
            if (arr[i][j] == 'k') cout<<"3 ";
            if (arr[i][j] == 'l') cout<<"4 ";
            if (arr[i][j] == 'm') cout<<"5 ";
            if (arr[i][j] == 'n') cout<<"6 ";
        }
        cout<<endl;
    }
    // if(!pickColumn.empty()){
    //     cout<<"┌──────────────────────────────────────────────────┐"<<endl;
    //     cout<<"                총 결제 금액 ₩"<<ticketTotal<<"               "<<endl;
    //     cout<<"└──────────────────────────────────────────────────┘"<<endl;
    //     cout<<"┌──────────────────────────────────────────────────┐"<<endl<<endl;
    //     for (int i = 0; i < pickRow.size(); i++)
    //     {
    //         cout<<"               선택하신 좌석은 "<<pickRow[i]<<"-"<<pickColumn[i]<<"입니다."<<endl;
    //     }
    //     cout<<endl<<"└──────────────────────────────────────────────────┘"<<endl;
    // }
}

// 경기 좌석 선택
void BockTicketPayment::ChoiceSeat(int area){
    system("clear");
    int xpos = 0, ypos = 0;
    int seatCount = 0;
    SeatMap(arr);

    while(1)
    {
        ChoiceRow(&xpos);
        ChoiceColumn(&ypos);

        if (arr[xpos][ypos] == 'g' || arr[xpos][ypos] == 'h')
        {
            cout<<"이미 선택된 좌석입니다."<<endl<<"다시 선택해주십시오."<<endl;
            sleep(2);
        }
        else
        {
            pickscheduleDay.push_back(scheduleDay);
            pickCountry.push_back(choiceCountry);
            pickArea.push_back(choiceArea);
            pickRow.push_back(row);
            pickColumn.push_back(column);

            arr[xpos][ypos] = 'h';
            ticketTotal += area;        // 티켓 총 금액에 구역 금액 더하기
            system("clear");
            SeatMap(arr);
            cout<<"┌──────────────────────────────────────────────────┐"<<endl;
            cout<<"│                   1. 결제하기                    │"<<endl;
            cout<<"│                   2. 추가예매                    │"<<endl;
            cout<<"└──────────────────────────────────────────────────┘"<<endl; 
            cin>>userChoice2;

            // while (!(cin>>userChoice2) || userChoice2 != 1 || userChoice2 != 2)
            // {
            //     cout<<"잘못 입력하셨습니다."<<endl;
            //     cin.clear();
            //     cin.ignore(100, '\n');
            //     sleep(1);
            //     cout<<"┌──────────────────────────────────────────────────┐"<<endl;
            //     cout<<"│                   1. 결제하기                    │"<<endl;
            //     cout<<"│                   2. 추가예매                    │"<<endl;
            //     cout<<"└──────────────────────────────────────────────────┘"<<endl; 
            //     cin>>userChoice2;
            // }
            if (userChoice2 == 1)
                break;
            else if(userChoice2 == 2)
                continue;            
        }
    }
}

// 행 선택
void BockTicketPayment::ChoiceRow(int* xpos)
{
    system("clear");
    SeatMap(arr);
    cout<<"┌──────────────────────────────────────────────────┐"<<endl;
    cout<<"│                 행을 선택하시오                  │"<<endl;
    cout<<"│                 (A, B, C, D, E)                  │"<<endl;
    cout<<"└──────────────────────────────────────────────────┘"<<endl;
    cin>>row;

    while(row != 'A' && row != 'a' && row != 'B' && row != 'b' && row != 'C' && row != 'c'
        && row != 'D' && row != 'd' && row != 'E' && row != 'e')
    {
        cout<<"잘못 입력하셨습니다."<<endl;
        cin.clear();
        cin.ignore(100, '\n');
        sleep(1);
        system("clear");
        SeatMap(arr);        
        cout<<"┌──────────────────────────────────────────────────┐"<<endl;
        cout<<"│                 행을 선택하시오                  │"<<endl;
        cout<<"│                 (A, B, C, D, E)                  │"<<endl;
        cout<<"└──────────────────────────────────────────────────┘"<<endl;
        cin>>row;
    }
    if(row == 'a') row = 'A';
    else if(row == 'b') row = 'B';
    else if(row == 'c') row = 'C';
    else if(row == 'd') row = 'D';
    else if(row == 'e') row = 'E';    
    cout<<row<<"행을 선택하셨습니다."<<endl<<endl;
    sleep(1);

    if(row == 'A') *xpos = 4;
    else if(row == 'B') *xpos = 6;        
    else if(row == 'C') *xpos = 8;
    else if(row == 'D') *xpos = 10;
    else if(row == 'E') *xpos = 12;
}

// 열 선택
void BockTicketPayment::ChoiceColumn(int* ypos){
    system("clear");
    SeatMap(arr);
    cout<<"┌──────────────────────────────────────────────────┐"<<endl;
    cout<<"│                 열을 선택하시오                  │"<<endl;
    cout<<"│                (1, 2, 3, 4, 5, 6)                │"<<endl;
    cout<<"└──────────────────────────────────────────────────┘"<<endl;
    while (!(cin>>column) || column > 6 || column < 1)
    {
        cout<<"잘못 입력하셨습니다."<<endl;
        cin.clear();
        cin.ignore(100, '\n');
        sleep(1);
        system("clear");
        SeatMap(arr);   
        cout<<"┌──────────────────────────────────────────────────┐"<<endl;
        cout<<"│                 열을 선택하시오                  │"<<endl;
        cout<<"│                (1, 2, 3, 4, 5, 6)                │"<<endl;
        cout<<"└──────────────────────────────────────────────────┘"<<endl;
    }
    if(column == 1) *ypos = 6;
    else if(column == 2) *ypos = 9;
    else if(column == 3) *ypos = 12;
    else if(column == 4) *ypos = 15;
    else if(column == 5) *ypos = 18;
    else if(column == 6) *ypos = 21;
}

// 결제
void BockTicketPayment::SaleTicket(const BockTicketUser & user){
    system("clear");
    string line;

    cout<<"┌──────────────────────────────────────────────────┐"<<endl;
    cout<<"                총 결제 금액 ₩"<<ticketTotal<<"               "<<endl;
    cout<<"└──────────────────────────────────────────────────┘"<<endl;
    cout<<"┌──────────────────────────────────────────────────┐"<<endl<<endl;
    for (int i = 0; i < pickRow.size(); i++)
    {
        cout<<"               선택하신 좌석은 "<<pickRow[i]<<"-"<<pickColumn[i]<<"입니다."<<endl;
    }
    cout<<endl<<"└──────────────────────────────────────────────────┘"<<endl;

    cout<<"┌──────────────────────────────────────────────────┐"<<endl;
    cout<<"│                결제를 진행합니다.                │";
    cout<<endl<<"└──────────────────────────────────────────────────┘"<<endl;

    sleep(1);
    for (int i = 0; i < 3; i++)
    {
        cout<<"."<<endl;
        sleep(1);
    }
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            if(arr[i][j] == 'h')
                arr[i][j] = 'g';
        }
    }
    
    ticketTotal = 0;
    
    ofstream reservMem("reservation.csv", ios::app);
    for (int i = 0; i < pickRow.size(); i++)
    {
        reservMem << user.userNum << "," << memCount << "," << pickscheduleDay[i] << "," << pickCountry[i] << "," << pickArea[i] << "," << pickRow[i] << "," << pickColumn[i] << "\n";
    }
    reservMem.close();

    // 추가 예매를 위해 벡터 초기화
    pickscheduleDay.clear();
    pickCountry.clear();
    pickArea.clear();
    pickRow.clear();
    pickColumn.clear();
    memCount++;
    
    cout<<"결제가 정상적으로 완료되었습니다."<<endl;
    cout<<"잠시 후 첫 화면으로 돌아갑니다."<<endl;
    sleep(3);
}

int main(void){
    int mainKey, input;
    BockTicketUser user;
    BockTicketPayment ticket;

    // 로그인
    user.Start();
    sleep(1);

    while (1)
    {
        // 메인
        mainKey = user.PrintMain();

        if (mainKey == 1)
            user.ChoiceInformation();
        
        // 예매하기
        else if (mainKey == 2)
        {
            ticket.ChoiceSchedule();
            ticket.SaleTicket(user);
            
        }
        // 예매내역
        else if (mainKey == 3)
        {
            string rePW, line;
            cout<<"┌───────────────────────────────────────────────────────────────────────┐"<<endl;
            cout<<"│                       비밀번호를 입력해주세요.                                             │" << endl;
            cout<<"└───────────────────────────────────────────────────────────────────────┘"<<endl;
            cin >> rePW;
            if (rePW == user.userPW)
            {
                ifstream openReserv("reservation.csv");
                while (getline(openReserv, line))
                {
                    stringstream sline(line);
                    string smemberNum, sCount, sscheduleDay, sCountry, sArea, sRow, sColumn;
                    getline(sline, smemberNum, ',');
                    getline(sline, sCount, ',');
                    getline(sline, sscheduleDay, ',');
                    getline(sline, sCountry, ',');
                    getline(sline, sArea, ',');
                    getline(sline, sRow, ',');
                    getline(sline, sColumn, ',');

                    if (user.userNum == smemberNum)
                    {
                        cout<<"┌────────────────────────────── 예매내역 ──────────────────────────────┐"<<endl;
                        cout<<" "<<endl;
                        cout<<"                경기: " << sscheduleDay << "     " << sCountry <<endl;
                        cout<<"                구역: " << sArea << endl;
                        cout<<"                좌석: " << sRow << "-" << sColumn <<endl;
                        cout<<" "<<endl;
                        cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl<<endl;                                    
                    }
                    cin.get();
                }
                cout<<"┌────────────────────────────── 예매내역 ──────────────────────────────┐"<<endl;
                cout<<" "<<endl;
                cout<<"                회원님의 예매내역이 존재하지 않습니다.                "<<endl;
                cout<<" "<<endl;
                cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl<<endl;                                    
            }
            else{
                cout<<"┌───────────────────────────────────────────────────────────────────────┐"<<endl;
                cout<<"│                       비밀번호가 일치하지 않습니다.                                             │" << endl;
                cout<<"└───────────────────────────────────────────────────────────────────────┘"<<endl;                
                sleep(1);
            } 
        }

        // 종료
        else if (mainKey == 4)
        {
            system("clear");
            user.MainLogoFile();
            cout<<"┌──────────────────────────────────────────────────────────────────────┐"<<endl;
            cout<<"│           프로그램을 종료합니다. 이용해주셔서 감사합니다.            │"<<endl;
            cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl<<endl;
            sleep(1);
            break;
        }

        else{
            cout<<"잘못된 선택입니다."<<endl;
            cin.clear();
            cin.ignore(100, '\n');
            sleep(1);
        }
    }   

    return 0;
}