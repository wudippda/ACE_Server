#pragma once
#include "StdAfx.h"
#include "LocalFile.h"

#define SCENE_FILE_POSTFIX ".json"
#define FILE_INDEX "..//Scene//"

class Scene
{
public:

	Scene(char* path)
	{
		this->scenceFileName = path;
	}

	void setPos(ACE_UINT16 x,ACE_UINT16 y){this->xPos = x;this->yPos = y;}
	ACE_UINT16 getX(){return this->xPos;}
	ACE_UINT16 getY(){return this->yPos;}

private:

	ACE_UINT16 xPos,yPos;
	char* scenceFileName;
};