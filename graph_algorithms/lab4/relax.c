#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


void Relax(Graph *g, Edge *e, int *flag_ptr){
	Vertex *u = &(g->v[e->vertex]);
	Vertex *v = &(g->v[e->other_vertex]);
	if(v->d > (u->d + e->weight)){
		printf("\tvertex %d estimate changed from %d to %d\n",e->other_vertex, v->d, u->d + e->weight);
		v->d = (u->d + e->weight);
		v->pred = e->vertex;
		*flag_ptr = 1;
	}
}