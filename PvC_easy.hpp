#ifndef PvP_easy_hpp
#define PvP_easy_hpp

#include <iostream>
#include <vector>
#include "HistoryOfMoves.hpp"
#include "board.hpp"

using namespace std;

class AI{
    public:

    int move(board board, HistoryOfMoves HOS);
    
};

void PvC();

int grab_initiating_data(string data_name);

#endif