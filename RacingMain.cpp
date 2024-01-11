#include "Car.h"

int main(void){
    Car run99;
    run99.InitMemebers("run99", 100);       // 초기화 목적으로 InitMembers 함수 호출
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    return 0;
}