#pragma once
#include "StdAfx.h"
#include "MessageConstructor.h"

ACE_Message_Block* MessageConstructor::createConnectionAck(ACE_UINT16 xPos,ACE_UINT16 yPos,ACE_UINT16 radius)
{
	cdrOut << ACE_CDR::UShort(COM::CONNECTION_ACK);
	this->writeAddressInfo();
	this->writeTimeStamp();
	cdrOut << ACE_CDR::UShort(xPos);
	cdrOut << ACE_CDR::UShort(yPos);
	cdrOut << ACE_CDR::UShort(radius);
	this->mb = cdrOut.begin()->duplicate();
	return mb;
}

//ACE_Message_Block* Message_Constructor::createConnectionAck(bool verified)
//{
//	cdrOut << ACE_CDR::UShort(COM::CONNECTION_ACK);
//	this->writeAddressInfo();
//	this->writeTimeStamp();
//	cdrOut << ACE_CDR::Boolean(verified);
//	ACE_Message_Block* mb = cdrOut.begin()->duplicate();
//	return mb;
//}
//
//ACE_Message_Block* Message_Constructor::createConnectionAck(bool verified)
//{
//	cdrOut << ACE_CDR::UShort(COM::CONNECTION_ACK);
//	this->writeAddressInfo();
//	this->writeTimeStamp();
//	cdrOut << ACE_CDR::Boolean(verified);
//	ACE_Message_Block* mb = cdrOut.begin()->duplicate();
//	return mb;
//}
//
//ACE_Message_Block* Message_Constructor::createConnectionAck(bool verified)
//{
//	cdrOut << ACE_CDR::UShort(COM::CONNECTION_ACK);
//	this->writeAddressInfo();
//	this->writeTimeStamp();
//	cdrOut << ACE_CDR::Boolean(verified);
//	ACE_Message_Block* mb = cdrOut.begin()->duplicate();
//	return mb;
//}
//
//ACE_Message_Block* Message_Constructor::createConnectionAck(bool verified)
//{
//	cdrOut << ACE_CDR::UShort(COM::CONNECTION_ACK);
//	this->writeAddressInfo();
//	this->writeTimeStamp();
//	cdrOut << ACE_CDR::Boolean(verified);
//	ACE_Message_Block* mb = cdrOut.begin()->duplicate();
//	return mb;
//}
