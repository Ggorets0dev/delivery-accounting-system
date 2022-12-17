#pragma once

public value struct Record
{
	int code;
	String^ title;
	String^ category;
	String^ transport;
	String^ early_delivery_date;
	String^ late_delivery_date;
	bool delivered;
};