#pragma once
#include "..\Defs.h"
class Table
{

	int ID;
	ORD_TYPE type;
	STATUS	status;
	int Return_time,returing_time;
	REGION	region;
public:
	Table(); 
	Table(int, ORD_TYPE, REGION);
	virtual ~Table();
	ORD_TYPE GetORD_Type();
	REGION Get_Region();
	STATUS Get_Staus();
	void Set_Status(STATUS);
	void Set_ReturnTS(int);
	int Get_ReturnTS();
	void Set_ID(int id);
	void Set_Type(ORD_TYPE type);
	void set_returing_time(int);
	int get_returing_time(); 



};

