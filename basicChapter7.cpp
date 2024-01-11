// // 문제1
// #include <iostream>
// using namespace std;

// double average(double a, double b){
//     double result = 2.0 * a * b / (a+b);
//     return result;
// }

// int main(void){
//     double a, b;

//     cout << "쌍을 이루는 두 수를 입력하시오: ";
//     cin >> a >> b;
//     while(a != 0 && b != 0){
//         cout << "조화평균: "<< average(a, b) << endl;
//         cout << "쌍을 이루는 두 수를 입력하시오: ";
//         cin >> a >> b;
//     }
//     return 0;
// }


// // 문제2
// #include <iostream>
// using namespace std;

// void input(int arr[], int* size){       // 입력 함수
//     int i = 0;
//     cout << "숫자를 입력하시오(q 누르면 입력 종료): ";
//     while (i < 10 && cin >> arr[i]){
//         cout << "숫자를 입력하시오(q 누르면 입력 종료): ";
//         i++;
//         *size = i;
//     }
// }

// void output(int arr[], int size){       // 출력 함수
//     for (int i = 0; i < size; i++)
//         cout << arr[i] << ' ';
//     cout << endl;
// }

// void average(int arr[], int size){      // 평균 함수
//     int result, total = 0;

//     for (int i = 0; i < size; i++)
//         total += arr[i];

//     result = total/size;

//     cout << "평균: " << result << endl;
// }

// int main(void){
//     int arr[10];    // int형 원소가 10개인 변수 arr 배열
//     int n = 0;      // 배열이 다 끝나지 않았을 때의 배열 마지막 값을 위해 임의 설정한 변수

//     input(arr, &n);     // 입력을 위한 함수 인자로 int형 arr 배열, n의 주소값
//     output(arr, n);     // 출력을 위한 함수 인자로 int형 arr 배열, n의 값
//     average(arr, n);    // 평균 출력을 위한 함수 인자로 int형 arr 배열, n의 값
//     return 0;
// }


// // 문제3
// #include <iostream>
// using namespace std;

// struct box{
//     char maker[40];
//     float height;
//     float width;
//     float length;
//     float volume;
// };

// void recv_value(const box num){
//     cout << "구조체 값: " << num.maker << ' ' << num.height << ' ' << num.width << ' '
//         << num.length << ' ' << num.volume << endl;
// }

// void recv_pvalue(box* num){
//     num -> volume = num ->height * num->width * num ->length;

//     cout << "구조체 값: " << num -> maker << ' ' << num->height << ' ' << num->width << ' '
//         << num->length << ' ' << num->volume << endl;
// }


// int main(void){
//     box x;      //  box 구조체 변수 선언
    
//     cout << "구조체 입력받기(문자열): ";
//     cin >> x.maker;
//     cout << "구조체 입력받기(height): ";
//     cin >> x.height;
//     cout << "구조체 입력받기(width): ";
//     cin >> x.width;
//     cout << "구조체 입력받기(length): ";
//     cin >> x.length;
//     cout << "구조체 입력받기(volume): ";
//     cin >> x.volume;

//     // box 구조체를 값으로 전달받아, 각 멤버의 값을 출력하는 함수
//     recv_value(x);
//     // box 구조체의 주소를 전달받아, volume 멤버를 다른 세 가지 멤버의 곱으로 설정하는 함수
//     recv_pvalue(&x);

//     return 0;
// }


// // 문제4
// #include <iostream>
// using namespace std;
// double probability(unsigned numbers, unsigned picks);

// int main(void){
//     double total, choices;
//     double first, second;

//     // 사용자가 수의 범위를 정하고 그 집합에서 몇 개의 수를 뽑을 수 있음
//     cout << "전체 수의 개수와 뽑을 수의 개수를 입력하십시오: \n";
//     while((cin >> total >> choices) && choices <= total){
//         cout << "당신이 이길 확률은 ";
//         cout << probability(total, choices);    // 승률을 계산한다
//         cout << "번 중에 한 번입니다.\n";
//         cout << "다시 두 수를 입력하십시오. (끝내려면 q를 입력): ";
//     }
        
//     cout << "!!!파워볼!!! 숫자 1~27 중 숫자 하나 뽑으시오.\n";
//     while (cin >> num)
//     {
//         /* code */
//     }
    
//     cout << "프로그램을 종료합니다.\n";
//     return 0;
// }

// // 이 함수는 nubmers개의 수 중에서 picks개의 수를 정확하게 뽑을 확률을 계산
// double probability(unsigned numbers, unsigned picks){
//     double result = 1.0;    // 이 자리에는 지역 변수들이 옴
//     double n;
//     unsigned p;

//     for (n = numbers, p = picks; p>0; n--, p--)
//         result = result * n/p;
//     return result;
// }




// //문제 5
// #include <iostream>
// using namespace std;

// int factorial(int num){
//     // n이 0 이하면 1
//     if (num < 1)
//         return 1;

//     // n이 0보다 크면 재귀함수
//     return num * factorial(num-1);
// }

// int main(void){
//     int n;
//     cout << "정수를 입력하시오: ";
//     cin >> n;
//     cout << n << "! = " << factorial(n) << endl;
//     return 0;
// }


// // 문제6
// #include <iostream>
// using namespace std;
// #define BUF_SIZE 50

// // 배열에 저장할 double형 값 입력
// // 배열이 가득 찼거나, 숫자가 아닌 것이 입력되면 입력받기를 멈추고, 그때까지 받은 값의 개수를 리턴
// int Fill_array(double arr[], int size){        /// 배열의 이름, 배열의 크기
//     int i = 0;
//     cout << i+1 << "번째 숫자를 입력하시오 : ";
//     while (cin>>arr[i] && i < size)
//     {
//         cout << i+2 << "번째 숫자를 입력하시오 : ";
//         i++;
//     }
//     return i;
// }

// // 배열의 내용 출력
// void Show_arry(double arr[], int size){
//     cout << "배열의 값 : ";
//     for (int i = 0; i < size; i++)
//         cout << arr[i] << ' ';    
//     cout << endl;
// }

// // 배열에 저장된 값들의 순서를 뒤집음
// void Reverse_array(double arr[], int size){
//     for (int i = 0; i < size/2; i++){
//         double temp = arr[i];
//         arr[i] = arr[(size-i)-1];
//         arr[(size-i)-1] = temp;
//     }
// }

// int main(void){
//     double arr[BUF_SIZE];
//     int len;

//     len = Fill_array(arr, BUF_SIZE);        // 배열에 입력된 값의 개수 리턴
//     Show_arry(arr, len);
//     Reverse_array(arr, len);
//     Show_arry(arr, len);

//     return 0;
// }



// // 문제7
// #include <iostream>
// using namespace std;

// const int Max = 5;

// int fill_array(double ar[], int limit);
// void show_array(const double ar[], int n);          // 데이터를 보호한다
// void revalue (double r, double ar[], int n); 

// int main(void){
//     double properties[Max];

//     int size = fill_array(properties, Max); 
//     show_array(properties, size);

//     if(size>0){
//         cout << "재평가율을 입력하십시오: "; 
//         double factor;
//         while ( ! (cin >> factor) ) // 잘못된 입력임
//         {
//             cin.clear();
//             while(cin.get() != '\n')
//                 continue;
//             cout<<"잘못 입력했습니다, 수치를 입력하세오: ";
//         }
//         revalue(factor, properties, size);
//         show_array(properties, size);
//     }
//     cout <<"프로그램을 종료합니다.\n";
//     cin.get();
//     cin.get();
//     return 0;
// }

// int fill_array(double ar[], int limit){
//     using namespace std;
//     double temp;
//     int i;

//     for (i = 0; i < limit; i++)
//     {
//         cout << (i+1) << "번 부동산의 가격: ";
//         cin >> temp;
//         if(!cin)        // 입력 불량
//         {
//             cin.clear();    // 입력 비우기
//             while(cin.get() != '\n')
//                 continue;
//             cout<<"입력 불량; 입력 과정을 끝내겠습니다.\n";
//             break;
//         }
//         else if (temp<0)        //루프 탈출을 위한 음수 값
//             break;
//         ar[i] = temp;
//     }
//     return i;
// }

// // 주소가 ar인 배열을 사용할 수 있으나, 변경 불가
// void show_array(const double ar[], int n){
//     for(int i= 0; i<n; i++){
//         cout<<(i+1)<<"번 부동산: $";
//         cout<<ar[i]<<endl;
//     }
// }

// // ar[]의 각 원소에 재평가율 r을 곱함
// void revalue(double r, double ar[], int n){
//     for (int i = 0; i < n; i++)
//         ar[i] *= r;    
// }



// // 문제8
// #include <iostream>
// #include <array>
// #include <string>
// //상수(constant) 데이터

// const int Seasons = 4;
// const std::array<std::string, Seasons> Sname = {"Spring", "Summer", "Fall", "Winter"};

// // array 객체를 수정하는 기능
// void fill(std::array<double, Seasons>* pa);
// // 수정하지 않고 객체를 사용하는 기능
// void show(std::array<double, Seasons> da);

// int main(void){
//     std::array<double, Seasons> expenses;
//     fill(&expenses);
//     show(expenses);
//     return 0;
// }

// void fill(std::array<double, Seasons>* pa){
//     using namespace std;
//     for (int i = 0; i < Seasons; i++)
//     {
//         cout<<Sname[i]<<"에 소요되는 비용:";
//         cin>>(*pa)[i];
//     }
// }

// void show(std::array<double, Seasons> da){
//     using namespace std;
//     double total = 0.0;
//     cout << "\n계절별 비용S\n";
//     for (int i = 0; i < Seasons; i++)
//     {
//         cout<<Sname[i]<<" : $"<<da[i]<<endl;
//         total += da[i];
//     }
//     cout << "총 비용: $"<<total <<endl;
// }



// // 문제9
// #include <iostream>
// #include <stirng>
// using namespace std;

// const int SLEN = 30;
// struct student{
//     char fullname[SLEN];
//     char hobby[SLEN];
//     int ooplevel;
// };

// int getinfo(student pa[], int size);     // student 구조체 배열의 첫 번째 원소를 지시하는 포인터, 그 배열의 원소 수
// void display1(student st);
// void display2(const student* ps);
// void display3(const student pa[], int n);

// int main(void){
//     cout << "학급의 학생 수를 입력하십시오: ";
//     int class_size;
//     cin >> class_size;

//     while (cin.get() != '\n')
//         continue;

//     student* ptr_stu = new student[class_size];
//     int entered = getinfo(ptr_stu, class_size);
//     for (int i = 0; i < entered; i++)
//     {
//         display1(ptr_stu[i]);
//         display2(&ptr_stu[i]);
//     }
//     display3(ptr_stu, entered);
//     cout << "프로그램을 종료합니다. \n";
//     return 0;    
// }

// int getinfo(student pa[], int size){
//     int i = 0;
//     cout << i+1 << "번째 학생 이름을 입력하시오: ";
//     while (getline(cin, pa->fullname[i]) && i < SLEN){
//         cout << i+2 << "번째 학생 이름을 입력하시오: ";
//         i++;
//     }
//     return i;
// }