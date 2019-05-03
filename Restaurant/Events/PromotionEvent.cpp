#include"PromotionEvent.h"
#include "..\Rest\Restaurant.h"

PromotionEvent::PromotionEvent(int Time , int ID , int EXmoney ):Event(Time ,ID )
{
	this->Exmoney = Exmoney;
}

void PromotionEvent::Execute(Restaurant *PRest)
{
	int reg=0;
	Order* Ord=new Order() ;
	Ord->setID(OrderID);
	for (int i = 0; i < 4; i++)
	{
		if (PRest->Get_region(i)->PickOrd(Ord)) {
			reg = i;
			break;
		}	
	}
	Ord->setMoney(Ord->getMoney() + Exmoney);
	Ord->Set_Type(TYPE_VIP);
	Ord->calcPriority();
	PRest->Get_region(reg)->decNormOrds();
	PRest->Get_region(reg)->insert_viporder(Ord);

}

double PromotionEvent::GetEXmoney()
{
	return Exmoney; 
}
