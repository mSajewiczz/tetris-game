#include <iostream>
#include <chrono>
#include <thread>

#include "shape.h"
#include "player.h"
#define ClearConsole    system("clear")// clear the console
#define Wait(x)         this_thread::sleep_for(chrono::milliseconds(x)) // waits for 1000 ms
#define Now             system_clock::now()

using namespace std;
using namespace std::chrono;
/* check if the set time hasalready passed to make the moving down actually 
independent of everything else (in a sense of course)*/


bool TimePassed(long int time)
{
    static auto start = Now; //zapisuje sie do kazdego nowego wywolania funkcji

    auto now = Now;
    long int duration = duration_cast<milliseconds>(now - start).count();
    if (duration >= time)
    {
        start = Now;
        return true;
    }
    return false;
}

bool MoveDownPlayer(Player &gracz)
{
    if (TimePassed(1000))
    {
        ClearConsole;
        gracz.Fall();
        gracz.PrintPlayer();
    }
    return true;
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
        system("stty raw"); // setting terminal to raw mode
        int c = getchar();
        system("stty cooked"); // setting terminal to a person during a math exam mode
        if (c == (int)'w' && MoveDownPlayer(gracz))
        {
            ClearConsole;
            gracz.Rotate();
            gracz.PrintPlayer();
        }
        if (c == (int)'a' && MoveDownPlayer(gracz))
        {
            ClearConsole;
            gracz.MoveLeft();
            gracz.PrintPlayer();
        }
        if (c == (int)'d' && MoveDownPlayer(gracz))
        {
            ClearConsole;
            gracz.MoveRight();
            gracz.PrintPlayer();
        }
    }
    return 0;
}