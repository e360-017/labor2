// gcc -g -fsanitize=address -std=c11 compare4_releps_cancellation.c && ./a.out

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// maximum relative difference below fixed threshold
bool compare_releps(float a, float b)
{
  double reldiff1 = fabs(a - b) / fabs(a);
  double reldiff2 = fabs(a - b) / fabs(b);
  double reldiffmax = reldiff1 > reldiff2 ? reldiff1 : reldiff2;
  return reldiffmax <= 20 * FLT_EPSILON;
}

int main() {

  { // catastrophic cancellation around 0

    float p01 = 0.1;
    float p10 = 10;

    float a1 = 1.0;
    a1 = a1 - 1.0; // catastrophic cancellation

    float a2 = 0.0;
    for (int i = 0; i != 100; ++i)
      a2 += p01 / p10;
    a2 = a2 - 1.0; // catastrophic cancellation

    float a3 = 0.0;
    for (int i = 0; i != 10; ++i)
      a3 += p01;
    a3 = a3 - 1.0; // catastrophic cancellation

    printf("a1 = %.20e\n", a1);
    printf("a2 = %.20e\n", a2);
    printf("a3 = %.20e\n", a3);

    printf("compare_releps(a1, 0.0) = %i\n", compare_releps(a1, 0.0));
    printf("compare_releps(0.0, a2) = %i\n", compare_releps(0.0, a2));
    printf("compare_releps(a3, 0.0) = %i\n", compare_releps(a3, 0.0));
  }

  return 0;
}