#include <iostream>
#include "shape.h"
#include <chrono>
#include <thread>

#define ClearConsole system("clear")// clear the console

using namespace std;

int main()
{
    ClearConsole;
    Shape test(ZIGZAG);
    test.PrintShape();
    cout << "\n";
    this_thread::sleep_for(chrono::milliseconds(1000)); // waits for 1000 ms
    ClearConsole;
    test.Rotate();
    test.PrintShape();
    cout << "\n";

    return 0;
}