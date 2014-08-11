#pragma once
#include "StdAfx.h"
#include "ClientManager.h"

/////////----------------Public-----------------//////////////
bool ClientManager::addClient(ACE_UINT32 id,Client c)
{
	if(clients.find(id) != clients.end())
	{
		this->clients.insert(ClientMap::value_type(id,c));
		return true;
	}
	else
		return false;
}

bool ClientManager::deleteClient(ACE_UINT32 id)
{
	ClientMap::iterator iter;
	if((iter = clients.find(id)) != clients.end())
	{
		clients.erase(iter);
		return true;
	}
	return false;
}

Client* ClientManager::getClient(ACE_UINT32 id)
{
	ClientMap::iterator iter;
	if((iter = clients.find(id)) != clients.end())
		return &(iter->second);
	return NULL;
}


/////////----------------Private-----------------//////////////
int ClientManager::getCurrentUserNum()
{
	return this->clients.size();
}