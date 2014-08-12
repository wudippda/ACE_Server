#pragma once
#include "StdAfx.h"
#include "Scene.h"
#include "Map.h"

class SceneManager
{
public:

	SceneManager();
	~SceneManager();

	static SceneManager* getInstance()
	{
		if(SMsingleton == NULL)
		{
			static SceneManager instance;
			SMsingleton = &instance;
		}
		return SMsingleton;
	}

	void createDebugMap();
	void check4Scene(ACE_UINT16 x,ACE_UINT16 y,ACE_UINT16 radius);

private:

	static SceneManager* SMsingleton;
	Map* map;
};