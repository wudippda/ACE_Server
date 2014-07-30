#include "LocalFile.h"

LocalFile::LocalFile(const char *fileName)
{
	if(fileName != NULL)
	{
		this->fileAddr.set(fileName);
		this->open(fileName);
	}
}

bool LocalFile::fileExist(const char *fileName)
{
	if(NULL == fileName)
		return false;

	ACE_FILE_Connector conn;
	ACE_FILE_IO dfile;
	return conn.connect(dfile, ACE_FILE_Addr(fileName),0, ACE_Addr::sap_any, 0, O_RDWR,ACE_DEFAULT_FILE_PERMS) == 0;
}

bool LocalFile::createFile(const char *fileName)
{
	if(NULL == fileName)
	{
		return false;
	}

	ACE_FILE_Connector conn;
	ACE_FILE_IO dfile;
	return conn.connect(dfile, ACE_FILE_Addr(fileName)) == 0;
}

bool LocalFile::deleteFile(const char *fileName)
{
	if(NULL == fileName)
	{
		return false;
	}

	ACE_FILE_Connector conn;
	ACE_FILE_IO dfile;
	if(conn.connect(dfile, ACE_FILE_Addr(fileName)) == -1)
	{
		return false;
	}

	return dfile.remove() == 0;
}

bool LocalFile::open(const char *fileName)
{
	if(NULL == fileName)
	{
		return false;
	}

	ACE_FILE_Connector conn;
	this->fileAddr.set(fileName);
	this->cacheFileName(fileName);
	return conn.connect(this->fileIO, this->fileAddr) == 0;
}

void LocalFile::close()
{
	this->fileIO.close();
}

int LocalFile::write(char *data, int length)
{
	return this->fileIO.send_n(data, length);
}

int LocalFile::read(char *data, int length)
{
	return this->fileIO.recv(data, length);
}

void LocalFile::cacheFileName(const char *fileName)
{
	int len = strlen(fileName);
	this->pureFileName = "";
	for(int ix = len - 1; ix >= 0; ix--)
	{
		if('\\' == fileName[ix])
		{
			break;
		}
		else
		{
			this->pureFileName.insert(0, fileName[ix]);
		}
	}
}
