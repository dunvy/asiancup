// 잘못된 입력
void BockTicketUser::InvalidInput()
{
    cout<<"잘못 입력하셨습니다."<<endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout<<"재입력하시려면 엔터를 누르세요."<<endl;
    cin.get();
}

// 시작 페이지 아스키 아트
void BockTicketUser::StartLogoFile()
{
    system("clear");
    string line;
    ifstream mainLogo("logo2.txt");
    if (mainLogo.is_open())             // 파일 열렸는지 확인
    {
        while (!mainLogo.eof())         // 파일 끝까지 읽었는지 확인
        {
            getline(mainLogo, line);    // 한 줄씩 읽기
            cout << line << endl;       // 읽은 문자열 바로 출력
        }
    }
    mainLogo.close();
}

// 메인 페이지 아스키 아트
void BockTicketUser::MainLogoFile()
{
    system("clear");
    string line;
    ifstream mainLogo("logo3.txt");
    if (mainLogo.is_open())
    {        
        while (!mainLogo.eof())
        {    
            getline(mainLogo, line);
            cout << line << endl;   
        }
    }
    mainLogo.close();
}

// 스플래시
void BockTicketUser::Start()
{
    string line;
    ifstream startLogo("logo.txt");
    if (startLogo.is_open())
    {
        while (!startLogo.eof())
        {
            getline(startLogo, line);
            cout << line << endl;
        }
    }
    startLogo.close();
    sleep(2);

    // 로그인 및 회원가입 고르는 페이지로 넘어감
    PrintStart();
}

// 시작 페이지
void BockTicketUser::PrintStart()
{
    StartLogoFile();
    cout<<" 【 원하는 기능을 선택해주세요! 】"<<endl;
    cout<<"┌─────────────────────────────────┐"<<endl;
    cout<<"│          1. 로그인              │" << endl;
    cout<<"│          2. 회원가입            │" << endl;
    cout<<"└─────────────────────────────────┘"<<endl;

    cin >> userChoice;

    // 로그인
    if (userChoice == 1) LoginChoice();
    // 회원가입
    else if (userChoice == 2) Join();
    else
    {
        InvalidInput();
        PrintStart();
    }
}

// 로그인 및 ID/PW 선택
void BockTicketUser::LoginChoice()
{
    StartLogoFile();
    cout<<" 【 원하는 기능을 선택해주세요! 】"<<endl;
    cout<<"┌─────────────────────────────────┐"<<endl;
    cout<<"│          1. 로그인              │" << endl;
    cout<<"│          2. ID찾기              │" <<endl;
    cout<<"│          3. PW찾기              │" <<endl;
    cout<<"└─────────────────────────────────┘"<<endl;    
    cin >> userChoice;

    if (userChoice == 1) Login();
    else if (userChoice == 2) FindId();
    else if (userChoice == 3) FindPw();
    else
    {
        InvalidInput();
        LoginChoice();
    }
}

// 로그인
void BockTicketUser::Login()
{
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

        while (getline(inMember, line))
        {
            stringstream sline(line); 
            string smemberNum, spw, sid, sphoneNum, semail;
            getline(sline, smemberNum, ',');        
            getline(sline, sid, ',');
            getline(sline, spw, ',');

            if (userID == sid && userPW == spw)
            {
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
void BockTicketUser::Join()
{
    system("clear");
    cout<<"┌─────────────────────────────────┐"<<endl;
    cout<<"│        회원가입 진행중…         │" << endl;
    cout<<"└─────────────────────────────────┘"<<endl;

    string id, pw, phoneNum, email, line;   // 회원id, 회원pw, 회원핸드폰번호, 회원email, 비교할 문자열
    int count = 1;                          // 회원번호

    // 아이디 입력 및 중복 검사
    while(1)
    {
        int a = 0;

        ifstream inMember("member.csv");
        cout<< "사용할 ID를 입력해주세요: ";
        cin>>id;

        while (getline(inMember, line))
        {
            stringstream sline(line);                  // 한줄 읽어서 sline에 저장
            string smemberNum, sid;

            getline(sline, smemberNum, ',');           // ,를 기준으로 잘라서 smemberNum에 저장
            getline(sline, sid, ',');

            if (id == sid)
            {
                cout<<"중복된 아이디입니다."<<endl;
                a = 1;
                inMember.close();
                break;
            }
        }
        if (a == 0)
        {
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

        if (phoneNum.length() != 11)
        {
            cout<<"다시 입력해주세요!\n";
            continue;
        }

        while (getline(inMember, line))
        {
            stringstream sline(line); 
            string smemberNum, spw, sid, sphoneNum;
            getline(sline, smemberNum, ',');        
            getline(sline, sid, ',');
            getline(sline, spw, ',');
            getline(sline, sphoneNum, ',');

            if (phoneNum == sphoneNum)
            {
                cout<<"중복된 핸드폰 번호입니다."<<endl;
                a = 1;
                inMember.close();
                break;
            }
        }
        if (a == 0)
        {
            inMember.close();
            break;
        }
    }

    // 이메일 입력 및 중복 검사
    while(1)
    {
        int a = 0;

        ifstream inMember("member.csv");        
        cout<< "사용할 e-mail을 입력해주세요: ";
        cin>>email;
        
        while (getline(inMember, line))
        {
            stringstream sline(line);   
            string smemberNum, spw, sid, sphoneNum, semail;

            getline(sline, smemberNum, ',');  
            getline(sline, sid, ',');
            getline(sline, spw, ',');
            getline(sline, sphoneNum, ',');
            getline(sline, semail, ',');

            if (email == semail)
            {
                cout<<"중복된 e-mail입니다."<<endl;
                a = 1;
                inMember.close();
                break;
            }
        }
        if (a == 0)
        {
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

    while (getline(inMember, line))
    {
        stringstream sline(line);
        string smemberNum, spw, sid, sphoneNum, semail;

        getline(sline, smemberNum, ',');
        getline(sline, sid, ',');
        getline(sline, spw, ',');
        getline(sline, sphoneNum, ',');
        getline(sline, semail, ',');

        if (emailFind == semail)
        {
            cout<<"회원님의 아이디는 "<<sid<<" 입니다."<<endl;
            a = 1;
            inMember.close();
            break;
        }
    }

    if (a == 0)
    {
        cout<<"일치하는 e-mail 정보가 없습니다."<<endl;
        cout<<"┌─────────────────────────────────┐"<<endl;
        cout<<"│          1. 돌아가기            │" << endl;
        cout<<"│          2. 재입력              │" <<endl;
        cout<<"└─────────────────────────────────┘"<<endl;
        cin>>userChoice;
        while (userChoice != 1 && userChoice !=2)
        {
            cout<<"잘못 입력하셨습니다."<<endl<<"다시 입력해주세요!"<<endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin>>userChoice;
        }
        
        if (userChoice == 1)
            LoginChoice();
        else if (userChoice == 2)
            FindId();        
    }

    else if(a == 1)
    {
        cout<<"┌─────────────────────────────────┐"<<endl;
        cout<<"│          1. 로그인              │" << endl;
        cout<<"│          2. PW 찾기             │" <<endl;
        cout<<"└─────────────────────────────────┘"<<endl;
        cin>>userChoice;
        
        while (userChoice != 1 && userChoice !=2)
        {
            cout<<"잘못 입력하셨습니다."<<endl<<"다시 입력해주세요!"<<endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin>>userChoice;
        }

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

    while (getline(inMember, line))
    {
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

    if (a == 0)
    {
        cout<<"일치하는 회원 정보가 없습니다."<<endl;
        cout<<"┌─────────────────────────────────┐"<<endl;
        cout<<"│          1. 로그인              │" << endl;
        cout<<"│          2. 재입력              │" <<endl;
        cout<<"└─────────────────────────────────┘"<<endl;
        cin>>userChoice;
        
        while (userChoice != 1 && userChoice !=2)
        {
            cout<<"잘못 입력하셨습니다."<<endl<<"다시 입력해주세요!"<<endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin>>userChoice;
        }

        if (userChoice == 1)
            Login();
        else if (userChoice == 2)
            FindPw();        
    }

    else if(a == 1)
    {
        cout<<"┌─────────────────────────────────┐"<<endl;
        cout<<"│          1. 로그인              │" << endl;
        cout<<"└─────────────────────────────────┘"<<endl;
        cin>>userChoice;
        while (userChoice != 1)
        {
            cout<<"잘못 입력하셨습니다."<<endl<<"다시 입력해주세요!"<<endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin>>userChoice;
        }
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
    if (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4)
    {
        InvalidInput();
        PrintMain();
    }
    
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
    while (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5)
    {
        cout<<"잘못 입력하셨습니다."<<endl<<"다시 입력해주세요!"<<endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin>>userChoice;
    }
    
    if (userChoice == 5)
        return;        
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
    while (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5)
    {
        cout<<"잘못 입력하셨습니다."<<endl<<"다시 입력해주세요!"<<endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin>>userChoice;
    }
    if(userChoice == 5)
        return;
    else
        PrintInformation(userChoice);
}
