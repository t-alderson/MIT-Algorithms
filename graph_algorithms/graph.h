#ifndef _GRAPH_H_
#define _GRAPH_H_

/*
  Definitions for Edge, Vertex, and Graph data structures
 */

typedef struct _edge
{
  struct _edge	*next; //next edge in the path
  int weight;
  int vertex;		/* for edges in the same list, this will be the same */
  int other_vertex;	/* identifies the other endpoint of the edge */
} edge;

typedef struct _vertex
{
  int weight;
  int color;
  int d;		/* discovery value (i.e., distance from source) */
  int f;
  int pred;		/* predecessor vertex index */
  edge *adj;		/* point to list of edges for adjacent vertices */
  double x;
  double y;
} vertex;

typedef struct _graph
{
  enum {UNDIRECTED, DIRECTED} type;
  int num_vertices;
  int num_edges;
  vertex *v;		/* array of vertex structures */
} graph;


/*
  Declarations for functions related to graphs using the above structures
*/

graph *ReadGraphFile (char *filename);
//void BFS (graph *g, int s);

#endif /* _GRAPH_H_ */
