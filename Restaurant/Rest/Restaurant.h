#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include"..\Generic_DS\PriorityQueue.h"

#include<fstream>
#include "Order.h"
#include "Motorcycle.h"
#include "Region.h"
// it is the maestro of the project
class Restaurant
{
private:
	GUI * pGUI;

	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file
	Queue<Order*> ActiveOrds;
	int AutoPromotionlimit;
	Order * DeliveredOrders[200];
	int Num_of_Deliverd_Orders = 0;

	/* it will be queue bc there is no way to treat with any element except the first one but in the normal orders
	I will make it a list(OR binary search tree ) bc  the program can search for an order to promote it to VIP
	and in VIP orders I will make it by(priority queue using (heap OR Binary search tree  ))
	*/

	// I should add motorcycle lists forzen , VIP  and normal
	// I should add list of ordes forzen ,VIP and normal 

	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	//Important: This is just for demo

public:
	Region Reg[REG_CNT];
	Restaurant();
	~Restaurant();
	void AddEvent(Event* pE);	//adds a new event to the queue of events
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();
	void PrintInfo(int, string a = "", string b = "", string c = "", string d = "");
	void Silent_Mode(); 
	void StepByStep_Mode(); 

	//added by (abdalla )

	/*   start sir_sayed modification    */
	
	void Load();
	Region *Get_region(int i);
	/*   END sir_sayed modification    */
	void interactive_mode();
	void UpdateMoto(int currTS);
	void ProcessOrders(int currTS, string & a, string & b, string & c, string & d);
	void DrawActiveOrds();

	bool OrdersDone();
	void output();
	void Add_Delivered_Order(Order*);
	void Auto_Promotion(int); 
	bool Returned_Done(); 
	void Update_tables(int);
	

};

#endif