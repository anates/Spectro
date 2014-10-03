//
//{$M 16384, 0, 250000 }
//
//Program Raman;
//
///****************************************************************
//*                                                               *
//*    Hovedprogram for automatisering av apparatur for           *
//*    måling av fotoluminescens fra halvledermaterialer.         *
//*    Programmet kaller opp hovedmenyen og leser valg som        *
//*    gjøres i denne.                                            *
//*                                                               *
//*    REVIDERT: 05.07.89 av Trond Westgaard                      *
//*****************************************************************/
//
//USES Crt,
//GKernel,
//GDriver,
//Analyse, { Finner maxverdier og halvverdibredder }
//Com_Proced, { Små rutiner som brukes av andre enheter }
//Globale, { Deklarasjon av globale variable og konstanter }
//Grafikk, { Tegning av vinduer, kurver etc. }
//Help, { Prosedyrer for hjelp - informasjon }
//Lagring, { Lagre / hente data til / fra fil }
//Maaling, { Automatisk styring av system for måling }
//Menyer, { Menyer og skjermbilder }
//MonoKrom;        { Prosedyrer for stepping av monokromator       }
//
//
//CONST  MainSet : LetterSet = ['1', '2', '3', '4', '5', '6', '7', '8', '9', 'H', 'F', 'X'];
//
//
//VAR
//i : integer;
//next,
//previous,
//avslutt : BOOLEAN;
//valg: CHAR;
//FileType:string;
//
//BEGIN
//
//InitGraphic;                         { Initialisering }
//LeaveGraphic;
//Textbackground(black);
//Port[DPCport]   : = $9A;     { Definerer input - og outputporter }
//Port[driveport] : = $80;
//
//Port[Polarport] : = $7;      { Trekker ut polarisatorene }
//Port[Flagport]  : = $4;
//Antall: = 0;
//FlushData(LumiSpectrum);
//Average: = NoAverage;
//Avslutt: = FALSE;
//(*KontrollMonoPos; *)
//Scan.loaded: = false;
//Scan.altered: = false;
//Monochecked: = false;
//Polsetting[1]: = 'XX';
//Polsetting[2]: = 'XZ';
//Polsetting[3]: = 'XS';
//Polsetting[4]: = 'X0';
//Polsetting[5]: = 'YX';
//Polsetting[6]: = 'YZ';
//Polsetting[7]: = 'Y0';
//
//REPEAT{ Hovedløkke for hovedmeny }
//LogWritten: = False;
//Next: = false;
//Scan.saved: = true;
//Repeat
//previous : = false;
//Textcolor(lightgray);
//Textbackground(black);
//FileType: = 'LST';
//PrepOfScanMenu;
//GotoXY(5, 20);
//ClrEol;
//WRITE('Choice : ');         { Leser valg i hovedmeny }
//ReadFromSet(valg, MainSet);
//
//CASE valg of
//'1'  : ShowDir(FileType);
//'2'  : RetrieveScanList;
//'3'  : Begin
//PrintScanList;
//Repeat
//Until Keypressed;
//End;
//'4'  : ChangeScanList;
//'5'  : If Scan.Altered Then
//SaveScanList
//				   else
//				   Begin
//				   ClrScr;
//				   Writeln('No changes to be saved!   (<CR> to continue)');
//				   Waitfor(CR);
//				   End;
//				   '6'  : Next : = True;
//				   'H'  : WriteHelp(1);
//				   'F'  : FlushData(LumiSpectrum);
//				   'X'  : begin
//				   Next : = true;
//			   avslutt: = true;
//				   end;
//
//				   END;             { End case }
//				   until Next;
//				   IF(Not Scan.Saved) THEN
//					   BEGIN
//
//					   GotoXY(5, 20);
//				   WRITE('Scan list has been changed! Save? [y/n] : ');
//				   If  YesOrNoQuery  then SaveScanList;
//				   END;
//				   If(Not avslutt) then
//					   begin
//				   next : = false;
//				   Repeat
//					   MenyHoved;
//				   GotoXY(5, 20);
//				   ClrEol;
//				   WRITE('Choice : ');         { Leser valg i hovedmeny }
//				   ReadFromSet(valg, MainSet);
//
//				   CASE valg of
//					   '1'  : SelectScan;
//				   '2'  : RecordSpectrum;
//				   '4'  : FetchData(LumiSpectrum);
//				   '5'  : PlottSkrivSkjerm;
//				   '6'  : Analyze(LumiSpectrum);
//				   '7'  : ManuellMonoFlytting;
//				   '8'  : previous : = true;
//				   'H'  : WriteHelp(1);
//				   'F'  : FlushData(LumiSpectrum);
//				   'X'  : IF antall > 0 THEN
//					   BEGIN
//					   GotoXY(5, 20);
//				   WRITE('Do you want to exit without storing data ? [y/n] : ');
//			   Avslutt: = YesOrNoQuery
//				   END
//				   ELSE
//			   Avslutt : = TRUE;
//						END;             { End case }
//						until previous or avslutt;
//						end;
//						UNTIL Avslutt;
//						writeMonopos;
//						END.