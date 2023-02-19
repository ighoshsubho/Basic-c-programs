#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fptr;
int arr[3];

typedef struct node{
  int wt;
  int vertex;
  struct node *next;
}node;

void createAdjacencyMatrix(int n, int type)
{
  int **mat, i, j;
  mat = (int **)(malloc(n*sizeof(int *)));
  for(i=0;i<n;i++)
    mat[i] = (int *)(calloc(n,sizeof(int)));
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
        mat[i][j] = 0;
  }
  if(type){
    while (!feof(fptr))
	  {
      for (i = 0; i < 3; i++)
			  fscanf(fptr, "%d ", &arr[i]);
      mat[arr[0]][arr[1]] = arr[2];
    }
  }
  else{
    while (!feof(fptr))
	  {
      for (i = 0; i < 3; i++)
			  fscanf(fptr, "%d ", &arr[i]);
      mat[arr[0]][arr[1]] = arr[2];
      mat[arr[1]][arr[0]] = arr[2];
    }
  }
  printf("ADJACENCY MATRIX :\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      printf("%d ",mat[i][j]);
    printf("\n");
  }
}

void displayList(node *head){
  node *ptr;
  ptr = head;
  while(ptr != NULL){
    printf("|%d|%d| ", ptr->vertex, ptr->wt);
    ptr = ptr->next;
  }
}

node *insertAtBeg(node *head, int vertex, int wt){
  node *newnode;
  newnode = (node *)(malloc(sizeof(node)));
  newnode->wt = wt;
  newnode->vertex = vertex;
  if(head == NULL){
    head = newnode;
    newnode->next = NULL;
  }
  else{
    newnode->next = head;
    head = newnode;
  }

  return head;
}

void createAdjacencyList(int n, int type)
{
  node **list;
  int i;
  list = (node **)(malloc(n*sizeof(node *)));
  for(i=0;i<n;i++)
    list[i] = NULL;
  if(type){
    while (!feof(fptr))
	  {
      for (i = 0; i < 3; i++)
			  fscanf(fptr, "%d", &arr[i]);
      list[arr[0]] = insertAtBeg(list[arr[0]],arr[1],arr[2]);
    }
  }
  else{
    while (!feof(fptr))
	  {
      for (i = 0; i < 3; i++)
			  fscanf(fptr, "%d", &arr[i]);
      list[arr[0]] = insertAtBeg(list[arr[0]],arr[1],arr[2]);
      list[arr[1]] = insertAtBeg(list[arr[1]],arr[0],arr[2]);
    }
  }
  printf("ADJACENCY LIST :\n");
  for(i=0;i<n;i++)
  {
    displayList(list[i]);
    printf("\n");
  }
}

int main(){
  // int type;
  // printf("\nEnter the type of adjacency matrix and list :");
  // scanf("%d",&type);
  int n;

  arr[0] = arr[1] = arr[2] = 0;

  printf("TYPE 1(DIRECTED) :");

  fptr = fopen("./graphInput.txt","r");
  fscanf(fptr,"%d",&n);
  createAdjacencyMatrix(n,1);
  fclose(fptr);
  fptr = fopen("./graphInput.txt","r");
  fscanf(fptr,"%d",&n);
  createAdjacencyList(n,1);
  fclose(fptr);


  printf("TYPE 0(UNDIRECTED) :");

  fptr = fopen("./graphInput.txt","r");
  fscanf(fptr,"%d",&n);
  createAdjacencyMatrix(n,0);
  fclose(fptr);
  fptr = fopen("./graphInput.txt","r");
  fscanf(fptr,"%d",&n);
  createAdjacencyList(n,0);
  fclose(fptr);

}