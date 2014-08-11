#pragma once
#include "stdafx.h"
#include <time.h>
#include "ACE_headers.h"

#define MAX_MSG_LEN 1024

/*****************������ͨ���¼�����*****************/
	/** 
    * @brief �ͻ��������¼����Ͷ��� 
    * @param [in] ACE_UINT32 �ͻ��˵�ַ 
    * @param [in] ACE_UINT16 �ͻ��˶˿� 
    * @param [in] TTcpHandler* ���Ӿ�� 
    */  
    //typedef TEvent<void, ACE_UINT32, ACE_UINT16> TOnClientConnect;  
    /** 
    * @brief �ͻ��˶Ͽ������¼����Ͷ��� 
    * @param [in] ACE_UINT32 �ͻ��˵�ַ 
    * @param [in] ACE_UINT16 �ͻ��˶˿� 
    */  
    //typedef TEvent<void, ACE_UINT32, ACE_UINT16> TOnClientDisconnect;  
    /** 
    * @brief �ͻ���������֤�¼� 
    * @param [in] ACE_UINT32 �ͻ��˵�ַ 
    * @param [in] ACE_UINT16 �ͻ��˶˿� 
    * @return bool 
    * - true ��֤ͨ�� 
    * - false ��֤ʧ�� 
    */  
    //typedef TEvent<bool, ACE_UINT32, ACE_UINT16> TOnClientValidate;  
    /** 
    * @brief ���յ��ͻ��������¼����Ͷ��� 
    * @param [in] ACE_UINT32 �ͻ��˵�ַ 
    * @param [in] ACE_UINT16 �ͻ��˶˿� 
    * @param [in] unsigned int ���ݰ����к� 
    * @param [in] const char* ��������ָ�� 
    * @param [in] size_t ���ݳ��� 
    */  
    //typedef TEvent<void, ACE_UINT32, ACE_UINT16, unsigned int, const char*, unsigned short> TOnDataReceive;  
      
    /** 
    * @brief �ɹ����Ϳͻ��������¼����Ͷ��� 
    * @param [in] ACE_UINT32 �ͻ��˵�ַ 
    * @param [in] ACE_UINT16 �ͻ��˶˿� 
    * @param [in] unsigned int ���ݰ����к� 
    * @param [in] const char* ��������ָ�� 
    * @param [in] size_t ���ݳ��� 
    */  
    //typedef TEvent<void, ACE_UINT32, ACE_UINT16, unsigned int, const char*, unsigned short> TOnDataSendSucceeded;  
      
    /** 
    * @brief ʧ�ܷ��Ϳͻ��������¼����Ͷ��� 
    * @param [in] ACE_UINT32 �ͻ��˵�ַ 
    * @param [in] ACE_UINT16 �ͻ��˶˿� 
    * @param [in] unsigned int ���ݰ����к� 
    * @param [in] const char* ��������ָ�� 
    * @param [in] size_t ���ݳ��� 
    */  
    //typedef TEvent<void, ACE_UINT32, ACE_UINT16, unsigned int, const char*, unsigned short> TOnDataSendFailed; 
	
	/*******************************************************************************************************/

static class COM
{
	COM()
	{
		CONNECT_SERVER = 0x01;
		GET_SCENE_DATA = 0x02;
		SCENE_IS_HIT_ACK = 0x03;
		CLIENT_CHAT = 0x04;
		CONNECT_FAIL_REPORT = 0x05;
		CLIENT_MOVE = 0x06;
		CLIENT_QUIT = 0x07;

		//////////Server//////////
		CONNECTION_ACK = 0x61;
		CHAT_SUCCESS_ACK = 0x62;
		MOVE_SUCCESS_ACK = 0x63;
		UPDATA_NEIGHBOUR = 0x64;
	}

public:
	//Commands use by Client
	static ACE_UINT16 CONNECT_SERVER;
	static ACE_UINT16 GET_SCENE_DATA;
	static ACE_UINT16 SCENE_IS_HIT_ACK;
	static ACE_UINT16 CLIENT_CHAT;
	static ACE_UINT16 CONNECT_FAIL_REPORT;
	static ACE_UINT16 CLIENT_MOVE;
	static ACE_UINT16 CLIENT_QUIT;

	//Commands use by Server
	static ACE_UINT16 CONNECTION_ACK;
	static ACE_UINT16 CHAT_SUCCESS_ACK;
	static ACE_UINT16 MOVE_SUCCESS_ACK;
	static ACE_UINT16 UPDATA_NEIGHBOUR;
};