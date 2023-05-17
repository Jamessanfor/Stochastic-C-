#pragma once

#include "Header.h"
#define e 2.71828
#define set 1000
default_random_engine gen;
uniform_real_distribution<double> dist_possion(0, 1);
normal_distribution<double> dist_normal(5, 2);

//typical random c++ using time
vector<unsigned> randgen(){
	int len = 1000;
	vector<unsigned> vec;
	srand(time(0));
	for (int i = 0; i < len;i++) {
	vec.push_back(rand());
	}
	return vec;

}

//factorial function
unsigned fact(unsigned a) {
	unsigned temp= 1;
	for (int i = 1; i < (a+1); i++) {
		temp *= i;
	}
	return temp;

}




//markov






//possion
double poission(void) {
	
	int x = 5 ;
	int lambda = 3 ;
		return (((pow(lambda, x) * pow(e, -1 * lambda)) / fact(x)));
}

double poission(int lambda, int x) {
	return (dist_possion(gen) * ((pow(lambda, x) * pow(e, -1 * lambda)) / fact(x)));
}





//time series 






//Bayesian estimation










