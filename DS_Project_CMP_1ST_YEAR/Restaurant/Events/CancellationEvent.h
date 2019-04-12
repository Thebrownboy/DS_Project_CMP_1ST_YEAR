#pragma once
#include"Event.h"
//added by (abdalla )
class CancellationEvent :public Event
{
	// there is no mean to add the type of the order bc it will be normal order !! 
public :
	CancellationEvent(int Timestep, int oID);
	virtual void Execute(Restaurant *);



};
