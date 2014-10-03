/*******************************************************************
*              ***  FIL - BESKRIVELSE  ***                           *
*                                                                  *
*  FILNAVN   : COM_PROCED.PAS                                      *
*  FORM�L : Samle enkelte generelle prosedyrer som brukes       *
*              av mange prosedyrer i de fleste units.              *
*  INNHOLD : KeyBuffer, ReadReal, ReadInt, FlushData             *
*  FORFATTER : Trond Westgaard                                     *
*  DATO : 22.08.90                                            *
*                                                                  *
*******************************************************************/

#include "../Include/Globale.h"



int StrToInt(std::string InString)
{
	return std::stoi(InString);
}

double StrToReal(std::string InString)
{
	return std::stod(InString);
}

void KeyBuffer(void)
{
	char value;
	while (!(std::cin >> value))
	{
		std::cin.clear();
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void WaitFor(char letter)
{
	char input = ' ';
	while (input != letter)
		std::cin >> input;
}

void Beep(unsigned int time)
{
#ifdef WIN32
	Beep(443, time);
#else
	std::cout << '\a';
#endif
};

void Readword(std::string &Name)
{
	std::getline(std::cin, Name);
}


void ReadLine(std::string &name)
{
	std::getline(std::cin, name);
}


void ReadReal(double & Real)
{
	std::string name;
	std::getline(std::cin, name);
	convertToNumber<double>(name);
}

void ReadInt(int & Real)
{
	std::string name;
	std::getline(std::cin, name);
	convertToNumber<int>(name);
}

void ReadLongInt(long int & Real)
{
	std::string name;
	std::getline(std::cin, name);
	convertToNumber<long int>(name);
}

void ReadFromSet(char &letter, LetterSet CurrentSet)
{
	char c = ' ';
	while (!isInSet(c))
		std::cin >> c;
	letter = c;
}

bool YesOrNoQuery(void)
{
	char input;
	std::cin >> input;
	if (input == 'Y' || input == 'y')
		return true;
	else
		return false;
}

bool DefaultYes(void)
{
	char input;
	std::cin >> input;
	if (input == 'Y' || input == 'y' || input == ' ')
		return true;
	else
		return false;
}
