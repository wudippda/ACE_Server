#pragma once
#include "StdAfx.h"
#include "ACE_headers.h"
#include "ClientManager.h"
#include "SceneManager.h"
#include "Util.h"

class MessageHandler
{
public:
	
	MessageHandler();
	~MessageHandler();

	std::pair<ACE_UINT16,ACE_UINT16> handleConnectionSever(ACE_INT32 ip,ACE_INT16 port);

private:

	ClientManager* m_ClientManager;
};