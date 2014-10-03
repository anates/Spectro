#include "Maaling.h"


/*************************************************************
*             ***  FIL - BESKRIVELSE  ***                      *
*                                                            *
* FILNAVN   : MAALING.PAS(aka measurement.pas)              *
* FORM�L : Samle prosedyrene som tar for seg innlesing av *
*             m�leintervaller, logisk styring av step - *
*             motorene og avlesning av Lock - in - spenning      *
*             under m�lingen.                                *
* INNHOLD : PL_Interval, PL_Point                          *
*             RecordSpectrum                                 *
* BRUKES AV : Hovedprogram                                   *
* FORFATTER : Martin Nese                                    *
* DATO : 88.10.09                                       *
* REVIDERT : 05.07.89 av Trond Westgaard                    *
*                                                            *
*************************************************************/



unsigned char SetPolarizer(int i)
{
	switch (i)
	{
	case 1:
		return 0x2;
	case 2:
		return 0x1;
	case 3:
		return 0x0;
	case 4:
		return 0x3;
	case 5:
		return 0x6;
	case 6:
		return 0x5;
	case 7:
		return 0x7;
	default:
		return 0x0;
	}
}

/*void SelectScan(void)
{
	std::string instring;

	StorageOK = false;
	if(!Scan.loaded) 
		RetrieveScanList();
	if (Scan.loaded)
	{
		i = 1;
		while(getchar()!= do
		begin
			ClrScr;
		PrintScanList;
		Textcolor(black);
		Textbackground(lightgray);
		Writeln;
		Writeln('Arrow keys-up/down  SPACE-Select  CR-Exit');
		Textcolor(lightgray);
		Textbackground(black);
		GotoXY(1, Cursor(0));
	Instring: = Readkey;
		If Instring = #0 then
			begin
		Instring : = Readkey;
		If Instring = Uparrow then GotoXY(1, Cursor(-1));
		IF Instring = Downarrow then GotoXY(1, Cursor(1));
		end;
		If Instring = Space then
			begin
			Scan.Selected[i]: = Not(Scan.Selected[i]);
		GotoXY(1, Cursor(1));
		end;
		end
	}
	ScanPrepOk = false;
	for(i = 1; i <= Scan.I; i++)
		if(Scan.selected[i])
			ScanprepOk = true;

}*/


/*
Procedure LoadScanParameters(i:integer);

************************************************************
*             ***  PROSEDYRE - BESKRIVELSE  ***                *
*                                                            *
* NAVN      : ReadScanParameters                             *
* FUNKSJON : Reading interval borders, start values and     *
*             which type of average                          *
*             Converts it into internal values               *
* DATO : 17.09.90                                       *
*                                                            *
************************************************************


BEGIN
MonoStart : = Scan.Lower[i];
MonoStop: = Scan.Upper[i];
MonoStep: = Scan.Step[i];
Average: = Scan.average[i];
AntMidl: = Scan.averageNo[i];

END;        { ReadScanParameters }






Function Read_DPC : INTEGER;

CONST   Inhibit = $0;
Enable = $4;

VAR  Flag, Highbytes, Lowbytes : BYTE;
Digit: ARRAY[0..3] OF BYTE;

BEGIN
{ triggering of DPC : }
Port[Flagport] : = Enable;

{ Waiting till bit 7 is on high : }
REPEAT Flag : = PORT[Flagport] UNTIL((Flag AND $80) > 0);
{ Waiting till bit 7 is low again}
REPEAT Flag : = PORT[Flagport] UNTIL((Flag AND $80) = 0);

Port[Flagport] : = Inhibit;

{ Read data port }
Highbytes: = Port[Highport];
Lowbytes: = Port[Lowport];

Port[Flagport] : = Enable;

{ convert it into a decimal number }
Digit[3] : = Highbytes DIV $10;
Digit[2] : = Highbytes MOD $10;
Digit[1] : = Lowbytes DIV $10;
Digit[0] : = Lowbytes MOD $10;

{ Hardcoding to repair a particular data transfer error : }
IF Digit[3] > 7 THEN Digit[3] : = 0;

Read_DPC: = Digit[3] * 1000 + Digit[2] * 100 + Digit[1] * 10 + Digit[0];
END;    { Read_DPC }



Function Read_DMM(device : INTEGER) :REAL;

CONST  buflength = 21;
nrbuflength = 12;
FirstPos = 8;
LastPos = 19;
MaxValue = 0.100;

TYPE   DMM_string = STRING[buflength];

VAR  rec_string, fix_string : DMM_string;
Number: STRING[nrbuflength];
TmpResult: REAL;
i, ErrorCode : INTEGER;

BEGIN
ibrd(device, rec_string, buflength);
FOR i : = 1 TO buflength DO
fix_string[i] : = rec_string[i - 1];
FOR i : = 1 TO nrbuflength DO Number[i] : = ' ';
Number: = Copy(fix_string, FirstPos, LastPos);
Val(Number, TmpResult, ErrorCode);
IF ErrorCode > 0 THEN
Read_DMM : = MaxValue
		   ELSE
	   Read_DMM : = TmpResult;
END;      { Read_DMM }




Procedure PM_avlesning(VAR Intensitet, Avvik : REAL);

************************************************************
*             ***  PROSEDYRE - BESKRIVELSE  ***                *
*                                                            *
* NAVN      : PM_avlesning                                   *
* FUNKSJON : Leser av PM_spenningen p� Lock - in - forsterkeren *
*             et valgt antall ganger med TidsKonst / 10 *
*             intervall.Beregner s� middelverdi og avviket  *
*             fra denne middelverdien.Punkt midling : det   *
*             midles et gitt antall ganger mens laser        *
*             st�r stille.Standardavvik beregnes.           *
* BRUKES AV : PLE_spekter                                    *
* DATO : 88.10.24                                       *
*                                                            *
************************************************************

CONST  Factor = 10;

VAR    index : INTEGER;           { L�kketeller }
DPC_value, Ref_value : REAL;
PM_avlest: Array[1..MaxAntMidl] of REAL;

BEGIN
Intensitet : = 0;

FOR index : = 1 to AntMidl DO
BEGIN
DPC_value : = Read_DPC;
{Ref_value: = Factor * Read_DMM(DMM_ID); }
PM_avlest[index] : = DPC_value; { / Ref_value; }
Intensitet: = Intensitet + PM_avlest[index]
	END;


			IF(AntMidl > 1) THEN
			Intensitet : = Intensitet / AntMidl;  { Middelverdien }

		Avvik: = 0;                     { Avvik fra middelverdi, RMS }
			IF(AntMidl > 1) THEN
				BEGIN
				FOR index : = 1 to AntMidl DO
			Avvik : = Avvik + SQR(PM_avlest[index] - Intensitet);
		Avvik: = SQRT(Avvik / (AntMidl - 1))
			END;

			   END;     { Procedure PM_avlesning }




			   Procedure PL_Interval;

			   ************************************************************
				   *             ***  PROSEDYRE - BESKRIVELSE  ***                *
				   *                                                            *
				   * NAVN      : PL_Interval                                     *
				   * FUNKSJON : Tar opp fotoluminescens - spektrum.              *
				   *             IntervallMidling : *
				   *             En m�ling for hver b�lgelengde, men b�lge - *
				   *             lengdeintervallet blir scannet et gitt antall  *
				   *             ganger og deretter midlet.                     *
				   *             Hvert enkelt scan plottes som stiplet linje p� *
				   *             skjerm, midlet resultat plottes heltrukket.    *
				   * BRUKES AV : PL_spekter                                     *
				   * DATO : 88.10.26                                       *
				   *                                                            *
				   ************************************************************


			   VAR   index, PktNr           : INTEGER;
			   PktSpenn, Count, Vektf : REAL;
			   Brk, DrawPoint         : BOOLEAN;

			   BEGIN
				   IF AntMidl > 1 THEN SetLineStyle(1);
		   Vektf: = 1.0 / AntMidl;
		   DrawPoint: = False;

			   If(Monostart < Monostop) then
				   begin
				   FOR index : = 1 to AntMidl DO{ B�lgelengdeinterv.scannes }
			   BEGIN
			   PktNr : = 0;
		   Count: = MonoStart;
			   WHILE(PktNr <= MaxPoints) AND(Count <= MonoStop) DO
				   BEGIN
				   Inc(PktNr);
			   LumiSpectrum[PktNr, 1] : = Count;
		   Count: = Count + MonoStep
			   END;

			  PktNr: = 0;
				  WHILE(PktNr <= MaxPoints) AND(MonoPos <= MonoStop) DO
					  BEGIN
					  Inc(PktNr);
			  PktSpenn: = Read_DPC / 1000;
				  LumiSpectrum[PktNr, 2] : = LumiSpectrum[PktNr, 2] + PktSpenn * Vektf;
				  PlottSistePunkt(PktSpenn, 0, MonoPos, DrawPoint);
			  DrawPoint: = True;
				  Monoopp(MonoStep, Brk);
				  END;                  { End while - loop }

				  DELAY(500);
				  MonoInit(MonoStart, Brk);
				  END;                     { End for - loop   }
				  end
else
FOR index : = 1 to AntMidl DO{ B�lgelengdeinterv.scannes }
BEGIN
PktNr : = 0;
Count: = MonoStart;
WHILE(PktNr <= MaxPoints) AND(Count >= MonoStop) DO
BEGIN
Inc(PktNr);
LumiSpectrum[PktNr, 1] : = Count;
Count: = Count - MonoStep
	END;

   PktNr: = 0;
	   WHILE(PktNr <= MaxPoints) AND(MonoPos >= MonoStop) DO
		   BEGIN
		   Inc(PktNr);
   PktSpenn: = Read_DPC / 1000;
	   LumiSpectrum[PktNr, 2] : = LumiSpectrum[PktNr, 2] + PktSpenn * Vektf;
	   PlottSistePunkt(PktSpenn, 0, MonoPos, DrawPoint);
   DrawPoint: = True;
	   Mononed(MonoStep, Brk);
	   END;                  { End while - loop }

	   DELAY(500);
	   MonoInit(MonoStart, Brk);
	   END;
	   begin

		   end;
   Antall: = PktNr;

	   SetLineStyle(0);
	   IF AntMidl > 1 THEN{ Det midlete resultat plottes heltrukket }
	   BEGIN
		   PlottSistePunkt(LumiSpectrum[1, 2], 0, LumiSpectrum[1, 1], False);
	   FOR PktNr : = 2 to Antall DO
		   PlottSistePunkt(LumiSpectrum[PktNr, 2], 0, LumiSpectrum[PktNr, 1], True);
	   END;
	   END;           {  PL_Interval  }


	   Procedure PL_Point;

	   ************************************************************
		   *             ***  PROSEDYRE - BESKRIVELSE  ***                *
		   *                                                            *
		   * NAVN      : PL_Point                                   *
		   * FUNKSJON : Tar opp fotoluminescens - spektrum.              *
		   *             PunktMidling : *
		   *                M�ler et gitt antall punkter for hver       *
		   *                b�lgelengde og midler f�r monokromatoren    *
		   *                flyttes til neste m�lepunkt.                *
		   * BRUKES AV : PL_spekter                                     *
		   * DATO : 07.07.89                                       *
		   *                                                            *
		   ************************************************************

	   VAR    Intensitet, Avvik, Dummy : REAL;
	   PktNr, i                 : INTEGER;
	   Brk, DrawPoint    : BOOLEAN;

	   BEGIN
		   FOR i : = 1 TO 10 DO Dummy : = Read_DMM(DMM_ID);  { To get GPIB running }
   PktNr: = 0;
   Brk: = False;
   DrawPoint: = False;
	   if (Monostart<Monostop) then

		   WHILE(PktNr <= MaxPoints) AND(MonoPos < MonoStop) AND(NOT Brk) DO
		   BEGIN
		   Inc(PktNr);
	   PM_avlesning(Intensitet, Avvik);
	   LumiSpectrum[PktNr, 1] : = MonoPos;
	   LumiSpectrum[PktNr, 2] : = Intensitet;
	   PlottSistePunkt(Intensitet, Avvik, MonoPos, DrawPoint);
   DrawPoint: = True;
	   Monoopp(MonoStep, Brk);

	   END{ while - loop }
	   else
		   WHILE(PktNr <= MaxPoints) AND(MonoPos > MonoStop) AND(NOT Brk) DO
		   BEGIN
		   Inc(PktNr);
	   (*PM_avlesning(Intensitet, Avvik); *)
		   LumiSpectrum[PktNr, 1] : = MonoPos;
	   LumiSpectrum[PktNr, 2] : = Intensitet;
	   PlottSistePunkt(Intensitet, Avvik, MonoPos, DrawPoint);
   DrawPoint: = True;
	   MonoNed(MonoStep, Brk);

	   END;  { while - loop   }
   Antall: = PktNr;
	   IF Brk THEN MonoStop : = MonoPos;
	   END;     { Prosedyre PL_Point }


	   Procedure RecordSpectrum;

	   ************************************************************
		   *             ***  PROSEDYRE - BESKRIVELSE  ***                *
		   *                                                            *
		   * NAVN      : PLE_spekter                                    *
		   * FUNKSJON : Tar opp fotoluminescens - spektere over et bredt *
		   *             b�lgelengdeintervall.Har to typer midling : *
		   *             i) PunktMidling:                               *
		   *                M�ler et gitt antall punkter for hver       *
		   *                b�lgelengde og midler f�r laseren           *
		   *                flyttes til neste m�lepunkt.                *
		   *             ii)IntervallMidling:                           *
		   *                En m�ling for hver b�lgelengde, men b�lge - *
		   *                lengdeintervallet blir scannet et gitt      *
		   *                antall ganger og deretter midlet.           *
		   * BRUKES AV : Hovedprogram                                   *
		   * DATO : 88.10.26                                       *
		   *                                                            *
		   ************************************************************

	   VAR   FirstScan,
		   Exit,

		   i,
		   control,
		   StartScan,
		   NewSet,
		   Brk,
	   Store :BOOLEAN;
	   k, l,
	   j     :integer;
   Reaction: String;



	   BEGIN
		   ClrScr;
	   If Not ScanPrepOk then SelectScan;
	   ClrScr;
   Exit: = False;
	   Showscanplan(Exit);
	   If Not Exit  then
		   begin
	   if not monochecked then manuellMonoFlytting;
   FirstScan: = True;
   k: = 0;
	   For j : = 1 to Scan.I do
	   If Scan.Selected[j] then
		   begin
		   For l : = 1 to Number_Settings do
	   if PolSetChosen[j, l] then
		   begin
		   Port[Polarport] : = SetPolarizer(l);
	   Inc(k);
	   FlushData(LumiSpectrum);
   StartScan: = false;
   NewSet: = true;
	   LoadScanParameters(j);
   DMM_ID: = ibfind(DMM);
	   If FirstScan Then
		   begin
		   WRITELN;
	   WRITELN('Close monochromator slits !');
	   WRITE('Press <CR> to continue : ');
	   WaitFor(CR);
	   WRITELN('Initializing !');
	   MonoInit(MonoStart + 20, Brk);
	   Delay(100);
	   MonoInit(MonoStart, Brk);
	   WRITELN;
	   WRITELN('Open monochromator slits !');
	   WRITE('Press <CR> to continue : ');
	   WaitFor(CR);
   FirstScan: = False;
	   end
	   else  MonoInit(MonoStart, Brk);

	   EnterGraphic;
	   VinduMaaling(MonoStart, MonoStop);
	   VinduTabell(MonoPos);
	   CASE Average OF
	   Point : PL_Point;
   Interval: PL_Interval;
	   END;
	   LeaveGraphic;
	   StoreData(LumiSpectrum, k);
	   (*PlotData(LumiSpectrum);  *)
		   END;
	   End;
	   If Not Logwritten then WriteLogfile;
	   end;
	   end;


	   END.   {  Unit Maaling }








*/



