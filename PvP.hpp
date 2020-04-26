#ifndef PvP_hpp
#define PvP_hpp

#include<iostream>
#include<vector>

using namespace std;

class Players{
    public:
    string first_player_name;
    string second_player_name;
    string player=first_player_name;
    int moves=0;
    
    void change_player();
    
};

int grab_initiating_data(string data_name);

void PvP();

#endif