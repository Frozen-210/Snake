# Snake
Simple console game. Written in C++ with ncurses.

### The idea
It started as an exercise in the JUNIOR .NET programming learning group.
I wrote my first Snake in C# and then even rewrote it to work on the WinRT platform.

### Requirements
* ncurses
* g++

I recommend compiling ncurses from [source](ftp://ftp.gnu.org/pub/gnu/ncurses/)

	curl -O ftp://ftp.gnu.org/pub/gnu/ncurses/ncurses-5.9.tar.gz
	tar -zxvf ncurses-5.9.tar.gz
	cd ncurses-5.9
	./configure
	make
	sudo make install

Or you can get them from your distribution

	apt install libncurses5-dev 

Then go into Snake folder and run

	make
	sudo make install

You will then run it with `md-snake`.

### Controls
Use arrows to move the snake, `p` to pause, `q` to quit

