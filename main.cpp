#include <iostream>
#include "shape.h"
#include <chrono>
#include <thread>

#define ClearConsole    system("clear")// clear the console
#define Wait(x)          this_thread::sleep_for(chrono::milliseconds(x)) // waits for 1000 ms
using namespace std;

int main()
{
    ClearConsole;
    Shape test(ZIGZAG);
    test.PrintShape();
    while (true)
    {
        Wait(1000);
        ClearConsole;
        test.Rotate();
        test.PrintShape();
    }


    return 0;
}