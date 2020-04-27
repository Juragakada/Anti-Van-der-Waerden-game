#include <iostream>
#include <vector>
#include "board.hpp"
#include "HistoryOfMoves.hpp"
#include "PvC_easy.hpp"

using namespace std;





int main(){

    while(1){

        cout << "Choose Game Mode:" << endl;
        cout << " 1 - Player vs Player" << endl;
        cout << " 2 - Player vs Computer" << endl;
        cout << " x - Exit" << endl;
        string a;
        while(1){
                
            cin >> a;

                if (a=="1"){
                    //PvP();
                    //function with game
                    break;
                
                } else if (a=="2"){
                    
                    PvC(); 
                    break;
                
                } else if (a=="x"){
                    return 0;
                } else {
                   
                    cout << "Wrong Number" << endl;
                }
        }
    }

    // board first;
    // first.intput_data(12,3,5);
    // first.create_board(first.size);
    // for (int i =0;i<first.board.size();i++){
    // cout << first.board[i];
    // }
    // first.create_colors(first.number_of_colours,first.colours);
    // for(int i=0;i<12;i++){
    //     first.board[i]=rand()%6;
    // }
    // //first.color_the_field(3,4);
    // bool a=first.check_if_win(first.board,3,5,7);
    // cout << a << endl;

    // for(int i=0;i<first.size;i++){
    //     cout << first.board[i];
    // }

    // int c=5;
    // vector<int> row(2);
    //     vector<vector<int>> colours(c,row);
    //     for(int i=0;i<c;i++){
    //         colours[i][0]=i+1;
    //         cout<<colours[i][0] << colours[i][1] << endl;
    // }

    return 0;
}