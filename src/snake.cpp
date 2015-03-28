#include <ncurses.h>
#include <cstring>
using namespace std;

class Snake;
class Vector;

int main()
{

}

class Vector
{
	public:
		Vector() : x(0), y(0){}
		Vector(int x, int y) {setX(x); setY(y);}

		setX(int x){this->x = x;}
		getX(){return this->x}
		setY(int y){this->y = y;}
		getY(){return this->y}

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

