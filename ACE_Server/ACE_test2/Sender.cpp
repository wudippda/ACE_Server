#pragma once
#include "StdAfx.h"
#include "Sender.h"

#pragma comment(lib,"ACEd.lib")

Sender::Sender()
{
	;
}

Sender::~Sender()
{
	if(this->handle () != ACE_INVALID_HANDLE)  
		ACE_OS::closesocket(this->handle ());  
}

void Sender::addresses(const ACE_INET_Addr &remote_address, const ACE_INET_Addr &local_address)
{
	this->client_address = remote_address;
	this->local_address = local_address;
}

void Sender::open(ACE_HANDLE h, ACE_Message_Block&)  
{  
	//ACE_DEBUG LOG here,print ip,port,establish time

	//client_address.addr_to_string(peer_name, sizeof(peer_name) / sizeof(ACE_TCHAR));
	//ACE_DEBUG((LM_DEBUG, "%s", "\nOne User has established a connection.\n"));
	//ACE_DEBUG((LM_DEBUG,ACE_TEXT("IP Address:%s \n"),peer_name));
	//ACE_OS::printf("Current time:%s",this->CurTime());

    this->handle(h);
    if (this->reader_.open(*this) != 0 )  
    {  
        delete this;  
        return;  
    }  
    if (this->writer_.open(*this) != 0 )  
    {  
        delete this;  
        return;  
	}

    ACE_Message_Block *mb = new ACE_Message_Block(buffer,MAX_MSG_LEN);  
    if (this->reader_.read (*mb, mb->space()) != 0)  
    {  
        //ACE_OS::printf("Begin read failed!\n");  
        delete this;  
        return;
    }
    return;  
}  
      
void Sender::handle_read_stream (const ACE_Asynch_Read_Stream::Result &result)
{  
    ACE_Message_Block &mb = result.message_block();

    //if the connection is failed£¬release the connection resource to the client
    if (!result.success () || result.bytes_transferred () == 0)  
    {  
        mb.release ();  
        delete this;  
        return;  
	}
	mb.release();

	/*if (this->writer_.write(*smb,smb->length()) != 0)  
	{  
		ACE_OS::printf("Write Failed!");
		MessageConstructor::getInstance()->setMB_NULL();
		smb->release();
		delete this; 
		return;
	}*/
}
  
void Sender::handle_write_dgram(const ACE_Asynch_Write_Stream::Result &result)  
{  
    ACE_Message_Block &mb = result.message_block ();  
    mb.release();  
    return;  
}

void Sender::wirteMessage(ACE_Message_Block* mb)
{
	if (this->reader_.open(*this) != 0 )  
    {  
        if (this->writer_.write(*mb,mb->length()) != 0)  
		{  
			ACE_OS::printf("Write Failed!");
			MessageConstructor::getInstance()->setMB_NULL();
			mb->release();
			delete this; 
			return;
		 }
	}
}	