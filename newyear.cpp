#include <iostream>
#include <unistd.h>
using namespace std;

void map(char (*sun)[13]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 13; j++){
            if(sun[i][j] == 0)
                cout << "   ";
            if(sun[i][j] == 1)
                cout << "🌞 ";
            if(sun[i][j] == 4)
                cout << "2️⃣  ";
            if(sun[i][j] == 5)
                cout << "0️⃣  ";
            if(sun[i][j] == 6)
                cout << "2️⃣  ";
            if(sun[i][j] == 7)
                cout << "4️⃣  ";
            if(sun[i][j] == 8)
                cout << "❗  ";
        }
        cout <<"\n";
    }
}
void move(char (*sun)[13], int* xpos, int* ypos, int* turn){
    sleep(1);
    system("clear");
    map(sun);

    (*xpos)--;
    int count = *turn;

    // if (*turn < 3){
    //     for (int i = 0; i < *turn; i++){
    //         sun[(*xpos)+i+1][(*ypos)+i] = 1;
    //         sun[(*xpos)+i+1][(*ypos)-i] = 1;
    //     }
    // }

    if (count < 3){
        for (int i = 0; i < count; i++){
            sun[(*xpos)+i+1][(*ypos)+i] = 1;
            sun[(*xpos)+i+1][(*ypos)-i] = 1;
        }
    }
    if (count == 3)
    {
        sun[(*xpos)+1][*ypos] = 1;
        for (int i = 1; i < count; i++){
            sun[(*xpos)+i+1][(*ypos)+1] = 1;
            sun[(*xpos)+i+1][(*ypos)-1] = 1;
        }
    }
    if (count == 4)
    {
        sun[(*xpos)+1][*ypos] = 1;
        for (int i = 1; i < 3; i++){
            sun[(*xpos)+i+1][(*ypos)+1] = 1;
            sun[(*xpos)+i+1][(*ypos)-1] = 1;
        }
        sun[(*xpos)+count][(*ypos)+1] = 0;
        sun[(*xpos)+count][(*ypos)-1] = 0;
    }
    if (count == 5)
    {
        sun[(*xpos)+1][*ypos] = 1;
        for (int i = 1; i < 3; i++){
            sun[(*xpos)+i+1][(*ypos)+1] = 1;
            sun[(*xpos)+i+1][(*ypos)-1] = 1;
        }
        sun[(*xpos)+count-1][(*ypos)+1] = 0;
        sun[(*xpos)+count-1][(*ypos)-1] = 0;

        sun[(*xpos)+count][(*ypos)+1] = 0;
        sun[(*xpos)+count][(*ypos)-1] = 0;
        sun[(*xpos)+count][(*ypos)] = 0;
    }
    (*turn)++;
}

int main(void){
    int xpos = 10, ypos = 6, turn = 0;
    char sun[10][13] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0}        
    };
    map(sun);
    
    while (turn < 7){
        move(sun, &xpos, &ypos, &turn);    
    }
    sleep(1);    

    sun[3][4] = 4;
    sun[3][5] = 5;
    sun[3][6] = 6;
    sun[3][7] = 7;
    sun[3][8] = 8;
    system("clear");
    map(sun);
    cout << endl << "2024!" << endl;
}