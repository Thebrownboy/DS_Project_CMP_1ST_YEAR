#include "..\Rest\Restaurant.h"
#include "CancellationEvent.h"

CancellationEvent::CancellationEvent(int Time, int ID ):Event(Time ,ID )
{

}

void CancellationEvent::Execute(Restaurant *)
{
}
