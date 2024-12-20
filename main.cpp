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
    while (true)
    {
        char c = getccin();
            if (c == 'w')
            {
                ClearConsole;
                gracz.Rotate();
                gracz.PrintPlayer();
            }
            if (c == 'a')
            {
                ClearConsole;
                gracz.MoveLeft();
                gracz.PrintPlayer();
            }
            if (c == 'd')
            {
                ClearConsole;
                gracz.MoveRight();
                gracz.PrintPlayer();
            }
        MoveDownPlayer(gracz);
    }
    return 0;
}