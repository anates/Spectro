
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

void MonoNed(const double step, qreal &MonoPos)
{
    long int i, iMonoStep, limit1, limit2, limit3;
	
	i = 0;
	iMonoStep = (int)(step / MonoFaktor);
	limit1 = iMonoStep - 100;
	limit2 = iMonoStep - 200;
	limit3 = iMonoStep - 300;
    while ((i < iMonoStep) && (MonoPos >= MinMonoPos))
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

            //Port[monoport] = Current | Step_Opp;
			ShortDelay(StepTime);
            //Port[monoport] = Current | Opp;  Port muss angepasst werden
            MonoPos = MonoPos - MonoFaktor;
            i++;
		}
	}
}

void MonoOpp(const qreal step, qreal &MonoPos)
{
	long int i, iMonoStep, limit1, limit2, limit3;
	i = 0;
	iMonoStep = (int)(step / MonoFaktor);
	limit1 = iMonoStep - 100;
	limit2 = iMonoStep - 200;
	limit3 = iMonoStep - 300;
    while ((i < iMonoStep) && (MonoPos <= MaxMonoPos))
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
        //Port[monoport] = Current | Step_Ned; Hier muss der Port angepasst werden
        ShortDelay(StepTime);
        //Port[monoport] = Current | Ned; Hier muss der Port angepasst werden
        MonoPos = MonoPos + MonoFaktor;
        i++;
    }
}

void moveToTarget(const double &NewMonoPos, qreal &MonoPos)
{
	double Step;
	Step = abs((float)(MonoPos - NewMonoPos));
	if (MonoPos < NewMonoPos)
        MonoOpp(Step, MonoPos);
	else 
        MonoNed(Step, MonoPos);
}
