#pragma once
#include "stdafx.h"  
#include "ACE_headers.h"
#include "ClientManager.h"
#include "MessageConstructor.h"
#include "MessageDispatcher.h"
#include "MessageHandler.h"
#include "COM.h"


class Reciever : public ACE_Service_Handler  
{
public:
	
	Reciever();
	~Reciever()  
    {  
        if (this->handle () != ACE_INVALID_HANDLE)  
            ACE_OS::closesocket (this->handle ());  
    }

	//virtual void addresses (const ACE_INET_Addr &remote_address, const ACE_INET_Addr &local_address);
    virtual void open (ACE_HANDLE h, ACE_Message_Block&);     
    virtual void handle_read_stream(const ACE_Asynch_Read_Stream::Result &result);
    virtual void handle_write_dgram(const ACE_Asynch_Write_Stream::Result &result);  
      
private:  
    ACE_Asynch_Read_Stream reader_;  
    ACE_Asynch_Write_Stream writer_;  
    char buffer[MAX_MSG_LEN];
	char* curTime();

	ACE_INET_Addr client_address,local_address;
	int client_x,client_y;
	MessageDispatcher* dispatcher;
	MessageHandler* handler;
};  