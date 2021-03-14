#include "A4Stuff.h"
#include "SetupA4.h"
#include "ShowInitIcon.h"
#include "xpram.h"

const int kInitIcon = 128;
const int kYesIcon = 129;
const int kNoIcon = 130;

// weAre32Bit reads the 32-bit addressing status out of the xPRAM of the machine
// and returns true if we're currently set up for 32-bit addressing or false if not.
int weAre32Bit() {
	char membyte;
	read_xpram(&membyte, 0x8A, 1);
	
	if ((membyte & 5) != 5) {
		return false;
	}

	return true;
}

// force32On turns on the two bits that control 32-bit addressing in the xPRAM.
// Note, it dos not sanity check whether this will work or not...
void force32On() {
	char membyte;
	read_xpram(&membyte, 0x8A, 1);

	// clear bits 1 and 3
	membyte = (membyte | 5);
	
	write_xpram(&membyte, 0x8A, 1);
}

// restart restarts by jumping to the ROM entry point.  See Inside
// Macintosh II, p. 386.  Obviously, this never returns. 
asm void restart() {
	move.l 0x02AE, A0
	jmp 0x0A(A0)
}


void main(void)
{
	long	oldA4;	
	oldA4 = SetCurrentA4();
	RememberA4();
	
	ShowInitIcon(kInitIcon, false);
	
	if (weAre32Bit()) {
		ShowInitIcon(kYesIcon, true);
	} else {
		ShowInitIcon(kNoIcon, true);
		force32On();
		restart();
	}
	
	/* restore the a4 world */
	SetA4(oldA4);
}
