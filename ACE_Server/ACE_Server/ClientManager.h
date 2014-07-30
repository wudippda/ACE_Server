#pragma once
#include "StdAfx.h"
#include <map>
#include "Client.h"

using namespace std;

typedef map<ACE_UINT32,Client> ClientMap;

class ClientManager
{

private:

	ClientManager();
	~ClientManager()
	{
		if(CMsingleton != NULL)
			delete CMsingleton;
	}

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