#include <iostream>
#include <vector>
#include <queue>


void topological_sort(const std::vector<std::vector<int>>& adj_list)
{

	std::vector<int> indegree(adj_list.size(), 0);

	std::queue<int> vertices_with_indegree_zero;

	std::vector<int> visiting_order;

	for (auto& neighbours: adj_list)
	{

		for (auto& neighbour_vertex:  neighbours)
			indegree[neighbour_vertex] += 1; 


	}

	int count = 0;

	for (auto& vertex : indegree)
	{

		if (vertex == 0)
			vertices_with_indegree_zero.push(count);

		count++;
	}

	while (!vertices_with_indegree_zero.empty())
	{

		int vertex_with_indegree_zero = vertices_with_indegree_zero.front();

		visiting_order.push_back(vertex_with_indegree_zero);

		vertices_with_indegree_zero.pop();

		for (auto v : adj_list[vertex_with_indegree_zero])
		{

			indegree[v] -= 1;

			if (indegree[v] == 0)
				vertices_with_indegree_zero.push(v);  

		}



	}

	if (visiting_order.size() != 0)
		std::cout << "\nThe visiting order of vertices is as follows:" << std::endl;

	for (auto& vertex : visiting_order)
		std::cout << vertex << " ";

	std::cout << std::endl;
}


void check_vertex(int& v, int& vc)	// check_vertex starts
{
	while (v >= vc || v < 0)
	{
		std::cout << "Invalid vertex no: " << v << std::endl;
		std::cout << "Re enter the vertex: " << std::endl;
		std::cin >> v;
	}
}	                               // check_vertex ends


void read_vertex_and_edge_count(int& v_count, int& e_count)
{

	std::cout << "Enter the no of vertices:" << std::endl;
	std::cin >> v_count;
	std::cout << "Enter the no of edges: " << std::endl;
	std::cin >> e_count;

}


void read_the_edges(std::vector<std::vector<int>>& adj, int& ec, int& v_count)
{

	int source;
	int destination;
	std::cout << "\nEnter the edges: " << std::endl;

	while (ec--)
	{
		std::cin >> source >> destination;

		check_vertex(source, v_count);
		check_vertex(destination, v_count);

		adj[source].push_back(destination);

	}

}


int main()
{

	int start_vertex;
	int vertex;
	int vertices_count = 0;
	int edges_count = 0;

	read_vertex_and_edge_count(vertices_count, edges_count);

	std::vector<std::vector<int>> adjacency_list(vertices_count);

	read_the_edges(adjacency_list, edges_count, vertices_count);

	topological_sort(adjacency_list);             // CALLING THE Topological Sort function

	return 0;

}	

