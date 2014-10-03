/***************************************************************
*              ***  FIL - BESKRIVELSE  ***                     *
*                                                              *
*  FILNAVN   : MENYER.cpp                                      *
*  INNHOLD : Prosedyrer som legger ut alle menyer og skjerm -  *
*              bilder                                          *
*  BRUKES AV : Hovedprogram, Lagring og Maaling                *
*  FORFATTER : Roland Richter                                  *
*  DATO : 15.09.14                                             *
*                                                              *
***************************************************************/

#include "../Include/Globale.h"

void ClrScr(void)
{
#ifdef _WIN32
	std::system("cls");
#elif __linux
	std::system("clear");
#else
	std::system("clear");
#endif
};

void MenyHoved(void)
{
	/***************************************************************
	*              ***  PROSEDYRE - BESKRIVELSE  ***               *
	*                                                              *
	*  NAVN      : MenyHoved                                       *
	*  FUNKSJON : Legger ut hovedmenyen p� skjermen.               *
	*  DATO : 15.09.14											   *
	*                                                              *
	***************************************************************/

	ClrScr();
	printf("RAMAN MEASUREMENTS\n");
	printf("******************\n");
	printf("Main options : \n\n\n");
	printf("1 :  Select scans from scanlist\n");
	printf("2 :  Start measurement\n");
	printf("3 :  Store data\n");
	printf("4 :  Fetch data\n");
	printf("5 :  Plot/print data on screen\n");
	printf("6 :  Analysis of spectra\n");
	printf("7 :  Control of monochromator position\n");
	printf("8 :  Previous Menu\n");
	printf("F :  Flush current data\n");
	printf("X :  Exit\n");
	printf("******************\n");
}




void MenyPlottSkriv(void)
{

	/*************************************************************
	*              ***  PROSEDYRE - BESKRIVELSE  ***               *
	*                                                            *
	*  NAVN      : MenyPlottSkriv                                *
	*  FUNKSJON : Legger ut meny for plotting og skriving av    *
	*              data til skjerm                               *
	*  BRUKES AV : PlottSkrivSkjerm(Unit Lagring)             *
	*  DATO : 15.09.14                                      *
	*                                                            *
	*************************************************************/

	ClrScr();
	printf("PLOTTING / SKRIVING  AV  M�LEDATA TIL SKJERMEN\n");
	printf("**********************************************\n\n");
	printf("MENY\n\n");
	printf("1 :  Help\n");
	printf("2 :  Draws Raman-spectrum on the screen\n");
	printf("3 :  Writes data from the Raman-Spectrum on the screen\n");
	printf("R :  Back\n");
	printf("**********************************************\n\n");
}



void Ram_Menu(void){


	ClrScr();
	printf("RAMAN SPECTRUM \n");
	printf("*********** \n\n\n");
	printf("Essential physical parameters for the scan : \n\n\n\n");
	printf("Mono-start (cm-1) = \n");
	printf("Mono-stop  (cm-1) = \n");
	printf("Mono-step (cm-1) = \n\n\n");
	printf("Technical parameters for the scan : \n\n");
	printf("Point < P > or interval < I > measurement : \n");
	printf("Measurements pr. point ( Max. 20 )        : \n");
	printf("*********** \n\n\n");
}

/**************************************************************************/
void PrepOfScanMenu(void)
{

	/**************************************************************
	*              ***  PROCEDURE - DESCRIPTION  ***              *
	*                                                             *
	*  NAME      : PrepOfScanMenu                                *
	*  FUNCTION : Writing on screen choices for preparation      *
	*              of a sequence of scans.It"s possible to       *
	*              look at allready existing *.LST - files, to      *
	*              chose on of them and to alter it.              *
	*              actual directory, *
	*  USED BY                       *
	*  DATO      : 15.09.14                                      *
	*                                                             *
	**************************************************************/


	ClrScr();
	printf("Preparation of Scan\n");
	printf("*******************\n\n");
	printf("Main options :\n\n");
	printf("1 : Show existing files containing lists of scans: \n");
	printf("2 : Retrieve scan list\n");
	printf("3 : Print scan list\n");
	printf("4 : Change scan list\n");
	printf("5 : Save scan list\n");
	printf("6 : Next Menu\n");
	printf("F : Flush current data\n");
	printf("X : Exit\n");
	printf("*******************\n\n");

}


