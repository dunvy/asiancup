#include <iostream>
#include <cmath>
#include "coordin.h"        // 구조체 템플릿, 함수 원형
using namespace std;

// 직각 좌표를 극 좌표로 변환
polar rect_to_polar(rect xypos){
    polar answer;

    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = std::atan2(xypos.y, xypos.x);
    return answer;          // polar형 구조체를 리턴
}

// 라디안 단위를 도 단위로 변환하여 극 좌표를 출력함
void show_polar(polar dapos){
    const double Ran_to_deg = 57.29577951;

    cout << "거리 = " << dapos.distance;
    cout << ", 각도 = " << dapos.angle*Ran_to_deg;
    cout << "도\n";
}