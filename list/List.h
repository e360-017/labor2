#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

struct Item
{
  char name[128];
};

struct Node
{
  struct Node *next;
  struct Item item;
};

// invariant1: if the list is empty --> root == NULL
// invariant2: 'size' is the current number of Nodes in the list
// the 'next' pointer of the last element always points to NULL
struct List
{
  struct Node *root; // root node of the list
  size_t size;       // current size of the list
};

void list_invariants(const struct List *list)
{
  if (list->root == NULL && list->size > 0)
    printf("invariant1 violated\n");
  else
  {
    int count = 0;
    struct Node *iter = list->root;
    while (iter != NULL)
    {
      ++count;
      iter = iter->next;
    }
    if (count != list->size)
      printf("invariant2 violated\n");
  }
}

