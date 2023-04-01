#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

FILE *fptr;
int arr[3];

typedef struct node
{
    int weight;
    int vertex;
    struct node *next;
} Node;
typedef struct PriorityQueue
{
    int size;
    Node **heap;
} PriorityQueue;

PriorityQueue *createPriorityQueue(int capacity)
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->heap = (Node **)malloc(capacity * sizeof(Node *));
    return pq;
}

Node *extractMin(PriorityQueue *pq)
{
    if (pq == NULL || pq->size == 0)
    {
        return NULL;
    }

    int minIndex = 0;
    for (int i = 1; i < pq->size; i++)
    {
        if (pq->heap[i]->weight < pq->heap[minIndex]->weight)
        {
            minIndex = i;
        }
    }

    Node *minNode = pq->heap[minIndex];
    pq->size--;

    pq->heap[minIndex] = pq->heap[pq->size];
    return minNode;
}

void enqueue(PriorityQueue *pq, Node *node)
{
    pq->heap[pq->size++] = node;
}

Node *insertAtBeg(Node *head, int vertex, int wt)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
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

void displayList(Node *head)
{
    Node *ptr = head;
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

Node **createAdjacencyList(int n, int type)
{
    Node *p = (Node *)malloc(n * sizeof(Node *));
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
    }
    distance[sourceVertex] = 0;
}

void dijkstra(Node **graph, int numNodes, int source, int *distance, int *predecessor)
{

    PriorityQueue *pq = createPriorityQueue(numNodes);
    Initialize_Single_Source_Shortest_Path(source, numNodes, distance, predecessor);
    Node *sourceNode = (Node *)malloc(sizeof(Node));
    sourceNode->vertex = source;
    sourceNode->weight = 0;
    enqueue(pq, sourceNode);
    while (pq->size > 0)
    {

        Node *currNode = extractMin(pq);
        int u = currNode->vertex;
        for (Node *adjNode = graph[u]; adjNode != NULL; adjNode = adjNode->next)
        {
            int v = adjNode->vertex;
            int w = adjNode->weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                predecessor[v] = u;
                Node *updatedNode = (Node *)malloc(sizeof(Node));
                updatedNode->vertex = v;
                updatedNode->weight = distance[v];
                enqueue(pq, updatedNode);
            }
        }
    }
}

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
    Node *graph = (Node *)malloc(n * sizeof(Node *));
    int *predecessor = (int *)malloc(n * sizeof(int));
    int *distance = (int *)malloc(n * sizeof(int));
    printf("TYPE 1 DIRECTED\n");
    fptr = fopen("./graph.txt", "r");
    fscanf(fptr, "%d", &n);
    graph = createAdjacencyList(n, 1);
    fclose(fptr);
    dijkstra(graph, n, 0, distance, predecessor);

    Display_Path_and_distance(0, n, distance, predecessor);
}