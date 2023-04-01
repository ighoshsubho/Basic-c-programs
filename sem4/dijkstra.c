#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

FILE *fptr;
int arr[3];
int *PrQueue;
int size;

typedef struct node
{
    int weight;
    int vertex;
    struct node *next;
} node;

/*void dijkstra(int graph[], int source){
  //create vertex set Q
  int *Q;
  Q = (int *)(malloc(vertexCount*sizeof(int)));
  for(i=0;i<vertexCount;i++){
    dist[i] = INT_MAX;
  }
  dist[source] = 0;
  for(i=0;i<vertexCount;i++)
    insert(Q, dist[i]);
  while(size){
    u = Q[0];
    //for each neighbour v of u
    //  Relac(u,v)
    //deleteRoot(Q, u)
  }
*/

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

node **createAdjacencyList(int n, int type)
{
    node **p = (node **)malloc(n * sizeof(node *));
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
void Initialize_Single_Source_Shortest_Path(int sourceVertex, int vertexCount, int distance[], int predecessor[])
{
    int i;
    for (i = 0; i < vertexCount; i++)
    {
        distance[i] = INT_MAX;
        predecessor[i] = -1;
        PrQueue[i] = distance[i];
    }
    distance[sourceVertex] = 0;
    PrQueue[sourceVertex] = distance[sourceVertex];
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

void dijkstra(node **graph, int numNodes, int source, int *distance, int *predecessor)
{
    int smallest, i;
    Initialize_Single_Source_Shortest_Path(source, numNodes, distance, predecessor);
    while(size){
        smallest=extractMin(numNodes);
        for(i=0;i<numNodes;i++){
            node *ptr = graph[i];
            ptr=ptr->next;
            while(ptr!=NULL){
                if(distance[smallest]!=INT_MAX && distance[ptr->vertex]>distance[smallest]+ptr->weight){
                    distance[ptr->vertex] = distance[smallest]+ptr->weight;
                    predecessor[ptr->vertex] = smallest;
                }
                ptr = ptr->next;
            }
        }
        size--;
    }
    // Node *sourceNode = (Node *)malloc(sizeof(Node));
    // sourceNode->vertex = source;
    // sourceNode->weight = 0;
    // enqueue(pq, sourceNode);
    // while (pq->size > 0)
    // {

    //     Node *currNode = extractMin(pq);
    //     int u = currNode->vertex;
    //     for (Node *adjNode = graph[u]; adjNode != NULL; adjNode = adjNode->next)
    //     {
    //         int v = adjNode->vertex;
    //         int w = adjNode->weight;
    //         if (distance[u] != INT_MAX && distance[u] + w < distance[v])
    //         {
    //             distance[v] = distance[u] + w;
    //             predecessor[v] = u;
    //             Node *updatedNode = (Node *)malloc(sizeof(Node));
    //             updatedNode->vertex = v;
    //             updatedNode->weight = distance[v];
    //             enqueue(pq, updatedNode);
    //         }
    //     }
    // }
}

// void dijkstra(Node **graph, int numNodes, int source, int *distance, int *predecessor)
// {

//     PriorityQueue *pq = createPriorityQueue(numNodes);
//     Initialize_Single_Source_Shortest_Path(source, numNodes, distance, predecessor);
//     Node *sourceNode = (Node *)malloc(sizeof(Node));
//     sourceNode->vertex = source;
//     sourceNode->weight = 0;
//     enqueue(pq, sourceNode);
//     while (pq->size > 0)
//     {

//         Node *currNode = extractMin(pq);
//         int u = currNode->vertex;
//         for (Node *adjNode = graph[u]; adjNode != NULL; adjNode = adjNode->next)
//         {
//             int v = adjNode->vertex;
//             int w = adjNode->weight;
//             if (distance[u] != INT_MAX && distance[u] + w < distance[v])
//             {
//                 distance[v] = distance[u] + w;
//                 predecessor[v] = u;
//                 Node *updatedNode = (Node *)malloc(sizeof(Node));
//                 updatedNode->vertex = v;
//                 updatedNode->weight = distance[v];
//                 enqueue(pq, updatedNode);
//             }
//         }
//     }
// }

void Display_Path(int predecessor[], int sourceVertex, int currentVertex)
{
    if (currentVertex == sourceVertex)
    {
        printf("%d", sourceVertex);
    }
    else if (predecessor[currentVertex] == -1)
    {
        printf("No path exists from %d to %d", sourceVertex, currentVertex);
    }
    else
    {
        Display_Path(predecessor, sourceVertex, predecessor[currentVertex]);
        printf(" -> %d", currentVertex);
    }
}

void Display_Path_and_distance(int sourceVertex, int vertexCount, int distance[], int predecessor[])
{
    int i;
    for (i = 0; i < vertexCount; i++)
    {

        printf("\nShortest path from %d to %d: ", sourceVertex, i);
        Display_Path(predecessor, sourceVertex, i);
        if (distance[i] != INT_MAX)
        {

            printf(" with distance %d\n", distance[i]);
        }
    }
}

int main()
{
    int n;
    printf("TYPE 1 DIRECTED\n");
    fptr = fopen("./graphInput.txt", "r");
    fscanf(fptr, "%d", &n);
    size = n;
    node **graph = (node **)malloc(n * sizeof(node *));
    int *predecessor = (int *)malloc(n * sizeof(int));
    int *distance = (int *)malloc(n * sizeof(int));
    PrQueue = (int *)(malloc(n*sizeof(int)));
    createAdjacencyList(n, 1);
    fclose(fptr);
    dijkstra(graph, n, 0, distance, predecessor);
    Display_Path_and_distance(0, n, distance, predecessor);
}