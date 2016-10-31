
#ifndef PACKETMANAGER_H
#define PACKETMANAGER_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "EventAndState.h"

using namespace std;

class packetManager
{
public:

        packetManager();
	bool createPacket(string& packet, typeEvent event, string& dataString, unsigned int blockNum); 
	bool createPacket(string& packet, typeEvent event, string& dataString);
	bool createPacket(string& packet, typeEvent event, unsigned int blockNum);
	bool createErrorPacket(string& packet, unsigned int error, string& message);
	typeEvent getPacketType(string& packet);
	unsigned int getPacketBLock(string& packet);
	void getPacketData(string& packet, string& dataString);
	void getPacketFileName(string& packet, string& dataString);

};



#endif /* PACKETMANAGER_H */

