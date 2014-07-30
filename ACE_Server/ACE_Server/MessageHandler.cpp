#pragma once
#include "StdAfx.h"
#include "MessageHandler.h"

std::pair<ACE_UINT16,ACE_UINT16> MessageHandler::handleConnectionSever(ACE_INT32 ip,ACE_INT16 port)
{
	ClientManager* tmp = ClientManager::getInstance();

	ACE_INET_Addr addr(port,ip);
	ACE_UINT16 xPos = UTIL::getRandomInt(MIN_MAP_X,MAX_MAP_X);
	ACE_UINT16 yPos = UTIL::getRandomInt(MIN_MAP_Y,MAX_MAP_Y);
	Client newClient(addr,xPos,yPos,DEFAULT_AOI_RADIUS);

	if(tmp->addClient(ip,newClient))
	{
		//add Client SuccessLog here,record ip address and port;
		return pair<ACE_UINT16,ACE_UINT16>(xPos,yPos);
	}
	else
	{
		//add ClientFailLog here,record ip address and port;
		return pair<ACE_UINT16,ACE_UINT16>();
	}
}