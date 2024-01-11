
int main(void)
{
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
            int a = 0;
            string rePW, line;
            cout<<"┌───────────────────────────────────────────────────────────────────────┐"<<endl;
            cout<<"│                       비밀번호를 입력해주세요.                        │" << endl;
            cout<<"└───────────────────────────────────────────────────────────────────────┘"<<endl;
            cin >> rePW;
            if (rePW == user.userPW)
            {
                system("clear");
                // cout<<"┌───────────────────────────────────────────────────────────────────────┐"<<endl;
                // cout<<"│                 엔터 키를 누르면 이전으로 돌아갑니다.                 │" << endl;
                // cout<<"└───────────────────────────────────────────────────────────────────────┘"<<endl;                
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
                        cout<<"         경기: " << sscheduleDay << "     " << sCountry <<endl;                        
                        cout<<" "<<endl;
                        cout<<"         구역: " << sArea << endl;
                        cout<<" "<<endl;
                        cout<<"         좌석: " << sRow << "-" << sColumn <<endl;
                        cout<<" "<<endl;
                        cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl<<endl;                                    
                        a = 1;
                    }
                    // sleep(3);
                    
                }
                openReserv.close();
                if (a == 0)
                {
                    system("clear");
                    cout<<"┌────────────────────────────── 예매내역 ──────────────────────────────┐"<<endl;
                    cout<<" "<<endl;
                    cout<<"                    회원님의 예매내역이 존재하지 않습니다."<<endl;
                    cout<<" "<<endl;
                    cout<<"└──────────────────────────────────────────────────────────────────────┘"<<endl<<endl;                                    
                }
            }
            else
            {
                cout<<"┌───────────────────────────────────────────────────────────────────────┐"<<endl;
                cout<<"│                     비밀번호가 일치하지 않습니다.                     │" << endl;
                cout<<"└───────────────────────────────────────────────────────────────────────┘"<<endl;                
            }
            cout<<"┌───────────────────────────────────────────────────────────────────────┐"<<endl;
            cout<<"│                 엔터 키를 누르면 이전으로 돌아갑니다.                 │" << endl;
            cout<<"└───────────────────────────────────────────────────────────────────────┘"<<endl;                
            cin.clear();
            cin.ignore(100, '\n');
            cin.get();
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