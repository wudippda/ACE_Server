#pragma once
#include "StdAfx.h"
#include "MessageDispatcher.h"

MessageDispatcher::MessageDispatcher()
{
	;
}

MessageDispatcher::~MessageDispatcher()
{
	if(this->mb != NULL)
		delete mb;
}