#include "Motorcycle.h"

  



Motorcycle::Motorcycle(int ID , ORD_TYPE Type , int speed,REGION  Region)
{
	this->ID = ID;
	this->type = Type;
	this->speed = speed;
	this->region = Region;
	status = IDLE;
	returnTS = 0;
}

Motorcycle::~Motorcycle()
{
}

int Motorcycle::GetID()
{
	return ID;
}

ORD_TYPE  Motorcycle::GetORD_Type()
{
	return type;
}

int Motorcycle::Get_speed()
{
	return speed;
}

REGION Motorcycle::Get_Region()
{
	return region;
}

STATUS Motorcycle::Get_Staus()
{
	return status;
}

void Motorcycle::Set_Status(STATUS status )
{
	this->status = status;
}

void Motorcycle::Set_Speed(int speed )
{ 
	this->speed = speed;
}

void Motorcycle::Set_ReturnTS(int r)
{
	this->returnTS = r;
}

int Motorcycle::Get_ReturnTS()
{
	return this->returnTS;
}

Motorcycle::Motorcycle()
{
	status = IDLE;
}

void Motorcycle::Set_ID(int id)
{
	ID = id;
}

void Motorcycle::Set_Type(ORD_TYPE type)
{
	this->type = type;
}

void Motorcycle::AddDist(int d)
{
	totDistace += d;
}

int Motorcycle::Get_totDist()
{
	return totDistace;
}

bool Motorcycle::operator >(Motorcycle & M)const 
{
	if (speed > M.Get_speed())
		return true;
	else
		return false;
	
}

bool Motorcycle::operator<(Motorcycle & Mo)const 
{
	if (speed < Mo.Get_speed())
		return true;
	else
		return false;
}

bool Motorcycle::operator==(Motorcycle & Mo)const 
{
	if (this->returnTS == Mo.Get_ReturnTS() )
		return true;
	else
		return false;
}

void Motorcycle::inc_numDelOrds()
{
	numDeliveredOrds++;
}

int Motorcycle::Get_numDelOrds()
{
	return numDeliveredOrds;
}
