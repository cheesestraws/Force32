# Force32

If you want to use lots of memory on a classic Mac, you need to turn on 32-bit addressing (if the machine supports it).  However, this setting is stored in the battery-backed xPRAM.  A lot of us run our old Macs without PRAM batteries, simply in the interests of not finding battery leakage all over the place one morning.

That means that, normally, you have to turn it on, manually, every time you start using the machine.  This gets tiresome fast.

This extension solves that.  Put it early in your boot sequence (by putting a few spaces before the name).  It will, at load-time, check whether 32-bit addressing is enabled in the PRAM; if it is, it will just display its icon and continue.  Otherwise, it will flip the bits that enable 32-bit addressing (see [this page](http://okmij.org/ftp/xPRAM.html) for more details) and start booting all over again.

Note that it doesn't check whether the Mac can actually do 32-bit addressing before fiddling; so please make sure it can.  That said, it will behave properly with MODE32 if you rely on that for 32-bit addressing on Macs without 32-bit clean ROMs.

## How to build

I built this using CodeWarrior Pro 4.  Other versions will probably work.  It has no external dependencies.  Resource and project files are inside the .sit file.  It would probably be pretty straightforward to get it to work under THINK C, too, aside from the assembler (though the above linked page has pre-assembled routines that would be a good starting point).

## A note on licensing

It seems kind of absurd to explicitly license something that's basically three pieces of sample code bolted together.  My bits are BSD-licensed, but the rest is sample code that has been released with unclear licensing terms.

## Acknowledgements

I wish explicitly to acknolwedge Oleg Kiselyov for their xPRAM work linked above, and the many authors that ShowInitIcon seems to have passed through.
