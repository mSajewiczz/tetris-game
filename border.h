#pragma once

#include "player.h"

class Border {
private:
    char board[20][10]; // 20 - y wiersze, 10 - x kolumny

public:
    Player curr_player; // przyjmujesz player i automatycznie shape (grida).
    Border();
    void PrintBorder();
};