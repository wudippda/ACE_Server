#pragma once
#include "stdafx.h"
#include <time.h>
#include "ACE_headers.h"

#define MAX_MSG_LEN 1024

/*****************服务器通信事件定义*****************/
	/** 
    * @brief 客户端连接事件类型定义 
    * @param [in] ACE_UINT32 客户端地址 
    * @param [in] ACE_UINT16 客户端端口 
    * @param [in] TTcpHandler* 连接句柄 
    */  
    //typedef TEvent<void, ACE_UINT32, ACE_UINT16> TOnClientConnect;  
    /** 
    * @brief 客户端断开连接事件类型定义 
    * @param [in] ACE_UINT32 客户端地址 
    * @param [in] ACE_UINT16 客户端端口 
    */  
    //typedef TEvent<void, ACE_UINT32, ACE_UINT16> TOnClientDisconnect;  
    /** 
    * @brief 客户端连接验证事件 
    * @param [in] ACE_UINT32 客户端地址 
    * @param [in] ACE_UINT16 客户端端口 
    * @return bool 
    * - true 验证通过 
    * - false 验证失败 
    */  
    //typedef TEvent<bool, ACE_UINT32, ACE_UINT16> TOnClientValidate;  
    /** 
    * @brief 接收到客户端数据事件类型定义 
    * @param [in] ACE_UINT32 客户端地址 
    * @param [in] ACE_UINT16 客户端端口 
    * @param [in] unsigned int 数据包序列号 
    * @param [in] const char* 数据区域指针 
    * @param [in] size_t 数据长度 
    */  
    //typedef TEvent<void, ACE_UINT32, ACE_UINT16, unsigned int, const char*, unsigned short> TOnDataReceive;  
      
    /** 
    * @brief 成功发送客户端数据事件类型定义 
    * @param [in] ACE_UINT32 客户端地址 
    * @param [in] ACE_UINT16 客户端端口 
    * @param [in] unsigned int 数据包序列号 
    * @param [in] const char* 数据区域指针 
    * @param [in] size_t 数据长度 
    */  
    //typedef TEvent<void, ACE_UINT32, ACE_UINT16, unsigned int, const char*, unsigned short> TOnDataSendSucceeded;  
      
    /** 
    * @brief 失败发送客户端数据事件类型定义 
    * @param [in] ACE_UINT32 客户端地址 
    * @param [in] ACE_UINT16 客户端端口 
    * @param [in] unsigned int 数据包序列号 
    * @param [in] const char* 数据区域指针 
    * @param [in] size_t 数据长度 
    */  
    //typedef TEvent<void, ACE_UINT32, ACE_UINT16, unsigned int, const char*, unsigned short> TOnDataSendFailed; 
	
	/*******************************************************************************************************/

class COM
{
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