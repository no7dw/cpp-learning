#include <iostream>
#include <vector>
#include "dscombine_poly.h"

void run_vehicles(const std::vector<Vehicle*>& vehicles)
{
	for(unsigned int i = 0 ; i < vehicles.size(); i++)
	{
		vehicles[i]->run();
	}
}

template <typename Aircraft>
void add_oil_to_aircrafts_in_the_sky(const std::vector<Aircraft>& aircrafts)
{
	
	for(unsigned int i = 0 ; i < aircrafts.size(); i++)
	{
		aircrafts[i]->add_oil();
	}
}

int main()
{
	Car car1,car2;
	Airplane airplane1,airplane2;
	Airship airship1, airship2;
	std::vector<Vehicle*>v;
	v.push_back(&car1);
	v.push_back(&airplane1);
	v.push_back(&airship1);
	run_vehicles(v);
	
	std::vector<Airplane*>vp;
	vp.push_back(&airplane1);
	vp.push_back(&airplane2);
	add_oil_to_aircrafts_in_the_sky(vp);	

	std::vector<Airship*>vs;
	vs.push_back(&airship1);
	vs.push_back(&airship2);
	add_oil_to_aircrafts_in_the_sky(vs);
	
}	
