#pragma once

#define ENABLE 1
#define DISABLE 0

int AnyButtonDown();
void CanonicalMode(int state);      // enables / disables the canonical mode in terminal
char getccin();                     // this name stands for get console char input
