#include "PvC_easy.hpp"
#include "HistoryOfMoves.hpp"
#include "board.hpp"

#include <vector>
#include <iostream>

int AI::move(board board, HistoryOfMoves HOS){
    Move last_one=HOS.History.back();
    int a(0);
    
    while(1){
        a=rand()%board.size;
        if(board.board[a]==0){
            break;
        }
    }
    return a;
};

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

void PvC(){

    int n,k,c;
    AI AI;

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
    
    HistoryOfMoves HOS;
    first.print_board(first.board);
    
    while(1){
        cout << "Your turn"<< endl;
        
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
        HOS.add_move(a-1,b,"Player");
        first.print_board(first.board);

        if(HOS.History.size()>=first.winning_series_size){
        bool c=first.check_if_win(a);
        if(c==1){
            cout << "Player won!" << endl;
            break;
        }
        }
        if(HOS.History.size()==n){
            cout <<  "Computer won!" << endl;
            break; 
        }


        //AI MOVE
        cout << "AI's turn" << endl;
        Move lol=HOS.History.back();

        first.color_the_field(AI.move(first,HOS),lol.colour);
        
        //HOS.History[HOS.History.end].colour;

        HOS.add_move(a-1,b,"AI");
        first.print_board(first.board);

        if(HOS.History.size()>=first.winning_series_size){
        bool c=first.check_if_win(a);
        if(c==1){
            cout << "Player won!" << endl;
            break;
        }
        }
        if(HOS.History.size()==n){
            cout <<  "AI won!" << endl;
            break; 
        }

    }


}
