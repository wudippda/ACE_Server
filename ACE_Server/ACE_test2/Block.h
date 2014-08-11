#pragma once
#include "Map.h"
#include "Scene.h"

#define BLOCK_BORDER 50

class Block
{
public:

	Block(ACE_UINT16 x,ACE_UINT16 y)
	{
		this->xPos = x;
		this->yPos = y;
	};

private:

	ACE_UINT16 xPos,yPos;
	std::vector<Scene> scenes;
};