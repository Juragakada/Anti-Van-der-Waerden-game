#ifndef HistoryOfMoves_hpp
#define HistoryOfMoves_hpp

#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Move{

public:

    int field;
    int colour;
    string player;

};

class HistoryOfMoves{

public:

    vector<Move> History;

    void add_move(int field, int colour, string player);

    Move last_move();

};


#endif 