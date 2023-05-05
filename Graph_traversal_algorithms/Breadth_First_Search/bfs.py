def check_vertex(vertex, nov):
    
    while(1):
        
        if (vertex > nov or vertex < 0):
            
            print("Invalid vertex: ", vertex)
            
            vertex = int(input("Re-enter the vertex: "))
        
        else:
            return vertex


def read_edges(nov, noe, adj_list): 
    
    print("Enter the edges: ")

    while (noe):

        vertex = list(input().split())
        source, destination = int(vertex[0]), int(vertex[1])     
    
        source = check_vertex(source, nov)
        destination = check_vertex(destination, nov)
        
        adj_list[source].append(destination)
    
        if graph_type == 'u':
        
            adj_list[destination].append(source)
    
        noe -= 1
    
    return adj_list    


def bfs(start, adj_list):
    
    visited = [False for i in range(len(adj_list))]    
    
    visited[start] = True
    queue = []
    
    queue.append(start)
    
    vertex = start
    
    while (len(queue)):
       
       vertex =  queue[0]
       
       queue = queue[1:] 
       
       for neighbour in adj_list[vertex]:
          
          if (not visited[neighbour]):
              
              visited[neighbour] = True 
              queue.append(neighbour)
          
       print(vertex)   

 
#######################################################   

no_of_vertices = int(input("Enter the no of vertices: "))

adj_list = [[] for i in range(0, (no_of_vertices + 1))]

no_of_edges = int(input("Enter the no of edges: "))    

graph_type = input("Enter the graph type -  undirected [ u ] or directed [ d ]: ")

adj_list = read_edges(no_of_vertices, no_of_edges, adj_list)

start_vertex = int(input("Enter the start vertex: "))

start_vertex = check_vertex(start_vertex, no_of_vertices)

bfs(start_vertex, adj_list) #calling the bfs() function on the adj_list


