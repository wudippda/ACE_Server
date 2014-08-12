#pragma once
#include "StdAfx.h"
#include "SceneManager.h"
#include "Util.h"

#define TEST_SCENE_DATA_PATH "test_scene"

SceneManager::SceneManager()
{
	;
}

SceneManager::~SceneManager()
{
	;
}

void SceneManager::createDebugMap()
{
	this->map = new Map(MAP_X,MAP_Y,BLOCK_BORDER);

	//random SceneNum between block_num ~ block_num * 2
	int randomSceneNum = UTIL::getRandomInt(map->block_size,map->block_size * 2);
	for(int ix = 0;ix != randomSceneNum;ix++)
	{
		Scene scene(TEST_SCENE_DATA_PATH);
		ACE_UINT16 block_x = map->Blocks[ix % map->block_size].getX();
		ACE_UINT16 block_y = map->Blocks[ix % map->block_size].getY();

		scene.setPos(UTIL::getRandomUINT16(block_x,block_x + BLOCK_BORDER),UTIL::getRandomUINT16(block_y,block_y + BLOCK_BORDER));
		map->Blocks[ix % map->block_size].addScene(scene);
	}
}

void SceneManager::check4Scene(ACE_UINT16 x,ACE_UINT16 y,ACE_UINT16 radius)
{
	for(int ix = 0;ix != map->block_size;ix++)
	{
		for(int iy = 0;iy != map->Blocks[ix].scenes.size();iy++)
		{
			if(UTIL::PowUINT16(x - map->Blocks[ix].scenes[iy].getX(),2) + UTIL::PowUINT16(y - map->Blocks[ix].scenes[iy].getY(),2) <= radius * radius)
			{
				//Do something to handle data
				;
			}
		}
	}
}