#pragma once
#include "StdAfx.h"
#include "ACE_headers.h"
#include "Reciever.h"
#include "Sender.h"

#define LISTEN_PORT 20002
#define SEND_PORT 20003

class DVE_Server
{
	DVE_Server()
	{
		;
	}

private:

	Reciever reciever;
	Sender sender;
};
