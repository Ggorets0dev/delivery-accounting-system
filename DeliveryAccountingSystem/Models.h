#pragma once

using namespace System;

public value struct Record
{
	Int32 code;
	String^ title;
	String^ category;
	String^ transport;
	String^ early_delivery_date;
	String^ late_delivery_date;
	Boolean^ delivered;
};