#include "HistoryOfMoves.hpp"
#include <vector>
#include <string>



void HistoryOfMoves::add_move(int field, int colour, string player){
    History.push_back(Move{field,colour,player});
}

Move HistoryOfMoves::last_move(){
    return History.back();
}
