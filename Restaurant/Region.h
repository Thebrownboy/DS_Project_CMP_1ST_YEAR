#pragma once
#include"Generic_DS\PriorityQueue.h"
#include"Rest\Motorcycle.h"
#include"Rest\Order.h"
#include"Generic_DS\Queue.h"
#include"Generic_DS/List.h"

class Region
{ 
	/*   start sir_sayed modification    */

	PriorityQueue<Order> VipOr;
	List<Order> NormOr;
	Queue<Order> FrozOr;

	PriorityQueue <Motorcycle > VIPMoto;
	PriorityQueue <Motorcycle > FrozMoto;
	PriorityQueue <Motorcycle > NormMoto;
	int NumVIPMoto, NumFrozMoto, NumNormMoto;


	/*  END sir_sayed modification    */



public:
	/*   start sir_sayed modification    */
	Region();
	void Set_motors(int NumN,int NumF,int NumVIP,Motorcycle**Norm, Motorcycle**FROZ, Motorcycle**VIP);
	void insert_viporder(Order&ord);
	void insert_frozorder(Order&ord);
	void insert_norm(Order&ord);
	/*  END sir_sayed modification    */
	~Region();
};

