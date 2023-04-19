adj_list = []
visited = []

def check_vertex(vertex, nov):
    
    while(1):
        
        if (vertex > nov or vertex < 0):
            
            print("Invalid vertex: ", vertex)
            
            vertex = int(input("Re-enter the vertex: "))
        
        else:
            return vertex


def initialise_visited(nov):
    
    
    
    for i in range(nov):     
        visited.append(False)
    
    return visited
    

def dfs(vertex):
    
    visited[vertex] = True
    
    for neighbour in  adj_list[vertex]:
        
        if not visited[neighbour]:
            
            dfs(neighbour)    
    
    print(vertex)
        

no_of_vertices = int(input("Enter the no of vertices: "))

adj_list = [[] for i in range(0, (no_of_vertices+1))]

no_of_edges = int(input("Enter the no of edges: "))    

graph_type = input("Enter the graph type -  undirected [ u ] or directed [ d ]: ")

print("Enter the edges: ")

while (no_of_edges):

    vertex = list(input().split())
    source, destination = int(vertex[0]), int(vertex[1])     
    
    source = check_vertex(source, no_of_vertices)
    destination = check_vertex(destination, no_of_vertices)
    
   
    adj_list[source].append(destination)
    
    if graph_type == 'u':
        
        adj_list[destination].append(source)
    
    no_of_edges -=1

     
start_vertex = int(input("Enter the start vertex: "))

start_vertex = check_vertex(start_vertex, no_of_vertices)

visited = initialise_visited(len(adj_list))       

dfs(start_vertex)
