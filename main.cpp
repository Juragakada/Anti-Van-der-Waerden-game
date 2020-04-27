#include <iostream>
#include <vector>
#include "board.hpp"
#include "HistoryOfMoves.hpp"

using namespace std;





int main(){

    while(1){

        cout << "Choose Game Mode:" << endl;
        cout << " 1 - Player vs Player" << endl;
        cout << " 2 - Player vs Computer" << endl;
        
        string a;
        while(1){
                
            cin >> a;
            
                if (a=="1"){
                   
                    //function with game
                    break;
                
                } else if (a=="2"){
                    
                    //function with game 
                    break;
                
                } else {
                   
                    cout << "Wrong Number" << endl;
                }
        }
    }

    return 0;
}