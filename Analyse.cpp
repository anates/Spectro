/*******************************************************************
*              ***  FIL - BESKRIVELSE  ***                           *
*                                                                  *
*  FILNAVN   : ANALYSE.PAS                                         *
*  FORM�L : Analysere m�ledata                                  *
*  INNHOLD : Analyze                                             *
*  FORFATTER : Trond Westgaard                                     *
*  DATO : 22.08.90                                            *
*                                                                  *
*******************************************************************/

#include "../Include/Globale.h"


void Check_for_max(Spectrum Data, SingleSpec AuxData, int i, bool ok, ResultTab tab, int nr)
{

	double MaxValue;
	int j, jmax;
	MaxValue = AuxData[i];
	ok = true;

	// Checks that nearby points have lower intensity : }
	if (i <= CheckLimit)
		j = 0;
	else
		j = i - CheckLimit - 1;

	jmax = i + CheckLimit;

	do{
		j++;
		if(j == i) 
			j++;
		if(MaxValue < AuxData[j]) 
			ok = false;
	}
	while(j == jmax || !ok);

	// Position and intensity are stored if a maximum was detected : }
	if (ok)
	{
		nr = nr + 1;
		tab[nr][1] = Data[i][1];
		tab[nr][2] = Data[i][2];
	}

}

void Finn_FWHM(Spectrum Data, int j, int nr, ResultTab Tab)
{
	int k, l;
	double HalvMax, HiSide, LoSide, steplength, factor;
	HalvMax = Data[j][2]/2;
	k = j;
	l = j;

	do
	{
		k++;
	} while ((Data[k][2] >= HalvMax) && (k != Antall));

	if (k < Antall)
	{
		steplength = Data[k][1] - Data[k - 1][1];
		factor = (HalvMax - Data[k][2]) / (Data[k - 1][2] - Data[k][2]);
		HiSide = Data[k][1] - steplength * factor;
	}
	else
		HiSide = Data[Antall][1];
		//IF k < ...  }

	do
	{
		l--;
	}
	while((Data[l][2] >= HalvMax) && (l != 1));

	if(l > 1)
	{
		steplength = Data[l + 1][1] - Data[l][1];
		factor = (HalvMax - Data[l][2]) / (Data[l + 1][2] - Data[l][2]);
		LoSide = Data[l][1] + steplength * factor;
	}
	else
		LoSide = Data[1][1];
			// IF l > ...  }

			// Stores FWHM in the array of maxima : }
	Tab[nr][3] = abs((float)(HiSide - LoSide));


}



void Analyze(Spectrum Data)  // VAR transfer to avoid overflow }
{
	SingleSpec SmoothData;
	int i, j, Norm, linjer, AntMax, index;
	bool positiv, max;
	double DataAverage;
	ResultTab MaxTab;

	if (Antall > 0)
	{
		positiv = true;
		max = false;
		AntMax = 0;
		Norm = 2 * SmoothLimit + 1;

		for(i = 1; i <= SmoothLimit; i++)
			SmoothData[i] = Data[i][2];

		for(i = SmoothLimit + 1; i <= Antall - SmoothLimit; i++)
		{
			DataAverage = 0;
			for(j = i - SmoothLimit; j <= i + SmoothLimit; j++)
				DataAverage = DataAverage + Data[j][2];
			SmoothData[i] = DataAverage / Norm;
		};

		for(i = Antall - SmoothLimit + 1; i <= Antall; i++)
			SmoothData[i] = Data[i][2];


		for (i = 1; i < Antall - CheckLimit; i++)
		{
			if (SmoothData[i + 1] < SmoothData[i])
			{
				if (positiv)
				{
					if (SmoothData[i] > terskel)
					{
						Check_for_max(Data, SmoothData, i, max, MaxTab, AntMax);
						if (max)
						{
							Finn_FWHM(Data, i, AntMax, MaxTab);
							max = false;
						};  // IF max }
					};  // IF SmoothData > terskel }
					positiv = false;
				}   // IF positiv }
			}
				 positiv = true;
		}
		if (AntMax > 0)// Skriv en rapport p� skjermen : }
		{
			ClrScr();
			std::cout << AntMax << " maxima were detected.\n";
			std::cout << "Energy(cm-1\t Intensity(Cts)\t FWHM(cm-1)\n";
			linjer = 0;
			for (index = 1; index <= AntMax; index++)
			{
				printf("%07.5f\t%08.3f\t%05.1f\n", MaxTab[index][1], MaxTab[index][2], MaxTab[index][3]);
			};      // FOR index }
		}// IF AntMax }
		else
			std::cout << "No maxima was found.";
	}// IF antall }
	else
		std::cout << "No spectrum in memory.";
	getchar();
}
