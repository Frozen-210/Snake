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

		setX(int x){this->x = x;}
		getX() const {return this->x}
		setY(int y){this->y = y;}
		getY() const {return this->y}

		Vector& operator=(const Vector& vec)
		{setX(vec.getX()); setY(vec.getY()); return *this;}
		Vector& operator+=(const Vector& vec)
		{setX(getX()+vec.getX()); setY(getY()+vec.getY()); return *this;}
		Vector operator+(Vector v, const Vector& vec)
		{return v+=vec; }
		Vector& operator-=(const Vector& vec)
		{setX(getX()-vec.getX()); setY(getY()-vec.getY()); return *this;}
		Vector operator-(Vector v, const Vector& vec)
		{return v-=vec;}
			
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
		const int height, width;
		bool exit;
		int speed;
		bool move; //maybe unnecessary, otherwise move buffer
	public:
		Snake(int height, int width, int best)
		: heigth(height), width(width), best(best) 
		{	getApple(); 
			body.push_back(Vector(height/2, width/2)); 
			setDirection(0); 
			exit=false; 
			speed=180; 
			level=1;
			srand(time(NULL));
		}
};
