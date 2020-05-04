//Matt Walsh (mw6es)
//mw6es_virus_batch.cpp

/*This is the file i used for my batch jobs. 100 experiments takes about 25 minutes. Command line should be ./a.out {num experiments} {rand seed} */

#include <stdio.h>
#include<stdlib.h>
#include <random.hpp>
#include <timer.hpp>


int main(int argc, char* argv[]) {

  if (argc != 3) {
    printf("Enter random seed and number of experiments in command line\n");
    return -1;
  }

  int n_start = 10; //starting number of infected people
  double R_0 = 3; //rate of spread
  int gens = 15; //number of generations
  double R_rand;
  int PE = atoi(argv[1]);
  int seed = atoi(argv[2]);
  
  Timer time;
  
  int init=randui(0,100);
  rand_seed(seed);  //Where "seed" is the seed that I set with the command-line argument


  long n_cont, n_tot, n_new;

  //run simulation
  time.start();
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
	
      }
      printf("%d %ld \n", e+1, n_tot); 
  }
  time.stop();
  printf("%f\n", time.cpuTime());
}
