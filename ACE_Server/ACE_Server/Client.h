#pragma once
#include "stdafx.h"  
#include "ACE_headers.h"

class Ability
{
public:

	double bandwidth;
	double cache_fill_ratio;
	int hop_to_super_peer;
};

class SimpleNeighborList
{
public:

	SimpleNeighborList* next;
	int num;
};

class Client
{
public:

	Client(ACE_INET_Addr address,int x,int y,int AOI)
	{
		addr = address;
		client_x = x;
		client_y = y;
		AOI_radius = AOI;
		head.next = NULL;
	}

	void setClientPos(int x,int y)
	{
		this->xPos = x;
		this->yPos = y;
	}

	void setNum(int num)
	{
		this->num = num;
		head.num = this->num;
	}

	//void setSpeed(int speed){this->client_speed = speed;}
	void updataCacheRatioInfo(double ratio){this->ability.cache_fill_ratio = ratio;}
	void updataBandwidthInfo(double bandwidth){this->ability.bandwidth = bandwidth;}
	void updataHopInfo(int hop){this->ability.hop_to_super_peer = hop;}

	Ability getAbility(){return this->ability;}

	ACE_INET_Addr addr;

	int client_x,client_y;
	int xPos,yPos;
	int num;
	int AOI_radius;
	Ability ability;
	SimpleNeighborList head;
};