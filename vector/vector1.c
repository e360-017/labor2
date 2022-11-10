// gcc -g -fsanitize=address -std=c11 vector1.c && ./a.out

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Item
{
  char name[128];
};

struct Vector
{
  struct Item data[4];
  size_t size;
};

int main()
{

  struct Item a = {"A"};
  struct Item b = {"B"};
  struct Item c = {"C"};
  struct Item d = {"D"};

  struct Vector vec = {.size = 4};

  // TODO:
  // 1. add copies of the items above into the vector in the order of their
  // declaration
  // 2. implement a 'print' function to print all elements of a vector to
  // the console


  return 0;
}

