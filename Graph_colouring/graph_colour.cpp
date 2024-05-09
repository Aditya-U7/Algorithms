#include <iostream>
#include <vector>


void graph_colour(const std::vector<std::vector<int>>& adj_l)
{
	                          

	short current_vertex = 0;
	std::vector<int> coloured(adj_l.size(), 1);
        short min_col_req = 1;
	
           
        for (auto& neighbours: adj_l)
	{
		
		for (auto& neighbour: neighbours)
		{
			if (coloured[neighbour] == coloured[current_vertex])
			{
				coloured[neighbour] += 1;
			        if (coloured[neighbour] > min_col_req)
			        min_col_req = coloured[neighbour]; 
			}
		}
		current_vertex += 1;
	}
	
	std::cout << "The minimum colour(s) required is/are: " << min_col_req << std::endl;
}	



void check_vertex(int& v, const int& vc)	
{
	while (v >= vc || v < 0)
	{
		std::cout << "Invalid vertex no: " << v << std::endl;
		std::cout << "Re enter the vertex: " << std::endl;
		std::cin >> v;
	}
}	


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
                adj[destination].push_back(source);
	}

}


int main()
{
	
	int vertex;
	int vertices_count = 0;
	int edges_count = 0;
	
	read_vertex_and_edge_count(vertices_count, edges_count);

	std::vector<std::vector<int>> adjacency_list(vertices_count);

        if (edges_count > 0)
                read_the_edges(adjacency_list, edges_count, vertices_count);
          
	graph_colour(adjacency_list);

	return 0;

}
