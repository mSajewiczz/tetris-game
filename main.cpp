#include <iostream>
#include "shape.h"
#include <chrono>
#include <thread>
#include <X11/Xlib.h>

#define ClearConsole    system("clear")// clear the console
#define Wait(x)         this_thread::sleep_for(chrono::milliseconds(x)) // waits for 1000 ms
#define Now             system_clock::now()

using namespace std;
using namespace std::chrono;
/* check if the set time hasalready passed to make the moving down actually 
independent of everything else (in a sense of course)*/


bool TimePassed(long int time) 
{
    static auto start = Now;

    auto now = Now;
    long int duration = duration_cast<milliseconds>(now - start).count();
    if (duration >= time)
    {
        start = Now;
        return true;
    }
    return false;
}


int main()
{
    system("tput civis"); // makes the cursor invisible so it won't interfere with the game looks
    ClearConsole;
    Shape test(STRAIGHT);
    test.PrintShape();
    while (true)
    {
        system("stty raw"); // setting terminal to raw mode
        int c = getchar();
        system("stty cooked");
        if (c == (int)'w')
        {
            ClearConsole;
            test.Rotate();
            test.PrintShape();
        }
        if (TimePassed(1000))
        {
            // ClearConsole;
            // test.Rotate();
            // test.PrintShape();            
        }
    }


    return 0;
}