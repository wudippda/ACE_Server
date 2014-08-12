#pragma once
#include "StdAfx.h"
#include <random>
#include <math.h>

static class UTIL
{
public:
	static ACE_UINT16 getRandomUINT16(ACE_UINT16 range_min,ACE_UINT16 range_max)
	{
		srand((unsigned)time(NULL));
		return rand() % (range_max - range_min) + range_min;
	}

	static int getRandomInt(ACE_UINT16 range_min,ACE_UINT16 range_max)
	{
		srand((unsigned)time(NULL));
		return rand() % (range_max - range_min) + range_min;
	}

	static ACE_UINT16 PowUINT16(ACE_UINT16 x,int pow)
	{
		ACE_UINT16 tmp = x;
		for(int ix = 0;ix != pow;ix++)
			tmp *= tmp;
		return tmp;
	}
};