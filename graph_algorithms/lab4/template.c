#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

/* declaration of function in library */

void DFS (Graph *g, int s){
   Vertex *u = g->v;
   
   for(int i = 0; i < g->num_vertices; i++){
      u->pred = -1;
      u->color = 0;                          //0 is white
   }
   for (int i = 0; i< g->num_vertices; i++){
      if(u->color == 0)
         DFS_Visit(g, u);
   }
   
}

void dfs_Visit(Graph *g, Vertex* u){
   u->color = 1;      // GRAY
   for(Edge *e = u->adj; e !=NULL; e = e->next){
      Vertex *v = &g->v[e->other_vertex];
      if(v->color == 0){
         DFS_Visit(g, v);
      }
   }
   u->color = 2; //BLACK
}
/* fill in this function with the specified processing on the graph
   after the search has been performed */

void GraphProcessing (Graph *g, int s)
{
}


/* main routine that reads in text file describing a graph
   then performs search and subsequent processing */

int main (int argc, char *argv[])
{
   Graph *g;
   int s;
  
   if (argc != 3)
   {
      printf ("usage: %s <graph_file> <source_vertex>\n");
      return 1;
   }

   g = ReadGraphFile (argv[1]);

   if (g != NULL)
   {
       s = atoi (argv[2]);

       DFS (g, s);

       GraphProcessing (g, s);
   }
}

