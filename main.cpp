#include <iostream>
#include <chrono>
#include <termios.h>
#include <unistd.h>

#include "shape.h"
#include "player.h"
#include "border.h"
#include "ignoredInput.h"

#define ClearConsole    system("clear")// clear the console
#define Wait(x)         this_thread::sleep_for(chrono::milliseconds(x)) // waits for 1000 ms
#define Now             system_clock::now()

using namespace std;
using namespace std::chrono;
/* check if the set time has already passed to make the moving down actually 
independent of everything else (in a sense of course)*/


bool TimePassed(long int time)
{
    static auto start = Now;
    static bool firstCall = true;

    if (firstCall)
    {
        start = Now;
        firstCall = false;
    }

    auto now = Now;
    long int duration = duration_cast<milliseconds>(now - start).count();
    if (duration >= time)
    {
        start = Now;
        return true;
    }
    return false;
}

void MoveDownPlayer(Player &gracz)
{
    if (TimePassed(1000))
    {
        ClearConsole;
        gracz.Fall();
        gracz.PrintPlayer();
    }
}

int main()
{
    system("tput civis"); // makes the cursor invisible so it won't interfere with the game looks
    ClearConsole;
    Shape test(SHAPE_T);
    Player gracz(test);
    test.PrintShape();
    nonblock(NB_ENABLE);
    int i = 0;
    while (true)
    {
        system("stty raw"); // setting terminal to raw mode
        i = kbhit();
        system("stty cooked");
        if (i != 0)
        {
            int c = fgetc(stdin);
            if (c == (int)'w')
            {
                ClearConsole;
                gracz.Rotate();
                gracz.PrintPlayer();
            }
            if (c == (int)'a')
            {
                ClearConsole;
                gracz.MoveLeft();
                gracz.PrintPlayer();
            }
            if (c == (int)'d')
            {
                ClearConsole;
                gracz.MoveRight();
                gracz.PrintPlayer();
            }
            i = 0;
        }
        MoveDownPlayer(gracz);

        
    }
    nonblock(NB_DISABLE);
    return 0;
}