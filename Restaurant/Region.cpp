#include "Region.h"



Region::Region()
{
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

void Region::insert_viporder(Order &ord)
{
	VipOr.Enqueue(ord);
}

void Region::insert_frozorder(Order & ord)
{
	FrozOr.enqueue(ord);
	
}

void Region::insert_norm(Order & ord)
{
	NormOr.Insert(ord);
}


Region::~Region()
{
}
