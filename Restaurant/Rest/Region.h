#pragma once
#include"..\Generic_DS\PriorityQueue.h"
#include"..\Rest\Motorcycle.h"
#include"..\Rest\Order.h"
#include"..\Generic_DS\Queue.h"
#include"..\Generic_DS/List.h"
#include"..\Generic_DS/Queue.h"

class  Restaurant; 
class Region
{ 
	/*   start sir_sayed modification    */

	PriorityQueue<Order*> VipOr;
	List<Order*> NormOr;
	Queue<Order*> FrozOr;

	PriorityQueue <Motorcycle* > VIPMoto;
	PriorityQueue <Motorcycle* > FrozMoto;
	PriorityQueue <Motorcycle* > NormMoto;
	int NumVIPMoto, NumFrozMoto, NumNormMoto;
	int FixNumVIPMoto, FixNumFrozMoto, FixNumNormMoto;
	int NumVIPOrd, NumFrozOrd, NumNormOrd;
	int FixNumVIPOrd, FixNumFrozOrd, FixNumNormOrd;
	List <Motorcycle* > UnavailableMoto;
	double Wating_time=0, Service_time=0;

	/*  END sir_sayed modification    */



public:
	/*   start sir_sayed modification    */
	Region();
	void Set_motors(int NumN,int NumF,int NumVIP,Motorcycle**Norm, Motorcycle**FROZ, Motorcycle**VIP);
	void insert_viporder(Order* ord);
	void insert_frozorder(Order* ord);
	void insert_norm(Order* ord);
	bool deleteoreder(int ID );
	PriorityQueue<Order*> getViPords();
	Queue<Order*> getFrzOrds();
	List<Order*> getNormOrds();
	bool PickOrd(Order* &Or);
	/*  END sir_sayed modification    */
	void returnAvailMoto(int currTS);
	void AssignNorm(int currTS, string & a, Restaurant *);
	void AssignVIP(int currTS, string & a,Restaurant *);
	void AssignFroz(int currTS, string & a,Restaurant *);
	int getNVM();
	int getNFM();
	int getNNM();
	int getNNO();
	int getNVO();
	int getNFO();
	void incVIPords();
	void decNormOrds();
	void print(ofstream&);
	~Region();
};

