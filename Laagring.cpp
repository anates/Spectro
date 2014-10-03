#include "../Include/Laagring.h"

/*************************************************************
*             ***  FIL - BESKRIVELSE  ***                      *
*                                                            *
* FILNAVN   : LAGRING.PAS                                    *
* FORM�L : Samle prosedyrer som lagrer og henter m�ledata *
*             til / fra fil, samt lesing av m�ledata til       *
*             skjerm.Data fra en m�ling lagres p� to filer; *
*             informasjon om m�lingen lagres p� filen        *
*             A:FILNAVN.DOC, mens rene m�ledata lagres p�    *
*             filen A : FILNAVN.DAT.                           *
* INNHOLD : ListDataDir, FetchData, LesFilnavn, StoreData, *
*             ShowDir                                        *
* FORFATTER : Martin Nese                                    *
* DATO : 88.10.11                                       *
* REVIDERT : 11.10.90 av Trond Westgaard                    *
* Revised : 20.10.92  Hans Joerg Fell                      *                                     *
*************************************************************/

std::string FileName;

/*************************************************************
*             ***  FUNKSJONS - BESKRIVELSE  ***                *
*                                                            *
* NAVN      : Funnet                                         *
* FUNKSJON : Tilordner og resetter �nsket filnavn til en    *
*             DAT. - fil p� diskett - drev A.Tester om fil med  *
*             dette navn allerede eksisterer p� denne disk.  *
* BRUKES AV : Fillagring, StoreData, FetchData                     *
* DATO : 88.10.11                                       *
*                                                            *
*************************************************************/

inline bool Funnet(const std::string& name) {
	if (FILE *file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}


//PROCEDURE ShowDir(FileType:string);
//
///*************************************************************
//*       ***   Procedure   Description  ***                   *
//*                                                            *
//* NAME      : ShowDir                                        *
//* FUNCTION : Writes on screen all files in the actual       *
//*             directory with a given extension FileType      *
//* BRUKES AV : *
//* DATO : 92.10.21                                       *
//*                                                            *
//*************************************************************/
//
//CONST  FullSide = 22;
//
//VAR    DirInfo : SearchRec;
//Dato: DateTime;
//linjer: INTEGER;
//Filename,
//Directory : string;
//drive: byte;
//
//BEGIN
//ClrScr;
//drive: = 0;
//GetDir(drive, directory);
//Filename: = concat('*.', Filetype);
//WRITELN;
//WRITELN(directory, ' contains  the following files ', FileName, ':');
//WRITELN;
//linjer: = 3;
//FindFirst(Filename, AnyFile, DirInfo);
//WHILE DosError = 0 DO
//BEGIN
//Inc(linjer);
//WRITE(DirInfo.name);
//GotoXY(22, WhereY);
//UnpackTime(DirInfo.time, Dato);
//WRITELN(Dato.Day:2, '/', Dato.Month : 2, '/', Dato.Year);
//IF(linjer = FullSide) THEN
//BEGIN
//KeyBuffer;
//WRITE('Press <CR> for next page : ');
//WaitFor(CR);
//ClrScr;
//linjer: = 0;
//END;
//FindNext(DirInfo);
//END;
//WRITELN;
//KeyBuffer;
//WRITE('Press <CR> to continue : ');
//WaitFor(CR);
//
//
//
//END;     { End ListDataDir }

//void ShowDir(void)
//{
//	std::vector<std::string> out;
//#ifdef WIN32
//	HANDLE dir;
//	WIN32_FIND_DATA file_data;
//
//	if ((dir = FindFirstFile(("./*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
//		return; /* No files found */
//
//	do {
//		const std::string file_name = file_data.cFileName;
//		const std::string full_file_name = "./" + file_name;
//		const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
//
//		if (file_name[0] == '.')
//			continue;
//
//		if (is_directory)
//			continue;
//
//		out.push_back(full_file_name);
//	} while (FindNextFile(dir, &file_data));
//
//	FindClose(dir);
//#else
//	DIR *dir;
//	class dirent *ent;
//	class stat st;
//
//	dir = opendir("./");
//	while ((ent = readdir(dir)) != NULL) {
//		const string file_name = ent->d_name;
//		const string full_file_name = "./" + file_name;
//
//		if (file_name[0] == '.')
//			continue;
//
//		if (stat(full_file_name.c_str(), &st) == -1)
//			continue;
//
//		const bool is_directory = (st.st_mode & S_IFDIR) != 0;
//
//		if (is_directory)
//			continue;
//
//		out.push_back(full_file_name);
//	}
//	closedir(dir);
//#endif
//	for (int i = 0; i < out.size(); i++)
//		std::cout << out[i] << '\n';
//} // GetFilesInDirectory


/*void PrepareStorage(bool Exit, int k, int l)
{
	int	position,
	int i;
	std::string number, reaction, OldData, newname, fn;
	std::string oldfile;

	begin
		If Not StorageOK then
		begin
		Textbackground(black);
	Textcolor(lightgray);
fn: = Scan.Name;
	writeln('You have chosen ', k, ' different spectra.');
	writeln('Combined with the different polarizer settings there are ');
	writeln(l, ' files to be stored!');
	Write('I propose ');
	TextColor(White);
	Write(fn);
	TextColor(Lightgray);
	Writeln(' as common filename. You`ll find the following files:');
	Writeln;
	TextColor(White);
	For i : = 1 to l do
	begin
	if i < 10 then write(fn, '.D0', i, '   ')
	else
	write(fn, '.D', i, '   ');
	if (i mod 5 = 0) then writeln;

	end;
	Textcolor(black);
	Textbackground(lightgray);
Position: = WhereY;
	GotoXY(1, 24);
	writeln('CR - okay   ESC - exit   Or just type in new  common name');
	GotoXY(WhereX, Position + 2);
	TextColor(lightgray);
	Textbackground(black);
	Write('Common filename:   ');
	TextColor(White);
	Readword(fn);
	TextColor(lightgray);
	If fn = ESC then Exit : = True
	else
	begin
	Scan.Name: = fn;
	For i : = 1 to l do
	begin
		str(i, number);
	if (i < 10)  then
		begin
	OldData : = Concat(fn, '.D0', number);
	If   funnet(OldData) then
		begin
	newname : = ConCat('Old.D0', number);
	If funnet(Newname) then
		begin
		assign(oldfile, newname);
	erase(oldfile);
	end;
	Assign(oldfile, oldData);
	Rename(Oldfile, NewName);
	Writeln('File(s) already exist(s)! They`ll be renamed to OLD.Dxx!');
	end;
	end
	else
	begin
OldData : = Concat(fn, '.D', number);
	If   funnet(OldData) then
		begin
	NewName : = ConCat('Old.D', number);
	If funnet(Newname) then
		begin
		assign(oldfile, newname);
	erase(oldfile);
	end;
	Assign(oldfile, oldData);
	Rename(Oldfile, NewName);
	Writeln('File(s) already exist(s)! They`ll be renamed to OLD.Dxx!');
	Waitfor(CR);
	end;
	end;
	end;
	end;


	end;
	end;
}*/
//(*****************************************************************************)
//Procedure WritePolSet(var Outfile : text; FileOutput:Boolean; k: integer);
//
//Var
//i : integer;
//highlighted:Boolean;
//
//Begin
//if (textattr = 7) or(textattr = 15) then highlighted : = false
//else highlighted: = true;
//Case FileOutput of
//false  :   Begin
//For i : = 1 to Number_Settings do
//begin
//
//write(' ');
//If PolSetChosen[k, i] then
//begin
//Textcolor(black);
//Textbackground(lightgray);
//end
//						   else
//						   begin
//						   Textcolor(lightgray);
//						   Textbackground(black);
//						   end;
//						   Write(PolSetting[i]);
//						   If highlighted  then
//							   begin
//							   Textcolor(black);
//						   Textbackground(lightgray);
//						   end
//							  else
//							  begin
//							  Textcolor(lightgray);
//							  Textbackground(black);
//							  end;
//							  End;
//
//							  end;
//
//							  true    :
//							  Begin
//								  For i : = 1 to Number_Settings do
//							  Case PolSetChosen[k, i] of
//								  true : write(OutFile, '1':2);
//
//							  false  : write(OutFile, '0':2);
//
//							  End;
//							  End;
//							  End;
//							  End;
//							  (*****************************************************************************)
//								  Procedure ReadFile_PolSet(Var In_File : Text; j:integer);
//
//							  Var
//								  k,
//							  i  : integer;
//
//							  Begin
//								  For i : = 1 to Number_Settings do
//							  begin
//								  Read(In_File, k);
//							  Case k of
//								  1   : PolSetChosen[j, i] : = True;
//							  0   : PolSetChosen[j, i] : = False;
//							  End;
//							  End;
//							  End;

//(*****************************************************************************)
void WriteScanLine(std::string outfile, bool fileoutput, int i)
{
	/*FILE * pFile;
	pFile = fopen(outfile.c_str(), "w");
	fprintf(pFile, "%10.2f, %10.2f, %10.2f, %.5f\n", Scan.Lower[i]:10 : 2, Scan.Upper[i] : 10 : 2, Scan.Step[i] : 10 : 2, Scan.counts[i] : 5);
	WritePolSet(Outfile, fileoutput, i);
	if(Scan.Average[i] == Point)
		Write(Outfile, ' P ');
	else
		if(Scan.Average[i] == Interval)
			Write(Outfile, ' I ');
	Writeln(outfile, '  ', Scan.averageno[i]);
*/
}
//		(*****************************************************************************)
//
//
//			Procedure WriteScans(Var Logfile : Text; fileoutput:boolean);
//
//
//		Var
//		first : boolean;
//		firstNo,
//			i, k, l, j:integer;
//
//		begin
//		k : = 0;
//	l: = 0;
//		For i : = 1 to Scan.I do
//		begin
//			If Scan.Selected[i] then
//			begin
//		k : = k + 1;
//	first: = true;
//		For j : = 1 to Number_Settings do
//		begin
//		if PolSetChosen[i, j] then
//			begin
//		l : = l + 1;
//		if (j = Number_settings) then
//		if l<10 then write(logfile, Scan.Name, '.D0', l, ' ')
//		else  write(logfile, Scan.Name, '.D', l, ' ')
//		else   if first then
//		begin
//	firstNo : = l;
//	first: = false;
//		if l<10 then write(logfile, Scan.Name, '.D0', l, '-')
//		else  write(logfile, Scan.Name, '.D', l, '-');
//		end;
//
//		end;
//		end;
//		WriteScanLine(Logfile, fileoutput, i)
//
//			end;
//		end;
//		writeln(Logfile);
//
//		end;
//
//		(***********************************************************************)
//			Procedure WriteLogfile;
//
//		Var
//			bredde,
//		intens:Real;
//		counts,
//		sensitivity:LongInt;
//		Ypos,
//			i, k,
//		Posistreng : Integer;
//		control,
//			streng,
//			Logfilename,
//		fn:string;
//	Logfile:text;
//		Year, Month, Day, Dayno, Hour, Min, Sec, Sec100 : WORD;
//	Done: Boolean;
//
//		Begin
//			ClrScr;
//		Writeln('Information about the experiment can be saved on log-file.');
//		Write('You will create:     ');
//	fn: = Concat(Scan.Name, '.LOG');
//		TextColor(White);
//		Writeln(fn);
//		TextColor(lightgray);
//		Textbackground(black);
//		If funnet(fn) then
//			begin
//			If funnet('Old.Log') then
//			begin
//			Assign(Logfile, 'Old.Log');
//		Erase(Logfile);
//		end;
//		Assign(Logfile, fn);
//		Rename(Logfile, 'Old.Log');
//		Write('File already exists! Old file renamed to ');
//		Textcolor(White);
//		Writeln('OLD.LOG!');
//		TextColor(lightgray);
//
//		end;
//		Writeln('------------------------------------------------------------------------------');
//		ASSIGN(Logfile, fn);
//		REWRITE(Logfile);
//		{ Skriver ut tidspunkt for utskriften: }
//		GetDate(Year, Month, Day, Dayno);
//		GetTime(Hour, Min, Sec, Sec100);
//		WRITELN(Logfile, 'Date : ', Day:2, '/', Month : 2, '/', Year : 4);
//		WRITELN(Logfile, 'Time : ', Hour:2, ':', Min : 2, ':', Sec : 2);
//		WRITELN;
//		Writeln(logfile, 'Measurements being made:');
//		Writeln(logfile, '');
//		Writeln(logfile, 'File      Lower    Upper   Step Counts  Pol');
//		Writeln(logfile, '');
//		WriteScans(logfile, Onfile);
//		Writeln;
//		WRITELN(Logfile, '');
//		WRITELN('Date : ', Day:2, '/', Month : 2, '/', Year : 4);
//		WRITELN('Time : ', Hour:2, ':', Min : 2, ':', Sec : 2);
//		Writeln;
//		Writeln(output, 'Measurements being made:');
//		Writeln(output, '');
//		Writeln(output, 'File       Lower    Upper   Step Counts  Pol');
//		Writeln(output, '');
//		WriteScans(output, Onscreen);
//	Ypos: = WhereY;
//		WRITELN('Laserintensity         (mW) :');
//		WRITELN('Width of slits         (mm) :');
//		WRITELN('PC sensitivety   (counts/s) :');
//		WRITELN('PC counts          (counts) :');
//		KeyBuffer;
//		GotoXY(32, Ypos);
//		ReadReal(intens);
//		GotoXY(32, Ypos + 1);
//		ReadReal(bredde);
//		GotoXY(32, Ypos + 2);
//		ReadLongInt(sensitivity);
//		GotoXY(32, Ypos + 3);
//		ReadLongInt(counts);
//
//		{ Skriver ut kompletterende fors�ksbetingelser p� fil : }
//		WRITELN(Logfile, 'Laserintensity         (mW) : ', intens:4 : 1);
//		WRITELN(Logfile, 'Width of slits         (mm) : ', bredde:5 : 3);
//		WRITELN(Logfile, 'PC sensitivety   (counts/s) : ', sensitivity);
//		WRITELN(Logfile, 'PC counts          (counts) : ', counts);
//	Done: = false;
//		WRITELN('You may now write additional information about you experiment (Esc to exit).');
//		REPEAT
//			ReadLine(Streng, Done);
//		Writeln(LogFile, Streng);
//		UNTIL Done;
//		Close(Logfile);
//	LogWritten: = True;
//		End;
//
//
//
/*void ShowScanPlan(bool Exit)
{
	************************************************************
		*       ***   Procedure   Description  ***                   *
		*                                                            *
		* NAME      : PrintScanList                                  *
		* FUNCTION : Prints file containing scan list               *
		*                                            on screen.      *
		* BRUKES AV : RetieveScanList, Raman                         *
		* DATO : 92.10.21                                       *
		*                                                            *
		************************************************************

	int	I, k, j, l;

	std::cout << "You have chosen the following measurements:\n";
	std::cout << " #  Lower-    UpperLimit   Step   Counts  Position of Pol.  Average   #\n";
	k = 0;
	l = 0;

	For i : = 1 to Scan.I do
	If Scan.Selected[i] then
		begin
		For j : = 1 to Number_Settings do
	if PolSetChosen[i, j] then  l : = l + 1;
k: = k + 1;
	Write(k:2);
	WriteScanLine(Output, onscreen, i);
	end;
	Writeln;
	PrepareStorage(Exit, k, l);
	If Not Exit Then
		Begin
		ClrScr;
	Write('Do you wish to write LOG - file now?  y');
	GotoXY(WhereX - 1, WhereY);
	If Defaultyes then WriteLogfile;
	End;
}*/

//
//
//
//
//		PROCEDURE PrintScanList;
//
//		/*************************************************************
//			*       ***   Procedure   Description  ***                   *
//			*                                                            *
//			* NAME      : PrintScanList                                  *
//			* FUNCTION : Prints file containing scan list               *
//			*                                            on screen.      *
//			* BRUKES AV : RetieveScanList, Raman                         *
//			* DATO : 92.10.21                                       *
//			*                                                            *
//			*************************************************************/
//
//		Var
//		I : integer;
//
//
//		Begin
//			Writeln;
//		Textcolor(white);
//		Writeln(' #  Lower-    UpperLimit   Step   Counts  Position of Pol.  Average   #');
//		Textcolor(lightgray);
//		writeln;
//		For i : = 1 to Scan.I do
//		If Scan.Selected[i] then
//			begin
//			Textbackground(white);
//		Textcolor(black);
//		Write(i);
//		WriteScanLine(Output, onscreen, i);
//		Textbackground(black);
//		Textcolor(lightgray);
//		end
//		else  begin
//		Write(i);
//		WriteScanLine(Output, OnScreen, i);
//		end;
//		Writeln;
//		end;
//
//
//
//
//		Procedure CheckScanParameters(VAR status : BOOLEAN; start, Stop,
//		step:Real);
//
//		/*************************************************************
//			*             ***  PROSEDYRE - BESKRIVELSE  ***                *
//			*                                                            *
//			* NAVN      : CheckScanParameters                            *
//			* FUNKSJON : Checks scan parameters for inconsistencies     *
//			*             before the start of the scan.                  *
//			* DATO : 17.09.90                                       *
//			*                                                            *
//			*************************************************************/
//
//		VAR  NoPts : INTEGER;
//
//		BEGIN
//		status : = true;
//
//		IF(Step = 0) THEN
//			BEGIN
//			GoToXY(1, 3);
//		WRITE('ERROR: Too small intervals.');
//	status: = false
//		END;
//
//	{ Avoid division by zero : }
//			IF(Step = 0) THEN
//			NoPts : = 100
//					ELSE
//				NoPts : = TRUNC(ABS((Stop - Start)) / Step + 1);
//
//			IF(NoPts > MaxPoints) THEN
//				BEGIN
//				WRITE(' ERROR: Too many measurement points.');
//		status: = false
//			END;
//
//				END;   { CheckScanParameters }
//
//
//				Procedure SaveScanList;
//
//				/*************************************************************
//					*       ***   Procedure   Description  ***                   *
//					*                                                            *
//					* NAME      : SaveScanList                               *
//					* FUNCTION : Saves file containing scan list(default:      *
//					*             SCAN.LST).The File is printed on screen.      *
//					*             The user may change the data.                  *
//					* BRUKES AV : *
//					* DATO : 92.10.21                                       *
//					*                                                            *
//					*************************************************************/
//				Var
//					FirstLetter,
//				Filename : string;
//				Exit,
//				Save : boolean;
//			File_1: Text;
//				Startposition,
//					CursorPosition,
//				index : integer;
//
//				begin
//				Exit : = false;
//			Save: = true;
//				Repeat
//					ClrScr;
//				GotoXY(15, 2);
//				Write('Save Scan list on file');
//				GotoXY(15, 3);
//				Write('**********************');
//				GotoXY(5, 10);
//			CursorPosition: = 1;
//				Write('Scan list to be saved as: ');
//			FileName: = Concat(Scan.Name, '.LST');
//				ReadWord(FileName);
//				If Funnet(FileName) THEN
//					BEGIN
//					GotoXY(5, 20);
//				Write('The file ');
//				(*Textcolor(16); *)
//					WRITE(Filename);
//				(*TextColor(15);  *)
//					Writeln(' already exists! Data might be overwritten!');
//				WRITE('Save? [y/n] :  Y');
//				GotoXY(WhereX - 1, WhereY);
//			Save: = DefaultYes;
//			Exit: = Not(Save);
//				END;
//
//				UNTIL   Save or Exit;
//
//				IF Save THEN
//					BEGIN
//					Scan.Name: = Filename;
//				Delete(Scan.Name, (Length(Scan.Name) - 3), 4);
//				ClrScr;
//				ASSIGN(File_1, Filename);
//				REWrite(File_1);
//			Index: = 0;
//				Writeln(File_1, 'No.     Lower    Upper   Step Counts  Pol');
//				Writeln(File_1, Scan.I);
//				Writeln(File_1);
//				For Index : = 1 to Scan.I do  WriteScanLine(File_1, OnFile, Index);
//				CLOSE(File_1);
//				Scan.altered: = False;
//				WRITELN;
//				WRITELN('Ok!  Data saved on file ', FileName, '!');
//				Writeln;
//				END;
//
//
//				KeyBuffer;
//				WRITELN;
//				WRITE('Press <ESC> for menu : ');
//				WaitFor(Esc);
//				end;
//
//				Procedure SortData(k, j:Integer);
//
//				var
//				i : integer;
//				begin
//					Scan.Lower[k]: = Scan.Lower[j];
//				Scan.Upper[k]: = Scan.Upper[j];
//				Scan.Counts[k]: = Scan.Counts[j];
//				Scan.Step[k]: = Scan.Step[j];
//				Scan.Pol[k]: = Scan.Pol[j];
//				Scan.Average[k]: = Scan.Average[j];
//				Scan.AverageNo[k]: = Scan.AverageNo[j];
//				For i : = 1 to Number_settings do
//				PolSetChosen[k, i] : = PolSetChosen[j, i];
//
//				end;
//
//				/*************************************************************/
//				Procedure DeleteScan;
//
//				var number : string;
//				i, j, code:integer;
//				begin
//				number : = 'a';
//				while (Number<>'') do
//				begin
//					clrScr;
//				Writeln('Input number of scan to be deleted (CR to quit):  ');
//				writeln;
//				PrintScanList;
//				GotoXY(1, 2);
//				Readln(number);
//				If(number<>'') then
//					begin
//					val(number, i, code);
//				If(code = 0) and(i <= Scan.i) then
//					begin
//					Scan.Altered: = true;
//				for j: = i to(Scan.I - 1) do SortData(j, j + 1);
//				Scan.I: = Scan.I - 1;
//				end
//		else write('No scan to be deleted');
//				end;
//				end;
//				end;
//				/*************************************************************/
//				Procedure InsertScan(var i : integer);
//
//				var
//				number : string;
//				k, j, code:integer;
//				begin
//					If Scan.I = 20 then
//					begin
//					writeln('There are allready 20 Scans in my memory!');
//				write('You HAVE to delete some Scans. Ok?   Y');
//				GotoXY(WhereX - 1, WhereY);
//				If Defaultyes then DeleteScan;
//				end;
//				clrScr;
//				Writeln('Input number of scan to be inserted (CR to quit):  ');
//				Writeln;
//				PrintScanList;
//				GotoXY(1, 2);
//				If(Scan.I<20) then
//					begin
//
//					Readln(number);
//				If(number<>'') then
//					begin
//					val(number, i, code);
//				If(code = 0) and(i <= 20) then
//					begin
//					Scan.Altered: = true;
//				for j: = (Scan.I) downto i do  SortData(j + 1, j);
//				if i>Scan.I then i : = Scan.I + 1;
//				Scan.I: = Scan.I + 1;
//				Scan.Lower[i]: = 0;
//				Scan.Upper[i]: = 0;
//				Scan.Counts[i]: = 0;
//				Scan.Step[i]: = 0;
//				Scan.Pol[i]: = 0;
//				Scan.Average[i]: = Interval;
//				Scan.AverageNo[i]: = 0;
//				Scan.selected[i]: = false;
//				For k : = 1 to Number_settings do
//				PolSetChosen[i, k] : = False;
//				end
//				else write('No scan to be inserted');
//				end
//		else i: = -Maxint;
//				end;
//				end;
//				/*************************************************************/
//				Procedure CopyScan;
//
//				var
//				number : string;
//				ypos,
//					xpos,
//					i, k, j, l, code:integer;
//				begin
//					If Scan.I = 20 then
//					begin
//					writeln('There are allready 20 Scans in my memory!');
//				write('You HAVE to delete some Scans. Ok?   Y');
//				GotoXY(WhereX - 1, WhereY);
//				If Defaultyes then DeleteScan;
//				end;
//				clrScr;
//				Write('Input number of scan to be copied (CR to quit):  ');
//			xpos: = whereX;
//			ypos: = wherey;
//				GotoXY(1, 4);
//				PrintScanList;
//				If(Scan.I<20) then
//					begin
//					GotoXY(Xpos, ypos);
//				Readln(number);
//				If(number<>'') then
//					begin
//					val(number, i, code);
//				If(code = 0) and(i <= 20) then
//					begin
//					Write('Input number of scan to be copied to:  ');
//				GotoXY(Xpos, ypos + 1);
//				Readln(number);
//				val(number, k, code);
//				if k>Scan.I then k : = Scan.I + 1;
//				Scan.Altered: = true;
//				Scan.I: = Scan.I + 1;
//				for j: = Scan.I downto k do SortData(j + 1, j);
//				SortData(k, i);
//				end
//				else write('No scan to be copied');
//				end;
//				end;
//				end;
//				/*************************************************************/
//
//				Procedure WriteHeading;
//
//
//				Begin
//					ClrScr;
//				Textcolor(black);
//				Textbackground(white);
//				Writeln('Number-Edit Line  i-insert d-delete  c-copy ESC-Exit');
//				Textbackground(black);
//				Textcolor(white);
//				writeln;
//				PrintScanList;
//				Writeln('- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -');
//				Textcolor(lightgray);
//				Writeln;
//
//				End;
//
//				Procedure ChangeScanList;
//
//				(**************************************************************************
//					*      ******      Procedure - Description ******                         *
//					*                                                                         *
//					*   Name      :   ChangeScanList                                          *
//					*   Function : Prints existing ScanList on Screen                      *
//					*                 Asks for Linenumber to be edited.Exit by 0 or ESC      *                *
//					***************************************************************************)
//					CONST  MaxLength = 256;
//				Tabspace = 10;
//				MiniTabspace = 3;
//
//
//				Var
//					Rightmargin,
//				Leftmargin:integer;
//				Lower,
//					Upper,
//				Step:real;
//				Counts,
//
//					ScanNo,
//					code,
//					start,
//					aveNo,
//					xpos,
//					ypos,
//					inputposition,
//					i, k,
//				Cursor: integer;
//				Nextstring,
//					Instring,
//				LineNo : string;
//				DataOK,
//					newnumber,
//				ok : BOOLEAN;
//			mean:avemode;
//			Polarizer: Array[1..6] of boolean;
//			Tabsetting: Array[1..14] of integer;
//
//
//
//				Function Tab(move : integer) :Integer;
//
//				begin
//				inputposition : = inputposition + move;
//				if inputposition>13 then inputposition : = 1;
//				if inputposition<1then inputposition: = 13;
//			Tab: = Tabsetting[inputposition];
//
//				end;
//				Procedure InitializeTab;
//
//				Begin
//					Tabsetting[1]: = 3;
//				Tabsetting[2]: = 13;
//				Tabsetting[3]: = 23;
//				Tabsetting[4]: = 33;
//				Tabsetting[5]: = 38;
//				Tabsetting[6]: = 41;
//				Tabsetting[7]: = 44;
//				Tabsetting[8]: = 47;
//				Tabsetting[9]: = 50;
//				Tabsetting[10]: = 53;
//				Tabsetting[11]: = 56;
//				Tabsetting[12]: = 59;
//				Tabsetting[13]: = 62;
//				Tabsetting[14]: = 70;
//				End;
//
//
//				Procedure TranslateInput;
//
//
//
//				Begin
//
//					case inputposition of
//					1: Lower : = StrToReal(Nextstring);
//				2    : Upper : = StrToReal(Nextstring);
//				3    : Step : = StrToReal(Nextstring);
//				4    : Counts : = StrToInt(Nextstring);
//				13   : AveNo : = StrToInt(Nextstring);
//				end;
//			Nextstring: = '';
//				end;
//				(***************************************************************************)
//
//
//					Begin(*Begin 1 : main *)
//					InitializeTab;
//			Rightmargin: = 6 + Number_Settings;
//			Leftmargin: = 1;
//
//				Textcolor(white);
//				If  Scan.Loaded = false then
//					begin
//					ClrScr;
//				Writeln('There is no Scan List in my memory! Press ESC.');
//				Waitfor(ESC);
//				end
//				else
//				begin
//				WriteHeading;
//			Cursor: = 1;
//				GotoXY(Cursor, 2);
//			LineNo: = Readkey;
//				While(LineNo<>ESC) and(LineNo<>CR) do
//				begin(*while loop*)
//					GotoXY(Cursor, 2);
//				ClrEol;
//				Write(LineNo);
//			Instring: = Readkey;
//				If(LineNo = 'C') or(LineNo = 'c') then CopyScan
//				else
//				begin
//				If(LineNo = 'D') or(LineNo = 'd') then DeleteScan
//				  else
//				  begin
//				  If(LineNo = 'I') or(LineNo = 'i') then InsertScan(ScanNo)
//					  else
//					  begin
//					  If Instring<>CR Then
//					  begin
//					  Write(LineNo);
//				  LineNo: = Concat(LineNo, Instring);
//			  Instring: = readkey;
//			  end;
//		  ScanNo: = StrToInt(LineNo);
//			  end;
//
//		  Instring: = '';
//			  If ScanNo >0 then
//				  begin
//			  Upper : = Scan.Upper[ScanNo];
//		  Lower: = Scan.Lower[ScanNo];
//		  Step: = Scan.Step[ScanNo];
//		  Counts: = Scan.Counts[ScanNo];
//			  For K : = 1 to 7 do
//			  Polarizer[k] : = PolSetChosen[ScanNo, k];
//		  Mean: = Scan.Average[ScanNo];
//		  AveNo: = Scan.AverageNo[ScanNo];
//			  GotoXY(1, 1);
//			  TextBackground(white);
//			  Textcolor(Black);
//			  Write('<== Left  ==> Right  SPACE Switch alphabetic positions  CR Exit/Save  ESC Quit');
//			  TextBackground(black);
//			  Textcolor(white);
//			  GoToXY(1, 2);
//			  Write(ScanNo);
//			  WriteScanLine(Output, OnScreen, ScanNo);
//			  GoToXY(1, 3);
//			  Write(ScanNo);
//			  WriteScanLine(Output, OnScreen, ScanNo);
//		  Inputposition: = 1;
//			  GotoXY(Tab(0), 3);
//		  Nextstring: = '';
//		  NewNumber: = true;
//			  While(Instring <>CR) and(Instring <> ESC) do
//			  begin
//			  Instring : = Readkey;
//			  If(Instring = #0) or(Instring = Space)  then
//				  Begin
//			  Newnumber : = true;
//			  If Nextstring<>'' Then TranslateInput;
//
//
//			  If Instring = Space then
//				  begin
//				  If(Inputposition>4) and(Inputposition<12)
//				  then
//				  begin
//			  K : = Inputposition - 4;
//			  PolSetChosen[ScanNo, k]: = Not(PolSetChosen[ScanNo, k]);
//			  GotoXY(WhereX - (k - 1) * 3 - 1, WhereY);
//			  WritePolSet(Output, OnScreen, ScanNo);
//			  end;
//			  If(Inputposition = 12) then
//				  Begin
//				  If(mean = Interval) then
//				  begin
//			  mean : = Point;
//			  write('P');
//			  end
//										else
//										begin
//									mean : = Interval;
//									write('I');
//									end;
//									End;
//									end
//						  else  Instring: = Readkey;
//									If Instring = #75 then  GotoXY(tab(-1), 3);
//									If(Instring = #77) or(Instring = Space) then
//										GotoXY(tab(1), 3);
//									end
//					else
//					If(Instring<>Cr) and(Instring<>ESC) and
//					((Inputposition<5) or(Inputposition>12)) then
//					begin
//					If Newnumber then
//					begin
//					for i: = 1 to(tabsetting[inputposition + 1] -
//						tabsetting[inputposition]) do write(' ');
//						GotoXY(Tab(0), WhereY);
//				Newnumber: = false;
//					end;
//					If(Instring = Backspace)and(WhereX>Tab(0)) then
//						begin
//						write(Backspace, ' ', Backspace);
//
//					Delete(Nextstring, Length(Nextstring), 1);
//					end
//							else
//					if (Instring<>Backspace) then
//						begin
//						write(Instring);
//				Nextstring: = Concat(Nextstring, Instring);
//					end;
//					end;
//					end;
//					If Instring = CR then
//						begin
//						If Nextstring<>'' Then TranslateInput;
//					Scan.Altered: = true;
//					Scan.Upper[ScanNo]: = Upper;
//					Scan.Lower[ScanNo]: = Lower;
//					Scan.Step[ScanNo]: = Step;
//					Scan.Counts[ScanNo]: = Counts;
//					Scan.Average[ScanNo]: = mean;
//					Scan.AverageNo[ScanNo]: = AveNo;
//					CheckScanParameters(DataOK, Lower, Upper, Step);
//					GotoXY(1, 3);
//					WriteScanLine(Output, Onscreen, ScanNo);
//					If DataOK then
//						begin
//						Textcolor(white);
//					GotoXY(1, 2);
//					WriteScanLine(Output, Onscreen, ScanNo);
//				Inputposition: = 1;
//					Textcolor(lightgray);
//					GotoXY(1, 3);
//					ClrEol;
//					end
//					else Instring: = '';
//					end;
//					If Instring = ESC then
//						For k : = 1 to Number_Settings do PolSetChosen[ScanNo, k] : = Polarizer[k];
//					end;
//					end;
//					end;
//					WriteHeading;
//
//				Cursor: = 1;
//					GotoXY(Cursor, 3);
//				LineNo: = Readkey;
//					end;
//					end;
//					If Scan.altered then
//						begin
//						ClrScr;
//					GotoXY(5, 5);
//					Write('You changed the Scanlist!');
//					GotoXY(5, 7);
//					Write('Do you want to save changes? (Y/N):  Y');
//					GotoXY(WhereX - 1, WhereY);
//					If DefaultYes then SaveScanlist;
//
//					end;
//					end;
//

/*************************************************************/

/*void RetrieveScanList(void)
{
	************************************************************
		*       ***   Procedure   Description  ***                   *
		*                                                            *
		* NAME      : RetrieveScanList                               *
		* FUNCTION : Loads file containing scan list(default:      *
		*             SCAN.LST).The File is printed on screen.      *
		*             The user may change the data.                  *
		* BRUKES AV : *
		* DATO : 92.10.21                                       *
		*                                                            *
		************************************************************
	std::string FirstLetter, Filename;
	bool success, retry;
	std::string File_1;
	int Startposition, CursorPosition, index;
	char character;

	do
	{
		ClrScr();
		std::cout << "Retrival of Scan list\n";
		std::cout << "*********************\n";
		Filename = "SCAN.LST";
		std::cout <<  "You want to open the scan list named: \n";
		std::cin >> Filename;
		if (Filename.empty())
			retry = false;
		else
		{
			success = Funnet(Filename);
			if (!success)
			{
				std::cout << "The File ";
				std::cout << Filename;
				std::cout << " does not exist.\n";
				std::cout << "Do you want to search for another file ? [y/n] : ";
				retry = YesOrNoQuery();
			}
		}
	} while (!success && retry);

	if (success)
	{
		ClrScr();
		ScanPrepOK = false;
		Scan.name: = FileName;
		Delete(Scan.Name, Length(Scan.Name) - 3, 4);
		ASSIGN(File_1, Filename);
		RESET(File_1);
		Readln(File_1);
		Readln(File_1, Scan.I);
		Readln(File_1);
		For Index : = 1 to Scan.I do
		BEGIN
			READ(File_1, Scan.Lower[Index], Scan.Upper[Index], Scan.Step[Index],
			Scan.Counts[Index]);
		ReadFile_PolSet(File_1, Index);
		Repeat
			Read(File_1, character);
		Until(Character = 'I') or(Character = 'P');
		Case character of
			'I' : Scan.Average[Index] : = Interval;
		'P' : Scan.Average[Index] : = Point;
		end;
		Read(File_1, Scan.AverageNo[Index]);
		Scan.Selected[Index]: = false;
		END;
		CLOSE(File_1);
		Scan.loaded: = true;
		WRITELN;
		WRITELN('Ok! The data of file ', FileName, ' is at your disposal:');
		Writeln;
		PrintScanList;
		Textcolor(white);
		Write('Do you wish to make any changes? - [y/n]  Y');
		GotoXY(WhereX - 1, WhereY);
		If DefaultYes then ChangeScanList;
		Textcolor(lightgray);
		END;

	}
}*/

//	   PROCEDURE FetchData(VAR Data : Spectrum);
//
//	   /*************************************************************
//		   *             ***  PROSEDYRE - BESKRIVELSE  ***                *
//		   *                                                            *
//		   * NAVN      : FetchData                                      *
//		   * FUNKSJON : Henter data fra DAT.og DOC. - filene.Data      *
//		   *             leses til de globale variable og innholdet i   *
//		   *             DOC. - filen skrives til skjerm.                 *
//		   * BRUKES AV : DataLagring                                    *
//		   * DATO : 88.10.11                                       *
//		   *                                                            *
//		   *************************************************************/
//
//	   VAR  Fil_1, Fil_2 : TEXT;
//	   Filnavn, Navn1, Navn2 : FileName;
//   Filtekst: STRING[80];
//   index: INTEGER;
//	   Slett, success, retry : BOOLEAN;
//
//	   BEGIN
//		   IF(Antall > 0) THEN
//		   BEGIN
//		   GotoXY(5, 20);
//	   WRITE('Do you want to delete the current spectrum ?  [y/n] : ');
//   Slett: = YesOrNoQuery
//	   END
//	   ELSE
//   Slett : = TRUE;
//
//		  IF Slett THEN
//			  BEGIN
//			  FlushData(Data);   { Sletter eksisterende data i hovedminnet }
//		  (*ListDataDir; *)
//
//		  {
//				  Leser inn filnavn :
//			  }
//		  REPEAT
//			  WRITELN;
//		  WRITELN;
//		  KeyBuffer;
//		  WRITE('Filename (without A: and .DAT) : ');
//		  READLN(Filnavn);
//	  Navn1: = CONCAT(DrevA, Filnavn, '.DAT');   { Fil med m�ledata }
//	  Navn2: = CONCAT(DrevA, Filnavn, '.DOC');   { Fil med informasjon om m�ling }
//	  success: = Funnet(Navn1);
//		  IF NOT success THEN
//			  BEGIN
//			  WRITELN('This file does not exist.');
//		  WRITE('Do you want to search for another file ? [y/n] : ');
//	  retry: = YesOrNoQuery
//		  END;
//			 UNTIL success OR NOT retry;
//
//			 IF success THEN
//				 BEGIN
//				 ClrScr;
//
//			 IF(Funnet(Navn2)) THEN
//				 BEGIN
//				 ASSIGN(Fil_2, Navn2);
//			 RESET(Fil_2);
//			 WRITELN('Documentation on file ', Navn2, ' :');
//			 WRITELN;
//			 WHILE(NOT EOF(Fil_2)) DO
//				 BEGIN{ Informasjonen skrives til skjerm }
//			 READLN(Fil_2, Filtekst);
//			 WRITELN('    ', Filtekst);
//			 END;
//			 CLOSE(Fil_2);
//			 END
//				 ELSE
//				 WRITELN('The DOC-file does not exist.');
//
//
//			 ASSIGN(Fil_1, Navn1);
//			 RESET(Fil_1);
//		 index: = 0;
//			 WHILE(NOT EOF(Fil_1)) DO
//				 BEGIN
//				 Inc(index);
//			 READ(Fil_1, Data[index, 1], Data[index, 2]);
//			 END;
//			 CLOSE(Fil_1);
//
//		 Antall: = index - 1;
//
//			 WRITELN;
//			 WRITELN('The data in file ', Navn1, ' are fetched.');
//			 END;
//
//
//			 KeyBuffer;
//			 WRITELN;
//			 WRITE('Press <ESC> for menu : ');
//			 WaitFor(Esc);
//			 END;
//
//			 END;     { FetchData }
//
//
//
//			 PROCEDURE KontrollerFilplass(Drev : WORD; Testfil: FileName);
//
//			 /*************************************************************
//				 *            ***  PROSEDYRE - BESKRIVELSE  ***                 *
//				 *                                                            *
//				 * NAVN      : KontrollerFilplass                             *
//				 * FUNKSJON : Kontrollerer at det er plass til dataene i     *
//				 *             LumiSpectrum p� disketten i drevet.            *
//				 * BRUKES AV : StoreData                                          *
//				 * DATO : 10.07.89                                       *
//				 *                                                            *
//				 *************************************************************/
//
//			 CONST   Margin = 200;
//		 Linjelengde: LONGINT = 30;
//
//			 VAR     MinSize : LONGINT;
//		 Fil_aux: TEXT;
//		 kontroll: BOOLEAN;
//
//			 BEGIN
//				 REPEAT
//			 kontroll : = TRUE;
//			 ASSIGN(Fil_aux, testfil);
//			 {$I - }
//			 REWRITE(Fil_aux);
//			 CLOSE(Fil_aux);
//			 {$I + }
//			 IF(IOResult = 0) THEN
//				 BEGIN
//			 MinSize : = Antall * Linjelengde + Margin;
//			 IF DiskFree(Drev) < MinSize THEN
//				 BEGIN
//				 WRITELN('Datadisketten er full.');
//			 WRITELN('Ledig plass : ', DiskFree(Drev), ' bytes',
//				 '  Behov : ', MinSize, ' bytes.');
//		 kontroll: = FALSE;
//			 END;   { IF DiskFree ...}
//			 END
//				 ELSE
//				 BEGIN
//				 WRITELN('Datadisketten mangler / er skrivebeskyttet.');
//		 kontroll: = FALSE;
//			 END;   { IF IORESULT ...}
//
//			 IF NOT kontroll THEN
//				 BEGIN
//				 WRITELN('Sett inn en 360K formatert floppy-disk i drev A: .');
//			 KeyBuffer;
//			 WRITE('Trykk s� <CR> : ');
//			 WaitFor(CR);
//			 WRITELN;
//			 END;
//			 UNTIL kontroll;
//
//			 END;       { KontrollerFilplass }
//
//
//
//
//			 PROCEDURE LesFilnavn(VAR Navn1, Navn2 : FileName);
//
//			 /*************************************************************
//				 *            ***  PROSEDYRE - BESKRIVELSE  ***                 *
//				 *                                                            *
//				 * NAVN      : LesFilnavn                                     *
//				 * FUNKSJON : Leser fra tastatur hvilket filnavn data skal   *
//				 *             skrives til.                                   *
//				 * BRUKES AV : StoreData                                          *
//				 * DATO : 88.10.11                                       *
//				 *                                                            *
//				 *************************************************************/
//
//			 VAR  Filnavn : FileName;
//		 Filklar: BOOLEAN;
//		 svar: CHAR;
//
//			 BEGIN
//				 ClrScr;
//			 GotoXY(10, 3);
//			 WRITE('N�r en fil lagres vil tekstlinjer lagres',
//				 ' p� en fil med navn :');
//			 GotoXY(25, 5);
//			 WRITE('A:<Filnavn>.DOC');
//			 GotoXY(10, 7);
//			 WRITE('Alle data vil lagres p� en annen',
//				 ' fil med navn :');
//			 GotoXY(25, 9);
//			 WRITE('A:<Filnavn>.DAT');
//
//		 Filklar: = FALSE;
//
//			 REPEAT
//				 KeyBuffer;
//			 GotoXY(10, 14);
//			 WRITE('Filnavn (Max 8 bokstaver, bruk ikke A: eller . ) : ');
//			 READLN(Filnavn);
//		 Filnavn: = COPY(Filnavn, 1, 8);
//		 Navn1: = CONCAT(DrevA, Filnavn, '.DAT');
//		 Navn2: = CONCAT(DrevA, Filnavn, '.DOC');
//
//			 IF Funnet(Navn1) THEN
//				 BEGIN
//				 GotoXY(10, 16);
//			 WRITE('Filen ', Navn1, ' eksisterer allerede, skal den slettes ? [y/n] : ');
//		 Filklar: = YesOrNoQuery;
//			 IF NOT filklar THEN
//				 BEGIN
//				 GotoXY(1, 16);
//			 ClrEol;
//			 GotoXY(1, 14);
//			 ClrEol
//				 END;
//			 END
//				 ELSE
//			 Filklar : = TRUE;
//			 UNTIL Filklar;
//
//			 ClrScr;
//
//			 END;    { LesFilnavn }
//
//
//			 PROCEDURE StoreData(VAR Data : Spectrum; k:integer);
//
//			 /*************************************************************
//				 *            ***  PROSEDYRE - BESKRIVELSE  ***                 *
//				 *                                                            *
//				 * NAVN     : StoreData                                       *
//				 * FUNKSJON : Skriver m�ledata til fil.                       *
//				 * BRUKES AV : Main and measurement routines.                  *
//				 * DATO : 88.10.11                                        *
//				 *                                                            *
//				 *************************************************************/
//
//			 VAR  Fil_1, Fil_2             : TEXT;
//			 Posistreng, index, Ypos  : INTEGER;
//			 Datnavn, Docnavn         : FileName;
//		 Streng: STRING[150];
//			 temp, intens, bredde     : REAL;
//			 sensitivity, counts      : LONGINT;
//			 Year, Month, Day, Dayno, Hour, Min, Sec, Sec100 : WORD;
//
//			 BEGIN
//				 Str(k, Datnavn);
//			 If k < 10 then Datnavn : = Concat(Scan.Name, '.D0', Datnavn);
//			 (*KontrollerFilplass(1, Datnavn);               *)  {
//				 1 = Drev A :
//			 }
//			 ASSIGN(Fil_1, Datnavn);
//			 REWRITE(Fil_1);
//			 FOR index : = 1 to Antall DO
//				 WRITELN(Fil_1, Data[index, 1]:8 : 2, '    '
//				 , Data[index, 2] : 8 : 2);
//			 CLOSE(Fil_1);
//
//			 END;                  {  StoreData  }
//
//
//			 END.            { Lagring   }

