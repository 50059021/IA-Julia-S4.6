#ifndef PROTOC_H
#define PROTOC_H

#include "User.h"
#include "Prodef.h"

void gObjTradeOkButton(int aIndex);
int gObjAttack(LPOBJ lpObj, LPOBJ lpTargetObj, class CMagicInf* lpMagic, int magicsend, unsigned char MSBFlag, int AttackDamage, BOOL bCombo);
void gObjPlayerKiller(LPOBJ lpObj, LPOBJ lpTargetObj);
bool ProtocolCore (BYTE protoNum, LPBYTE aRecv, DWORD aLen, int aIndex, DWORD Encrypt, int Serial);
void ProtocolCoreSend(int aIndex,unsigned char* aSend, int aLen);
void SetProtocol();
#endif