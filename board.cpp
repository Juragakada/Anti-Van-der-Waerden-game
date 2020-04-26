#include "board.hpp"
#include <vector>



void board::intput_data(int n,int k, int c){
        size=n;
        winning_series_size=k;
        number_of_colours=c; 
}

void board::create_board(){
        for(int i=0;i<size;i++){
            board.push_back(0);
        }
}

void board::create_board(int number){
        for(int i=0;i<size;i++){
            board.push_back(number);
        }
}

void board::clear_board(){
        board.clear();
        create_board();
}

void board::clear_board(int number){
        board.clear();
        create_board(number);
}

void board::color_the_field(int n,int c){
        if(c>number_of_colours)
        board[n-1]=c;
}
   
bool board::check_if_win(vector<int> board,int WinLenght,int ColoursNumbers, int last_move){
        const int max_x=board.size()/WinLenght + 1;
        vector<int>series(2*WinLenght-1);
        
        //creating matrix to comparison colors
        vector<int> row(ColoursNumbers);
        vector<vector<int>> colours(2,row);

        //colours are repleaced numbers between 1 and maximum color numbers
        for(int i=0;i<ColoursNumbers;i++){
            colours[0][i]=i+1;
            //The numbers in second row cannot be 0, becouse if any colour would be in series[0], algorihtm would asign 0 and it will
            //generate mistake
            colours[1][i]=ColoursNumbers+1;
            }
        
        //Loop 1- setting x - the differnce between elements of series
        for(int x=0;x<max_x;x++){

            series[WinLenght-1]=board[last_move];

            //Filling series with board elements from center to end
            for(int i=0;i<WinLenght;i++){
                
                
                if(last_move+(i*x)>board.size()){

                    series.erase(series.begin()+WinLenght-1+i,series.end());
                    break;

                } else {
                    series[WinLenght-1+i]=board[last_move+(i*x)];
                }
            }

            //Filling series with board elements from center to begin
            for(int i=1;i<WinLenght;i++){

                if(last_move-(i*x)<=0){

                    series.erase(series.begin(),series.begin()+WinLenght-1+i);
                    break;
                    
                } else {
                    series[WinLenght-1-i]=board[last_move-(i*x)];
                }
            }
            
            
            //begim checking if all the colors in series are different

            bool same_color_error(0);
            int number_of_different_colours(0);

            //setting where to start comparsson 
            for(int i=0;i<WinLenght;i++){
                
                same_color_error=0;
                number_of_different_colours=0;

                //comparison for all elements
                for(int j=0;j<WinLenght;j++){
                    
                    //comparison with all colour element
                    for(int k=0;i<ColoursNumbers;k++){
                        
                        //comparisson of element
                        if(series[i+j]==colours[0][k]){
                            
                            //checking if this is first appear of this colour
                            if(colours[1][k]==ColoursNumbers+1){
                                
                                colours[1][k]=i+j;
                                break;
                            
                            }else {

                                //changing i will to the number of element where coluor first appear will accelerate alogirthm
                                i=colours[1][k];
                                same_color_error=1;
                                break;
                            }
                        }
                    }

                    //this is for accelerate alogirthm and begin new comparison 
                    if (same_color_error==1){
                        break;
                    }
                }

                //checking how many different colorous we have
                for(int j=0;j<ColoursNumbers;j++){

                    if(colours[1][i]!=ColoursNumbers+1){

                        number_of_different_colours++;
                    }
                }
                if(number_of_different_colours>=WinLenght){
                    return 1;
                }
            }
            //preapering for creating new series
            clear_board(series,2*WinLenght-1); 
            clear_board(colours[1],ColoursNumbers,ColoursNumbers+1);
        }
        return 0;        
}
