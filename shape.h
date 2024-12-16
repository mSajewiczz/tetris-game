#pragma once
enum
{
    STRAIGHT,   // a 4 tiles line
    SQUARE,     // a 2x2 square
    SHAPE_T,    // a t-shaped figure
    SHAPE_L,    // an L shaped like the letter 'L'
    ZIGZAG      // a zigzag (hard to explan if you haven't played tetris)
};
struct Position
{
    int x;
    int y;
};
class Shape
{
private:
    Position charPos[4];
    char CurrPattern[4][4];
    void Straight_Shape();
    void Square_Shape();
    void Letter_T_Shape();
    void Letter_L_Shape();
    void Zigzag_Shape();
    void ResetShape();

public:

    Shape();
    Shape(int type);

    void PrintShape();
    void Rotate();
};
