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

#include "Globale.h"

void Check_for_max(ScanData &Data, const QVector<qreal> &AuxData, int place, bool &ok)
{

    double MaxValue = AuxData[0];

    if(place > AuxData.size())
    {
        ok = false;
        return;
    }
    for(int i = 0; i < AuxData.size(); i++)
    {
        if(AuxData[i] >= MaxValue)
            MaxValue = AuxData[i];
        ok = i > (int)(place) ? false:true;
        if(!ok)
            break;
    }
    // Position and intensity are stored if a maximum was detected
	if (ok)
        Data.Maxima.push_back(qMakePair((qreal)place, (qreal)Data.Data[place].second));

}

void Finn_FWHM(ScanData &Data, int j)
{

    qreal HalfMax, HiSide, LoSide, steplength, factor;
    HalfMax = Data.Data[j].second / 2.0;
    qint32 k = j;

	do
	{
		k++;
    } while ((Data.Data[k].second >= HalfMax) && (k <= Data.Data.size()));

    if (k < Data.Data.size())
	{
        steplength = Data.Data[k].first - Data.Data[k - 1].first;
        factor = (HalfMax - Data.Data[k].second) / (Data.Data[k - 1].second - Data.Data[k].second);
        HiSide = Data.Data[k].first - steplength * factor;
	}
	else
        HiSide = Data.Data[Data.Data.size()-1].first;

    k = j;
	do
	{
        k--;
	}
    while((Data.Data[k].second >= HalfMax) && (k >= 0));

    if(k > 0)
	{
        steplength = Data.Data[k + 1].first - Data.Data[k].first;
        factor = (HalfMax - Data.Data[k].second) / (Data.Data[k + 1].second - Data.Data[k].second);
        LoSide = Data.Data[k].first + steplength * factor;
	}
	else
        LoSide = Data.Data[0].first;

    Data.FWHM.push_back(qMakePair(LoSide, HiSide));
}

void Analyze(ScanData &Data)
{
    QVector<qreal> SmoothData;
    int i, j, Norm;
	bool positiv, max;
	double DataAverage;

    positiv = true;
    max = false;
    Norm = 2 * SmoothLimit;

    for(i = 0; i < SmoothLimit; i++)
        SmoothData.push_back(Data.Data[i].second);

    for(i = SmoothLimit; i < Data.Data.size() - SmoothLimit; i++)
    {
        DataAverage = 0;
        for(j = i - SmoothLimit; j < i + SmoothLimit; j++)
            DataAverage = DataAverage + Data.Data[j].second;
        SmoothData.push_back(DataAverage/Norm);
    };

    for(i = Data.Data.size() - SmoothLimit; i < Data.Data.size(); i++)
        SmoothData.push_back(Data.Data[i].second);


    for (i = 0; i < Data.Data.size() - CheckLimit; i++)
    {
        if (SmoothData[i + 1] < SmoothData[i])
        {
            if (positiv)
            {
                if (SmoothData[i] > treshold)
                {
                    Check_for_max(Data, SmoothData, i, max);
                    if (max)
                    {
                        Finn_FWHM(Data, i);
                        max = false;
                    };
                };
                positiv = false;
            }
        }
        positiv = true;
    }
        //Muss durch Analyseausgabe ergänzt werden!!!

}
