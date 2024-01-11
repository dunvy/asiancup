

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
    void InvalidInput();            // 잘못된 입력
};
