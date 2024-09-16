#include "graph.h"

Graph::Graph() 
{
    numVertices = 0;
    numEdges = 0;
}

void Graph::initialize(int m) 
{
    numVertices = m;
    adjMatrix.resize(m, vector<double>(m, 0));
}

bool Graph::addEdge(int u, int v, double w) 
{
    if (u >= numVertices || v >= numVertices || u < 0 || v < 0 || w <= 0.00)
    {
        return false;
    }

    numEdges += 1 ? adjMatrix[u][v] == 0 : 0;
    adjMatrix[u][v] = w;
    numEdges += 1 ? adjMatrix[v][u] == 0 : 0;
    adjMatrix[v][u] = w;
    
    return true;
}

bool Graph::eraseEdge(int u, int v) 
{
    if (u >= numVertices || v >= numVertices || u < 0 || v < 0)
    {
        return false;
    }

    numEdges -= 1 ? adjMatrix[u][v] != 0 : 0;
    adjMatrix[u][v] = 0;
    numEdges -= 1 ? adjMatrix[v][u] != 0 : 0;
    adjMatrix[v][u] = 0;
    
    return true;
}

bool Graph::isEdge(int u, int v, double w) 
{
    return adjMatrix[u][v] == w && adjMatrix[v][u] == w;
}

int Graph::degree(int u) 
{
    int count = 0;
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        if (adjMatrix[u][i] > 0)
        {
            count++;
        }
    }

    return count;
}

int Graph::edge_count() 
{
    return numEdges;
}

void Graph::clear()
{
    size_t n = adjMatrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0.0;
        }
    }

    numEdges = 0;
}

void Graph::print()
{
    size_t n = adjMatrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << ", ";
        }
        cout << endl;
    }
}

double Graph::mst(int u)
{
    int* prev = new int[numVertices];
    double* cost = new double[numVertices];

    /* init */
    for (int i = 0; i < numVertices; i++)
    {
        cost[i] = numeric_limits<double>::infinity();
        prev[i] = -1;
    }

    cost[u] = 0;

    /* build MST */
    PriorityQueue H(numVertices, cost);

    while (!H.isEmpty())
    {
        int v = H.deleteMin();

        // look at all edges starting from vertex v
        for (int z = 0; z < numVertices; z++)
        {
            if (z != v && adjMatrix[v][z] > 0)
            {
                // decrease key of vertex in priority queue if better soln found
                if (H.inQueue(z) && cost[z] > adjMatrix[v][z])
                {
                    cost[z] = adjMatrix[v][z];
                    prev[z] = v;
                    H.decreaseKey(z, cost[z]);
                }
            }
        }
    }

    /* determine weight of MST */
    double sum = 0;
    for (int i = 0; i < numVertices; i++)
    {
        sum += cost[i];
    }

    // cleanup
    delete[] prev;
    delete[] cost;
    prev = nullptr;
    cost = nullptr;

    return sum;
}