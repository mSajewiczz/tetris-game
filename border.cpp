#include<iostream>
#include "border.h"

using namespace std;

Border::Border() // klasa Border wywołuje konstruktor Border
{
    //a tu definiujesz co ma zrobic Border().
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i == 0 || i == 19)
            {
                board[i][j] = '-';
            } else if(j == 0 || j == 9)
            {
                board[i][j] = '|';
            } else
            {
                board[i][j] = ' ';
            }
        }
    }
}

void Border::PrintBorder()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}