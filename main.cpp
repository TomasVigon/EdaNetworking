
#include <cstdlib>
#include <iostream>
#include <string>
#include "ncurses.h"
#include "fsmClient.h"

cout << putooooooooooo;

putooooooo
typedef enum{NOEVENT,PUT,GET,QUIT} inputType;
#define ERROR -1
using namespace std;

inputType parseInput(string&); //devuelve el evento y en input el nombre del archivo

int main(int argc, char** argv)

{
    string input;
    inputType inputEvent=NOEVENT;
    fsmClient fsm;

    do{
    getline(cin,input);
    inputEvent=parseInput(input); 
    }
    while(inputEvent==NOEVENT);
        
    if(inputEvent==PUT) cout << endl << "option PUT";
    else if(inputEvent==GET) cout << endl << "option GET";
    else if(inputEvent==QUIT) cout << endl << "option QUIT";
    cout << endl << "file "<< input;
    
    
    if(inputEvent==PUT)fsm.cicleFsm(wrq);
    else if(inputEvent==GET)fsm.cicleFsm(rrq);
    else if(inputEvent==QUIT) return 0;
    fsm.setFilename(input);
    while(fsm.getCellState()!=FINISH)
    {
        //ACA TIENE QUE IR TIMEOUT Y KEYBOARD
        if(fsm.isEvent())
        fsm.cicleFsm(fsm.getEvent());
    }
    cout << endl << "fin";
    
    

    
    
}

inputType parseInput(string& input)
{
	size_t space=input.find(' ');
        size_t secondSpace;
	string aux;
        inputType event= NOEVENT;
        
	if(space!=input.npos)
	{
                aux=input.substr(0,space);                
		if(aux.compare("GET")==0) event=GET;
                else if(aux.compare("PUT")==0) event=PUT;
                else if(aux.compare("QUIT")==0) event=QUIT;
                else
                {
                    event= NOEVENT;
                    cout << endl <<"Invalid option";
                }
                if(event!=NOEVENT)
                {
                    secondSpace=input.find(' ',space+1);
                    /*if(secondSpace!=input.npos)*/input=input.substr(space+1,secondSpace-4);                    
                }
	}
	else
	{
		cout << endl << "Invalid Input";
	}
        
        return event;
}
