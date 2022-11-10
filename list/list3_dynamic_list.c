// gcc -g -fsanitize=address -std=c11 list3_dynamic_list.c && ./a.out

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

#include "List.h"

int main()
{

  struct Item a = {"A"};
  struct Item b = {"B"};
  struct Item c = {"C"};
  struct Item d = {"D"};

  // TODO:
  // 1. create 4 DYNAMICALLY ALLOCATED  nodes `struct Node` and store copies of
  // the items in them
  // 2. concatenate the nodes in the order of the items given above
  // 3. use the concatenated nodes to initialize the DYNAMICALLY allocated list
  // 4. apply the 'list_invariants' function to list to check state of list
  // 5. use your 'print' function to print all elements of the list to
  // the console

  struct List *list = NULL;

  return 0;
}
