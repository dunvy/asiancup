#ifndef __CAR_H__
#define __CAR_H__

namespace CAR_CONST{
    enum{
        ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2, ACC_STEP = 10, BRK_STEP = 10
    };
}

class Car
{
private:        // 변수와 함수는 private에 해당하는 범위 내에서(클래스 내에서만) 접근 가능
    char gamerID[CAR_CONST::ID_LEN];   
    int fuelGauge;          
    int curSpeed;           
public:         // 변수와 함수는 public에 해당하는 범위 내에서(어디서든) 접근 가능
    void InitMemebers(char* ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

#endif