#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Shape
{
private:
	char typeOfShape;
public:
	Shape();
	Shape(char sType);
};

Shape::Shape()
{
	typeOfShape = '0';  //zero no shape
}
Shape::Shape(char sType)
{
	typeOfShape = sType;
}

class Point: public Shape
{
private:
	int x, y;

public:
	Point();

	Point(int parX, int parY)
	{
		x = parX;
		y = parY;
	}
	void setPoint( int x, int y );


	void getPoint();
	

	int getX()
	{
		return x;
	}

	void setX(int parX)
	{
		x = parX;
	}

	int getY()
	{
		return y;
	}

	void setY(int parY)
	{
		y = parY;
	}


};

Point::Point( )
{
	x = rand( ) % (100 - -100 + 1) + -100;
	y = rand( ) % (100 - -100 + 1) + -100;
}



class Line: public Shape
{

private:

	double length;
	Point start;
	Point end;


public:

	Line();
	
	void calcLength( );


	int getStartX()
	{
		return start.getX();
	}

	int getStartY()
	{
		return start.getY();
	}

	int getEndX()
	{
		return end.getX();
	}

	int getEndY()
	{
		return end.getY();
	}

};

Line::Line( )
{
	int x1 = rand( ) % (100 - -100 + 1) + -100;
	int x2 = rand( ) % (100 - -100 + 1) + -100;
	int y1 = rand( ) % (200 - -200 + 1) + -200;
	int y2 = rand( ) % (200 - -200 + 1) + -200;
	
	start = Point(x1, y1);
	end = Point(x2, y2);
	length = sqrt((y2 - y1) + (x2 - x1));

}

void Line::calcLength( )
{
	//assume there is code here that will correctly calulate the lenght
}




Point sumPoints(Point parP1, Point parP2);



int main( )
{
	srand( 0 );
	Point p1;
	Point p2;
	Point p3;
	Line line1;
	vector<Point> vecPoints(10, p1);

	p3 = sumPoints(p1, p2);

	cout << " The lines starting point in (x, y) format is: (" << line1.getStartX() << ", " << line1.getStartY() << ")" << endl;
	cout << " The lines ending point in (x, y) format is: (" << line1.getEndX() << ", " << line1.getEndY() << ")" << endl;

	vecPoints.clear();
	system( "pause" );
	return 0;
}

Point sumPoints(Point parP1, Point parP2)
{
	
	Point p3;
	int x;
	int y;

	x = parP1.getX() + parP2.getX();
	p3.setX(x);
	y = parP1.getY() + parP2.getY();
	p3.setY(y);
	
	

	return p3;
}

//Problems: I do not think this was a great way to go about this test, very confusing, 
// should have been additional information on whether certain methods needed to stay prototyped.
// Also, having specified formulas for length would have been helpful so we know what the initialization of length would look like within our constructor.