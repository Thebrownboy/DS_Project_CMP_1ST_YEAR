#pragma once
#include"Event.h"
//added by (abdalla )
class PromotionEvent :public Event
{
	double Exmoney; //there is no mean to add the order type bc it will be for only normal orders!!
public  :
	PromotionEvent(int, int, int);
	void virtual Execute(Restaurant *);
	double GetEXmoney();
};
