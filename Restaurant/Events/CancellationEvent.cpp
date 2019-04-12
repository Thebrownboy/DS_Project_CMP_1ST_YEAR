#include "..\Rest\Restaurant.h"
#include "CancellationEvent.h"

CancellationEvent::CancellationEvent(int Time, int ID ):Event(Time ,ID )
{

}

void CancellationEvent::Execute(Restaurant * PRest)
{
	for (int i = 0; i < 4; i++) 
	{
		if (PRest->Get_region(i)->deleteoreder(this->OrderID))
			return;
	}
}

CancellationEvent::~CancellationEvent()
{
}
