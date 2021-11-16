#pragma once
#include <Windows.h>
#include "Edit_Form.h"
#include "MyForm.h"
interface IEvent
{
	virtual void SendText(System::String^ text) = 0;
	
};
