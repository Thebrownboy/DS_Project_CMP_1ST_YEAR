#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"

#include "..\Events\CancellationEvent.h"
#include "..\Events\PromotionEvent.h"


int num_of_digits(int x) 
{
	if (x == 0)
		return 1;
	int num = 0;
	while (x != 0) 
	{
		x /= 10;
		num++; 
	}
	return num; 

}
Restaurant::Restaurant() 
{
	pGUI = NULL;
}

void Restaurant::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
		
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		interactive_mode();
		break;
	case MODE_STEP:
		
		break;
	case MODE_SLNT:
		
		break;
		

	};

}

void Restaurant::PrintInfo(int cts )
{
	char timestep[10];
	itoa(cts, timestep, 10);
	string hg = "                                             Motorcycles                        Orders  ";
	string hs = "                                             V    N    F                        V    N    F  ";
	string st = "Time step : ";
	st.append(timestep);
	string sA = "Reg A                                   ";
	string sB = "Reg B                                   ";
	string sC = "Reg C                                   ";
	string sD = "Reg D                                   ";

	string sp1 = "    ";
	string sp2 = "                         ";
	char nVm[4], nNm[4], nFm[4], nNo[4], nFo[4], nVo[4];
	for (int i = 0; i < 4; ++i) {
		switch (i) {
		case 0:
			itoa(this->Get_region(i)->getNVM(), nVm, 10);
			sA.append(nVm);
			sA.append(sp1);
			itoa(this->Get_region(i)->getNNM(), nNm, 10);
			sA.append(nNm);
			sA.append(sp1);
			itoa(this->Get_region(i)->getNFM(), nFm, 10);
			sA.append(nFm);
			break;
		case 1:
			itoa(this->Get_region(i)->getNVM(), nVm, 10);
			sB.append(nVm);
			sB.append(sp1);
			itoa(this->Get_region(i)->getNNM(), nNm, 10);
			sB.append(nNm);
			sB.append(sp1);
			itoa(this->Get_region(i)->getNFM(), nFm, 10);
			sB.append(nFm);
			break;
		case 2:
			itoa(this->Get_region(i)->getNVM(), nVm, 10);
			sC.append(nVm);
			sC.append(sp1);
			itoa(this->Get_region(i)->getNNM(), nNm, 10);
			sC.append(nNm);
			sC.append(sp1);
			itoa(this->Get_region(i)->getNFM(), nFm, 10);
			sC.append(nFm);
			break;
		default:
			itoa(this->Get_region(i)->getNVM(), nVm, 10);
			sD.append(nVm);
			sD.append(sp1);
			itoa(this->Get_region(i)->getNNM(), nNm, 10);
			sD.append(nNm);
			sD.append(sp1);
			itoa(this->Get_region(i)->getNFM(), nFm, 10);
			sD.append(nFm);
			break;
		}
	}
	sA.append(sp2);
		sB.append(sp2);
		sC.append(sp2);
		sD.append(sp2);
		for (int i = 0; i < 4; ++i) {
			switch (i) {
			case 0:
				itoa(this->Get_region(i)->getNVO(), nVo, 10);
				sA.append(nVo);
				sA.append(sp1);
				itoa(this->Get_region(i)->getNNO(), nNo, 10);
				sA.append(nNo);
				sA.append(sp1);
				itoa(this->Get_region(i)->getNFO(), nFo, 10);
				sA.append(nFo);
				break;
			case 1:
				itoa(this->Get_region(i)->getNVO(), nVo, 10);
				sB.append(nVo);
				sB.append(sp1);
				itoa(this->Get_region(i)->getNNO(), nNo, 10);
				sB.append(nNo);
				sB.append(sp1);
				itoa(this->Get_region(i)->getNFO(), nFo, 10);
				sB.append(nFo);
				break;
			case 2:
				itoa(this->Get_region(i)->getNVO(), nVo, 10);
				sC.append(nVo);
				sC.append(sp1);
				itoa(this->Get_region(i)->getNNO(), nNo, 10);
				sC.append(nNo);
				sC.append(sp1);
				itoa(this->Get_region(i)->getNFO(), nFo, 10);
				sC.append(nFo);
				break;
			default:
				itoa(this->Get_region(i)->getNVO(), nVo, 10);
				sD.append(nVo);
				sD.append(sp1);
				itoa(this->Get_region(i)->getNNO(), nNo, 10);
				sD.append(nNo);
				sD.append(sp1);
				itoa(this->Get_region(i)->getNFO(), nFo, 10);
				sD.append(nFo);

		}
	}
	pGUI->PrintMessage(hg, hs, sA, sB, sC, sD, st);
}




//////////////////////////////////  Event handling functions   /////////////////////////////
void Restaurant::AddEvent(Event* pE)	//adds a new event to the queue of events
{
	EventsQueue.enqueue(pE);
}

//Executes ALL events that should take place at current timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event *pE;
	while( EventsQueue.peekFront(pE) )	//as long as there are more events
	{
		if(pE->getEventTime() > CurrentTimeStep )	//no more events at current time
			return;

		pE->Execute(this);
		EventsQueue.dequeue(pE);	//remove event from the queue
		delete pE;		//deallocate event object from memory//there is an abnormal thing 
		
	}

}


Restaurant::~Restaurant()
{
		delete pGUI;
}




////////////////////////////////////////////////////////////////////////////////
/// ==> 
///  DEMO-related functions. Should be removed in phases 1&2

//This is just a demo function for project introductory phase
//It should be removed starting phase 1
//void Restaurant::Just_A_Demo()
//{
//	
//	//
//	// THIS IS JUST A DEMO FUNCTION
//	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
//	
//	int EventCnt;	
//	Order* pOrd;
//	Event* pEv;
//	srand(time(NULL));
//
//	pGUI->PrintMessage("Just a Demo. Enter EVENTS Count(next phases should read I/P filename):");
//	EventCnt = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer
//
//	pGUI->UpdateInterface();
//
//	pGUI->PrintMessage("Generating orders randomly... In next phases, orders should be loaded from a file");
//		
//	int EvTime = 0;
//	
//	//Create Random events
//	//All generated event will be "ArrivalEvents" for the demo
//	for(int i=0; i<EventCnt; i++)
//	{
//		int O_id = i+1;
//		
//		//Rendomize order type
//		int OType;
//		if(i<EventCnt*0.2)	//let 1st 20% of orders be VIP (just for sake of demo)
//			OType = TYPE_VIP;
//		else if(i<EventCnt*0.5)	
//			OType = TYPE_FROZ;	//let next 30% be Frozen
//		else
//			OType = TYPE_NRM;	//let the rest be normal
//
//		
//		int reg = rand()% REG_CNT;	//randomize region
//
//
//		//Randomize event time
//		EvTime += rand()%4;
//		pEv = new ArrivalEvent(EvTime,O_id,(ORD_TYPE)OType,(REGION)reg);
//		AddEvent(pEv);
//
//	}	
//
//	int CurrentTimeStep = 1;
//	//as long as events queue is not empty yet
//	while(!EventsQueue.isEmpty())
//	{
//		//print current timestep
//		char timestep[10];
//		itoa(CurrentTimeStep,timestep,10);	
//		pGUI->PrintMessage(timestep);
//
//
//		ExecuteEvents(CurrentTimeStep);	//execute all events at current time step
//		//The above line may add new orders to the DEMO_Queue
//
//		//Let's draw all arrived orders by passing them to the GUI to draw
//
//		while(DEMO_Queue.dequeue(pOrd))
//		{
//			pGUI->AddOrderForDrawing(pOrd);
//			pGUI->UpdateInterface();
//		}
//		Sleep(1000);
//		CurrentTimeStep++;	//advance timestep
//	}
//
//
//	pGUI->PrintMessage("generation done, click to END program");
//	pGUI->waitForClick();
//
//	
//}
////////////////





/*   start sir_sayed modification    */
void Restaurant::Load()
{
	ifstream input;
	pGUI->PrintMessage("Enter File Name: ");
	string FileName = pGUI->GetString();
	input.open(FileName + ".txt");

	int SN, SF, SV;  // motorcycles speeds line 
	int NumN, Numf, NumVip;//Num of motorcycle in each region 
	
		/*variables to help in read file*/
	int numEvents;
	char event;
	int TimeStep;
	char type;
	int id;
	int Distance;
	double money;
	double extra_money;
	char Region;
	Motorcycle**VIP;
	Motorcycle**Norm;
	Motorcycle**Froz;
	Event*pEvent;

		if (!input.is_open())
		{
			pGUI->PrintMessage("an error occured while loading try again");
			return;
		}
		input >> SN >> SF >> SV;	// motorcycles speeds line

		for (int i = 0; i < REG_CNT; i++)
		{
			input >> NumN >> Numf >> NumVip;
			VIP = new Motorcycle*[NumVip];
			Norm = new Motorcycle*[NumN];
			Froz = new Motorcycle*[Numf];
			
			for (int j = 1; j <=NumN; j++)
			{
				Norm[j-1] = new Motorcycle;
				Norm[j-1]->Set_ID(j);
				Norm[j-1]->Set_Type(TYPE_NRM);
				Norm[j-1]->Set_Speed(SN);

			}
			for (int k = 1; k <= Numf; k++)
			{
				Froz[k-1] = new Motorcycle;
				Froz[k-1]->Set_ID(k+ NumN);
				Froz[k-1]->Set_Type(TYPE_FROZ);
				Froz[k-1]->Set_Speed(SF);

			}
			for (int l = 1; l <= NumVip; l++)
			{
				VIP[l-1] = new Motorcycle;
				VIP[l-1]->Set_ID(l+ NumN+ Numf);
				VIP[l-1]->Set_Type(TYPE_VIP);
				VIP[l-1]->Set_Speed(SV);

			}
			
			Get_region(i)->Set_motors(NumN, Numf, NumVip, Norm, Froz, VIP);
		}

		input >> AutoPromotionlimit;

		input >> numEvents;
		for (int i = 0; i < numEvents; i++)
		{
			input >> event;

			switch (event)
			{
			case 'R':
			{
				input >> TimeStep >> type >> id >> Distance >> money >> Region;
				pEvent = new ArrivalEvent(TimeStep, type, id, Distance, money, Region);
				AddEvent(pEvent);
				break;// added by ABDALLA 
			}
			case 'X':
			{
				input >> TimeStep >> id;
				pEvent = new CancellationEvent(TimeStep, id);
				AddEvent(pEvent);
				break;// added by ABDALLA 
			}
			case 'P':
			{
				input >> TimeStep >> id >> extra_money;
				pEvent = new PromotionEvent(TimeStep, id, extra_money);
				AddEvent(pEvent);
				break;// added by ABDALLA 
			}
			default:
				{
					pGUI->PrintMessage("you have to revise file format");
					 break; 
				}
	

			}



		}

}

void Restaurant::UpdateMoto(int currTS)
{
	for (int i = 0; i < 4; ++i) {
		Reg[i].returnAvailMoto(currTS);
	}
}

void Restaurant::ProcessOrders(int currTS, string & a, string & b, string & c, string & d)
{
	for (int i = 0; i < 4; ++i) {
		switch (i) {
		case(0):
			this->Get_region(i)->AssignVIP(currTS,a,this);
			this->Get_region(i)->AssignFroz(currTS,a, this);
			this->Get_region(i)->AssignNorm(currTS,a, this);
			break;
		case(1):
			this->Get_region(i)->AssignVIP(currTS,b, this);
			this->Get_region(i)->AssignFroz(currTS,b, this);
			this->Get_region(i)->AssignNorm(currTS,b, this);
			break;
		case(2):
			this->Get_region(i)->AssignVIP(currTS,c, this);
			this->Get_region(i)->AssignFroz(currTS,c, this);
			this->Get_region(i)->AssignNorm(currTS,c, this);
			break;
		case(3):
			this->Get_region(i)->AssignVIP(currTS,d, this);
			this->Get_region(i)->AssignFroz(currTS,d, this);
			this->Get_region(i)->AssignNorm(currTS,d, this);
		}

		
	}
}

Region * Restaurant::Get_region(int i)
{
	return &Reg[i];
}

void Restaurant::interactive_mode()
{
	Load();
	int CurrentTimeStep = 1;
	while (!EventsQueue.isEmpty() || !this->OrdersDone())
	{
		ExecuteEvents(CurrentTimeStep);//execute all events at current time step
		Order* dum;							//Let's draw all arrived orders by passing them to the GUI to draw

 		for (int i = 0; i < 4; ++i) {
			PriorityQueue < Order* > vip = this->Get_region(i)->getViPords();
			while (!vip.Is_Empty()) {
				dum = vip.Peek();
				vip.Dequeue();
				ActiveOrds.enqueue(dum);
			}
			Queue<Order*> frz = this->Get_region(i)->getFrzOrds();
			while (!frz.isEmpty()) {
				frz.dequeue(dum);
				ActiveOrds.enqueue(dum);
			}
			List <Order*> norm = this->Get_region(i)->getNormOrds();
			while (!norm.is_empty())
			{
				norm.get_first(dum);
				ActiveOrds.enqueue(dum);
				norm.Delete(dum); /// back
			}
		}

		while (ActiveOrds.dequeue(dum))
		{
			pGUI->AddOrderForDrawing(dum);
			pGUI->UpdateInterface();
		}
		this->PrintInfo(CurrentTimeStep);

		pGUI->waitForClick();
		pGUI->ResetDrawingList();
		pGUI->UpdateInterface();
		string motoA, motoB, motoC, motoD;
		UpdateMoto(CurrentTimeStep);
		ProcessOrders(CurrentTimeStep,motoA, motoB, motoC, motoD);
		for (int i = 0; i < 4; ++i) {
			PriorityQueue < Order* > vip = this->Get_region(i)->getViPords();
			while (!vip.Is_Empty()) {
				dum = vip.Peek();
				vip.Dequeue();
				ActiveOrds.enqueue(dum);
			}
			Queue<Order*> frz = this->Get_region(i)->getFrzOrds();
			while (!frz.isEmpty()) {
				frz.dequeue(dum);
				ActiveOrds.enqueue(dum);
			}
			List <Order*> norm = this->Get_region(i)->getNormOrds();
			while (!norm.is_empty())
			{
				norm.get_first(dum);
				ActiveOrds.enqueue(dum);
				norm.Delete(dum); /// back
			}
		}

		while (ActiveOrds.dequeue(dum))
		{
			pGUI->AddOrderForDrawing(dum);
			pGUI->UpdateInterface();
		}
		this->PrintInfo(CurrentTimeStep);
		pGUI->waitForClick();
		pGUI->ResetDrawingList();
		CurrentTimeStep++;

	}
	output(); 
}
/*   END sir_sayed modification    */
//void Restaurant::phase_one()
//{
//	Load();
//	///////////////
//	/*Psycho task*/
//	int CurrentTimeStep = 1;
//	//as long as events queue is not empty yet
//	while (!EventsQueue.isEmpty() || !this->OrdersDone() )
//	{
//		ExecuteEvents(CurrentTimeStep);//execute all events at current time step
//
//		
//
//		Order* dum;							//Let's draw all arrived orders by passing them to the GUI to draw
//		
//		for (int i = 0; i < 4; ++i) {
//			PriorityQueue < Order* > vip = this->Get_region(i)->getViPords();
//			while (!vip.Is_Empty()) {
//				dum = vip.Peek();
//				vip.Dequeue();
//				ActiveOrds.enqueue(dum);
//			}
//			Queue<Order*> frz = this->Get_region(i)->getFrzOrds();
//			while (!frz.isEmpty()) {
//				frz.dequeue(dum);
//				ActiveOrds.enqueue(dum);
//			}
//			List <Order*> norm = this->Get_region(i)->getNormOrds();
//			while (!norm.is_empty())
//			{
//				norm.get_first(dum);
//				ActiveOrds.enqueue(dum);
//				norm.Delete(dum); /// back
//			}
//		}
//		
//		while (ActiveOrds.dequeue(dum))
//		{
//			pGUI->AddOrderForDrawing(dum);
//			pGUI->UpdateInterface();
//		}
//		this->PrintInfo(CurrentTimeStep);
//
//		pGUI->waitForClick();
//		pGUI->ResetDrawingList();
//		pGUI->UpdateInterface();
//		for (int i = 0; i < 4; i++) 
//		{
//			this->Get_region(i)->Delete_from_each_one();
//		}
//		for (int i = 0; i < 4; ++i) {
//			PriorityQueue < Order* > vip = this->Get_region(i)->getViPords();
//			while (!vip.Is_Empty()) {
//				dum = vip.Peek();
//				vip.Dequeue();
//				ActiveOrds.enqueue(dum);
//			}
//			Queue<Order*> frz = this->Get_region(i)->getFrzOrds();
//			while (!frz.isEmpty()) {
//				frz.dequeue(dum);
//				ActiveOrds.enqueue(dum);
//			}
//			List <Order*> norm = this->Get_region(i)->getNormOrds();
//			while (!norm.is_empty())
//			{
//				norm.get_first(dum);
//				ActiveOrds.enqueue(dum);
//				norm.Delete(dum); 
//			}
//
//
//		}
//
//		while (ActiveOrds.dequeue(dum))
//		{
//			pGUI->AddOrderForDrawing(dum);
//			pGUI->UpdateInterface();
//		}
//		this->PrintInfo(CurrentTimeStep);
//		pGUI->waitForClick();
//		pGUI->ResetDrawingList();
//		CurrentTimeStep++;	//advance timestep
//	}
//
//}

bool Restaurant::OrdersDone()
{
	for (int i = 0; i < 4; i++) {
		if (!Reg[i].getFrzOrds().isEmpty()) return false;
		if (!Reg[i].getNormOrds().is_empty()) return false;
		if (!Reg[i].getViPords().Is_Empty()) return false;
	}
	return true;
}
void Restaurant::output()
{
	ofstream output_file;
	output_file.open("output_file.txt");
	output_file << "ID     FT     AT     WT     ST     Type" << endl;
	short int index;
	short int i = 0;
	 while( i < Num_of_Deliverd_Orders)
	 {
		 i = 0;
		while (i < Num_of_Deliverd_Orders&&DeliveredOrders[i] == NULL) 
		{
			i++;
		}
		index = i;
		for (short int j = i + 1;j < Num_of_Deliverd_Orders - 1; j++)
		{
			if (DeliveredOrders[j] != NULL && DeliveredOrders[j]->Get_finish_time() < DeliveredOrders[index]->Get_finish_time())
				index = j;
		}
		// here I won't swap any thing I will print the order's data then I will delete it 
		if (DeliveredOrders[index] != NULL&& i < Num_of_Deliverd_Orders)
		{
			output_file << DeliveredOrders[index]->GetID();
			int num = num_of_digits(DeliveredOrders[index]->GetID());
			if (num == 1)
				output_file << "      ";
			else if (num == 2)
				output_file << "     ";
			else if (num == 3)
				output_file << "    ";
			else if (num == 4)
				output_file << "    ";
			output_file << DeliveredOrders[index]->Get_finish_time();
			num = num_of_digits(DeliveredOrders[index]->Get_finish_time());
			if (num == 1)
				output_file << "      ";
			else if (num == 2)
				output_file << "     ";
			else if (num == 3)
				output_file << "    ";
			else if (num == 4)
				output_file << "    ";
			output_file << DeliveredOrders[index]->Get_Arrival_time();
			num = num_of_digits(DeliveredOrders[index]->Get_Arrival_time());
			if (num == 1)
				output_file << "      ";
			else if (num == 2)
				output_file << "     ";
			else if (num == 3)
				output_file << "    ";
			else if (num == 4)
				output_file << "    ";
			output_file << DeliveredOrders[index]->Get_Wating_time();
			num = num_of_digits(DeliveredOrders[index]->Get_Wating_time());
			if (num == 1)
				output_file << "      ";
			else if (num == 2)
				output_file << "     ";
			else if (num == 3)
				output_file << "    ";
			else if (num == 4)
				output_file << "    ";
			output_file << DeliveredOrders[index]->Get_servicing_time();
			num = num_of_digits(DeliveredOrders[index]->Get_servicing_time());
			if (num == 1)
				output_file << "      ";
			else if (num == 2)
				output_file << "     ";
			else if (num == 3)
				output_file << "    ";
			else if (num == 4)
				output_file << "    ";
			switch (DeliveredOrders[index]->GetType()) 
			{
			case 0:
				output_file << "N" << endl; 
				break;
			case 1:
				output_file << "F" << endl; 
				break; 
			default:
				output_file << "V" << endl;
				break; 
			}
			//delete DeliveredOrders[index];
			// here I won't delete it because I won't create a new one in the "asssing functions "so it will be deleted when the destructor of the list is called
			DeliveredOrders[index] = NULL;
		}
		i++;
	}
	char Region_type = 'A';
	for (short int i = 0; i < 4; i++)
	{
		Region_type += i;
		output_file << "Region " << Region_type << endl;
		Reg[i].print(output_file);
		Region_type = 'A';
	}// ofstream file cannot be passed by value it is passed only by referene
	 // or I can use something like that print (output_file("output_file.txt")); 
	 /// or using (std:: move(output_file))
}

void Restaurant::Add_Delivered_Order(Order * ord)
{
	DeliveredOrders[Num_of_Deliverd_Orders++] = ord;
}



