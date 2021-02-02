/* File: response.h
 * Author: Olga Seymour
 */
#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>  
using namespace std;
 
class Response
{
public:
    
    //Constructors
    Response();
    Response(string r, int i);
    Response(const Response&);
    //Destructor
    virtual ~Response(){}
    
    //Accessor and mutator functions
    void setResponse(string);
    string getResponse() const { return response; }
    void setIndex(int);
    int getIndex() const { return index; }
    
    //Overloaded operator  
    friend ostream& operator<<( ostream&, const Response& );
    
private:
    //Response to a prompt
    string response;   
    //The index into a vector of prompts of the prompt 
    //that comes next after this response
    int index;  
};
 #endif
