#pragma once

#include "Header.h"
#define e 2.71828
#define set 1000
default_random_engine gen;
uniform_real_distribution<double> dist_possion(0, 2);


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
vector<double> poission(void) {
	vector<double> vec;
	int x = 10 ;
	int lambda = 10 ;
	for (int i = 0; i < set; i++) {
		vec.push_back(dist_possion(gen)*((pow(lambda,x)*pow(e,-1*lambda))/fact(x)));
	}
	return vec;
}

vector<double> poission(int lambda, int x) {
	vector<double> vec;

	for (int i = 0; i < set; i++) {
		vec.push_back(dist_possion(gen) * ((pow(lambda, x) * pow(e, -1 * lambda)) / fact(x)));
	}
	return vec;
}





//time series 






//Bayesian estimation










