
void BockTicketPayment::InvalidInput2()
{
    cout<<"잘못 입력하셨습니다."<<endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout<<"재입력하시려면 엔터를 누르세요."<<endl;
    cin.get();
}


// 경기 일정 선택
void BockTicketPayment::ChoiceSchedule()
{
    system("clear");
    cout<<"┌──────────────────────────── 일자 선택 ───────────────────────────────┐"<<endl<<endl;
    for (int i = 0; i < 6; i++){
        cout<<"      "<<i+1<< ". " << day[i]<<"       "<<country[i]<<endl;
    }
    cout<<endl<<"└──────────────────────────────────────────────────────────────────────┘"<<endl;
    cin>>userChoice2;

    while (userChoice2 != 1 && userChoice2 != 2 && userChoice2 != 3 && userChoice2 != 4 && userChoice2 != 5 && userChoice2 != 6)
    {
        InvalidInput2();
        ChoiceSchedule();
    }
    
    scheduleDay = day[userChoice2-1];
    choiceCountry = country[userChoice2-1];

    ChoiceArea();
}

// 경기 구역 선택
void BockTicketPayment::ChoiceArea()
{
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
    
    while (userChoice2 != 1 && userChoice2 != 2 && userChoice2 != 3 && userChoice2 != 4)
    {
        InvalidInput2();
        ChoiceArea();
    }

    ticketMoney = money[userChoice2-1]; 
    choiceArea = area[userChoice2-1];

    ChoiceSeat(ticketMoney);
}

// 경기 좌석 맵 출력
void BockTicketPayment::SeatMap(char (*arr)[25])
{
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
}

// 경기 좌석 선택
void BockTicketPayment::ChoiceSeat(int area)
{
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
            while (userChoice2 != 1 && userChoice2 != 2)
            {
                cout<<"잘못 입력하셨습니다."<<endl<<"다시 입력해주세요!"<<endl;
                cin.clear();
                cin.ignore(100, '\n');
                cin>>userChoice2;
            }
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
