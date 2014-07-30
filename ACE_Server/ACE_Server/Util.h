#pragma once
#include "StdAfx.h"
#include <random>
#include <math.h>

static class UTIL
{
public:
	static ACE_UINT16 getRandomInt(ACE_UINT16 range_min,ACE_UINT16 range_max)
	{
		srand((unsigned)time(NULL));
		return rand() % (range_max - range_min) + range_min;
	}
};