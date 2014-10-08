#include <iostream>
#ifdef WIN32
#include <windows.h>
#endif
#include <chrono>
#include <thread>

/*GPIB Commands : */
#define UNL  0x3f                       /*GPIB unlisten command             */
#define UNT  0x5f                       /*GPIB untalk command               */
#define GTL  0x01                       /*GPIB go to local                  */
#define SDC  0x04                       /*GPIB selected device clear        */
#define PPC  0x05                       /*GPIB parallel poll configure      */
#define GGET  0x08                       /*GPIB group execute trigger        */
#define TCT  0x09                       /*GPIB take control                 */
#define LLO  0x11                       /*GPIB local lock out               */
#define DCL  0x14                       /*GPIB device clear                 */
#define PPU  0x15                       /*GPIB parallel poll unconfigure    */
#define SPE  0x18                       /*GPIB serial poll enable           */
#define SPD  0x19   			/*GPIB serial poll disable          */
#define PPE  0x60   			/*GPIB parallel poll enable         */
#define PPD  0x70   			/*GPIB parallel poll disable        */

/*GPIB status bit vector : */

#define ERR  0x8000			/*Error detected                    */
#define TIMO  0x4000			/*Timeout                           */
#define UEND  0x2000			/*EOI or EOS detected               */
#define SRQI  0x1000			/*SRQ detected by CIC               */
#define RQS  0x800 			/*Device needs service              */
#define CMPL  0x100 			/*I / O completed                     */
#define LOK  0x80  			/*Local lockout state               */
#define REM  0x40  			/*Remote state                      */
#define CIC  0x20  			/*Controller - in - Charge              */
#define ATN  0x10  			/*Attention asserted                */
#define TACS  0x8   			/*Talker active                     */
#define LACS  0x4   			/*Listener active                   */
#define DTAS  0x2   			/*Device trigger state              */
#define DCAS  0x1   			/*Device clear state                */

/*Error messages returned in global variable IBERR : */

#define EDVR = 0                      /*DOS error                              */
#define ECIC = 1 		   	   /*Function requires GPIB board to be CIC */
#define ENOL = 2 		   	   /*Write function detected no Listeners   */
#define EADR = 3 		   	   /*Interface board not addressed correctly*/
#define EARG = 4 		           /*Invalid argument to function call      */
#define ESAC = 5 		   	   /*Function requires GPIB board to be SAC */
#define EABO = 6 		   	   /*I / O operation aborted                  */
#define ENEB = 7 		   	   /*Non - existent interface board           */
#define EOIP = 10		   	   /*I / O operation started before previous  */
/*operation completed                    */
#define ECAP = 11		   	   /*No capability for intended operation   */
#define EFSO = 12		   	   /*File system operation error            */
#define EBUS = 14		   	   /*Command error during device call       */
#define ESTB = 15		   	   /*Serial poll status byte lost           */
#define ESRQ = 16  		   /*SRQ remains asserted                   */

/*EOS mode bits : */

#define BIN  0x1000			/*Eight bit compare                 */
#define XEOS  0x800 			/*Send EOI with EOS byte            */
#define REOS  0x400 			/*Terminate read on EOS             */


/*Timeout values and meanings : */

#define TNONE 0  			/*Infinite timeout(disabled)      */
#define T10us 1  			/*Timeout of 10 us(ideal)         */
#define T30us 2  			/*Timeout of 30 us(ideal)         */
#define T100us 3  			/*Timeout of 100 us(ideal)         */
#define T300us 4  			/*Timeout of 300 us(ideal)         */
#define T1ms 5  			/*Timeout of 1 ms(ideal)         */
#define T3ms 6  			/*Timeout of 3 ms(ideal)         */
#define T10ms 7  			/*Timeout of 10 ms(ideal)         */
#define T30ms 8  			/*Timeout of 30 ms(ideal)         */
#define T100ms 9  			/*Timeout of 100 ms(ideal)         */
#define T300ms 10 			/*Timeout of 300 ms(ideal)         */
#define T1s 11 			/*Timeout of 1 s(ideal)         */
#define T3s 12 			/*Timeout of 3 s(ideal)         */
#define T10s 13 			/*Timeout of 10 s(ideal)         */
#define T30s 14 			/*Timeout of 30 s(ideal)         */
#define T100s 15 			/*Timeout of 100 s(ideal)         */
#define T300s 16 			/*Timeout of 300 s(ideal)         */
#define T1000s 17 			/*Timeout of 1000 s(maximum)       */

/*Miscellaneous:                                                            */

#define S  0x08   			/*Parallel poll sense bit           */
#define LF  0x0A   			/*ASCII linefeed character          */

/*****************************************************************************/

#define nbufsize 7		/*Length of board / device names -- hard - coded
in TPIB (WTF, why hardcoded?)*/
#define flbufsize 50		/*A generous length for filenames -- the
minimum allowed by the handler is 32.
50 is hard - coded in TPIB */

/*****************************************************************************/
//Has to be upgraded to dynamical memory
//struct names
//{
//	char nbuf[nbufsize];		/*device / board names   */
//	char flbuf[flbufsize];		/*filenames	    */
//};

extern int Port[1000];

/*****************************************************************************/

/*These three variables are to be accessed directly in application program. */

extern unsigned int ibsta;			/*status word                       */
extern unsigned int iberr;   		/*GPIB error code                   */
extern unsigned int ibcnt;   		/*number of bytes sent or DOS error */

/*The following variables may be used directly in your application program. */

//extern names bname, bdname, flname;   			/*board name buffer, board or device name buffer, filename buffer */
//
//void ibbna(int bd, struct names bname);
//
//void ibcac(int bd, int v);
//
//void ibclr(int bd);
//
//void ibcmd(int bd, int cmd, unsigned int cnt);
//
//void ibcmda(int bd, int cmd, unsigned int cnt);
//
//void ibdiag(int bd, int cmd, unsigned int cnt);
//
//void ibdma(int bd, int v);
//
//void ibeos(int bd, int v);
//
//void ibeot(int bd, int v);
//
//int ibfind(struct names bdname);
//
//void ibgts(int bd, int v);
//
//void ibist(int bd, int v);
//
//void ibloc(int bd);
//
//void ibonl(int bd, int v);
//
//void ibpad(int bd, int v);
//
//void ibpct(int bd);
//
//void ibppc(int bd, int v);
//
//void ibrd(int bd, int rd, unsigned int crt);
//
//void ibrda(int bd, int rd, unsigned int cnt);
//
//void ibrdf(int bd, struct names flbuf);
//
//void ibrpp(int bd, int ppr);
//
//void ibrsc(int bd, int v);
//
//void ibrsp(int bd, int spr);
//
//void ibrsv(int bd, int v);
//
//void ibsad(int bd, int v);
//
//void ibsic(int bd);
//
//void ibsre(int bd, int v);
//
//void ibstop(int bd);
//
//void ibtmo(int bd, int v);
//
//void ibtrap(unsigned int mask, int v);
//
//void ibtrg(int bd);
//
//void ibwait(int bd, unsigned int mask);
//
//void ibwrt(int bd, int wrt, unsigned int cnt);
//
//void ibwrta(int bd, int wrt, unsigned int cnt);
//
//void ibwrtf(int bd, struct names flname);

//void init(void);

