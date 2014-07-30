#pragma once
#include "StdAfx.h"
#include "DVE_Server.h"

int main(int argc, char *argv[])   
{  
	//Init ACE dll resource
    ACE::init();
    ACE_Asynch_Acceptor<Reciever> acceptor;  
      
    //listen on specific port
    if (acceptor.open (ACE_INET_Addr(LISTEN_PORT)) == -1)  
        return -1; 

	ACE_OS::printf("Server Established...\n");  
	ACE_OS::printf("Current User Num: %d\n",0); 
	ACE_OS::printf("Server Local IP Address:%s\n","127.0.0.1");
	ACE_OS::printf("Listening at Port:%d \n",LISTEN_PORT);

	time_t now = ACE_OS::gettimeofday().sec();
    char *time = ctime(&now);
	ACE_OS::printf("Current time:%s",time);

    //Wait 4 client Connection
    ACE_Proactor::instance ()->proactor_run_event_loop();
	
	//Release dll resource  
    ACE::fini();
    return 0;   
}  