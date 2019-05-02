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
		VIPMoto.Enqueue(VIP[i]);
	}

	for (int i = 0; i < NumF; i++)
	{
		FrozMoto.Enqueue(FROZ[i]);
	}

	for (int i = 0; i < NumN; i++)
	{
		NormMoto.Enqueue(Norm[i]);
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
	if (NormOr.Delete(dum)) {
		NumNormOrd--;
		return true;
	}
	return false;
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





void Region::returnAvailMoto(int currTS)
{
	Motorcycle* Moto=new Motorcycle;
	Moto->Set_ReturnTS(currTS);
	while (UnavailableMoto.Pick( Moto)) {
		switch (Moto->GetORD_Type()) {
		case (0):
			this->NormMoto.Enqueue(Moto);
			this->NumNormMoto++;
			break;
		case(1):
			this->FrozMoto.Enqueue(Moto);
			this->NumFrozMoto++;
			break;
		case(2):
			this->VIPMoto.Enqueue(Moto);
			this->NumVIPMoto++;
		}
	}

}

void Region::AssignNorm(int currTS, string & a)
{
	while (!NormMoto.Is_Empty() && !NormOr.is_empty() ) {
		Order* Ord;
		NormOr.get_first(Ord);
		Motorcycle* Moto = NormMoto.Peek();
		int WaitTime = currTS - Ord->getArrivalTime();
		int ServTime = Ord->GetDistance() /Moto->Get_speed() + 1;
		int FinTime = currTS + ServTime;
		Moto->Set_ReturnTS(FinTime + ServTime);
		NormMoto.Dequeue();
		//data for printing
		UnavailableMoto.Insert(Moto);
		this->NormOr.Delete(Ord);
		this->NumNormMoto--;
		this->NumNormOrd--;
		char MotoID[4];
		itoa(Moto->GetID(), MotoID, 10);
		char OrdID[4];
		itoa(Ord->GetID(), OrdID, 10);
		string OrdType = "N";
		string MotoType = "N";
		a.append(MotoType);
		a.append(MotoID);
		a.append("(");
		a.append(OrdType);
		a.append(OrdID);
		a.append(")");
		a.append(" ");
		
		
		//print out in output file
		
	}
	while (!VIPMoto.Is_Empty() && !NormOr.is_empty()) {
		Order* Ord;
		NormOr.get_first(Ord);
		Motorcycle* Moto = VIPMoto.Peek();
		int WaitTime = currTS - Ord->getArrivalTime();
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		int FinTime = currTS + ServTime;
		Moto->Set_ReturnTS(FinTime + ServTime);
		VIPMoto.Dequeue();
		UnavailableMoto.Insert(Moto);
		this->NumNormOrd--;
		this->NumVIPMoto--;
		NormOr.Delete(Ord);
		//data for printing
		char MotoID[4];
		itoa(Moto->GetID(), MotoID, 10);
		char OrdID[4];
		itoa(Ord->GetID(), OrdID, 10);
		string OrdType = "N";
		string MotoType = "N";
		a.append(MotoType);
		a.append(MotoID);
		a.append("(");
		a.append(OrdType);
		a.append(OrdID);
		a.append(")");
		a.append(" ");
		//print out in output file
		
	}
	
}

void Region::AssignVIP(int currTS, string & a)
{
	while (!VIPMoto.Is_Empty() && !VipOr.Is_Empty()) {
		Order* Ord;
		Ord=VipOr.Peek();
		Motorcycle* Moto = NormMoto.Peek();
		int WaitTime = currTS - Ord->getArrivalTime();
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		int FinTime = currTS + ServTime;
		Moto->Set_ReturnTS(FinTime + ServTime);
		VIPMoto.Dequeue();
		UnavailableMoto.Insert(Moto);
		this->NumVIPOrd--;
		this->NumVIPMoto--;
		//data for printing
		char MotoID[4];
		itoa(Moto->GetID(),MotoID,10);
		char OrdID[4];
		itoa(Ord->GetID(), OrdID, 10);
		string OrdType = "V";
		string MotoType = "V";
		a.append(MotoType);
		a.append(MotoID);
		a.append("(");
		a.append(OrdType);
		a.append(OrdID);
		a.append(")");
		a.append(" ");
		VipOr.Dequeue();
		//print out in output file
	}
	while (!NormMoto.Is_Empty() && !VipOr.Is_Empty()) {
		Order* Ord;
		Ord = VipOr.Peek();
		Motorcycle* Moto = VIPMoto.Peek();
		int WaitTime = currTS - Ord->getArrivalTime();
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		int FinTime = currTS + ServTime;
		Moto->Set_ReturnTS(FinTime + ServTime);
		NormMoto.Dequeue();
		UnavailableMoto.Insert(Moto);
		this->NumVIPOrd--;
		this->NumNormMoto--;
		//data for printing
		char MotoID[4];
		itoa(Moto->GetID(), MotoID, 10);
		char OrdID[4];
		itoa(Ord->GetID(), OrdID, 10);
		string OrdType = "V";
		string MotoType = "N";
		a.append(MotoType);
		a.append(MotoID);
		a.append("(");
		a.append(OrdType);
		a.append(OrdID);
		a.append(")");
		a.append(" ");
		VipOr.Dequeue();
		//print out in output file
	}
	while (!FrozMoto.Is_Empty() && !VipOr.Is_Empty()) {
		Order* Ord;
		Ord = VipOr.Peek();
		Motorcycle* Moto = FrozMoto.Peek();
		int WaitTime = currTS - Ord->getArrivalTime();
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		int FinTime = currTS + ServTime;
		Moto->Set_ReturnTS(FinTime + ServTime);
		FrozMoto.Dequeue();
		UnavailableMoto.Insert(Moto);
		this->NumVIPOrd--;
		this->NumFrozMoto--;
		//data for printing
		char MotoID[4];
		itoa(Moto->GetID(), MotoID, 10);
		char OrdID[4];
		itoa(Ord->GetID(), OrdID, 10);
		string OrdType = "V";
		string MotoType = "F";
		a.append(MotoType);
		a.append(MotoID);
		a.append("(");
		a.append(OrdType);
		a.append(OrdID);
		a.append(")");
		a.append(" ");
		VipOr.Dequeue();
		//print out in output file
	}

}

void Region::AssignFroz(int currTS, string & a)
{
	while (!FrozOr.isEmpty() && !FrozMoto.Is_Empty()) {
		Order* Ord;
		FrozOr.dequeue(Ord);
		Motorcycle* Moto = FrozMoto.Peek();
		int WaitTime = currTS - Ord->getArrivalTime();
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		int FinTime = currTS + ServTime;
		Moto->Set_ReturnTS(FinTime + ServTime);
		FrozMoto.Dequeue();
		UnavailableMoto.Insert(Moto);
		this->NumFrozOrd--;
		this->NumFrozMoto--;
		//data for printing
		char MotoID[4];
		itoa(Moto->GetID(), MotoID, 10);
		char OrdID[4];
		itoa(Ord->GetID(), OrdID, 10);
		string OrdType = "F";
		string MotoType = "F";
		a.append(MotoType);
		a.append(MotoID);
		a.append("(");
		a.append(OrdType);
		a.append(OrdID);
		a.append(")");
		a.append(" ");
		//print out in output file
		
	}

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

void Region::incVIPords()
{
	NumVIPOrd++;
}

void Region::decNormOrds()
{
	NumNormOrd--;
}

Region::~Region()
{
}
