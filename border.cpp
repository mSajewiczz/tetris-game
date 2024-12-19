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

void Border::AddPlayer(Player AddPlayer)
{
    Border();
}


void Border::PrintBorder()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(board[i][j] == '-')
            {
                cout << "——";
            } else if(board[i][j] == ' ')
            {
                cout << "  ";
            } else if(board[i][j] == '*')
            {
                cout << "██";
            }else if(j == 0)
            {
                cout << "| "; // albo board[i][j] zapis '|' jest czytelniejszy sigma
            } else if(j == 9)
            {
                cout << " |";
            }
        }
        cout << endl;
    }
} // tablica jest cały czas zmieniana -> cały czas zwracasz nową tablicę z aktualnym stanem klcków itd.
/* to co zapisujemy do tablicy[][] to '-', '|', ' ' i '*' gdzie te pierwsze 2 to elementy bordera,
 * to inaczej oznaczenie pojedynsczego bloku shape, a spacja to puste miejsce. */