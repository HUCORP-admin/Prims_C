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

		}
		// add edge
		else if (cmd == "a") 
		{

		}
		// erase edge
		else if (cmd == "e") 
		{

		}
		// check edge
		else if (cmd == "edge") 
		{

		}
		// get degree of vertex
		else if (cmd == "deg") 
		{

		}
		// total num edges in graph
		else if (cmd == "num_edges") 
		{

		}
		else if (cmd == "clear") 
		{

		}
		else if (cmd == "print")
		{

		}
		else if (cmd == "mst") 
		{

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
