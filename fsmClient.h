
#ifndef FSMCLIENT_H
#define FSMCLIENT_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "cellType.h"
#include "packetManager.h"
#include "client.h"
#include "EventAndState.h"
#include "fileClass.h"

#define STATE_COUNT 7
#define EVENT_COUNT 8

#define TRANS_MODE "NETASCII"



using namespace std;

class fsmClient
{

public:

	fsmClient();
	~fsmClient();
	void cicleFsm(typeEvent event);
	cellType getCell(void);
        typeState getCellState(void);
        bool isEvent();
        typeEvent getEvent();
        void setFilename(string& name);

private:

        string packet;
	cellType cell;
        string filename;
        fileClass file;        
        packetManager p;
        client clientServer; 
	const cellType fsm_matrix[STATE_COUNT][EVENT_COUNT]=
	{		
//wrq			rrq			timeount                    ack                     quit			last_data 	data       		error
{{FIRST_WRITE,sendWrq},	{FIRST_READ,sendRrq},	{IDLE,nothing},             {IDLE,nothing},         {FINISH,end},	{IDLE,nothing},		{IDLE,nothing},		{FINISH,errorEvent}},	//IDLE
{{FIRST_WRITE,nothing},	{FIRST_WRITE,nothing},	{FIRST_WRITE,sendWrq},      {WRITE,sendData},       {FINISH,end},	{LAST_WRITE,nothing},	{FIRST_WRITE,nothing},	{FINISH,errorEvent}},	//FIRST_WRITE
{{WRITE,nothing},       {WRITE,nothing},	{WRITE,sendData},           {WRITE,sendData},       {FINISH,end},	{LAST_WRITE,nothing},	{WRITE,nothing},	{FINISH,errorEvent}},	//WRITE
{{LAST_WRITE,nothing},	{LAST_WRITE,nothing},	{LAST_WRITE,sendLastData},  {FINISH,end},           {FINISH,end},	{LAST_WRITE,nothing},  	{LAST_WRITE,nothing},	{FINISH,errorEvent}},	//LAST_WRITE
{{FIRST_READ,nothing},	{FIRST_READ,nothing},	{FIRST_READ,sendRrq},       {FIRST_READ,nothing},   {FINISH,end},	{FINISH,sendAck},	{READ,sendAck},		{FINISH,errorEvent}},	//FIRST_READ
{{READ,nothing},	{READ,nothing},		{READ,sendAck},             {READ,nothing},         {FINISH,end},	{FINISH,sendAck},	{READ,sendAck},         {FINISH,errorEvent}},	//READ
{{FINISH,nothing},	{FINISH,nothing},	{FINISH,nothing},           {FINISH,nothing},       {FINISH,nothing},	{FINISH,nothing},	{FINISH,nothing},	{FINISH,nothing}}	//FINISH
	};

	void sendWrq(void);
	void sendRrq(void);
	void end(void);
	void errorEvent(void);
	void sendData(void);
	void sendAck(void);	
	void nothing(void);
        void sendLastData(void);
        

};

#endif /* FSMCLIENT_H */

