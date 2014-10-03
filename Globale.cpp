
/*******************************************************************
*              ***  File-Description  ***                          *
*                                                                  *
*  FILNAVN   : GLOBALE.cpp	                                       *
*  FORM�L : Samle globale konstanter og globale variable           *
*  INNHOLD : Unit Globale                                          *
*  BRUKER : Hovedprogram og alle units med prosedyrer              *
*  FORFATTER : Roland Richter                                      *
*  DATO : 15.09.14                                                 *
*                                                                  *
*******************************************************************/

#include "Globale.h"

bool onScreen = false;
bool OnFile = true;

typedef double Spectrum[MaxPoints][2];
typedef bool PlSetChosenType[20][number_settings];
typedef std::string PlSettingType[2][number_settings];
extern struct LetterSet Letters;
const int PolPosition[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
extern struct ScanList Scan;

Spectrum LumiSpectrum;     // Data storage variable 

// Interne variable for monokromator:  
double MonoPos;
double MonoStep;
double MonoStart;
double MonoStop;

int AntMidl;   // Antall midlinger over spenningsavlesning, Lock - in 
int Antall;   // Antall m�lepunkter i spekter 
AveMode Average;
int DMM_ID;
bool Monochecked,
ScanPrepOK,
LogWritten,
StorageOK;
PlSetChosenType PolSetChosen;
PlSettingType Polsetting;

bool isInSet(char letter)
{
	LetterSet Letters;
	for (int i = 0; i < 62; i++)
	if (Letters.x[i] == letter)
		return true;
	return false;
}

inline bool exists_test1(const std::string& name) {
	if (FILE *file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

inline std::vector<std::string> split_string(std::string inputstring)
{
	std::istringstream iss(inputstring);
	std::vector<std::string> ret_string;
	do
	{
		std::string sub;
		iss >> sub;
		ret_string.push_back(sub);
	} while (iss);
	return ret_string;
}

static struct termios old, notold;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  notold = old; /* make new settings same as old settings */
  notold.c_lflag &= ~ICANON; /* disable buffered i/o */
  notold.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &notold); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void)
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void)
{
  return getch_(1);
}

