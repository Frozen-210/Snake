#include <ncurses.h>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>

class Snake;
class Vector;

int main()
{
	//init (Snake, curses)
	//loop
	//{
	////input
	////snake->proces
	////draw<<snake
	////refresh
	//}
}

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
		: height(_height), width(_width), best(_best) 
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
		{//do rand and set apple pos
		}

		void setDirection(int d)
		{//switch d and assign value to direction
		}
};
