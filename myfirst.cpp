// // myfirst.cpp  -- 메시지를 출력한다
// #include <iostream>     // 선행처리 지시자

// int main(){                                     // 함수 머리
//     using namespace std;                        // 정의 가시화
//     cout << "C++의 세계로 오십시오.";            // 메시지 출력
//     cout << endl;                               // 새로운 행 시작
//     cout << "후회하지 않으실 겁니다!" << endl;    // 또 다른 메시지 출력
//     return 0;                                   // main()을 종료
// }



// // carrots.cpp
// #include <iostream>     // 선행처리 지시자

// int main(){                                     // 함수 머리
//     using namespace std;                        // 정의 가시화

//     int carrots;
    
//     carrots = 25;
//     cout << "나는 당근을 ";                      // 메시지 출력
//     cout << carrots;
//     cout << "개 가지고 있다.";
//     cout << endl;                               // 새로운 행 시작
//     carrots = carrots - 1;
//     cout << "아삭아삭, 이제 당근은 " << carrots << "개이다." << endl;    // 또 다른 메시지 출력
//     return 0;                                   // main()을 종료
// }



// // getinfo.cpp      -- 입력과 출력
// // cout == printf / cin == scanf
// #include <iostream>
// int main(){
//     using namespace std;

//     int carrots;

//     cout << "당근을 몇 개나 가지고 있니?" << endl;
//     cin >> carrots;                                 // C++ 입력
//     cout << "여기 두 개 더 있다. ";
//     carrots = carrots + 2;
//     // 다음 라인은 출력을 연결한다.
//     cout << "이제 당근은 모두 " << carrots << "개이다." << endl;
//     return 0;
// }



// 함수의 재귀호출
#include <iostream>
using namespace std;

void countdown(int n);

int main(void){
    countdown(4);
    return 0;
}

void countdown(int n){
    cout << "카운트 다운.. " << n << endl;
    if (n > 0)
        countdown(n-1);
    cout << n << ": Kabbom!\n";
}