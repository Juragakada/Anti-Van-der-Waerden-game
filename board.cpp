#include "board.hpp"
#include <vector>





void board::create_board(int size,vector<int> &board){
        for(int i=0;i<size;i++){
            board.push_back(0);
        }
}

void board::create_board(int size,vector<int> &board,int number){
        for(int i=0;i<size;i++){
            board.push_back(number);
        }
}

void board::clear_board(vector<int>& board, int lenght){
        board.clear();
        create_board(lenght,board);
}

void board::clear_board(vector<int>& board, int lenght, int number){
        board.clear();
        create_board(lenght,board,number);
}

void board::color_the_field(int n,int c){
        
        board[n-1]=c;
        
}
   
bool board::check_if_win(int last_move){
        const int max_x=board.size()/winning_series_size + 1;
        vector<int>series(2*winning_series_size-1);
        
        //creating matrix to comparison colors
        vector<int> row(number_of_colours);
        vector<vector<int>> colours(2,row);

        //colours are repleaced numbers between 1 and maximum color numbers
        for(int i=0;i<number_of_colours;i++){
            colours[0][i]=i+1;
            //The numbers in second row cannot be 0, becouse if any colour would be in series[0], algorihtm would asign 0 and it will
            //generate mistake
            colours[1][i]=number_of_colours+1;
            }
        
        //Loop 1- setting x - the differnce between elements of series
        for(int x=0;x<max_x;x++){

            series[winning_series_size-1]=board[last_move];

            //Filling series with board elements from center to end
            for(int i=0;i<winning_series_size;i++){
                
                
                if(last_move+(i*x)>board.size()){

                    series.erase(series.begin()+winning_series_size-1+i,series.end());
                    break;

                } else {
                    series[winning_series_size-1+i]=board[last_move+(i*x)];
                }
            }

            //Filling series with board elements from center to begin
            for(int i=1;i<winning_series_size;i++){

                if(last_move-(i*x)<=0){

                    series.erase(series.begin(),series.begin()+winning_series_size-1+i);
                    break;
                    
                } else {
                    series[winning_series_size-1-i]=board[last_move-(i*x)];
                }
            }
            
            
            //begim checking if all the colors in series are different

            bool same_color_error(0);
            int number_of_different_colours(0);

            //setting where to start comparsson 
            for(int i=0;i<winning_series_size;i++){
                
                same_color_error=0;
                number_of_different_colours=0;

                //comparison for all elements
                for(int j=0;j<winning_series_size;j++){
                    
                    //comparison with all colour element
                    for(int k=0;i<number_of_colours;k++){
                        
                        //comparisson of element
                        if(series[i+j]==colours[0][k]){
                            
                            //checking if this is first appear of this colour
                            if(colours[1][k]==number_of_colours+1){
                                
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
                for(int j=0;j<number_of_colours;j++){

                    if(colours[1][i]!=number_of_colours+1){

                        number_of_different_colours++;
                    }
                }
                if(number_of_different_colours>=winning_series_size){
                    return 1;
                }
            }
            //preapering for creating new series
            clear_board(series,2*winning_series_size-1); 
            clear_board(colours[1],number_of_colours,number_of_colours+1);
        }
        return 0;        
}

void board::print_board(vector<int> board){
    for(int i=0;i<board.size();i++){
        cout << " | " << board[i];
    }
    cout << " | ";
}