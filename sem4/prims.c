//Prims algorithm
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

FILE *fptr;
int arr[3];
int size;
int *PrQueue;

typedef struct node
{
    int weight;
    int vertex;
    struct node *next;
} node;

void InitalizeMSTPrims(int *pred, int *PrQueue, int rootVertex, int vertexCount){
    int i;
    for(i=0;i<vertexCount;i++){
        pred[i] = -1;
        PrQueue[i] = INT_MAX;
    }
    pred[rootVertex] = rootVertex;
    PrQueue[rootVertex] = 0;
}

int extractMin(int numNodes){
    int i, smallest = 0;
    for(i=0;i<numNodes;i++){
        if(PrQueue[i]!=INT_MIN && PrQueue[i]<PrQueue[smallest])
            smallest=i;
    }
    PrQueue[smallest] = INT_MIN;
    return smallest;
}

void displayList(node *head)
{
    node *ptr = head;
    while (ptr)
    {
        if (!ptr->next)
        {
            printf("[%d,%d]", ptr->vertex, ptr->weight);
        }
        else
        {
            printf("[%d,%d]->", ptr->vertex, ptr->weight);
        }
        ptr = ptr->next;
    }
}

node *insertAtBeg(node *head, int vertex, int wt)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->weight = wt;
    newnode->vertex = vertex;

    if (!head)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }

    return head;
}


node **createAdjacencyList(int n, int type)
{
    node *p = (node *)malloc(n * sizeof(node *));
    int i;
    for (i = 0; i < n; i++)
    {
        p[i] = NULL;
    }
    if (type == 1)
    {
        while (!feof(fptr))
        {
            for (i = 0; i < 3; i++)
            {
                fscanf(fptr, "%d ", &arr[i]);
            }
            p[arr[0]] = insertAtBeg(p[arr[0]], arr[1], arr[2]);
        }
    }
    else
    {
        while (!feof(fptr))
        {
            for (i = 0; i < 3; i++)
            {
                fscanf(fptr, "%d ", &arr[i]);
            }
            p[arr[0]] = insertAtBeg(p[arr[0]], arr[1], arr[2]);
            p[arr[1]] = insertAtBeg(p[arr[1]], arr[0], arr[2]);
        }
    }
    printf("ADJACENCY LIST!!\n");
    for (i = 0; i < n; i++)
    {
        printf("%d->", i);
        displayList(p[i]);
        printf("\n");
    }
    return p;
}


int MSTPrimsAlgorithm(node **adjlist, int vertexCount, int *pred, int *PrQueue, int rootVertex){
    int u, curVertex;
    InitalizeMSTPrims(pred, PrQueue, rootVertex, vertexCount);
    while(size){
        u = ExtractMin(vertexCount, PrQueue);
        node *head = adjlist[u];
        while(head != NULL){
            curVertex = head->vertex;
            if(PrQueue[curVertex] != INT_MIN){
                if(PrQueue[curVertex]>head->weight){
                    PrQueue[curVertex] = head->weight;
                    pred[curVertex] = u;
                }
            }
            head = head->next;
        }
        size--;
    }
    return curVertex;
}

void PrintTree(int predecessor[], int sourceVertex, int endVertex){
    if(sourceVertex != endVertex){
        PrintTree(predecessor, sourceVertex, predecessor[endVertex]);
        printf("V%d->",predecessor[endVertex]);
    }
}

int main()
{
    int n, endVertex, sourceVertex;
    printf("TYPE 1 DIRECTED\n");
    fptr = fopen("./graph.txt", "r");
    fscanf(fptr, "%d", &n);
    node *adjlist = (node *)malloc(n * sizeof(node *));
    int *predecessor = (int *)malloc(n * sizeof(int));
    PrQueue = (int *)malloc(n * sizeof(int));
    adjlist = createAdjacencyList(n, 1);
    fclose(fptr);
    printf("\nEnter the root vertex :");
    scanf("%d", &sourceVertex);
    //Initialize
    InitalizeMSTPrims(predecessor, PrQueue, sourceVertex, n);
    endVertex = MSTPrimsAlgorithm(adjlist, n, predecessor, PrQueue, sourceVertex);
    printf("\nThe minimal spanning tree is :\n");
    PrintTree(predecessor, sourceVertex, endVertex);
}