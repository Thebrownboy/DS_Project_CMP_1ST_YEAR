#include "Region.h"



Region::Region()
{
	NumNormOrd = NumFrozOrd = NumVIPOrd = 0;
}

void Region::Set_motors(int NumN, int NumF, int NumVIP, Motorcycle ** Norm, Motorcycle ** FROZ, Motorcycle ** VIP)
{
	NumVIPMoto = NumVIP;
	NumFrozMoto = NumF;
	NumNormMoto = NumN;
	
	for (int  i = 0; i < NumVIP; i++)
	{
		VIPMoto.Enqueue(*VIP[i]);
	}

	for (int i = 0; i < NumF; i++)
	{
		FrozMoto.Enqueue(*FROZ[i]);
	}

	for (int i = 0; i < NumN; i++)
	{
		NormMoto.Enqueue(*Norm[i]);
	}

}

void Region::insert_viporder(Order * ord)
{
	VipOr.Enqueue(ord);
	this->NumVIPOrd++;
	
}

void Region::insert_frozorder(Order  *ord)
{
	FrozOr.enqueue(ord);
	this->NumFrozOrd++;
	
}

void Region::insert_norm(Order * ord)
{
	NormOr.Insert(ord);
	this->NumNormOrd++;
}

bool Region::deleteoreder(int ID)
{
	Order *dum=new Order();
	dum->setID(ID);
	return NormOr.Delete(dum);
}

PriorityQueue<Order*> Region::getViPords()
{
	return VipOr;
}

Queue<Order*> Region::getFrzOrds()
{
	return FrozOr;
}

List<Order*> Region::getNormOrds()
{
	return  NormOr;
}

bool Region::PickOrd(Order* & Or)
{
	return this->NormOr.Pick(Or);
}


void Region::Delete_from_each_one()
{
	AssignFroz();
	AssignNorm();
	AssignVIP();
}

bool Region::AssignNorm()
{
	if (NumNormOrd == 0) return 0;
	Order * top;
	this->NormOr.get_first(top);
	NumNormOrd--;
	this->NormOr.Delete(top);
	return true;
}

bool Region::AssignVIP()
{
	if (NumVIPOrd==0)
		return false;
	VipOr.Dequeue();
	NumVIPOrd--;
	return true;
}

bool Region::AssignFroz()
{
	if (NumFrozOrd == 0) return 0;
	Order * ord;
	this->FrozOr.peekFront(ord);
	FrozOr.dequeue(ord);
	NumFrozOrd--;
	return true;

}

int Region::getNVM()
{
	return this->NumVIPMoto;
}

int Region::getNFM()
{
	return this->NumFrozMoto;
}

int Region::getNNM()
{
	return this->NumNormMoto;
}

int Region::getNNO()
{
	return this->NumNormOrd;
}

int Region::getNVO()
{
	return this->NumVIPOrd;
}

int Region::getNFO()
{
	return this->NumFrozOrd;
}

Region::~Region()
{
}
