/* File: response.cpp
 * Author: Olga Seymour
 */
#include "response.h"

/* default constructor 
    sets instance variables
*/  
Response::Response(){
    response = "";
    index = 0;
}
/* 2-arg constructor
   Parameters
    r the text of the response 
    i the index of the reponse's prompt 
      in a vector of prompts
*/
Response::Response(string r, int i){
     setResponse(r);
     setIndex(i);
}
/* copy constructor
    Parameter r a constant reference to a Response object 
*/
Response::Response(const Response& r){
    response = r.response;
    index = r.index;
}
/* setResponse sets response
    Parameters r response
    Returns: nothing
*/
void Response::setResponse(string r){
    response = r;
}
/* setIndex sets index
    Parameters i index
    Returns: nothing
*/
void Response::setIndex(int i){
    index = i;       
}
/* operator<< overloaded for Response object
   prints out the text of the response to the screen
   Parameters
      outStream the output stream
      r the response
   Returns the output stream
*/
ostream& operator<<( ostream& outStream, const Response& r){
    outStream << r.getResponse();      
    return outStream;
}
