#ifndef __MOTORCYCLE_H_
#define __MOTORCYCLE_H_


#include "..\Defs.h"

#pragma once
class Motorcycle	
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding motorcycle type (it will be const forEver)  
	int speed;		//meters it can move in one clock tick (in one timestep)
	REGION	region;	//region of the motorcycle .it will be const  forever .. will be const forever  
	STATUS	status;	//idle or in-service
	int returnTS;
	int totDistace=0;
	int numDeliveredOrds = 0;
	int noMinorDamage = 0;
	int noMajorDamage = 0;
public:
	Motorcycle(int ,ORD_TYPE,int,REGION);
	virtual ~Motorcycle();
	int GetID();
	ORD_TYPE GetORD_Type();
	int Get_speed();
	REGION Get_Region();
	STATUS Get_Staus();
	void Set_Status(STATUS);// the only data that will be changed  ;//added by (abdalla )
	void Set_Speed(int);// for  bounus(//added by (abdalla ))
	void Set_ReturnTS(int );
	int Get_ReturnTS();
	/*   start sir_sayed modification    */
	Motorcycle();

	void Set_ID(int id);
	void Set_Type(ORD_TYPE type);
	void AddDist(int);
	int Get_totDist();
	bool operator >(Motorcycle &Mo)const;
	bool operator <(Motorcycle &Mo)const ;
	bool operator==(Motorcycle &Mo)const ;
	void inc_numDelOrds();
	int Get_numDelOrds();



};

#endif