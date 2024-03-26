#define MAX_SIZE 64

typedef struct {
    
} Vertex;

typedef struct AdjListNode {
    Vertex *vertex;
    struct AdjListNode *next;
} AdjListNode;

typedef struct {
    AdjListNode *heads[MAX_SIZE];
    int size;
} GraphAdjList;

AdjListNode *findNode(GraphAdjList *graph, Vertex *vet);