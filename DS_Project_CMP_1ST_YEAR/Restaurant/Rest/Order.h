#ifndef __ORDER_H_
#define __ORDER_H_

#include "..\Defs.h"

class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, Frozen, VIP
	REGION Region;  //Region of this order
	int Distance;	//The distance (in meters) between the order location and the resturant 
	                
	double totalMoney;	//Total order money

	int ArrTime, ServTime, FinishTime;	//arrival, service start, and finish times


	//
	// TODO: Add More Data Members As Needed
	//

	
	/*Start sir_sayed modification*/
		double  Priorty;
	/*End sir_sayed modification*/

public:
	
	Order();


	virtual ~Order();

	int GetID();

	int GetType() const;
	REGION GetRegion() const;

	void SetDistance(int d);
	int GetDistance() const;
	void Set_Type(ORD_TYPE);// it will be used if the promotion Event happens 
	void setMoney(double m);
	double  getMoney() const;
	void calcPriority();
	//
	// TODO: Add More Member Functions As Needed
	//
	void setID(int i);
	/*Start sir_sayed modification*/
	Order(int ID, ORD_TYPE r_Type, REGION r_region, int distance , double monney , int Arr_Time);
	bool operator <(Order &ord)const ;
	bool operator >(Order &ord)const ;
	bool operator ==(Order &ord)const ;
	/*End sir_sayed modification*/
};

#endif