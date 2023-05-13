#include <iostream>
#include <vector>
#include <queue>


void bfs(std::vector<std::vector<int>>& adj_l, int start)
{
	//bfs starts                          

	int v;
	std::vector<bool> visited(adj_l.size(), false);

	visited[start] = true;

	std::queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		v = q.front();
		std::cout << v << std::endl;

		for (auto& neighbour: adj_l[v])
		{
			if (!visited[neighbour])
			{
				q.push(neighbour);
				visited[neighbour] = true;
			}
		}

		std::cout << std::endl;
		q.pop();
	}
}	// bfs ends

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

void read_the_graph_type(char& gt)
{

	std::cout << "Enter the graph type - directed[ d ] or undirected[ u ]:  ";
	std::cin >> gt;

}

void read_the_edges(std::vector<std::vector<int>>& adj, int& ec, int& v_count, char& gt)
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

		if (gt == 'u')
			adj[destination].push_back(source);
	}

}

int main()
{
	int start_vertex;
	int vertex;
	int vertices_count = 0;
	int edges_count = 0;
	char graph_type = 'd';

	read_vertex_and_edge_count(vertices_count, edges_count);

	std::vector< std::vector<int> > adjacency_list(vertices_count);

	read_the_graph_type(graph_type); 

	read_the_edges(adjacency_list, edges_count, vertices_count, graph_type);

	std::cout << "\nEnter the start vertex: ";
	std::cin >> start_vertex;

	check_vertex(start_vertex, vertices_count); 

	bfs(adjacency_list, start_vertex);

	return 0;

}
