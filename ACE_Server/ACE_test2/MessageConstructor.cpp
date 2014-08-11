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

ACE_Message_Block* MessageConstructor::createMoveSuccessMessage()
{
	cdrOut << ACE_CDR::UShort(COM::MOVE_SUCCESS_ACK);
	this->writeAddressInfo();
	this->writeTimeStamp();
	this->mb = cdrOut.begin()->duplicate();
	return mb;
}

ACE_Message_Block* MessageConstructor::createUpdataNeighborMessage(std::vector<ACE_UINT32> neighbor)
{
	cdrOut << ACE_CDR::UShort(COM::UPDATA_NEIGHBOUR);
	this->writeAddressInfo();
	this->writeTimeStamp();
	cdrOut << ACE_CDR::UShort(neighbor.size());
	for(int ix = 0;ix != neighbor.size();ix++)
	{
		cdrOut << ACE_CDR::ULong(neighbor[ix]);
	}
	this->mb = cdrOut.begin()->duplicate();
	return mb;
}
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
