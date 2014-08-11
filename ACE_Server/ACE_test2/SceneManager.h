#pragma once
#include "StdAfx.h"
#include "Scene.h"
#include "Map.h"

class SceneManager
{
public:

	static SceneManager* getInstance()
	{
		if(SMsingleton == NULL)
		{
			static SceneManager instance;
			SMsingleton = &instance;
		}
		return SMsingleton;
	}

private:

	static SceneManager* SMsingleton;
};