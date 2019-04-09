#include"PromotionEvent.h"
#include "..\Rest\Restaurant.h"

PromotionEvent::PromotionEvent(int Time , int ID , int EXmoney ):Event(Time ,ID )
{
	this->Exmoney = Exmoney;
}

void PromotionEvent::Execute(Restaurant *PRest)
{
	int reg;
	Order* Ord;
	for (int i = 0; i < 4; i++)
	{
		if (PRest->Get_region(i)->deleteoreder(this->OrderID)) {
			reg = i;
			return;
		}	
	}
	PRest->Get_region(reg)->insert_viporder(Ord);
	//PRest->ActiveOrds.enqueue(Ord);

}

double PromotionEvent::GetEXmoney()
{
	return Exmoney; 
}
