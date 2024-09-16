#include "priority_queue.h"

PriorityQueue::PriorityQueue(int v, double c[])
{
	cap = v;
    total = v;
    H = new pair<int, double>[cap];
    idx_map = new int[cap];

    for (int i = 0; i < v; i++)
    {
        insert(i, c[i]);
        idx_map[i] = i;
    }
}

PriorityQueue::~PriorityQueue()
{
    delete[] H;
    delete[] idx_map;
    H = nullptr;
    idx_map = nullptr;
}

int PriorityQueue::parent(int i)
{
    return (i - 1)/2;
}

int PriorityQueue::left(int i)
{
    return 2*i + 1;
}

int PriorityQueue::right(int i)
{
    return 2*i + 2;
}

void PriorityQueue::insert(int idx, double val)
{
    H[idx] = { idx, val };
    heapifyUp(idx);
}

void PriorityQueue::heapifyUp(int i)
{
    while (i != 0 && H[parent(i)].second > H[i].second)
    {
        swap(H[i], H[parent(i)]);
        idx_map[H[i].first] = i;
        idx_map[H[parent(i)].first] = parent(i);
        i = parent(i);
    }
}

void PriorityQueue::heapifyDown(int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < cap && H[l].second < H[smallest].second)
    {
        smallest = l;
    }
    if (r < cap && H[r].second < H[smallest].second)
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap(H[i], H[smallest]);
        idx_map[H[i].first] = i;
        idx_map[H[smallest].first] = smallest;
        heapifyDown(smallest);
    }
}

bool PriorityQueue::isEmpty()
{
    return cap == 0;
}

bool PriorityQueue::inQueue(int v)
{
    for (int i = 0; i < cap; i++)
    {
        if (H[i].first == v)
        {
            return true;
        }
    }

    return false;
}

int PriorityQueue::deleteMin()
{
    pair<int, double> min = H[0];
    H[0] = H[cap - 1];
    idx_map[min.first] = -1;
    idx_map[H[0].first] = 0;

    // re-heapify
    cap--;
    heapifyDown(0);

    return min.first;
}


void PriorityQueue::decreaseKey(int v, double new_val)
{
    H[idx_map[v]].second = new_val;
    heapifyUp(idx_map[v]);
}

void PriorityQueue::printQueue()
{
    cout << "Queue contents:" << endl;
	for (int i = 0; i < cap; i++)
	{
		printf("Queue (H): vertex=%d, key:=%f\n", H[i].first, H[i].second);
	}

	cout << "Index Map:" << endl;
	for (int i = 0; i < total; i++)
	{
		printf("IDX Map: vertex=%d, idx=%d\n", i, idx_map[i]);
	}
}
