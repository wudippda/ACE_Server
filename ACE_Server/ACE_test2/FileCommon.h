#pragma once;

const int MAX_CLIENT_BUFFER_SIZE = 8*1024;
const int MAX_INFO_SIZE = 64;

//Client frame
enum ClientFrameType
{
	FILE_NAME_TYPE,	
	FILE_DATA_TYPE,	
	FILE_END_TYPE,	
	FILE_ERROR_TYPE,
	FILE_OVERWRITE_TYPE,	
	FILE_SKIP_TYPE,	
	DISCONNECT_TYPE	
};

//Client data frame
typedef struct
{
	ClientFrameType type;
	int length;
	char buffer[MAX_CLIENT_BUFFER_SIZE];
}ClientFrame;


//SeverFrame
enum ServerFrameType
{
	INVALID_TYPE,
	OK_TYPE,		
	FILE_EXIST_TYPE, 
	ERROR_TYPE,		
	FINISHED_TYPE	
};

//Sever data Frame
typedef struct
{
	ServerFrameType type;
	int length;
	char info[MAX_INFO_SIZE];
}ServerFrame;