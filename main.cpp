/* 
 * File: main.cpp
 * Author: Olga Seymour
 * Date: 11/03/2020
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "prompt.h"
#include "response.h"

using namespace std;

int main()
{
    ifstream in;  
    
    vector<Prompt> prompt;
    
    Prompt p = Prompt();
    
    in.open("Game.txt"); 
      
    //Uses current time as seed for random generator 
    srand(time(0)); 
    
    //Reads game input file into the vector of Prompt objects
    in >> p; 
    while(!in.eof()){  
        prompt.push_back(p);
        in >> p; 
    }
    
    //Plays the game until the user is done 
    int choice = 0;  
    cout << prompt[choice];   //prints out the first prompt
    do{ 
        //User's response to get the next prompt index
        int indexResp;       //index into the vector of Response objects.   
        cin >> indexResp;
      
        //Gets the next prompt index based on user's response 
        choice = prompt[choice].getResponse(indexResp).getIndex();  
            if( choice != -1){
            cout << prompt[choice];   
            }                                                
    }
    while( choice != -1);
    
    cout << "Thank you for playing our traveling adventure game!" << endl;
    return 0;
}
