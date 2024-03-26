#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "graph_adjacency_list.h"

int isVisited(Vertex **res, int size, Vertex *vet) {
    for (int i = 0; i < size; i++) {
        if (res[i] == vet) {
            return 1;
        }
    }
    return 0;
}

void dfs(GraphAdjList *graph, Vertex **res, int *resSize, Vertex *vet) {
    res[(*resSize)++] = vet;
    AdjListNode *node = findNode(graph, vet);
    while (node != NULL) {
        if (!isVisited(res, *resSize, node->vertex)) {
            dfs(graph, res, resSize, node->vertex);
        }
        node = node->next;
    }
}

/* 深度优先遍历 */
// 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点
void graphDFS(GraphAdjList *graph, Vertex *startVet, Vertex **res, int *resSize) {
    dfs(graph, res, resSize, startVet);
}
