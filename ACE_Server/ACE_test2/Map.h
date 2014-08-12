#pragma once
#include "StdAfx.h"
#include <vector>
#include "Block.h"

#define MAP_X 1000
#define MAP_Y 1000

#define MIN_MAP_X 50
#define MAX_MAP_X 950

#define MIN_MAP_Y 50
#define MAX_MAP_Y 950

#define DEFAULT_AOI_RADIUS 10

class Map
{
public:

	Map(int mapX,int mapY,int block_size);
	~Map();
	void addBlock(Block b){this->Blocks.push_back(b);}

	std::vector<Block> Blocks;
	int block_size;
	int col;
	int rol;
};