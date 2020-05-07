// Matt Walsh (mw6es)
// mw6es_virus_recovery.cpp

/*Approximate total people infected after threat has passed will be about 14 million. This is after 12 generations.*/

#include <stdio.h>
#include<stdlib.h>
#include <random.hpp>


int main(int argc, char* argv[]) {

  if (argc != 3) {
    printf("Enter random seed and number of experiments in command line\n");
    return -1;
  }

  int n_start = 10000000; //starting number of infected people
  double R_0 = 0.3; //rate of spread
  int gens = 0; //number of generations
  double R_rand;
  int PE = atoi(argv[1]);
  int seed = atoi(argv[2]);
  
  int init=randui(0,100);
  rand_seed(seed);  //Where "seed" is the seed that I set with the command-line argument

  long n_cont, n_tot, n_new;

  //run simulation
  for (int e = 0; e < PE; e++) {
    n_tot = n_start;
    n_cont = n_start;
    gens = 0;
    printf("%d %ld %ld \n", gens, n_cont, n_tot);
    while (n_cont >= 10) {
      n_new = 0;
	for (int p = 0; p < n_cont; p++) {
	R_rand = ranPoisson(R_0);
	n_new += R_rand; //new cases multiply by poisson random number
	}
	n_tot+=n_new; //total inc. by new cases
	n_cont = n_new; //new cases are contagious
	gens++;
	printf("%d %ld %ld \n", gens, n_cont, n_tot);
      }
       
  }

}
