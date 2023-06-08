#include <iostream>
#include <vector>
#include <map>


void dijkstra(const std::vector<std::map<int,int>>& adj, const int& start, const int& twc)
{

	int initial_vertex = start;

	std::vector<bool> visited(adj.size(), false);

	std::vector<int> distance(adj.size(), twc);

	distance[initial_vertex] = 0;

	for (int i = 0; i < adj.size(); i++)
	{

		int minimum_weight = twc;
		int selected_vertex;


		for (int vn = 0; vn < adj.size(); vn++) 
		{

			if (!visited[vn] && distance[vn] < minimum_weight)  
			{

				minimum_weight = distance[vn];
				selected_vertex = vn;

			}
		}

		visited[selected_vertex] = true;

		for (auto neighbour : adj[selected_vertex])
		{
			if (distance[neighbour.first] > distance[selected_vertex] + neighbour.second) 

				distance[neighbour.first] =  distance[selected_vertex] + neighbour.second;

		}
	}

	int count = 0;

	for (auto& d : distance)
	{
		std::cout << "Distance from "<< initial_vertex << " to  vertex " << count << " is: "<< d << std::endl;
		count++;
	}
}


void check_weight(int& w)
{
	while (w < 0)
	{
		std::cout << "Invalid weight input. Please enter a postive weight." <<std::endl;
		std::cin >> w;
	}
}

void check_vertex(int& v, int& vc)	// check_vertex starts
{
	while (v >= vc || v < 0)
	{
		std::cout << "Invalid vertex no: " << v << std::endl;
		std::cout << "Re enter the vertex: " << std::endl;
		std::cin >> v;
	}
}	// check_vertex ends


void read_vertex_and_edge_count(int& v_count, int& e_count)
{

	std::cout << "Enter the no of vertices:" << std::endl;
	std::cin >> v_count;
	std::cout << "Enter the no of edges: " << std::endl;
	std::cin >> e_count;

}


void read_the_edges(std::vector<std::map<int,int>>& adj, int& ec, int& v_count, int& twc)
{

	int source;
	int destination;
	int weight;
	std::cout << "\nEnter the edges and their weights (non-negative): " << std::endl;

	while (ec--)
	{
		std::cin >> source >> destination >> weight;

		check_vertex(source, v_count);
		check_vertex(destination, v_count);
		check_weight(weight);

		twc += weight;         // Representing the concept of infinity value at the beginning  

		adj[source].insert({destination, weight});

		adj[destination].insert({source, weight});


	}

}


int main()
{

	int start_vertex;
	int vertex;
	int vertices_count = 0;
	int edges_count = 0;
	int total_weight_count = 2;
	read_vertex_and_edge_count(vertices_count, edges_count);

	std::vector<std::map<int,int>> adjacency_list(vertices_count);
	read_the_edges(adjacency_list, edges_count, vertices_count, total_weight_count);

	std::cout << "\nEnter the start vertex: ";
	std::cin >> start_vertex;

	check_vertex(start_vertex, vertices_count);

	dijkstra(adjacency_list, start_vertex, total_weight_count);             // CALLING THE DIJKSTRA'S ALGORITHM

	return 0;
}
