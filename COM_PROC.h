#ifndef GLOBALE
#include "Globale.h"
#endif

#define COMPROC

int StrToInt(std::string Instring);
double StrToReal(std::string Instring);
void KeyBuffer(void);
void Beep(unsigned int time);
void WaitFor(char letter);
void ReadWord(std::string name);
void ReadLine(std::string Name, bool Done);
void ReadReal(double Realnumber);
void ReadInt(int Intnumber);
void ReadLongInt(long int longintnmbr);
void ReadFromSet(char &letter);
bool YesOrNoQuery(void);
void FlushData(Spectrum &data);
bool Defaultyes(void);
