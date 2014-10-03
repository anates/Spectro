#include "../Include/Globale.h"

/*******************************************************************
*              ***  FIL - BESKRIVELSE  ***                           *
*                                                                  *
*  FILNAVN   : HELP.PAS                                            *
*  FORM�L : Samle prosedyrer som leser hjelp - informasjon til    *
*              skjerm.Denne informasjonen er lagret p� filene    *
*              Help_1.TXT, Help_2.TXT, Help_3.TXT                  *
*  INNHOLD : WriteHelp.                                          *
*  BRUKES AV : Hovedprogram, Unit Lagring.                         *
*  FORFATTER : Martin Nese                                         *
*  DATO : 88.10.11                                            *
*  REVIDERT : 05.07.89 av Trond Westgaard                         *
*                                                                  *
*******************************************************************/


#define FullSide 20



inline bool FoundHelp(std::string &FilNavn)
{
	/*******************************************************************
	*              ***  PROSEDYRE - BESKRIVELSE  ***                     *
	*                                                                  *
	*  NAVN      : FoundHelp                                           *
	*  FUNKSJON : Leter etter spesifisert hjelpe - fil                  *
	*              og gj�r klar for lesing fra begynnelsen av filen.   *
	*  BRUKES AV : WriteHelp                                           *
	*  DATO : 88.12.07                                            *
	*                                                                  *
	*******************************************************************/
	if (FILE *file = fopen(FilNavn.c_str(), "r")) 
	{
		fclose(file);
		return true;
	}
	else {
		return false;
	}

}


void WriteHelp(int Help_Nr)
{
	/*******************************************************************
	*              ***  PROSEDYRE - BESKRIVELSE  ***                     *
	*                                                                  *
	*  NAVN      : WriteHelp                                           *
	*  FUNKSJON : Leser spesifisert hjelp informasjon til skjerm.     *
	*              Denne informasjonen er p� forh�nd lagt inn p� tre   *
	*              filer; Help_1.TXT, Help_2.TXT og Help_3.TXT.        *
	*  BRUKES AV : Hovedprogram, PlottSkrivSkjerm, DataLagring         *
	*  DATO : 88.12.07                                            *
	*                                                                  *
	*******************************************************************/

	std::string help = "Hjelp_" + std::to_string(Help_Nr) + ".txt";
	std::ifstream read_help(help);
	if (!FoundHelp(help))
	{
		std::cout << "Help information not avaliable.\n";
		std::cout << "Press <ESC> for menu\n";
		char c;
		while (true)
		{
			c = getch();
			if (c == 27)
				break;
		}
	}
	else
	{
		std::string str((std::istreambuf_iterator<char>(read_help)),std::istreambuf_iterator<char>());
		std::cout << str << '\n';
	}


}
