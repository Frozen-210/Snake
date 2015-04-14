
main:
	g++ -o bin/snake src/snake.cpp -lncurses

debug:
	g++ -Wall -g -o bin/snake src/snake.cpp -lncurses

install:
	@echo;
	@echo "Installing..."
	@cp bin/snake /usr/local/bin/md-snake
	@echo "Installed successfully!"
	@echo "Run it with 'md-snake'"
