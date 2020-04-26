#include "PvP.hpp"
#include "board.hpp"
#include <vector>

int grabbing_data(string data_name){
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
    
    n=grabbing_data("size of board");
    
    while(1){
        k=grabbing_data("lenght of winning series");
        if(k<n){
            break;
        } else {
            cout << "Lenght of winnig series must be less than board size. Enter correct data";
        }
    }

    while(1){
        c=grabbing_data("number of colors");
        if(c>=k){
            break;
        } else {
            cout <<"Number of colours must be greater than or equal to lenght of winning series";
        }
    }

    board first={n,k,c};
    first.create_board();
    while(1)


}
    




