#pragma once
#include "StdAfx.h"
#include "Map.h"

Map::Map(int mapX = MAP_X,int mapY = MAP_Y,int block_size = BLOCK_BORDER)
{
	int rol = mapY / block_size;
	int col = mapX / block_size;
	int block_count = rol * col;

	for(int ix = 0;ix != rol;ix++)
	{
		for(int iy = 0;iy != col;iy++)
		{
			this->addBlock(Block(ix * block_size,iy * block_size));
		}
	}

	this->col = col;
	this->rol = rol;
	this->block_size = block_size;
}