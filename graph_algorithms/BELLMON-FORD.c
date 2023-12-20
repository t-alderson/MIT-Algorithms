#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "data_structures.c"

/*
BELLMAN-FORD(G)
  initialize-single-shortest(G)
  for i from 0 to |G.V| - 1
    for each edge e (u, v) in G.E
        RELAX(u, v, e.weight)
  for each edge e (u, v) in G.E
    if v.d < u.d + e.weight
        return FALSE
  return TRUE

RELAX(u, v, e.weight)
  if v.d < u.d + e.weight
    v.d = u.d + e.weight
    v.pred = u

*/