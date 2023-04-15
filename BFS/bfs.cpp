#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<vector<int>> vertices;
queue<int> q; 


void initialise (vector<bool>& v)
{

	v.resize(vertices.size());

	for (int i=0; i<=vertices.size(); i++)
		v[i] = false;

}                         // initialise ends


void bfs (int start)      
{                         //bfs starts                          

	int v;
	vector<bool> visited;

	initialise (visited);

	visited[start] = true;

	q.push(start);

	while (!q.empty())
	{
		v = q.front();
		cout<<v<<endl;


		for (auto& e : vertices[v])
		{

			if ( visited[e] == false)
			{

				q.push(e);
				visited[e] = true;

			}
		}
		cout<<endl;
		q.pop();
	}

} // bfs ends

void check_vertex (int& v, int& vc)    // check_vertex starts
{

	while ( v > vc || v < 0 )
	{
		cout<<"Invalid vertex no: "<<v<<endl;
		cout<<"Re enter the vertex: "<<endl;
		cin>>v;  
	}

} // check_vertex ends

int main()
{

	int start_vertex;
	int vertex;
	int v_count = 0;
	int edges_count = 0;

	cout<<"Enter the no of vertices:"<<endl;
	cin>>v_count;
	vertices.resize (v_count+1);

	cout<<"Enter the no of edges: "<<endl;
	cin>>edges_count;

	int count = 0;
	int source;
	int destination;
	cout<<"Enter the edges: "<<endl;

	while ( count < edges_count)
	{

		cin>>source>>destination;

		check_vertex ( source, v_count);
		check_vertex ( destination , v_count);

		vertices[source].push_back(destination);
		
		if ( graph_type == 'u')
		vertices[destination].push_back(source); 
		
		count++;
	}

	cout<<"Enter the start vertex: ";
	cin>>start_vertex;

	bfs (start_vertex);

	return 0;

}
