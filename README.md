#Snake#
Simple console game. Written in C++ with ncurses.

###The idea###
It started as an exercise in the JUNIOR .NET programming learning group.
I wrote my first Snake in C# and then even rewrote it to work on the WinRT platform.

[ASCII Snake in Windows Store](http://apps.microsoft.com/windows/en-us/app/ascii-snake/6003a256-6452-9b52-ea3b0b1d102c)

[ASCII Snake for Windows Phone](http://www.windowsphone.com/en-us/store/app/ascii-snake/6bdda75f-f752-43e1-d053748a5b76)

###Requirements###
* ncurses
* g++

I recommend compiling ncurses from [source](ftp://ftp.gnu.org/pub/gnu/ncurses/)

	curl -O ftp://ftp.gnu.org/pub/gnu/ncurses/ncurses-5.9.tar.gz
	tar -zxvf ncurses-5.9.tar.gz
	cd ncurses-5.9
	./configure
	make
	sudo make install

Then go into Snake folder and run

	make
	sudo make install

You will then run it with `md-snake`.

###Controls###
Use arrows to move the snake, `p` to pause, `q` to quit

