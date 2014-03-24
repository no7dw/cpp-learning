#include <iostream>
#include <vector>

class Vehicle
{
public:
	virtual void run() const = 0;
};

class Car: public Vehicle
{
public:
	virtual void run() const
	{
		std::cout<< "run a car \n" ;
	}
};

class Airplane : public Vehicle
{
public:
	virtual void run() const
	{
		std::cout<< "run a airplane\n";
	}

	void add_oil() const
	{
		std::cout<<"add oil to airplane\n";
	}
};

class Airship: public Vehicle
{
public:
	virtual void run() const
	{
		std::cout <<"run a airship\n";
	}
	
	void add_oil() const
	{
		std::cout <<" add oil to airship\n";
	}
};

