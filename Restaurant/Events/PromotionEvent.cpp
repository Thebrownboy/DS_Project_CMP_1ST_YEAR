#include"PromotionEvent.h"
#include "..\Rest\Restaurant.h"

PromotionEvent::PromotionEvent(int Time , int ID , int EXmoney ):Event(Time ,ID )
{
	this->Exmoney = Exmoney;
}

void PromotionEvent::Execute(Restaurant *)
{
}

double PromotionEvent::GetEXmoney()
{
	return Exmoney; 
}
