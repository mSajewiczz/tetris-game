#include "ignoredInput.h"

#include <unistd.h>
#include <termios.h>
#include <chrono>
#include <iostream>

int AnyButtonDown()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}
void CanonicalMode(int state)
{
    struct termios terminalState;
    tcgetattr(STDIN_FILENO, &terminalState);//get the terminal state
    if (state == ENABLE)
    {
        terminalState.c_lflag &= (tcflag_t)(~ICANON);//turn off canonical mode   
        terminalState.c_cc[VMIN] = 1;//minimum number of characters in input to read
    }
    else if (state == DISABLE)
    {
        terminalState.c_lflag |= ICANON;//turn on canonical mode
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &terminalState);//set the terminal attributes
}
char getccin()
{
    int i = AnyButtonDown();
    if (i == 0)
    {
        return 0;
    }
    return fgetc(stdin);
}