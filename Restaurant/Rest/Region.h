#pragma once
#include"..\Generic_DS\PriorityQueue.h"
#include"..\Rest\Motorcycle.h"
#include"..\Rest\Order.h"
#include"..\Generic_DS\Queue.h"
#include"..\Generic_DS/List.h"
#include"..\Generic_DS/Queue.h"
#include"Table.h"

class  Restaurant; 
class Region
{ 
	/*   start sir_sayed modification    */

	PriorityQueue<Order*> VipOr;
	List<Order*> NormOr;
	Queue<Order*> FrozOr;
	Queue <Order*>Partyord; // it is a type that need two motorcycles to be delivered ;
	Queue<Order*>IN_Rest;//  
	PriorityQueue <Motorcycle* > VIPMoto;
	PriorityQueue <Motorcycle* > FrozMoto;
	PriorityQueue <Motorcycle* > NormMoto;
	Table *tables;
	int NumVIPMoto, NumFrozMoto, NumNormMoto;
	int FixNumVIPMoto, FixNumFrozMoto, FixNumNormMoto;
	int NumVIPOrd, NumFrozOrd, NumNormOrd,NumPartyOrd=0,NumINOrd=0;
	int FixNumVIPOrd, FixNumFrozOrd, FixNumNormOrd, FixNumPartyOrd=0, FixNumINOrd=0;
	List <Motorcycle* > UnavailableMoto;
	double Wating_time=0, Service_time=0;
	int Numoftables = 0,FixNumoftables=0,Numofassignedtables=0;


	/*  END sir_sayed modification    */



public:
	/*   start sir_sayed modification    */
	Region();
	void Set_motors(int NumN,int NumF,int NumVIP,int NumofT,Motorcycle**Norm, Motorcycle**FROZ, Motorcycle**VIP,Table*);
	void insert_viporder(Order* ord);
	void insert_frozorder(Order* ord);
	void insert_norm(Order* ord);
	void insert_party(Order* ord); 
	void insert_INREst(Order* ord);
	bool deleteoreder(int ID );
	PriorityQueue<Order*> getViPords();
	Queue<Order*> getFrzOrds();
	List<Order*> getNormOrds();
	Queue<Order*>getpartyOrds();
	Queue<Order*>getINOrds(); 
	bool PickOrd(Order* &Or);
	/*  END sir_sayed modification    */
	void returnAvailMoto(int currTS);
	void AssignNorm(int currTS, string & a, Restaurant *);
	void AssignVIP(int currTS, string & a,Restaurant *);
	void AssignFroz(int currTS, string & a,Restaurant *);
	void AssignParty(int currTs, Restaurant *); 
	void AssignIN(int currTs, Restaurant *); 
	int getNVM();
	int getNFM();
	int getNNM();
	int getNNO();
	int getNVO();
	int getNFO();
	int getNPO();
	int getNIO();

	int getNT();
	void incVIPords();
	void decNormOrds();
	void print(ofstream&);
	int Get_fixed_Norm();
	int Get_fixed_VIP();
	int Get_fixed_Froz();
	void Return_Available_tables(int );
	~Region();
};

