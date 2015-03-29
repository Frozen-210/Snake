#include <ncurses.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>

class Vector
{
	public:
		Vector() : x(0), y(0){}
		Vector(int x, int y) {setX(x); setY(y);}

		void setX(int x){this->x = x;}
		int getX() const {return this->x;}
		void setY(int y){this->y = y;}
		int getY() const {return this->y;}

		Vector& operator=(const Vector& vec)
		{setX(vec.getX()); setY(vec.getY()); return *this;}
		Vector& operator+=(const Vector& vec)
		{setX(getX()+vec.getX()); setY(getY()+vec.getY()); return *this;}
		Vector operator+(const Vector& vec)
		{Vector v(getX(),getY()); return v+=vec; }
		Vector& operator-=(const Vector& vec)
		{setX(getX()-vec.getX()); setY(getY()-vec.getY()); return *this;}
		Vector operator-(const Vector& vec)
		{Vector v(getX(),getY()); return v-=vec;}
		bool operator==(const Vector& vec)
		{return getX()==vec.getX() && getY()==vec.getY();}
		bool operator!=(const Vector& vec)
		{return !operator==(vec);}
			
	private:
		int x,y;
};

class Snake
{
	private:
		std::vector<Vector> body;
		Vector apple;
		Vector direction;
		int points;
		int level;
		int best;
		const int height;
		const int width;
		bool exit;
		int speed;
		bool move; //maybe unnecessary, otherwise move buffer
		char* table;
	public:
		Snake(int _height, int _width, int _best)
		: best(_best), height(_height), width(_width)
		{	getApple(); 
			body.push_back(Vector(height/2, width/2)); 
			setDirection(0); 
			exit=false; 
			speed=180; 
			level=1;
			srand(time(NULL));
			table = new char[height*width];
		}
		~Snake()
		{delete [] table;}

		void getApple()
		{
			int x = rand()%width;
			int y = rand()%height;
			apple = Vector(x,y);
			for(unsigned int i=0;i<body.size();++i)
				if(apple==body[i])getApple();
		}

		void setDirection(int d)
		{
			switch(d)
			{
				case 0:direction = Vector(0, -1); break;
				case 1:direction = Vector(1, 0); break;
				case 2:direction = Vector(0, 1); break;
				case 3:direction = Vector(-1, 0); break;
			}
		}
		
		void snakeMakeMove()
		{
			exit = false;
			if(body[0].getX()<0 || body[0].getX()>=width)
				exit = true;
			else if(body[0].getX()==0)
			{	if(direction==Vector(-1,0))
					exit = true;
			}
			else if(body[0].getX()==(width-1))
			{	if(direction==Vector(1,0))
					exit = true;
			}
			
			if(body[0].getY()<0 || body[0].getY()>=height)
				exit = true;
			else if(body[0].getY()==0)
			{
				if(direction==Vector(0,-1))
					exit = true;
			}
			else if(body[0].getY()==(height-1))
			{
				if(direction==Vector(0,1))
					exit = true;
			}
			if(!exit)body[0]+=direction;
		}
};

//------------------------------------
int getBest();
int main()
{
	initscr();
	int x,y;
	getmaxyx(stdscr, y, x);

	Snake snake(y, x, getBest());

	//game loop

	endwin();
}
FILE* getFile(const char* mode)
{
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	std::string home = "%appdata%";
	#else
	std::string home = "~";
	#endif
	home += "/.md.snake";
	
	struct stat buf;
	if(stat(home.c_str(), &buf) != -1)
		return fopen(home.c_str(), mode);
	else
		return NULL;
}
int getBest()
{
	FILE* fp = getFile("r");
	int best = 0;
	char content[5];
	if(fp!=NULL)
	{
		fscanf(fp, "%[^\n]\n", content); 
		best = atoi(content);
		fclose(fp);
	}
	return best;
}
