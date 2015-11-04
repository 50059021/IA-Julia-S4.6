#include "stdafx.h"
#include "RaklionSelupan.h"

void RaklionSelupan(){

	SetByte(0x0061801E,0x81); // Raklion Fix
	SetByte(0x0061018F,0x51); // Raklion Fix
	SetByte(0x00610190,0x01); // Raklion Fix
}