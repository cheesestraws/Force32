/* These two routines allow for reading and writing of arbitrary chunks of xPRAM,
   the extended PRAM that was introduced after the first generation of Macs.
   
   Credit for the implementations goes to Oleg Kiselyov, and more information can be found
   here: http://okmij.org/ftp/xPRAM.html
*/

asm void read_xpram(char* buf, const short offset, const short size) {
	fralloc
	clr.l d0
	move.w size, d0
	swap d0
	move.w offset, d0
	movea.l buf, a0
	dc.w 0xA051 // _ReadXPRam trap
	frfree
	rts
}

asm void write_xpram(char* buf, const short offset, const short size) {
	fralloc
	clr.l d0
	move.w size, d0
	swap d0
	move.w offset, d0
	movea.l buf, a0
	dc.w 0xA052 // _WriteXPRam trap
	frfree
	rts
}