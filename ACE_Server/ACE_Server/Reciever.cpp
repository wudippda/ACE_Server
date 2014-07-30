#pragma once
#include "StdAfx.h"
#include "Reciever.h"

void Reciever::addresses (const ACE_INET_Addr &remote_address, const ACE_INET_Addr &local_address)
{
	this->client_address = remote_address;
	this->local_address = local_address;
}

void Reciever::open (ACE_HANDLE h, ACE_Message_Block&)  
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
      
void Reciever::handle_read_stream (const ACE_Asynch_Read_Stream::Result &result)
{  
    ACE_Message_Block &mb = result.message_block ();

    //if the connection is failed£¬release the connection resource to the client
    if (!result.success () || result.bytes_transferred () == 0)  
    {  
        mb.release ();  
        delete this;  
        return;  
    }

	dispatcher = new MessageDispatcher();
	dispatcher->dispatchMessage(mb);
	handler = new MessageHandler();
	ACE_UINT32 cmd = dispatcher->getCmd();

	ACE_Message_Block* smb;

	//case CONNECT_SERVER
	//------------------------------------------------------------------------//
	if(cmd = COM::CONNECT_SERVER)
	{
		pair<ACE_UINT16,ACE_UINT16> randomPos = handler->handleConnectionSever(dispatcher->getIP(),dispatcher->getPort());
		if(randomPos.first != 0 && randomPos.second != 0)
		{
			MessageConstructor::getInstance()->setAddress(this->local_address);
			smb = MessageConstructor::getInstance()->createConnectionAck(randomPos.first,randomPos.second,DEFAULT_AOI_RADIUS);
		}
	}

	//case CONNECT_SERVER
	//------------------------------------------------------------------------//

	//case CONNECT_FAIL_REPORT
	//------------------------------------------------------------------------//

	//case CLIENT_MOVE
	//------------------------------------------------------------------------//

	//case CLIENT_QUIT
	//------------------------------------------------------------------------//

	//case MORE_COMMAND
	//------------------------------------------------------------------------//

	dispatcher->setMB_NULL();
	mb.release();
	ACE_OS::printf("\nMMB data:%s\n",smb->rd_ptr());
	if (this->writer_.write(*smb,smb->length()) != 0)  
	{  
		ACE_OS::printf("Write Failed!");
		//MessageConstructor::getInstance()->setMB_NULL();
		smb->release();
		delete this; 
		return;
	}

	MessageConstructor::getInstance()->setMB_NULL();
	smb->release();
}
  
void Reciever::handle_write_dgram(const ACE_Asynch_Write_Stream::Result &result)  
{  
    ACE_Message_Block &mb = result.message_block ();  
    mb.release();  
    return;  
}

char* Reciever::curTime()
{
	time_t now = ACE_OS::gettimeofday().sec();
    char *time = ctime(&now);
	return time;
}