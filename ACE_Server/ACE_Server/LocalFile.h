#pragma once
#include "ace/FILE_Addr.h"
#include "ace/FILE_IO.h"
#include "ace/FILE_Connector.h"
#include <string>

class LocalFile
{
public:

	LocalFile(const char *fileName = NULL);	
	virtual ~LocalFile(){this->close();}

	static bool fileExist(const char *fileName);	
	static bool createFile(const char *fileName);
	static bool deleteFile(const char *fileName);	

	bool open(const char *fileName);
	void close();
	int write(char *data, int length);
	int read(char *data, int length);

	const char* getPathName() const { return this->fileAddr.get_path_name(); }
	const char* getFileName() const { return this->pureFileName.c_str();}

private:

	void cacheFileName(const char *fileName);

private:

	ACE_FILE_Addr fileAddr;	
	ACE_FILE_IO fileIO;
	std::string pureFileName;
};