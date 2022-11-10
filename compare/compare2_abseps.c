// gcc -g -fsanitize=address -std=c11 compare2_abseps.c && ./a.out

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// require absolute difference below fixed threshold
bool compare_abseps(float a, float b)
{
  return fabsf(a - b) < 20 * FLT_EPSILON;
}

int main()
{

  { // scaling to 1

    float p01 = 0.1;
    float p10 = 10;

    float a1 = 1.0;

    float a2 = 0.0;
    for (int i = 0; i != 100; ++i)
      a2 += p01 / p10;

    float a3 = 0.0;
    for (int i = 0; i != 10; ++i)
      a3 += p01;

    printf("a1 = %.20e\n", a1);
    printf("a2 = %.20e\n", a2);
    printf("a3 = %.20e\n", a3);

    printf("compare_abseps(a1, 1.0) = %i\n", compare_abseps(a1, 1.0));
    printf("compare_abseps(a2, 1.0) = %i\n", compare_abseps(a2, 1.0));
    printf("compare_abseps(a3, 1.0) = %i\n", compare_abseps(a3, 1.0));
  }

  { // scaling to 1e10

    float p01 = 0.1e10;
    float p10 = 10;

    float a1 = 1.0e10;

    float a2 = 0.0;
    for (int i = 0; i != 100; ++i)
      a2 += p01 / p10;

    float a3 = 0.0;
    for (int i = 0; i != 10; ++i)
      a3 += p01;

    printf("a1 = %.20e\n", a1);
    printf("a2 = %.20e\n", a2);
    printf("a3 = %.20e\n", a3);

    printf("compare_abseps(a1, 1.0) = %i\n", compare_abseps(a1, 1.0e10));
    printf("compare_abseps(a2, 1.0) = %i\n", compare_abseps(a2, 1.0e10));
    printf("compare_abseps(a3, 1.0) = %i\n", compare_abseps(a3, 1.0e10));
  }

  { // scaling to 1e-10

    float p01 = 0.1e-10;
    float p10 = 10;

    float a1 = 1.0e-10;

    float a2 = 0.0;
    for (int i = 0; i != 100; ++i)
      a2 += p01 / p10;

    float a3 = 0.0;
    for (int i = 0; i != 10; ++i)
      a3 += p01;

    printf("a1 = %.20e\n", a1);
    printf("a2 = %.20e\n", a2);
    printf("a3 = %.20e\n", a3);

    printf("compare_abseps(a1, 1.0) = %i\n", compare_abseps(a1, 1.0e-10));
    printf("compare_abseps(a2, 1.0) = %i\n", compare_abseps(a2, 1.0e-10));
    printf("compare_abseps(a3, 1.0) = %i\n", compare_abseps(a3, 1.0e-10));
  }

  return 0;
}