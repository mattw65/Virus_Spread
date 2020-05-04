#include <stdio.h>

int main() {
  int n_start = 10; //starting number of infected people
  double R_0 = 3; //rate of spread
  int gens = 15; //number of generations


  FILE* out;
  out = fopen("simple.dat", "w");

  int n_cont = n_start;
  int n_tot = n_start;
  
  //run simulation
  for (int i = 0; i <= gens; i++) {

    fprintf(out, "%d %d\n", i, n_tot);
    n_tot += n_cont*R_0; //n_tot increases by number of contagions * spread rate
    n_cont *= R_0; //number of contagions multiplies by spread rate

  }

  //run simulation again with R0=2 to compare to R0=3
  R_0 = 2;
  int n_tot2 = n_start;
  n_cont = n_start;
  for (int j = 0; j <= gens; j++) {
    n_tot2 += n_cont*R_0;
    n_cont *= R_0;

  }

  //convert totals to doubles to allow for division
  double n = (double)(n_tot);
  double n2 = (double)(n_tot2);


  printf("Changing R0 from 3 to 2 reduces spread of virus by factor of %.2lf\n", n/n2); 
}


