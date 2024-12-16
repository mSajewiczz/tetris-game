#include "shape.h"

#include <iostream>
#include <cmath>

using namespace std;
/*
    pattern rules:
    pattern[0][0] top left corner
    [ ][ ][ ][ ]
    [ ][ ][ ][ ]
    [ ][ ][ ][ ]
    [*][*][*][*]
    basic pattern
*/
Shape::Shape()
{
    ResetShape();
    Straight_Shape();
}
Shape::Shape(int type)
{
    ResetShape();
    switch (type)
    {
        case STRAIGHT:
            Straight_Shape();
            break;
        case SQUARE:
            Square_Shape();
            break;
        case SHAPE_T:
            Letter_T_Shape();
            break;
        case SHAPE_L:
            Letter_L_Shape();
            break;
        case ZIGZAG:
            Zigzag_Shape();
            break;
        default:
            Straight_Shape();
            break;    
    }
}

void Shape::Straight_Shape()
{
    for (int i = 0; i < 4; i++)
    {
        CurrPattern[3][i] = '*';

        charPos[i].x = i;
        charPos[i].y = 3;
    }
}
void Shape::Square_Shape()
{
    int index = 0;
    for (int i = 2; i <= 3; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            CurrPattern[i][j] = '*';

            charPos[index].x = j;
            charPos[index].y = i;
        }
    }
}
void Shape::Letter_T_Shape()
{
    for (int i = 0; i < 3; i++)
    {
        CurrPattern[2][i] = '*';

        charPos[i].x = i;
        charPos[i].y = 2;
    }
    CurrPattern[3][1] = '*';

    charPos[3].x = 1;
    charPos[3].y = 3;
}
void Shape::Letter_L_Shape()
{
    for (int i = 1; i <= 3; i++)
    {
        CurrPattern[i][0] = '*';

        charPos[i - 1].x = 0;
        charPos[i - 1].y = i;
    }
    CurrPattern[3][1] = '*';

    charPos[3].x = 1;
    charPos[3].y = 3;
}
void Shape::Zigzag_Shape()
{    
    CurrPattern[3][0] = '*';
    CurrPattern[3][1] = '*';
    CurrPattern[2][1] = '*';
    CurrPattern[2][2] = '*';

    charPos[0] = {0, 3};
    charPos[1] = {1, 3};
    charPos[2] = {1, 2};
    charPos[3] = {2, 2};
}
void Shape::ResetShape()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            CurrPattern[i][j] = ' ';
        }
    }
}

void Shape::PrintShape()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j =0; j < 4; j++)
        {
            cout << CurrPattern[i][j];
        }
        cout << endl;
    }
}
/*
    Rotation formula for a 4x4 grid indexed from 0
    prevY = y
    y = x
    x = abs(prevY - 3)

    INDEXED FROM 0 4X4 GRID ROTATION FORMULA
*/
void Shape::Rotate()
{
    ResetShape();
    for (int i = 0; i < 4; i++)
    {
        int tmp = charPos[i].y;
        charPos[i].y = charPos[i].x;
        charPos[i].x = abs(tmp - 3);

        CurrPattern[charPos[i].y][charPos[i].x] = '*';
    }
}