#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
/* heap data structure */
struct heap
{
  int *data;
  int capacity;
  int node_index;
};
struct heap ds;
 
void init (int size)
{
  ds.data = (int *) malloc (sizeof (int) * size);
  int i = 0;
  for (i = 1; i < size; i++)
    ds.data[i] = INT_MAX;
 
  ds.capacity = size;
  ds.node_index = 0;
}
 
/* get left child index */
int getLetf (int index)
{
  return 2 * index;
}
 
/* get right child index */
int getRight (int index)
{
  return 2 * index + 1;
}
 
/* get parent index */
int getParent (int index)
{
  return (index / 2);
}
  
int isEmpty ()
{
  if (ds.node_index == 0)
    return 1;
  else
    return 0;
}
void heapyfy_push (int index)
{
  if (index >= ds.capacity)
    return;
  int parentNodeIndex = getParent (index);
  int tmp;
  if (index != 1)
    {
      if (ds.data[parentNodeIndex] > ds.data[index])
    {
      tmp = ds.data[parentNodeIndex];
      ds.data[parentNodeIndex] = ds.data[index];
      ds.data[index] = tmp;
      heapyfy_push (parentNodeIndex);
    }
    }
}
 
void push (int value)
{
  ds.node_index++;
  // check if heap is full or not full
  if (ds.node_index < ds.capacity)
    {
      ds.data[ds.node_index] = value;
      heapyfy_push (ds.node_index);
    }
  else
    {
      printf ("Heap is full\n");
      printf ("Not possible to push %d\n", value);
      exit (-1);
    }
}
 
void heapyfy_pop (int index)
{
  int tmp;
  int left = getLetf (index);
  int right = getRight (index);
  int min_index;
  if (right >= ds.node_index)
    {
      if (left >= ds.node_index)
    return;
      else
    min_index = left;
    }
  else
    {
      if (ds.data[left] <= ds.data[right])
    min_index = left;
      else
    min_index = right;
    }
  if (ds.data[index] > ds.data[min_index])
    {
      tmp = ds.data[min_index];
      ds.data[min_index] = ds.data[index];
      ds.data[index] = tmp;
      heapyfy_pop (min_index);
    }
}
 


int pop ()
{
  int minvalue;
  if (!isEmpty ())
    {
      minvalue = ds.data[1];
      ds.data[1] = ds.data[ds.node_index];
      ds.node_index--;
      if (ds.node_index > 1)
    heapyfy_pop (1);
 
      return minvalue;
    }
 
}
 
void cleanMemory ()
{
  free (ds.data);
}

 
void printHeap ()
{
  int i = 1;
  for (i; i <= ds.node_index; i++)
    printf ("%d ", ds.data[i]);
  printf ("\n");
 
}// test heap
int main ()
{
  int n,value;
  printf("Enter capacity of heap :\n");
  scanf("%d ",&n);
  printf("\n");
  init (n);
  while(n--){
    scanf("%d",&value);
     push(value);
   }
  printf ("heap after pusshing 9 8 -6 3 1 -5\n");
  printHeap ();
  pop ();
  printf ("heap array after pop \n");
  printHeap ();
  push (2);
  printf ("heap array after pushing 2\n");
  printHeap ();
  cleanMemory ();
  return 0;
}
