#include <stdlib.h>
#include <string.h>
#include "bfs.h"

#include <queue>

#include "parent_array_multiway_tree.h"
#include "multiway_tree.h"

bool is_in_grid(const Grid* grid, Point p)
{
    return p.row >= 0 && p.row < grid->rows && p.col >= 0 && p.col < grid->cols;
}

bool is_free_cell(const Grid* grid, Point p)
{
    return grid->mat[p.row][p.col] == 0;
}

Point potential_neighbor(Point p, Direction dir)
{
    Point neighbor;
    neighbor.row = p.row;
    neighbor.col = p.col;
	switch (dir)
	{
    case Direction::UP:
        neighbor.row--;
        break;
    case Direction::RIGHT:
        neighbor.col++;
        break;
    case Direction::DOWN:
        neighbor.row++;
        break;
    case Direction::LEFT:
        neighbor.col--;
        break;
	}
    return neighbor;
}

int get_neighbors(const Grid *grid, Point p, Point neighb[])
{
    // TODO: fill the array neighb with the neighbors of the point p and return the number of neighbors
    // the point p will have at most 4 neighbors (up, down, left, right)
    // avoid the neighbors that are outside the grid limits or fall into a wall
    // note: the size of the array neighb is guaranteed to be at least 4
    int no_neighbors = 0;
    Direction directions[4] = { Direction::UP, Direction::RIGHT, Direction::DOWN, Direction::LEFT };
	for (int i = 0; i < 4; i++)
	{
        Point np = potential_neighbor(p, directions[i]);
		if (is_in_grid(grid, np) && is_free_cell(grid, np))
		{
            neighb[no_neighbors] = np;
            no_neighbors++;
		}
	}
    return no_neighbors;
}

void grid_to_graph(const Grid *grid, Graph *graph)
{
    //we need to keep the nodes in a matrix, so we can easily refer to a position in the grid
    Node *nodes[MAX_ROWS][MAX_COLS];
    int i, j, k;
    Point neighb[4];

    //compute how many nodes we have and allocate each node
    graph->nrNodes = 0;
    for(i=0; i<grid->rows; ++i){
        for(j=0; j<grid->cols; ++j){
            if(grid->mat[i][j] == 0){
                nodes[i][j] = (Node*)malloc(sizeof(Node));
                memset(nodes[i][j], 0, sizeof(Node)); //initialize all fields with 0/NULL
                nodes[i][j]->position.row = i;
                nodes[i][j]->position.col = j;
                ++graph->nrNodes;
            }else{
                nodes[i][j] = NULL;
            }
        }
    }
    graph->v = (Node**)malloc(graph->nrNodes * sizeof(Node*));
    k = 0;
    for(i=0; i<grid->rows; ++i){
        for(j=0; j<grid->cols; ++j){
            if(nodes[i][j] != NULL){
                graph->v[k++] = nodes[i][j];
            }
        }
    }

    //compute the adjacency list for each node
    for(i=0; i<graph->nrNodes; ++i){
        graph->v[i]->adjSize = get_neighbors(grid, graph->v[i]->position, neighb);
        if(graph->v[i]->adjSize != 0){
            graph->v[i]->adj = (Node**)malloc(graph->v[i]->adjSize * sizeof(Node*));
            k = 0;
            for(j=0; j<graph->v[i]->adjSize; ++j){
                if( neighb[j].row >= 0 && neighb[j].row < grid->rows &&
                    neighb[j].col >= 0 && neighb[j].col < grid->cols &&
                    grid->mat[neighb[j].row][neighb[j].col] == 0){
                        graph->v[i]->adj[k++] = nodes[neighb[j].row][neighb[j].col];
                }
            }
            if(k < graph->v[i]->adjSize){
                //get_neighbors returned some invalid neighbors
                graph->v[i]->adjSize = k;
                graph->v[i]->adj = (Node**)realloc(graph->v[i]->adj, k * sizeof(Node*));
            }
        }
    }
}

void free_graph(Graph *graph)
{
    if(graph->v != NULL){
        for(int i=0; i<graph->nrNodes; ++i){
            if(graph->v[i] != NULL){
                if(graph->v[i]->adj != NULL){
                    free(graph->v[i]->adj);
                    graph->v[i]->adj = NULL;
                }
                graph->v[i]->adjSize = 0;
                free(graph->v[i]);
                graph->v[i] = NULL;
            }
        }
        free(graph->v);
        graph->v = NULL;
    }
    graph->nrNodes = 0;
}

void bfs(Graph *graph, Node *s, Operation *op)
{
    // TOOD: implement the BFS algorithm on the graph, starting from the node s
    // at the end of the algorithm, every node reachable from s should have the color BLACK
    // for all the visited nodes, the minimum distance from s (dist) and the parent in the BFS tree should be set
    // for counting the number of operations, the optional op parameter is received
    // since op can be NULL (when we are calling the bfs for display purposes), you should check it before counting:
    // if(op != NULL) op->count();
    std::queue<Node*> bfs_queue;
	for (int i = 0; i < graph->nrNodes; i++)
	{
        graph->v[i]->color = COLOR_WHITE;
        if (op != NULL) op->count();
	}
    s->color = COLOR_GRAY;
    s->dist = 0;
    bfs_queue.push(s);
    if (op != NULL) op->count(3);
	while (!bfs_queue.empty())
	{
        Node* curr_node = bfs_queue.front();
        if (op != NULL) op->count();
		// process neighbors
		for (int i = 0; i < curr_node->adjSize; i++)
		{
            if (op != NULL) op->count();
			if (curr_node->adj[i]->color == COLOR_WHITE)
			{
                bfs_queue.push(curr_node->adj[i]);
                curr_node->adj[i]->parent = curr_node;
                curr_node->adj[i]->color = COLOR_GRAY;
                curr_node->adj[i]->dist = curr_node->dist + 1;
                if (op != NULL) op->count(4);
			}
		}
        bfs_queue.pop();
        curr_node->color = COLOR_BLACK;
        if (op != NULL) op->count();
	}
}

void bfs_until_target(Graph* graph, Node* s, Node* target)
{
    //In comparsion to bfs(), this search stops when it founds the target node
    std::queue<Node*> bfs_queue;
    for (int i = 0; i < graph->nrNodes; i++)
    {
        graph->v[i]->color = COLOR_WHITE;
    }
    s->color = COLOR_GRAY;
    s->dist = 0;
    bfs_queue.push(s);
    bool found_target = s == target;
    while (!bfs_queue.empty() && !found_target)
    {
        Node* curr_node = bfs_queue.front();
        // process neighbors
        for (int i = 0; i < curr_node->adjSize; i++)
        {
            if (curr_node->adj[i]->color == COLOR_WHITE)
            {
                bfs_queue.push(curr_node->adj[i]);
                curr_node->adj[i]->parent = curr_node;
                curr_node->adj[i]->color = COLOR_GRAY;
                curr_node->adj[i]->dist = curr_node->dist + 1;
            	if (curr_node->adj[i] == target)
            	{
                    found_target = true;
            	}
            }
        }
        bfs_queue.pop();
        curr_node->color = COLOR_BLACK;
    }
}

void print_bfs_tree(Graph *graph)
{
    //first, we will represent the BFS tree as a parent array
    int n = 0; //the number of nodes
    int *p = NULL; //the parent array
    Point *repr = NULL; //the representation for each element in p

    //some of the nodes in graph->v may not have been reached by BFS
    //p and repr will contain only the reachable nodes
    int *transf = (int*)malloc(graph->nrNodes * sizeof(int));
    for(int i=0; i<graph->nrNodes; ++i){
        if(graph->v[i]->color == COLOR_BLACK){
            transf[i] = n;
            ++n;
        }else{
            transf[i] = -1;
        }
    }
    if(n == 0){
        //no BFS tree
        free(transf);
        return;
    }

    int err = 0;
    p = (int*)malloc(n * sizeof(int));
    repr = (Point*)malloc(n * sizeof(Node));
    for(int i=0; i<graph->nrNodes && !err; ++i){
        if(graph->v[i]->color == COLOR_BLACK){
            if(transf[i] < 0 || transf[i] >= n){
                err = 1;
            }else{
                repr[transf[i]] = graph->v[i]->position;
                if(graph->v[i]->parent == NULL){
                    p[transf[i]] = -1;
                }else{
                    err = 1;
                    for(int j=0; j<graph->nrNodes; ++j){
                        if(graph->v[i]->parent == graph->v[j]){
                            if(transf[j] >= 0 && transf[j] < n){
                                p[transf[i]] = transf[j];
                                err = 0;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    free(transf);
    transf = NULL;

    if(!err){
        // TODO: pretty print the BFS tree
        // the parrent array is p (p[k] is the parent for node k or -1 if k is the root)
        // when printing the node k, print repr[k] (it contains the row and column for that point)
        // you can adapt the code for transforming and printing multi-way trees from the previous labs
        ParentArrayMultiwayTree parent_array_multiway_tree(p, n);
        MultiwayTree multiway_tree(parent_array_multiway_tree);
        multiway_tree.PrettyPrint(repr);
    }

    if(p != NULL){
        free(p);
        p = NULL;
    }
    if(repr != NULL){
        free(repr);
        repr = NULL;
    }
}

void reverse_array(Node* array[], int size) {
    for (int i = 0; i < size / 2; i++)
    {
        Node* helper = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = helper;
    }
}

int shortest_path(Graph *graph, Node *start, Node *end, Node *path[])
{
    // TODO: compute the shortest path between the nodes start and end in the given graph
    // the nodes from the path, should be filled, in order, in the array path
    // the number of nodes filled in the path array should be returned
    // if end is not reachable from start, return -1
    // note: the size of the array path is guaranteed to be at least 1000
    bfs_until_target(graph, start, end);
	if (end->color == COLOR_WHITE){
        return -1;
	} else {
        Node* curr_node = end;
        int no_nodes = 0;
		while (curr_node != NULL)
		{
            path[no_nodes] = curr_node;
            curr_node = curr_node->parent;
            no_nodes++;
		}
        reverse_array(path, no_nodes);
        return no_nodes;
	}
}

bool contains(Node** array, int array_size, Node* node)
{
	for (int i = 0; i < array_size; i++)
	{
		if (array[i] == node)
		{
            return true;
		}
	}
    return false;
}

void addEdgesToMakeConnected(Graph* graph, int no_edges_to_add)
{
    srand(time(NULL));
	// make the graph connected and all nodes are reachable from v[0]
	for (int n1= 1; n1 < min(graph->nrNodes, no_edges_to_add + 1); n1++)
	{
        int n2 = rand() % n1;
        graph->v[n1]->adj[graph->v[n1]->adjSize++] = graph->v[n2];
	}
	// add the missing edges
    /*int no_missing_edges = no_edges_to_add - graph->nrNodes + 1;
    int no_added_edges = 0;
	while (no_added_edges < no_missing_edges)
	{
        int n1 = rand() % graph->nrNodes;
        int n2 = rand() % graph->nrNodes;
		if (n1 != n2)
		{
			if (!contains(graph->v[n1]->adj, graph->v[n1]->adjSize, graph->v[n2]))
			{
				graph->v[n1]->adj[graph->v[n1]->adjSize++] = graph->v[n2];
                no_added_edges++;
			}
		}
	}*/
}


void performance()
{
    int n, i;
    Profiler p("bfs");

    // vary the number of edges
    for(n=1000; n<=4500; n+=100){
        Operation op = p.createOperation("bfs-edges", n);
        Graph graph;
        graph.nrNodes = 100;
        //initialize the nodes of the graph
        graph.v = (Node**)malloc(graph.nrNodes * sizeof(Node*));
        for(i=0; i<graph.nrNodes; ++i){
            graph.v[i] = (Node*)malloc(sizeof(Node));
            memset(graph.v[i], 0, sizeof(Node));
        }
        // TODO: generate n random edges
        // make sure the generated graph is connected
        addEdgesToMakeConnected(&graph, n);

        bfs(&graph, graph.v[0], &op);
        free_graph(&graph);
    }

    // vary the number of vertices
    for(n=100; n<=200; n+=10){
        Operation op = p.createOperation("bfs-vertices", n);
        Graph graph;
        graph.nrNodes = n;
        //initialize the nodes of the graph
        graph.v = (Node**)malloc(graph.nrNodes * sizeof(Node*));
        for(i=0; i<graph.nrNodes; ++i){
            graph.v[i] = (Node*)malloc(sizeof(Node));
            memset(graph.v[i], 0, sizeof(Node));
        }
        // TODO: generate 4500 random edges
        // make sure the generated graph is connected
        // addEdgesToMakeConnected(&graph, 4500);

        bfs(&graph, graph.v[0], &op);
        free_graph(&graph);
    }

    p.showReport();
}
