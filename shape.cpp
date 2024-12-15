#include "shape.h"

#include <iostream>

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
    for (int i = 0; i < 4; i++)
    {
        pattern[3][i] = '*';
    }
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
Shape::Shape(char shape[4][4])
{
    ResetShape();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            pattern[i][j] = shape[i][j];
        }
    }
}

void Shape::Straight_Shape()
{
    for (int i = 0; i < 4; i++)
    {
        pattern[3][i] = '*';
    }
}
void Shape::Square_Shape()
{
    for (int i = 2; i <= 3; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            pattern[i][j] = '*';
        }
    }
}
void Shape::Letter_T_Shape()
{
    for (int i = 0; i < 3; i++)
    {
        pattern[2][i] = '*';
    }
    pattern[3][1] = '*';
}
void Shape::Letter_L_Shape()
{
    for (int i = 1; i <= 3; i++)
    {
        pattern[0][i] = '*';
    }
    pattern[3][1] = '*';
}
void Shape::Zigzag_Shape()
{
    pattern[3][0] = '*';
    pattern[3][1] = '*';
    pattern[2][1] = '*';
    pattern[2][2] = '*';
}
void Shape::ResetShape()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            pattern[i][j] = ' ';
        }
    }
}

void Shape::PrintShape()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j =0; j < 4; j++)
        {
            cout << pattern[i][j];
        }
        cout << endl;
    }
}