#pragma once

#include <vector>

struct CardPosition {
    int row;
    int col;
};

bool isValidPosition(int row, int col, const std::vector<std::vector<bool>>& revealed);

void pickTwoCards(const std::vector<std::vector<bool>>& revealed, CardPosition& card1, CardPosition& card2);