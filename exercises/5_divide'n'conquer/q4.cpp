#include <iostream>
#include <vector>

using namespace std;

#define C 299792458

void create_particles(vector<double> &particles);
void create_elements(vector<double> &particles, vector<double> &elements);
double calculate_net_force(vector<double> &particles,
	vector<double> &elements);

int main()
{
	vector<double> particles;
	create_particles(particles);

	vector<double> elements;
	create_elements(particles, elements);

	double net_force = calculate_net_force(particles, elements);
	cout << "The Net Force is: " << net_force << endl;

	return 0;
}

void create_particles(vector<double> &particles)
{
	const double END_OF_INPUT = 0.0;
	cout << "Insert a list of particle charges." << endl;
	cout << "End the insertion with " << END_OF_INPUT  << "." << endl;
	bool creation_is_done = false;
	while(!creation_is_done)
	{
		double charge = 0;
		cin >> charge;
		if(charge != END_OF_INPUT)
		{
			particles.push_back(charge);
		}
		else
		{
			creation_is_done = true;
		}
	}
}

void create_elements(vector<double> &particles, vector<double> &elements)
{
	for(unsigned int i = particles.size(); i > 0; --i)
	{
		double element = 1.0/(i*i);
		elements.push_back(element);
	}

	for(unsigned int i = 1; i < particles.size(); ++i)
	{
		double element = -1.0/(i*i);
		elements.push_back(element);
	}
}

double calculate_net_force(vector<double> &particles,
	vector<double> &elements)
{
	double net_force = 0;
	unsigned int i = 0;
	unsigned int j = particles.size()-1;
	bool inversed = false;
	for(double element : elements)
	{
		net_force = particles[i]*element*C*particles[j];
		if(!inversed)
		{
			--j;
			++i;
			if(i == particles.size()-1)
			{
				inversed = true;
			}
		}
		else
		{
			++j;
			--i;
		}
	}
	return net_force;
}
