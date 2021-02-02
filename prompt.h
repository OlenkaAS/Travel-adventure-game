/* File: prompt.h
 * Author: Olga Seymour
 */
#ifndef PROMPT_H
#define PROMPT_H

#define TRUE 1
#define FALSE 0

#include "response.h"
#include <vector>  
#include <iostream>  
#include <string>  
using namespace std;

class Prompt
{
public:
    
    static const string outputs [10];
    
    //Constructors
    Prompt();  
    Prompt(string p);
    Prompt(const Prompt&);
    //Destructor
    virtual ~Prompt(){}
    
    //Accessor and mutator functions
    void setQuestion(string);
    string getQuestion() const { return question; } //inline function returns question
    void setId(int);
    int getId() const { return pid; }  //inline function returns prompt id
    
    //Functions for the vector of responses
    void addResponse( Response);  
    Response getResponse(int i); 
    void clearResponses();  
    
    //Overloaded operators
    friend ostream& operator<<( ostream&, const Prompt& );      
    friend istream& operator>>( istream&, Prompt& );   

private:
    //The words in the prompt, a C++ string object
    string question; 
    //Prompt id, index of the prompt when it's placed in the vector of Prompt objects
    int pid;    
    //a vector of Response objects
    vector<Response> responses;   
};
#endif
