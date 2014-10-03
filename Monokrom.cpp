
/*************************************************************
*              ***  FIL - BESKRIVELSE  ***                     *
*                                                            *
*  FILNAVN   : MONOKROM.PAS                                  *
*  FORM�L : Samler de prosedyrer som styrer stepmotoren   *
*              til Monokromatoren p� en unit.                *
*  INNHOLD : MonoOpp, MonoNed, MonoInit, *
*              KontrollMonoPos, ManuellMonoFlytting          *
*  BRUKES AV : Hovedprogram og Maaling                       *
*  FORFATTER : Martin Nese.                                  *
*  DATO : 88.10.04                                      *
*  REVIDERT : 05.07.89 av Trond Westgaard                   *
*                                                            *
*************************************************************/

#include "../Include/Monokrom.h"

/*************************************************************
*                                                            *
*    Elektrisk kobling mellom datamaskin og stepmotorer      *
*                                                            *
*    Stepmotoren til Monokromatoren er tilkoblet IO - kort 2 *
*    (p� den hexadesimale adressen $03A2).                 *
*                                                            *
*************************************************************/


void ShortDelay(int StopCount)
{
	for (int i = 0; i < StopCount; i++)
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
}



void MonoNed(double step, bool signal)
{
	/*************************************************************
	*            ***  PROSEDYRE - BESKRIVELSE  ***                 *
	*                                                            *
	* FUNKSJON : MonoOpp kj�rer stepmotoren p� monokromatoren    *
	*            et gitt antall step oppover hvis den ikke       *
	*            st�r i endepunktet(maksimum lysfrekvens).      *
	*            Et step tilsvarer 0.0048 cm - 1.                    *
	* BRUKES AV : MonoScan, ManuellStep, MonoInit                 *
	* DATO : 88.10.04                                        *
	*                                                            *
	*************************************************************/

	long int i, iMonoStep, limit1, limit2, limit3;
	unsigned char Current;
	
	i = 0;
	iMonoStep = (int)(step / MonoFaktor);
	limit1 = iMonoStep - 100;
	limit2 = iMonoStep - 200;
	limit3 = iMonoStep - 300;
	Current = Port[monoport] & MonoMask;
	Port[monoport] = Current | Opp;
	KeyBuffer();
	signal = false;


	while ((i < iMonoStep) && (MonoPos >= MinMonoPos) && (!signal))
	{
		{
			if ((i <  100) || (i > limit1))
			{
				ShortDelay(StepTime);
				if ((i < 200) || (i > limit2))
				{
					ShortDelay(StepTime);
					if ((i < 300) || (i > limit3))
						ShortDelay(StepTime);
				}
			}

			Port[monoport] = Current | Step_Opp;
			ShortDelay(StepTime);
			Port[monoport] = Current | Opp;  // Motoren g�r et skritt opp }
			MonoPos = MonoPos - MonoFaktor;   // Oppdatering b�lgelengde   }
			i++;                          // L�kketeller inkrementeres }
			char c = getch();
			if (c == 27)
				signal = true;
		}
	}
}

void MonoOpp(double step, bool signal)
{
	/*************************************************************
	*            ***  PROCEDURE - BESKRIVELSE  ***                 *
	*                                                            *
	* FUNKSJON : MonoNed kj�rer stepmotoren p� monokromatoren    *
	*            et gitt antall step nedover hvis den ikke       *
	*            st�r i endepunktet(minimal lysfrekvens).       *
	*            Et step tilsvarer 0.0048 cm - 1.                    *
	* BRUKES AV : MonoScan, ManuellStep, MonoInit                 *
	* DATO : 88.10.04                                        *
	*                                                            *
	*************************************************************/

	long int i, iMonoStep, limit1, limit2, limit3;
	unsigned char Current;


	i = 0;
	iMonoStep = (int)(step / MonoFaktor);
	limit1 = iMonoStep - 100;
	limit2 = iMonoStep - 200;
	limit3 = iMonoStep - 300;
	Current = Port[monoport] & MonoMask;
	Port[monoport] = Current | Ned;
	KeyBuffer();
	signal = false;
	while ((i < iMonoStep) && (MonoPos <= MaxMonoPos) && (!signal))
	{
		if ((i < 100) || (i > limit1))
		{
			ShortDelay(StepTime);
			if ((i < 200) || (i > limit2))
			{
				ShortDelay(StepTime);
				if ((i < 300) || (i > limit3))
					ShortDelay(StepTime);
			}
		}
	}
	Port[monoport] = Current | Step_Ned;
	ShortDelay(StepTime);
	Port[monoport] = Current | Ned; // Motoren g�r et skritt ned }
	MonoPos = MonoPos + MonoFaktor;  // Oppdatering av b�lgelengde   }
	i++;                           // L�kketeller inkrementeres    }
	char c = getch();
	if (c == 27)
		signal = true;
}

void MonoInit(double NewMonoPos, bool signal)
{
	/*************************************************************
	*             ***  PROSEDYRE - BESKRIVELSE  ***                *
	*                                                            *
	* NAVN      : MonoInit                                       *
	* FUNKSJON : Plasserer monokromatoren i den posisjonen der  *
	*             den skal detektere fotoluminescens.            *
	* DATO : 30.08.90                                       *
	*                                                            *
	*************************************************************/

	double Step;

	Step = abs((float)(MonoPos - NewMonoPos));
	if (MonoPos < NewMonoPos)
		MonoOpp(Step, signal);
	else 
		MonoNed(Step, signal);
}

void ReadMonoPos(void)
{
	/*********************************************************
	*              ***  PROSEDYRE - BESKRIVELSE  ***           *
	*                                                        *
	*  NAVN      : ReadMonoPos                               *
	*  FUNKSJON : Leser inn den fysiske representasjonen    *
	*              (MonoPos) for monokromatorens posisjon fra*
	*              filen c : \mono\position.pos n�r programmet *
	*              startes.                                  *
	*  BRUKES AV : Hovedprogram                              *
	*  DATO : 13.12.90                                  *
	*                                                        *
	**********************************************************/

	std::string PosFile;
	std::string PosFileName;
	std::string wavenumber;
	PosFileName = "c:\\mono\\position.pos";
	std::ifstream in(PosFileName);
	if (in.good())
	{
		std::string Line;
		std::getline(in, Line);
		MonoPos = convertToNumber<double>(Line);
	}
	in.close();
}


void WriteMonoPos(void)
{
	/*********************************************************
	*              ***  PROSEDYRE - BESKRIVELSE  ***           *
	*                                                        *
	*  NAVN      : WriteMonoPos                              *
	*  FUNKSJON : Skriver ut den fysiske representasjonen   *
	*              (MonoPos) for monokromatorens posisjon til*
	*              filen c : \mono\position.pos n�r programmet *
	*              avsluttes.                                *
	*  BRUKES AV : Hovedprogram                              *
	*  DATO : 13.12.90                                  *
	*                                                        *
	**********************************************************/

	std::string PosFile;
	std::string PosFileName;

	PosFileName = "c:\\mono\\position.pos";
	std::ofstream outfile(PosFileName, std::ios::out | std::ios::trunc | std::ios::binary);
	outfile << MonoPos << '\n';
	outfile.close();
}


void KontrollMonoPos(void)
{
	/*********************************************************
	*              ***  PROSEDYRE - BESKRIVELSE  ***           *
	*                                                        *
	*  NAVN      : KontrollMonoPos                           *
	*  FUNKSJON : Operat�r m� kontrollere posisjonene p�    *
	*              monokromator f�r m�ling startes           *
	*  BRUKES AV : Hovedprogram                              *
	*  DATO : 88.12.20                                  *
	*                                                        *
	**********************************************************/

	std::cout << "Control of monochromator position.\n";
	std::cout << "MonoPos (in cm-1) = ";
	//ReadReal(MonoPos);//Has to be fixed???
}



//void ManuellMonoFlytting(void)
//{
//	/*************************************************************
//	*              ***  PROSEDYRE - BESKRIVELSE  ***               *
//	*                                                            *
//	*  NAVN      : ManuellMonoFlytting                           *
//	*  FUNKSJON : Leser inn antall step monokromatoren skal     *
//	*              flyttes og flytter den.                       *
//	*  BRUKES AV : Hovedprogram                                  *
//	*  DATO : 88.12.20                                      *
//	*                                                            *
//	*************************************************************/
//
//	double  K_NewPos, Step;
//	bool stop;
//	std::string position;
//
//	ClrScr();
//	Monochecked = true;
//	ReadMonoPos();
//	//Str(MonoPos:8 : 2, Position);//Has to be replaced with a c++-function
//	std::cout << "Actual Monochromator position  = ";
//	ReadWord(sosition);
//MonoPos: = StrToReal(Position);
//	If Position<>ESC then
//		begin
//		GotoXY(5, 12);
//	WRITE('New Monochromator position : ');
//	ReadWord(Position);
//K_NewPos: = StrToReal(Position);
//	GotoXY(5, 14);
//	If((K_Newpos<0) and(MonoPos>0)) or((K_Newpos > 0) and(MonoPos < 0)) then
//		begin
//		write('You`ll be crossing the Raman line - Close Monochromator slits!');
//	GotoXY(5, 16);
//	write('Press CR to continue');
//	Waitfor(CR);
//	end;
//	GotoXY(5, 18);
//	WRITE('Moving to monochromator position = ', K_NewPos:8 : 2, ' cm-1');
//	MonoInit(K_NewPos, Break);
//	IF break THEN
//		BEGIN
//		GotoXY(5, 14);
//	ClrEol;
//	WRITE('Operation aborted at ', MonoPos:8 : 2, ' cm-1');
//	GotoXY(5, 15);
//	WRITE('Press <ESC> for menu : ');
//	WaitFor(Esc)
//		END;
//MonoPos: = k_newpos;
//	WriteMonoPos;
//	end;
//
//
//
//}
