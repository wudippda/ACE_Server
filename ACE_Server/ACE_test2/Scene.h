#pragma once
#include "StdAfx.h"
#include "LocalFile.h"

#define SCENE_FILE_POSTFIX ".json"
#define FILE_INDEX "..//Scene//"

class Scene
{
private:

	ACE_UINT16 xPos,yPos;
	char* scenceFileName;
};