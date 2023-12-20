#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "data_structures.c"
#include "graph.h"

void enqueue(queue *q, vertex *v);
vertex* dequeue(queue *q);

/*
BFS(G, s)::
    for each vertex u in G.V - s
    u.color = WHite
    u.d = infinity
    u.pi = NULL
s.color = GRAY
s.d = 0
s.pi = NULL
MakeQueue(Q)
EnQueue(Q, s)
while Q != NULL
    u = DeQueue(Q)
    for each vertex in G.Adj[u]
        if v.color = WHITE
            v.color
            v.d = u.d + 1
            v.pi = u
            EnQueue(Q, u)
    u.color = BLACK
*/


void BFS(graph *g){
    vertex *v = &g->v[0]; //source
    

    for(int i = 0; i <= g->num_vertices; i++){
        v[i].color = 0;                 // 0 represents WHITE
        v[i].d = 100000000000000000000000000;
        v[i].pred = NULL;
    }
    v[0].color = 1;         // 1 represents GRAY
    v[0].d     = 0;         // distance from source is zero
    queue *q = createQueue();
    enqueue(q, v);
    while(!isEmpty(q)){
        int u = dequeue(q);
        for(edge *e = g->v[u].adj; e != NULL ; e = e->next){
            v = &g->v[e->other_vertex];
            if(v->color == 0){  //if current vertex is white
                v->color = 1;   //set state to gray
                v->d = u->d +1;
                v->pred = u;
                enqueue(q, v);
            }
        }
        u->color = 2;

    }
}
