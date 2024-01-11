// #include <iostream>
// using namespace std;

// // 점
// class Point
// {
// public:         // 어디서든 접근이 가능
//     int x;      // 멤버변수 x
//     int y;      // 멤버변수 y
// };

// // 직사각형
// class Rectangle
// {
// // 클래스의 멤버로 객체를 둘 수 있음
// public:                 // 어디서든 접근이 가능
//     Point upLeft;       // 멤버변수 Point 객체 upLeft
//     Point lowRight;     // 멤버변수 Point 객체 lowRight
// public:
//     void ShowRecInfo(){
//         cout<<"좌 상단: " << '[' << upLeft.x << ", ";       // Point 객체 upLeft의 멤버변수 x
//         cout<< upLeft.y << ']' << endl;                     // Point 객체 upLeft의 멤버변수 y
//         cout<< "우 하단: " << '['<< lowRight.x << ", ";     // Point 객체 lowRight의 멤버변수 x
//         cout<< lowRight.y << ']'<< endl<<endl;              // Point 객체 lowRight의 멤버변수 y
//     }
// };

// int main(void){
//     Point pos1 = {-2, 4};           // 직사각형을 표현할 Point 객체 pos1 생성
//     Point pos2 = {5, 9};            // 직사각형을 표현할 Point 객체 pos2 생성
//     Rectangle rec = {pos2, pos1};   // 위에서 생성한 Point 객체를 이용해서 Rectangle 객체 생성 및 초기화
//     rec.ShowRecInfo();
//     return 0;
// }


