#include "Motorcycle.h"

  



Motorcycle::Motorcycle(int ID , ORD_TYPE Type , int speed,REGION  Region)
{
	this->ID = ID;
	this->type = Type;
	this->speed = speed;
	this->region = Region;
	status = IDLE;
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
	if (speed == Mo.Get_speed())
		return true;
	else
		return false;
}
