/* File: prompt.cpp
 * Author: Olga Seymour
 * Description: implementation of Prompt class
 */
#include <ctime>
#include "response.h"
#include "prompt.h"

//Randomly selected for the user 
const string Prompt::outputs [10] = {"What now?", "What do you want to do?", "And, your choice is..?", 
                             "Which one?", "What is your choice?", "Are you sure?", "What you prefer to do?", 
                              "Have you decided what would you like to do?", "How would you like to continue?", 
                              "How do you want to proceed?"};
 
/* default constructor 
    sets instance variables
*/ 
 Prompt::Prompt(){
     question = "";
     pid = 0;
}
/* 1-arg constructor
   Parameter q the text of the prompt
*/
Prompt::Prompt(string q){
    setQuestion(q);
    pid = 0;  // setId(q);
}
/* copy constructor
    Parameter q a constant reference to a Prompt object 
*/
Prompt::Prompt(const Prompt& q){
    setQuestion(q.question);
    setId(q.pid);
    responses = q.responses;
}
/* setQuestion sets question
    Parameters q question
    Returns: nothing
*/
void Prompt::setQuestion(string q){
    if(q != "") question = q;
}
/* setId sets prompt id
    Parameters pid prompt id
    Returns: nothing
*/
void Prompt::setId(int i){
    if(i > 0) pid = i;
}
/* addResponse puts Response in the vector of responses
    Parameter r Response
    Returns nothing
*/
void Prompt::addResponse( Response r){
    responses.push_back(r);   
} 
/* getResponse allows to access private data
    Parameter i index into the vector of Response objects
    Returns the single Response object at that index
*/   
Response Prompt::getResponse(int i){
    return responses[i];
}
/* clearResponses clears(empties) the responses vector 
    Parameter none 
    Returns nothing
    Post-condition: responses vector is empty
*/ 
void Prompt::clearResponses(){
    responses.erase (responses.begin(),responses.end());   
}  
/* operator<< overloaded for Prompt object
    prints out the text of the prompt and its responses
    Parameters
       outStream the output stream
       p the prompt
    Returns the output stream
*/
ostream& operator<<( ostream& outStream, const Prompt& p){
    outStream << p.getQuestion() << endl;
    
    //Finds number of responses, the size  
    int s = p.responses.size();   
    for(int i = 0; i < s; i++){     
        outStream << i << " " << p.responses[i].getResponse() << endl;  //for each response
    }
    //Randomly selects one of the strings from the outputs array and prints it
    outStream << Prompt::outputs[rand() % 10] << endl; 
    
    return outStream;
}  
/* operator>> overloaded for Prompt object
    reads a prompt from a text input file
    Parameters:
       inStream the input stream
       p the prompt
    Returns the input stream
*/ 
istream& operator>>( istream& inStream, Prompt& p){
    //Declare a string to read into
    string temp1;
    
    //Find function returns size_t of the index's number, to find the bar in the text                        
    size_t bar;    
    
    Response r;
    string temp2;  //partial string 
    bool firstRead = TRUE;             
    bool secondRead = FALSE;   
    p.clearResponses();
    getline(inStream,temp1);
    
    //Prime read to find if there are any bars in the file
    bar = temp1.find("|");  
    
    //while did not find "|" 
    while(bar != std::string::npos){  //it doesn't have the index b/c didn't find the bar - the end of prompt        
        if(firstRead){               //first, reads the id of the prompt
            //Returns new string starting at 0 till bar
            temp2 = temp1.substr(0, bar);
            p.pid = stoi(temp2); 
            temp1.erase(0, bar+1);  //erases the previous content to read in the next string
            firstRead = FALSE;
            secondRead = TRUE;
        }
        else if(secondRead){         //reads the prompt's question
            p.question = temp1.substr(0, bar);
            temp1.erase(0, bar +1);
            secondRead = FALSE;
        }
        else{                              //reads the responses till the end of the line         
            temp2 = temp1.substr(0, bar);
            r.setResponse(temp2);         //puts text into generic response's text
            temp1.erase(0, bar +1);
            bar = temp1.find("|");
            temp2 = temp1.substr(0, bar);  
            r.setIndex(stoi(temp2));
            temp1.erase(0, bar+1);      
            p.addResponse(r);            //add the reponse to the prompt
        }    
        bar = temp1.find("|");           //finds the next bar each time
    }
    return inStream;
}


            
                   
    
    
