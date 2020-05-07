#include <stdio.h>
#include <random.hpp>


int main() {
  int n_start = 10; //starting number of infected people
  double R_0 = 3; //rate of spread
  int gens = 15; //number of generations
  double R_rand;
  int PE = 5;


  long n_cont, n_tot, n_new;
  
  //run simulation
  for (int e = 0; e < PE; e++) {
    n_tot = n_start;
    n_cont = n_start;
    for (int i = 0; i < gens; i++) {
      n_new = 0;
      for (int p = 0; p < n_cont; p++) {
	R_rand = ranPoisson(R_0);
	n_new += R_rand; //new cases increases by poisson random number
      }
      n_tot+=n_new; //total inc. by new cases
      n_cont = n_new; //new cases are contagious
      printf("%d %d %ld \n", e,i, n_tot);
    }
       
  }

	 
}


