#include "Region.h"
#include<fstream>
#include"Restaurant.h"
Region::Region()
{
	NumNormOrd = NumFrozOrd = NumVIPOrd = 0;
	FixNumNormOrd = FixNumFrozOrd = FixNumVIPOrd = 0;

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
	FixNumVIPOrd++;
	
}

void Region::insert_frozorder(Order  *ord)
{
	FrozOr.enqueue(ord);
	this->NumFrozOrd++;
	FixNumFrozOrd++; 
	
}

void Region::insert_norm(Order * ord)
{
	NormOr.Insert(ord);
	this->NumNormOrd++;
	FixNumNormOrd++; 
}

bool Region::deleteoreder(int ID)
{
	Order *dum=new Order();
	dum->setID(ID);
	if (NormOr.Delete(dum)) {
		NumNormOrd--;
		FixNumNormOrd--; 
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

void Region::AssignNorm(int currTS, string & a, Restaurant * REst )
{
	while (!NormMoto.Is_Empty() && !NormOr.is_empty() ) {
		Order* Ord;
		NormOr.get_first(Ord);
		Motorcycle* Moto = NormMoto.Peek();
		int WaitTime = currTS - Ord->getArrivalTime();
		Wating_time += WaitTime;
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		Service_time += ServTime;
		int FinTime = currTS + ServTime;
		Ord->set_finish_time(FinTime);
		Ord->set_sercive_time(ServTime); 
		Ord->set_Waiting_time(WaitTime); 
		REst->Add_Delivered_Order(Ord);
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
		Wating_time += WaitTime;
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		Service_time += ServTime;
		int FinTime = currTS + ServTime;
		Ord->set_finish_time(FinTime);
		Ord->set_sercive_time(ServTime);
		Ord->set_Waiting_time(WaitTime);
		REst->Add_Delivered_Order(Ord);
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

void Region::AssignVIP(int currTS, string & a, Restaurant *  REst)
{
	while (!VIPMoto.Is_Empty() && !VipOr.Is_Empty()) {
		Order* Ord;
		Ord = VipOr.Peek(); 
		
		// here I have to options , I can create a new order and delete it in the output function , or don't create a new one and don't delete it in 
		// the function and  it will be deleted when the destructor of the list called 
		///abdalla mahmoud 
		Motorcycle* Moto = VIPMoto.Peek();// it was written norm moto 
		int WaitTime = currTS - Ord->getArrivalTime();
		Wating_time += WaitTime;
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		Service_time += ServTime;
		int FinTime = currTS + ServTime;
		Ord->set_finish_time(FinTime);
		Ord->set_sercive_time(ServTime);
		Ord->set_Waiting_time(WaitTime);
		REst->Add_Delivered_Order(Ord);
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
		char MotoID[4];
		Motorcycle* Moto = NormMoto.Peek();// it was written Vip moto 
		int WaitTime = currTS - Ord->getArrivalTime();
		Wating_time += WaitTime;
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		Service_time += ServTime;
		int FinTime = currTS + ServTime;
		Ord->set_finish_time(FinTime);
		Ord->set_sercive_time(ServTime);
		Ord->set_Waiting_time(WaitTime);
		REst->Add_Delivered_Order(Ord);
		Moto->Set_ReturnTS(FinTime + ServTime);
		NormMoto.Dequeue();
		UnavailableMoto.Insert(Moto);
		this->NumVIPOrd--;
		this->NumNormMoto--;
		//data for printing
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
		Wating_time += WaitTime;
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		Service_time += ServTime;
		int FinTime = currTS + ServTime;
		Ord->set_finish_time(FinTime);
		Ord->set_sercive_time(ServTime);
		Ord->set_Waiting_time(WaitTime);
		REst->Add_Delivered_Order(Ord);
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

void Region::AssignFroz(int currTS, string & a, Restaurant * REst )
{
	while (!FrozOr.isEmpty() && !FrozMoto.Is_Empty()) {
		Order* Ord;
		FrozOr.dequeue(Ord);
		Motorcycle* Moto = FrozMoto.Peek();
		int WaitTime = currTS - Ord->getArrivalTime();
		Wating_time += WaitTime; 
		int ServTime = Ord->GetDistance() / Moto->Get_speed() + 1;
		Service_time += ServTime; 
		int FinTime = currTS + ServTime;
		Ord->set_finish_time(FinTime); 
		Ord->set_sercive_time(ServTime);
		Ord->set_Waiting_time(WaitTime);
		REst->Add_Delivered_Order(Ord);
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

void Region::print(ofstream & output_file)
{
	output_file << "Orders : " << FixNumFrozOrd + FixNumNormOrd + FixNumVIPOrd << "["
		<< "Norm:" << FixNumNormOrd << ", Froz:" << FixNumFrozOrd << ", VIP:" << FixNumVIPOrd << "]"
		<< endl << "MotorC:" << NumFrozMoto + NumNormMoto + NumVIPMoto << "["
		<< "Norm:" << NumNormMoto << ", Froz" << NumFrozMoto << ", VIP: " << NumVIPMoto << "]"
		<< endl << "Avg Wait =" << Wating_time/(this->FixNumNormOrd+this->FixNumFrozOrd+this->FixNumVIPOrd) << ", Avg Serv = " 
		<< Service_time/(this->FixNumNormOrd + this->FixNumFrozOrd + this->FixNumVIPOrd) << endl;
}
Region::~Region()
{
}
