#include <iostream>
#include <vector>
#include "board.hpp"
#include "HistoryOfMoves.hpp"
#include "PvP.hpp"

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
                    PvP();
                    //function with game
                    break;
                
                } else if (a=="2"){
                    
                    //function with game 
                    break;
                
                } else if (a=="x"){
                    return 0;
                } else {
                   
                    cout << "Wrong Number" << endl;
                }
        }
    }

  

    return 0;
}