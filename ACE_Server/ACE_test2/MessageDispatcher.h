#pragma once
#include "StdAfx.h"
#include "ACE_headers.h"

class MessageDispatcher
{
public:

	MessageDispatcher();
	~MessageDispatcher();

	ACE_UINT32 getCmd(){return this->cmd;}
	ACE_UINT32 getIP(){return this->tmpIP;}
	ACE_UINT16 getPort(){return this->tmpPort;}
	ACE_UINT32 getTimestamp(){return this->tmpTimestamp;}

	void dispatchMessage(ACE_Message_Block &data)
	{
		mb = data.clone();
		ACE_InputCDR cdrIn(mb);
		cdrIn >> this->cmd;
		cdrIn >> this->tmpIP;
		cdrIn >> this->tmpPort;
		cdrIn >> this->tmpTimestamp;
	}

	void setMB_NULL(){this->mb = NULL;}

private:

	ACE_Message_Block *mb;
	ACE_CDR::ULong cmd;
	ACE_CDR::ULong tmpIP;
	ACE_CDR::UShort tmpPort;
	ACE_CDR::LongLong tmpTimestamp;

	//for DEBUG,check dispatched data
	void checkResult();
};