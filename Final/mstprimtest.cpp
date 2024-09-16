#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "graph.h"

using namespace std;

// function declarations
vector<string> split(const string &str, char delimiter);

// function definitions
int main()
{
	string line;
	Graph graph;

	while (true) 
	{
		getline(cin, line);

		// extract command, params
		size_t pos = line.find(" ");
		string cmd = line.substr(0, pos);
		string params = line.substr(pos + 1);

		// initialize
		if (cmd == "i") 
		{
			int m = stoi(params);
			graph.initialize(m);
			cout << "success" << endl;
		}
		// add edge
		else if (cmd == "a") 
		{
			vector<string> args = split(params, ';');
			int u = stoi(args[0]);
			int v = stoi(args[1]);
			double w = stod(args[2]);

			if (graph.addEdge(u, v, w))
			{
				cout << "success" << endl;
			} 
			else {
				cout << "failure" << endl;
			}
		}
		// erase edge
		else if (cmd == "e") 
		{
			vector<string> args = split(params, ';');
			int u = stoi(args[0]);
			int v = stoi(args[1]);

			if (graph.eraseEdge(u, v))
			{
				cout << "success" << endl;
			} 
			else {
				cout << "failure" << endl;
			}
		}
		// check edge
		else if (cmd == "edge") 
		{
			vector<string> args = split(params, ';');
			int u = stoi(args[0]);
			int v = stoi(args[1]);
			double w = stod(args[2]);

			if (graph.isEdge(u, v, w))
			{
				printf("adjacent %d %d %.2f\n", u, v, w);
			}
			else {
				printf("not adjacent %d %d %.2f\n", u, v, w);
			}
		}
		// get degree of vertex
		else if (cmd == "deg") 
		{
			int u = stoi(params);
			int d = graph.degree(u);

			printf("degree of %d is %d\n", u, d);
		}
		// total num edges in graph
		else if (cmd == "num_edges") 
		{
			int n = graph.edge_count();
			cout << "edge count is " << n << endl;
		}
		else if (cmd == "clear") 
		{
			graph.clear();
			cout << "success" << endl;
		}
		else if (cmd == "print")
		{
			graph.print();
		}
		else if (cmd == "mst") 
		{
			int u = stoi(params);
			double w = graph.mst(u);

			printf("mst %0.2f\n", w);
		}
		else if (cmd == "exit") 
		{
			break;
		}
	}

	return 0;
}

vector<string> split(const string& str, char delimiter)
{
	vector<string> tokens;
	string token;
	stringstream ss(str);

	while (getline(ss, token, delimiter)) 
	{
		tokens.push_back(token);
	}

	return tokens;
}
