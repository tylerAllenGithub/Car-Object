#include <iostream>
using namespace std;

enum direct {NORTH, EAST, SOUTH, WEST};

class Car
{

private:
  string VIN;
  string make;
  string model;
  string color;
  int year;
  int milage;
  direct direction;
  int x;
  int y;

public:
  Car(string v, string mk, string md, string c, int yr);
  string getModel();
  void goForward(int blks);
  int getX();
  int getY(); 
  void turnRight();
  void turnLeft();
  int getMilage();
};

Car::Car(string v, string mk, string md, string c, int yr)
{
  VIN = v;
  make=mk;
  model=md;
  color=c;
  year=yr;
  milage=0;
  x=0;
  y=0;
  direction = NORTH;

}

string Car::getModel()
{
  return model;
}

void Car::goForward(int blks)
{
  if(direction==NORTH)
  y+=blks;
  else if(direction==SOUTH)
    y-=blks;
  else if(direction==EAST)
    x+=blks;
  else if(direction=WEST)
    x-=blks;

  milage+=blks;
}

int Car::getX()
{
  return x;
}

int Car::getY()
{
  return y;
}

void Car::turnRight()
{
  if(direction<WEST)
    direction= (direct)(direction+1);

  else//direction is WEST
    direction = NORTH;
}

void Car::turnLeft()
{
  if(direction>NORTH)
    direction= (direct)(direction-1);

  else//direction is NORTH
    direction = WEST;
}

int Car::getMilage()
{
  return milage;
}
int main()
{
  Car c1("w12345", "VW", "Beetle", "green", 2015);
  cout<<c1.getModel()<<endl;
  cout<<"c1 is at ("<<c1.getX()<<", "<<c1.getY()<<")"<<endl;
  c1.goForward(2);
  cout<<"c1 is at ("<<c1.getX()<<", "<<c1.getY()<<")"<<endl;
  c1.turnRight();
  c1.goForward(3);
  cout<<"c1 is at ("<<c1.getX()<<", "<<c1.getY()<<")"<<endl;
  c1.turnRight();
  c1.goForward(5);
  cout<<"c1 is at ("<<c1.getX()<<", "<<c1.getY()<<")"<<endl;

  c1.turnLeft();
  c1.goForward(3);
  cout<<"c1 is at ("<<c1.getX()<<", "<<c1.getY()<<")"<<endl;
  cout<<"c1's Milage is "<<c1.getMilage()<<endl; 

return 0;
}
