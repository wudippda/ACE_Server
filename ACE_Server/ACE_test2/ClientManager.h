#pragma once
#include "StdAfx.h"
#include "Client.h"
#include <map>

using namespace std;

typedef map<ACE_UINT32,Client> ClientMap;

class ClientManager
{

private:

	ClientManager();
	~ClientManager();

public:

	bool addClient(ACE_UINT32 id,Client c);
	bool deleteClient(ACE_UINT32 id);
	Client* getClient(ACE_UINT32 id);

	static ClientManager* getInstance()
	{
		if(CMsingleton == NULL)
		{
			static ClientManager instance;
			CMsingleton = &instance;
		}
		return CMsingleton;
	}

private:

	ClientMap clients;
	static ClientManager* CMsingleton;
	int getCurrentUserNum();
};