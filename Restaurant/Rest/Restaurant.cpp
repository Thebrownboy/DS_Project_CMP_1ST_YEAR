#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"

#include "..\Events\CancellationEvent.h"
#include "..\Events\PromotionEvent.h"

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
		break;
	case MODE_STEP:
		
		break;
	case MODE_SLNT:
		
		break;
	case MODE_DEMO:
		phase_one();

	};

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
void Restaurant::Just_A_Demo()
{
	
	//
	// THIS IS JUST A DEMO FUNCTION
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	
	int EventCnt;	
	Order* pOrd;
	Event* pEv;
	srand(time(NULL));

	pGUI->PrintMessage("Just a Demo. Enter EVENTS Count(next phases should read I/P filename):");
	EventCnt = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer

	pGUI->UpdateInterface();

	pGUI->PrintMessage("Generating orders randomly... In next phases, orders should be loaded from a file");
		
	int EvTime = 0;
	
	//Create Random events
	//All generated event will be "ArrivalEvents" for the demo
	for(int i=0; i<EventCnt; i++)
	{
		int O_id = i+1;
		
		//Rendomize order type
		int OType;
		if(i<EventCnt*0.2)	//let 1st 20% of orders be VIP (just for sake of demo)
			OType = TYPE_VIP;
		else if(i<EventCnt*0.5)	
			OType = TYPE_FROZ;	//let next 30% be Frozen
		else
			OType = TYPE_NRM;	//let the rest be normal

		
		int reg = rand()% REG_CNT;	//randomize region


		//Randomize event time
		EvTime += rand()%4;
		pEv = new ArrivalEvent(EvTime,O_id,(ORD_TYPE)OType,(REGION)reg);
		AddEvent(pEv);

	}	

	int CurrentTimeStep = 1;
	//as long as events queue is not empty yet
	while(!EventsQueue.isEmpty())
	{
		//print current timestep
		char timestep[10];
		itoa(CurrentTimeStep,timestep,10);	
		pGUI->PrintMessage(timestep);


		ExecuteEvents(CurrentTimeStep);	//execute all events at current time step
		//The above line may add new orders to the DEMO_Queue

		//Let's draw all arrived orders by passing them to the GUI to draw

		while(DEMO_Queue.dequeue(pOrd))
		{
			pGUI->AddOrderForDrawing(pOrd);
			pGUI->UpdateInterface();
		}
		Sleep(1000);
		CurrentTimeStep++;	//advance timestep
	}


	pGUI->PrintMessage("generation done, click to END program");
	pGUI->waitForClick();

	
}
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
			VIP = new				 Motorcycle*[NumVip];
			Norm = new Motorcycle*[NumN];
			Froz = new Motorcycle*[Numf];
			
			for (int j = 0; j < NumN; j++)
			{
				Norm[j] = new Motorcycle;
				Norm[j]->Set_ID(j);
				Norm[j]->Set_Type(TYPE_NRM);
				Norm[j]->Set_Speed(SN);

			}
			for (int k = 0; k < Numf; k++)
			{
				Froz[k] = new Motorcycle;
				Froz[k]->Set_ID(i+ NumN);
				Froz[k]->Set_Type(TYPE_FROZ);
				Froz[k]->Set_Speed(SF);

			}
			for (int l = 0; l < NumVip; l++)
			{
				VIP[l] = new Motorcycle;
				VIP[l]->Set_ID(l+ NumN+ Numf);
				VIP[l]->Set_Type(TYPE_VIP);
				VIP[l]->Set_Speed(SV);

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

Region * Restaurant::Get_region(int i)
{
	return &Reg[i];
}
/*   END sir_sayed modification    */
void Restaurant::phase_one()
{
	Load();
	///////////////
	/*Psycho task*/
	int CurrentTimeStep = 1;
	//as long as events queue is not empty yet
	while (!EventsQueue.isEmpty())
	{
		//print current timestep
		char timestep[10];
		itoa(CurrentTimeStep, timestep, 10);
		pGUI->PrintMessage(timestep);


		ExecuteEvents(CurrentTimeStep);	//execute all events at current time step
										//The above line may add new orders to the DEMO_Queue

		Order* dum;							//Let's draw all arrived orders by passing them to the GUI to draw
		/*
		for (int i = 0; i < 4; ++i) {
			PriorityQueue < Order* > vip = this->Get_region(i)->getViPords();
			while (!vip.Is_Empty()) {
				dum=vip.Peek();
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
				dum = norm.get_first();
				ActiveOrds.enqueue(dum);
				norm.Delete(dum); /// back
			}


		}
		*/
		
		while (ActiveOrds.dequeue(dum))
		{
			pGUI->AddOrderForDrawing(dum);
			pGUI->UpdateInterface();
		}
		Sleep(1000);
		ActiveOrds.~Queue();
		CurrentTimeStep++;	//advance timestep
	}

}


/// ==> end of DEMO-related function