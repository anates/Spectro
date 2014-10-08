#include "TPDECL.h"

/*****************************************************************************/

/*These three variables are to be accessed directly in application program. */

//unsigned int ibsta;			/*status word                       */
//unsigned int iberr;   		/*GPIB error code                   */
//unsigned int ibcnt;   		/*number of bytes sent or DOS error */

/*The following variables may be used directly in your application program. */

//names bname, bdname, flname;   			/*board name buffer, board or device name buffer, filename buffer */
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

int Port[1000] = { 0 }; //Is only used for debug, has to be removed before final compilation ???

//int found, our_lcv;

//void init(void)
//{
//	found = 0;	/*initialize successful ibfind flag */
//	ibsta = 0;	/*initialize global status variables */
//	iberr = 0;
//	ibcnt = 0;
//	for (our_lcv = 0; our_lcv < nbufsize; our_lcv++)
//	{
//		bname.nbuf[our_lcv] = ' ';
//		bdname.nbuf[our_lcv] = ' ';
//	}
//	for (our_lcv = 1; our_lcv < flbufsize; our_lcv++)
//	{
//		flname.flbuf[our_lcv] = ' ';
//	}
//}

