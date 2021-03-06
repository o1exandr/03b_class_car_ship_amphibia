/*
Завдання 3б.
Використати віртуальний базовий клас при вирішенні проблеми дублювання полів 
з базового класу Транспортний засіб у класі Амфібія.
*/

#include "stdafx.h"
#include <iostream> 
#include <string>


using namespace std;

class Transport
{
protected:

	string vendor;
	int speed;

public:

	Transport(string vendor = "unknown", int speed = 0) :vendor(vendor), speed(speed)
	{

	}

	void setVendor(string v)
	{
		vendor = v;
	}

	string getVendor() const
	{
		return vendor;
	}

	void setSpeed(int s)
	{
		speed = s;
	}

	int getSpeed() const
	{
		return speed;
	}

	void print()
	{
		cout << "\nVendor:\t" << getVendor() << "\t\nSpeed:\t" << getSpeed() << " km\n";
	}

};

class Car : virtual public Transport
{
protected:

	int doors;

public:

	Car(string vendor = "unknown", int speed = 0, int doors = 2) :Transport(vendor, speed), doors(doors)
	{
	}

	Car(Transport t, int doors = 2) :Transport(t), doors(doors)
	{
	}

	void setDoors(int d)
	{
		doors = d;
	}

	int getDoors()const
	{
		return doors;
	}

	void setSpeed(int s)
	{
		speed = s;
	}

	int getSpeed() const
	{
		return speed;
	}

	void print()
	{
		Transport::print();
		cout << "Doors:\t" << doors << endl;
	}
};

class Ship : virtual public Transport
{
protected:

	int turbin;

public:

	Ship(string vendor = "unknown", int speed = 0, int turbin = 1) :Transport(vendor, speed), turbin(turbin)
	{

	}

	void setTurbin(int t)
	{
		turbin = t;
	}

	int getTurbin() const
	{
		return turbin;
	}

	void print()
	{
		Transport::print();
		cout << "Turbin:\t" << turbin << endl;
	}
};

class Amphibia : public Car, public Ship
{

public:
	
	Amphibia(string vendor = "unknown", int speed = 10, int doors = 2, int turbin = 1) 
	{
		Amphibia::vendor = vendor;
		Amphibia::speed = speed;
		Amphibia::doors = doors;
		Amphibia::turbin = turbin;
	}
	

	Amphibia(Car c, Ship s) :Car(c), Ship(s)
	{
	}

	void print()
	{
		//Car::print();
		//Ship::print();
		cout << "\nVendor:\t" << getVendor() << "\t\nSpeed:\t" << getSpeed() << " km\nTurbin:\t" << getTurbin() << "\nDoors:\t" << getDoors();
	}
};

int main()
{
	Transport t("Skoda", 170);
	cout << "\n\tTransort";
	t.print();

	Car c(t, 4);
	cout << "\n\tCar";
	c.print();

	Ship s("Waterstrider", 47, 6);
	cout << "\n\tShip";
	s.print();

	//Amphibia a(c, s); //наслідує виробника і швидкість класу Transport 
	Amphibia a("WaterBug", 95, 3, 7);
	cout << "\n\tAmphibia";
	a.print();


	cout << endl;
	system("pause");
	return 0;
}

