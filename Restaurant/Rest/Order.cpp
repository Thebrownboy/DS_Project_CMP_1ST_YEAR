#include "Order.h"

void Order::setID(int i)
{
	ID = i;
}

Order::Order(int id, ORD_TYPE r_Type, REGION r_region,int distance  ,double money  ,int Arr_time  )
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	Region = r_region;	
	if (r_Type == 2) //added by abdalla mahmoud 
	{
		Priorty = (int(4 * (((distance*ArrTime*money) / 3) + (((distance + Arr_time + money)*Arr_time*money*distance)) / (money + distance)))) % 100;

	}
	else
		Priorty = 0;// it doesn't matter but I should give the variable  a value 

}



Order::Order()
{
}

Order::~Order()
{
}

int Order::GetID()
{
	return ID;
}


int Order::GetType() const
{
	return type;
}

REGION Order::GetRegion() const
{
	return Region;
}

void Order::SetDistance(int d)
{
	Distance = d>0?d:0;
}

int Order::GetDistance() const
{
	return Distance;
}

void Order::Set_Type(ORD_TYPE Type )
{
	this->type = Type;
}

bool Order::operator<(Order & ord)const 
{
	return this->Priorty<ord.Priorty;
}

bool Order::operator>(Order & ord)const 
{
	return this->Priorty >ord.Priorty;
}

bool Order::operator==(Order & ord)const 
{
	return (this->ID == ord.ID);
}
