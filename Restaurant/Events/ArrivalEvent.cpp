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
	
	if (this->OrdType == 0) {
		if(pRest->Get_region(this->OrdRegion)->AcceptNormOr())
			pRest->Get_region(this->OrdRegion)->insert_norm(PO);
	}
	
	else if (this->OrdType == 1) {
		if(pRest->Get_region(this->OrdRegion)->AcceptFrozOr() )
			pRest->Get_region(this->OrdRegion)->insert_frozorder(PO);

	}
	else if (this->OrdType == 2) {
		if(pRest->Get_region(this->OrdRegion)->AcceptVipOr())
			pRest->Get_region(this->OrdRegion)->insert_viporder(PO);

	}
	else if (this->OrdType == 3) {
		if (pRest->Get_region(this->OrdRegion)->AcceptPartyOr())
			pRest->Get_region(this->OrdRegion)->insert_party(PO);

	}
	else
		pRest->Get_region(this->OrdRegion)->insert_INREst(PO);
	
}

ArrivalEvent::~ArrivalEvent()
{
}
	
	
