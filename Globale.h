
/*******************************************************************
*              ***  File-Description  ***                          *
*                                                                  *
*  FILNAVN   : GLOBALE.h	                                       *
*  FORM�L : Samle globale konstanter og globale variable           *
*  INNHOLD : Unit Globale                                          *
*  BRUKER : Hovedprogram og alle units med prosedyrer              *
*  FORFATTER : Roland Richter                                      *
*  DATO : 15.09.14                                                 *
*                                                                  *
*******************************************************************/

#ifndef TPDECL
#include "TPDECL.h"
#endif

#include <cstring>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <streambuf>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <termios.h>
#include <ctype.h>

#include "Raman.h"

#define GLOBALE

#define Esc '\x27'			//ESC
#define CR '\x13'				//CR
#define Space '\x32'				//Space
#define Backspace '\x8'				//Backspace
#define Downarrow '\x80'				//Downarrow
#define Uparrow '\x72'				//Uparrow


#define DPCport 0x73A3
#define highport 0x73A0
#define lowport 0x73A1
#define flagport 0x73A2

#define driveport 0x03A3
#define polarport 0x03A0
#define monoport 0x03A2         // Monochromator and Ti : Sapphire laser 
#define laserport 0x03A2         // is connected to the same port 

//DMM: nbuf "DMM    "

#define MaxMonoPos 19438.2             // Monokromator konstanter 
#define MinMonoPos -10000
#define MonoFaktor 0.0048            // Enhetssteppet er 0.0048 cm - 1 

#define MaxPoints 2000       // Maks antall m�lepunkter for spektra 
#define MaxAntMidl 30         // Maks antall midlinger               
#define number_settings 7        /*Number of possible polazizer combinations*/

//New inserted
#define Ned '0x0'
#define Step_Ned '0x1'
#define Opp '0x2'
#define Step_Opp '0x3'

#define MonoMask '0xF8'
#define StepTime 20

#define FullSide 20

#define treshold 100
#define SmoothLimit 2
#define CheckLimit 5
#define FullSide 20

#define DrevA 'A:'
#define DrevB 'B:'

//

extern bool onScreen;
extern bool OnFile;


typedef QVector<QPair<qreal, qreal> > Spectrum;
typedef bool PlSetChosenType[20][number_settings];
typedef std::string PlSettingType[2][number_settings];
//extern const char LetterSet[];
//struct LetterSet{
//	std::string x = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//};

extern const int PolPosition[];
//struct ScanList
//{
//	std::string name;
//	int I;
//	double Lower[20], Upper[20];
//	double step[20];
//	int counts[20];
//	int Pol[20];
//	int AverageNo[20];
//	AveMode Average[20];
//	bool selected[20];
//	bool saved, loaded, altered;
//};

extern Spectrum LumiSpectrum;     // Data storage variable 

// Interne variable for monokromator:  
extern double MonoPos;
extern double MonoStep;
extern double MonoStart;
extern double MonoStop;

extern int AntMidl;   // Antall midlinger over spenningsavlesning, Lock - in 
extern int Antall;   // Antall m�lepunkter i spekter 
extern AveMode Average;
extern int DMM_ID;
extern struct ScanList Scan;
extern bool Monochecked, ScanPrepOK, LogWritten, StorageOK;
extern PlSetChosenType PolSetChosen;
extern PlSettingType Polsetting;

class BadConversion : public std::runtime_error
{
public:
	BadConversion(std::string const & s) : std::runtime_error(s)
	{

	}
};

template <typename T>
inline T convertToNumber(std::string const & s)
{
	std::istringstream i(s);
	T x;
	if (!(i >> x))
		throw BadConversion("convertToNumber(\"" + s + "\")");
	return x;
}


//New inserted from Monokrom
void MonoOpp(double step, bool signal);
void MonoNed(double step, bool signal);
void MonoInit(double MonoPos, bool signal);
void ReadMonoPos(void);
void WriteMonoPos(void);
void KontrollMonoPos(void);
void ManuellMonoFlytting(void);

typedef QVector<QPair<qreal, qreal> > ResultTab;
typedef QVector<qreal> SingleSpec;

void Analyze(Spectrum &Data);

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

void StoreData(const Spectrum &Data, int k);
void FetchData(Spectrum &Data);
void ShowDir(void);
void PrintScanList(void);
void SaveScanList(void);
void RetrieveScanList(void);
void ShowScanPlan(bool exit);
void WriteLogFile(void);

void ChangeScanList(void);

void ClrScr(void);
void MenyHoved(void);
void MenyPlottSkriv(void);
void PrepOfScanMenu(void);
void Ram_Menu(void);

inline bool exists_test1(const std::string& name);
inline std::vector<std::string> split_string(std::string inputstring);

inline bool FoundHelp(std::string &FilNavn);
void WriteHelp(int Help_Nr);


char getch(void);
char getche(void);
//
