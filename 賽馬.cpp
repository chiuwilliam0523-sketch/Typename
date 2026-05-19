#include <bits/stdc++.h>
#include "SetScreenCursor.h"

#define LENGTH 119
#define NUM 6

using namespace std;

int WinnerHorse[NUM];

void fence()
{
    for(int Fence = 1 ; Fence <= LENGTH + 1 ; Fence++)
        cout << "=";
    cout << "|\n";
}

void HorseGame();

int main()
{
    HorseGame();
    return 0;
}

void HorseGame()
{
    struct num
    {
        int space = 0;
        int RAND = 0;
        int line = LENGTH;
        int key = 0;
    } tmp[NUM];
    
    int speed = 20, judge = 0;
    bool winner[NUM];
    
    for(int Loop = 0 ; Loop < NUM ; Loop++)
        winner[Loop] = 0;
    
    srand(time(NULL));
    
    for(int Loop = 3 ; Loop >= 1 ; Loop--)
    { 
        SetScreenCursor(0 , 0); 
        fence();
        for(int control_all = 0 ; control_all < NUM ; control_all++)
        {
            cout << control_all;
            for(int endline = 1 ; endline <= tmp[control_all].line ; endline++)
                cout << " ";
            cout << "|\n";
            
            fence();
        }
        cout << "Starting in: " << Loop << "   ";
        Sleep(1000);
    }
    
    SetScreenCursor(0,(NUM * 2) + 1);
    cout << "Start!!!           \n";
    
    while(true)
    {
        SetScreenCursor(0 , 0);
        fence();
        
        for(int control_all = 0 ; control_all < NUM ; control_all++)
        {
            if(tmp[control_all].line >= 4)
            {
                tmp[control_all].RAND = (rand() % 3) + 1;
                tmp[control_all].space += tmp[control_all].RAND;
                tmp[control_all].line -= tmp[control_all].RAND;
            }
            if((tmp[control_all].line < 4) && (tmp[control_all].line > 0))
            {
                tmp[control_all].space++;
                tmp[control_all].line--;
            }
            if(tmp[control_all].line == 0)
            {
                winner[control_all] = 1;
                judge = 1;
            }
            
            // Print the track state
            for(int Space = 1 ; Space <= tmp[control_all].space ; Space++)
                cout << " ";
            
            cout << control_all;
            
            for(int endline = 1 ; endline <= tmp[control_all].line ; endline++)
                cout << " ";
            cout << "|\n";
        
            fence();
        }
        
        if(judge == 1)
            break;
        
        Sleep(speed);
    }
    
    // Print Winners
    SetScreenCursor(0, (NUM * 2) + 1); // Move below the game board to print winners
    cout << "Winner is: ";
    int TMP_check = 0;
    for(int Loop = 0 ; Loop < NUM ; Loop++)
        WinnerHorse[Loop] = 0;
        
    for(int check = 0 ; check < NUM ; check++)
    {
        if(winner[check] == 1)
        {
            TMP_check++;
            if(TMP_check >= 2)
                cout << " and ";
            cout << check;
            WinnerHorse[check] = 1;
        }
    }
    cout << "\n\n";
}
