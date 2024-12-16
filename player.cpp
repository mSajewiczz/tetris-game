#include "player.h"

#include <iostream>

using namespace std;
Player::Player()
{
    CurrentShape = Shape(STRAIGHT);
    PlayerPosition = {0, 0};
}
Player::Player(Shape NewShape)
{
    CurrentShape = NewShape;
    PlayerPosition = {0, 0};
}

bool Player::CanFall()
{
    //rest of the calculations;
    return true;
}
bool Player::CanMoveLeft()
{
    if (PlayerPosition.x == 0 && PlayerPosition.y == 0)
    {
        return false;
    }
    // rest of the calculations
    return true;
}
bool Player::CanMoveRight()
{
    // rest of the calculations
    return true;
}


void Player::MoveLeft()
{
    if (CanMoveLeft())
    {
        PlayerPosition.x--;
    }
}
void Player::MoveRight()
{
    if (CanMoveRight())
    {
        PlayerPosition.x++;
    }
}
void Player::Fall()
{
    if (CanFall())
    {
        PlayerPosition.y++;
    }
}
void Player::PrintPlayer()
{
    for (int i = 0; i < PlayerPosition.y; i++)
    {
        cout << endl;
    }
    CurrentShape.PrintShape(PlayerPosition.x);
}
void Player::Rotate()
{
    CurrentShape.Rotate();
}