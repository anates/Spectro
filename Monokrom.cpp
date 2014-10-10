
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

#include "Globale.h"

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
//Wird voraussichtlich entfernt, muss aber noch überprüft werden
void MonoNed(const double step, bool &signal)
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
//Wird voraussichtlich entfernt, muss aber noch überprüft werden
void MonoOpp(const double step, bool &signal)
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
//Wird voraussichtlich entfernt, muss aber noch überprüft werden
void MonoInit(const double NewMonoPos, bool signal)
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
