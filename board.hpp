#ifndef board_hpp
#define board_hpp

#include <iostream>
#include <vector>

using namespace std;

class board{
public:
    unsigned int size;
    unsigned int winning_series_size;
    unsigned int number_of_colours; 
    vector<int> board;
    vector<int> colours;


    void create_board(int size,vector<int> &board);

    void create_board(int size,vector<int> &board,int number);

    void clear_board(vector<int>& board, int lenght);

    void clear_board(vector<int>& board, int lenght, int number);

    void color_the_field(int n,int c);
    
    bool check_if_win(int last_move);

    void print_board(vector<int> board);

};




#endif
