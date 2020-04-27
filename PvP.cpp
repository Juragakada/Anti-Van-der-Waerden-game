#include "PvP.hpp"
#include "board.hpp"
#include "HistoryOfMoves.hpp"
#include <vector>




void Players::change_player(){
        if (player==first_player_name){
            player=second_player_name;
        } else {
            player=first_player_name;
        }
 }


int grab_initiating_data(string data_name){
    cout << "Enter" << data_name << endl;
    int a;
    while (1){
        cin >> a;
        if (a>0){
            break;
        } else {
            cout << "Enter correct data" << endl;
        }
    }
}



void PvP(){
    int n,k,c;
    
    //Take from player data to begin game
    n=grab_initiating_data(" size of board");
    
    while(1){
        k=grab_initiating_data(" lenght of winning series");
        if(k<n){
            break;
        } else {
            cout << "Lenght of winnig series must be less than board size. Enter correct data";
        }
    }

    while(1){
        c=grab_initiating_data(" number of colors");
        if(c>=k){
            break;
        } else {
            cout <<"Number of colours must be greater than or equal to lenght of winning series";
        }
    }

    //Creating Game Board
    board first={n,k,c};
    first.create_board(first.size,first.board);
    Players Gamers={"Adam","Bob"};
    HistoryOfMoves HOS;
    first.print_board(first.board);
    
    while(1){
        cout << Gamers.player << "'s turn"<< endl;
        
        cout << "Choose field" << endl;
        int a(0),b(0);
        while(1){
            
            cin >> a;
            if (a>=first.size || a<0){
                cout << "Enter correct field" << endl;
            } else if(first.board[a-1]!=0){
                cout << "You cannot recolor this field, enter empty field" << endl;
            } else if(first.board[a-1]==0){
                break;
            }

        }

        cout << "Choose color" << endl;

        while(1){
            
            cin >> b;

            if (b<=first.number_of_colours && b>0) {
                break;
            } else {
                cout << "Enter correct color" << endl;
            }
        }
        

        first.color_the_field(a,b);
        HOS.add_move(a-1,b,Gamers.player);
        first.print_board(first.board);

        if(HOS.History.size()>=first.winning_series_size){
        bool c=first.check_if_win(a);
        if(c==1){
            cout << Gamers.first_player_name << " won!" << endl;
            break;
        }
        }
        if(HOS.History.size()==n){
            cout << Gamers.second_player_name << " won!" << endl;
            break; 
        }
        Gamers.change_player();



    }


}
    




