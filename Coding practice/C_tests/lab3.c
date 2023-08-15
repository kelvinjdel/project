#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Define the voltage source
  float V = 12.0;

  // Define the range of resistances
  float Rmin = 1.0;
  float Rmax = 100.0;
  float dr = 1.0;

  // Create an array to store the current values
  float I[100];

  // Define the counter variable
  int i;

  // Calculate the current for each resistance value
  for (float R = Rmin; R <= Rmax; R += dr) {
    int R = (int) (Rmin + i * dr);
    I[R - Rmin] = V / (float) R;
    i++;
  }

  // Plot the current vs. resistance graph
  for (int i = 0; i < 100; i++) {
    printf("%f %f\n", Rmin + i * dr, I[i]);
  }

  return 0;
}