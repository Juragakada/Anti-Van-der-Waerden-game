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

    void intput_data(int n,int k, int c);

    void create_board(int size,vector<int> &board);

    void create_board(int size,vector<int> &board,int number);

    void clear_board(vector<int>& board, int lenght);

    void clear_board(vector<int>& board, int lenght, int number);

    void color_the_field(int n,int c);
    
    bool check_if_win(vector<int> board,int WinLenght,int ColoursNumbers, int last_move);

};



#endif
