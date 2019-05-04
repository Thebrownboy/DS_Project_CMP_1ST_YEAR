#include"Table.h"

Table::Table()
{
}

Table::Table(int ID, ORD_TYPE Type, REGION Region)
{
	this->ID = ID;
	this->type = Type;
	this->region = Region;
	status = IDLE;
	this->Return_time = 0;
}


Table::~Table()
{
}

ORD_TYPE Table::GetORD_Type()
{
	return type;
}

REGION Table::Get_Region()
{
	return region;
}

STATUS Table::Get_Staus()
{
	return status;
}

void Table::Set_Status(STATUS status)
{
	this->status = status;
}

void Table::Set_ReturnTS(int ReTs)
{
	this->Return_time = ReTs; 
}

int Table::Get_ReturnTS()
{
	return this->Return_time;
}

void Table::Set_ID(int id)
{
	this->ID = id;
}

void Table::Set_Type(ORD_TYPE type)
{
	this->type = type;
}

void Table::set_returing_time(int returing_time)
{
	this->returing_time = returing_time; 
}

int Table::get_returing_time()
{
	return this->returing_time;
}
