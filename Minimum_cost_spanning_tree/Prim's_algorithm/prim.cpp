#include <iostream>
#include <vector>
#include <map>


void prim(std::vector<std::map<int,int>>& adj_list, int& twc)
{

	std::vector<int> distance(adj_list.size(), twc);

	std::vector<bool> visited(adj_list.size(), false);

	std::vector<int> neighbour(adj_list.size(), -1);

	for (auto neighbour_of_vertex : adj_list[0])
	{

		distance[neighbour_of_vertex.first] = neighbour_of_vertex.second; 
		neighbour[neighbour_of_vertex.first] = 0;

	}

	visited[0] = true;
	distance[0] = 0;
	neighbour[0] = 0;

	for (int i = 1; i < adj_list.size(); i++)
	{

		int minimum_weight = twc;
		int selected_vertex;

		for (int vn = 1; vn < adj_list.size(); vn++) 
		{

			if (!visited[vn] && distance[vn] < minimum_weight)  
			{

				minimum_weight = distance[vn];
				selected_vertex = vn;

			}
		}

		visited[selected_vertex] = true;

		for (auto neighbour_of_vertex : adj_list[selected_vertex])
		{

			if (!visited[neighbour_of_vertex.first] and (distance[neighbour_of_vertex.first] > neighbour_of_vertex.second)) 
			{

				neighbour[neighbour_of_vertex.first] = selected_vertex;
				distance[neighbour_of_vertex.first] = neighbour_of_vertex.second;

			}
		}

	} 

	std::cout << "\nThe following edges and their distances form the minimum cost tree" << std::endl;

	for (int i = 1; i < neighbour.size(); i++)
	{

		std::cout << neighbour[i] << " <--> " << i << " with distance = " << distance[i] << std::endl;

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
	std::cout << "\nEnter the edges and their weights: " << std::endl;

	while (ec--)
	{
		std::cin >> source >> destination >> weight;

		check_vertex(source, v_count);
		check_vertex(destination, v_count);

		weight < 0 ? twc += ((-1) * (weight)) : twc += weight;         // Representing the concept of infinity

		adj[source].insert({destination, weight});

		adj[destination].insert({source, weight});

	}

}


int main()
{

	int vertex;
	int vertices_count = 0;
	int edges_count = 0;
	int total_weight_count = 1;

	read_vertex_and_edge_count(vertices_count, edges_count);

	std::vector<std::map<int,int>> adjacency_list(vertices_count);
	read_the_edges(adjacency_list, edges_count, vertices_count, total_weight_count);

	prim(adjacency_list, total_weight_count);             // CALLING THE PRIM'S ALGORITHM

	return 0;
}
