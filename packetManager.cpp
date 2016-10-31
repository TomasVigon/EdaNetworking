#include "packetManager.h"

bool packetManager::createPacket(string& packet, typeEvent event, string& dataString, unsigned int blockNum)
{//ESTE ES PARA DATA

	stringstream ss;
	packet.clear();
	if(event==data)
	packet+="03"; //DATA
	else return false;
	ss << blockNum;
	packet+=ss.str();
	packet+=dataString;
	return true;
}

bool packetManager::createPacket(string& packet, typeEvent event, string& dataString)
{//ESTE ES PARA WRQ Y RRQ
	packet.clear();
	if(event==rrq)packet+="01";//RRQ
	else if(event==wrq)packet+="02";//WRQ	
	else return false;
	packet+=dataString;
	packet+="0"; //NO ES ESTE CERO
	packet+=TRANS_MODE;
	packet+="0";
	return true;
}

bool packetManager::createPacket(string& packet, typeEvent event, unsigned int blockNum)
{//ESTE ES PARA ACK
	stringstream ss;
	packet.clear();
	if(event==ack) packet+="04";
	else return false;
	ss << blockNum;
	packet+=ss.str();
	return true;

}

bool packetManager::createErrorPacket(string& packet, unsigned int error, string& message)
{
	if(error>MAXERROR)return false;
	stringstream ss;
	packet.clear();
	packet+="05";
	ss << error;
	packet+=error.str();
	packet+=message;
	return true;

}

typeEvent packetManager::GetPacketType(string& packet)
{
	typeEvent event;
	if(packet[1]=='1')event=rrq;
	else if(packet[1]=='2') event=wrq;
	else if(packet[1]=='3') event=data;
	else if(packet[1]=='4') event=ack;
	else if(packet[1]=='5') event=error;
	else event=NOEVENT;
	return event;
}

unsigned int packetManager::getPacketBLock(string& packet)
{	
	return stoi(packet.substr(2,2));
}

void packetManager::getPacketData(string& packet, string& dataString)
{
	dataString=packet.substr(4);
}
void packetManager::getPacketFileName(string& packet, string& dataString)
{
	dataString=packet.substr(2);

}