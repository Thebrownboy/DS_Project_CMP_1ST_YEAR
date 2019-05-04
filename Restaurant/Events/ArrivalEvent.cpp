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
	else if (oType == 'F')
		OrdType = TYPE_FROZ;
	else if (oType == 'Q')
		OrdType = TYPE_PARTY;
	else
		OrdType = TYPE_INREST;

}
void ArrivalEvent::Execute(Restaurant* pRest)
{
	//This function should create and order and and fills its data 
	// Then adds it to normal, frozen, or VIP order lists that you will create in phase1

	Order *PO = new Order(this->OrderID, this->OrdType, this->OrdRegion,this->OrdDistance,this->OrdMoney,this->EventTime);
	
	if (this->OrdType == 0)
		pRest->Get_region(this->OrdRegion)->insert_norm(PO);
	else if (this->OrdType == 1)
		pRest->Get_region(this->OrdRegion)->insert_frozorder(PO);
	else if (this->OrdType == 2)
		pRest->Get_region(this->OrdRegion)->insert_viporder(PO);
	else if (this->OrdType == 3)
		pRest->Get_region(this->OrdRegion)->insert_party(PO);
	else
		pRest->Get_region(this->OrdRegion)->insert_INREst(PO);




		
}

ArrivalEvent::~ArrivalEvent()
{
}
	
	///*if (this->OrdRegion == 0) 
	//{
	//	if (this->OrdType == 0)
	//		pRest->Get_region(0)->insert_norm(PO);
	//	else if (this->OrdType == 1)
	//		pRest->Get_region(0)->insert_frozorder(PO);
	//	else if (this->OrdType == 2)
	//		pRest->Get_region(0)->insert_viporder(PO);
	//
	//}
	//else if (this->OrdRegion == 1)
	//{
	//	if (this->OrdType == 0)
	//		pRest->Get_region(1)->insert_norm(PO);
	//	else if (this->OrdType == 1)
	//		pRest->Get_region(1)->insert_frozorder(PO);
	//	else if (this->OrdType == 2)
	//		pRest->Get_region(1)->insert_viporder(PO);
	//
	//}
	//else if (this->OrdRegion == 2) 
	//{
	//	if (this->OrdType == 0)
	//		pRest->Get_region(2)->insert_norm(PO);
	//	else if (this->OrdType == 1)
	//		pRest->Get_region(2)->insert_frozorder(PO);
	//	else if (this->OrdType == 2)
	//		pRest->Get_region(2)->insert_viporder(PO);
	//}
	//else
	//{
	//	if (this->OrdType == 0)
	//		pRest->Get_region(3)->insert_norm(PO);
	//	else if (this->OrdType == 1)
	//		pRest->Get_region(3)->insert_frozorder(PO);
	//	else if (this->OrdType == 2)
	//		pRest->Get_region(3)->insert_viporder(PO);
	//}*/
	///pRest->ActiveOrds.enqueue(pO)
	/*Order*pOrder = new Order(OrderID, OrdType, OrdRegion, OrdDistance, OrdMoney, EventTime);
	
	if (OrdType == TYPE_NRM)
		pRest->Get_region(OrdRegion)->insert_norm(*pOrder);
	else if (OrdType == TYPE_VIP)
		pRest->Get_region(OrdRegion)->insert_viporder(*pOrder);
	else
		pRest->Get_region(OrdRegion)->insert_frozorder(*pOrder);*/


     /* end sir sayed modification*/