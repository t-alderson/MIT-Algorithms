#include "graph.h"
#include <stdlib.h>

/*
DFS(G):
    for each vertex u in G.v
        u.color = WHITE
        u.pred = NULL
    time = 0
    for each vertex u in G.v
        if (u.color == WHITE)
            DFS-VISTED(G, u)

DFS-VISIT(G, u):
    u.color = GRAY
    time = time + 1
    u.d = time
    for each vertex v in G.adj[u]
        v.pred = u
        if(v.color == WHITE)
            DFS-VISIT(G, v)
    time = time + 1
    u.f = time
    u.color = BLACK
*/

void DFS(graph *g){
    vertex *u = g->v;
    for(int i = 0; i < g->num_vertices; i++){
        u->color = 0;                            // WHITE = 0
        u->pred = NULL;
    }
    for(int i = 0; u < g->num_vertices; i++){
        if(u->color = 0){
            DFS_Visit(g, u);
        }
    }
}

void DFS_Visit(graph *g, vertex *u){
    u->color = 1;                                 // GRAY = 1
    for(edge *e = u->adj; e != NULL; e = e->next){
        vertex *v = &g->v[e->other_vertex];
        v->pred = u;
        if(v->color == 0){
            DFS_Visit(g, v);
        }
        
    }    
    u->color = 2;
}

/*
*/