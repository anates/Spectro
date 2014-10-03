#ifndef COMPROC
#include "COM_PROC.h"
#endif

#define MONOKROM

#define Ned '0x0'
#define Step_Ned '0x1'
#define Opp '0x2'
#define Step_Opp '0x3'

#define MonoMask '0xF8'
#define StepTime 20


void MonoOpp(double step, bool signal);
void MonoNed(double step, bool signal);
void MonoInit(double MonoPos, bool signal);
void ReadMonoPos(void);
void WriteMonoPos(void);
void KontrollMonoPos(void);
void ManuellMonoFlytting(void);
