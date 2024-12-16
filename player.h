#pragma once

#include "shape.h"

class Player
{
private:
    Shape CurrentShape;
    Position PlayerPosition;

    bool CanFall();
    bool CanMoveLeft();
    bool CanMoveRight();
public:
    Player();
    Player(Shape NewShape);
    void MoveLeft();
    void MoveRight();
    void Fall();
    void PrintPlayer();
    void Rotate();
};