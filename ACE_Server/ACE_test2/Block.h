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

	void addScene(Scene s){this->scenes.push_back(s);}
	ACE_UINT16 getX(){return this->xPos;}
	ACE_UINT16 getY(){return this->yPos;}

	std::vector<Scene> scenes;

private:

	ACE_UINT16 xPos,yPos;
};