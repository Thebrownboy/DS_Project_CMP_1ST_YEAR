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
#include "..\Region.h"
// it is the maestro of the project
class Restaurant  
{	
private:
	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file
	Queue<Order*> Frozen_orders;
	/* it will be queue bc there is no way to treat with any element except the first one but in the normal orders 
		I will make it a list(OR binary search tree ) bc  the program can search for an order to promote it to VIP  
		and in VIP orders I will make it by(priority queue using (heap OR Binary search tree  )) 
	*/ 
	
	// I should add motorcycle lists forzen , VIP  and normal
	// I should add list of ordes forzen ,VIP and normal 

	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo
	/// ==>
	PriorityQueue<Order*> VIP_Queue; //added by(abdalla)
	Queue<Order*> Interactive; //added by (abdalla )
	Queue<Order*> Step_by_step;//added by (abdalla )
	Queue<Order*> Silent;//added by (abdalla )
	//
	// TODO: Add More Data Members As Needed
	//
	/*   start sir_sayed modification    */
	Region Reg[REG_CNT];
	int AutoPromotionlimit;


public:
	
	Restaurant();
	~Restaurant();
	void AddEvent(Event* pE);	//adds a new event to the queue of events
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();
	void Interactive_Execute();//added by (abdalla )
	void Step_Execute();//added by (abdalla )
	void Silent_Execute();//added by (abdalla )
	void Add_to_Interactive_Queue(Order*);//added by (abdalla )
	void Add_to_step_Queue(Order*);//added by (abdalla )
	void Add_to_silent_Queue(Order*);//added by (abdalla )
	/// ==> 
	///  DEMO-related functions. Should be removed in phases 1&2
	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void AddtoDemoQueue(Order* po);	//adds an order to the demo queue
	Order* getDemoOrder();			//return the front order from demo queue
	Order* getIterOrder();//added by (abdalla )
	Order* GetStepOrder();//added by (abdalla )
	Order* Getsilentorder();//added by (abdalla )
	/// ==> 


	//
	// TODO: Add More Member Functions As Needed
	//


/*   start sir_sayed modification    */

	void Load();

	Region*Get_region(int i);

	void phase_one();

/*   END sir_sayed modification    */

};

#endif