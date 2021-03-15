/**
Monte Carlo Method
*/

#include<iostream>
#include <random>
#include <cmath>
#include <array>
#include <omp.h>


using namespace std;

double monte_carlo(int num_points)
{
	
	  std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,1);
	double in_circle = 0;
	double total_points = 0;
	double start = omp_get_wtime();

	 for (int i=0; i<num_points; ++i) 
	 {
		 
		int x = distribution(generator);
		int y = distribution(generator);
		double distance = sqrt(pow(x,2) + pow(y,2));
		
		if(distance <= 1){in_circle++;}
		
		total_points++;
	 }
	 double end = omp_get_wtime();
	 std::cout << end-start << " seconds, estimated pi: ";
	 return (4*(in_circle/total_points));
		
}






int main(int argv, char* argc[]){
	
	std::array< long long int, 7> try_this = {10, 100, 1000, 2500, 4000, 5000, 10000};
	
	for(int i = 0; i < try_this.size(); i++)
	{
		std::cout << "Estimate pi from " << try_this[i];
		double monte= monte_carlo(try_this[i]);
		std::cout << " points in time of: " << monte << std::endl;
		
	}
	
	
	

	
	return 0;
}