#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"


ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType, REGION reg):Event(eTime, oID)
{
	OrdType = oType;
	OrdRegion = reg;
}


/* start sir_sayed modification*/
ArrivalEvent::ArrivalEvent(int Timestep, char oType, int oID, int dist, double money, char reg):Event(Timestep, oID)
{
	OrdMoney = money;
	OrdDistance = dist;

	if (reg == 'A')
		OrdRegion = A_REG;
	else if (reg == 'B')
		OrdRegion = B_REG;
	else if (reg == 'C')
		OrdRegion = C_REG;
	else
		OrdRegion = D_REG;
////////////////////////////////////////////////////////////////////////
	if (oType == 'N')
		OrdType = TYPE_NRM;
	else if (oType == 'V')
		OrdType = TYPE_VIP;
	else
		OrdType = TYPE_FROZ;

}
void ArrivalEvent::Execute(Restaurant* pRest)
{
	//This function should create and order and and fills its data 
	// Then adds it to normal, frozen, or VIP order lists that you will create in phase1


	/*Order*pOrder = new Order(OrderID, OrdType, OrdRegion, OrdDistance, OrdMoney, EventTime);
	
	if (OrdType == TYPE_NRM)
		pRest->Get_region(OrdRegion)->insert_norm(*pOrder);
	else if (OrdType == TYPE_VIP)
		pRest->Get_region(OrdRegion)->insert_viporder(*pOrder);
	else
		pRest->Get_region(OrdRegion)->insert_frozorder(*pOrder);*/

}
     /* end sir sayed modification*/