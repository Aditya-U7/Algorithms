def dijkstra(adj_list, start_vertex, tw):
    
    visited = [ False for i in range(len(adj_list))]
    
    distance = [tw for i in range(len(adj_list))]
   
    distance[start_vertex] = 0
    
    for i in range(len(adj_list)):
    
        minimum_weight = tw
        
        for j in range(len(distance)):
        
            if ((not visited[j]) and (distance[j] < tw)):
            
                minimum_weight = distance[j]
                
                mw_vertex = j
                
        visited[mw_vertex] = True
        
        for key, value in adj_list[mw_vertex].items():
        
            if distance[key] > distance[mw_vertex] + value:
                
                distance[key] = distance[mw_vertex] + value             
    
    vertex_no = 0        
    
    for each in distance:
        
        print("Shortest distance to vertex", vertex_no," : ", each)
        
        vertex_no += 1         


def check_vertex(vertex, nov):
    
    while(1):
        
        if (vertex > nov or vertex < 0):
            
            print("Invalid vertex: ", vertex)
            
            vertex = int(input("Re-enter the vertex: "))
        
        else:
            return vertex


def check_weight(weight):
    
    while(1):
        
        if (weight < 0):
            
            weight = int(input("Invalid weight. Enter a non-negative weight"))
        
        else:
            
            return weight    


def read_edges(nov, noe, adj_list):                  # noe = no_of_edges
    
    tw = 1
    
    print("\nProvide the edges and their weights: \nvertex1 vertex2 weight", end="\n")
    
    while (noe):

        vertex = list(input().split(" "))
        source, destination, weight = int(vertex[0]), int(vertex[1]), int(vertex[2])     
    
        source = check_vertex(source, nov)
        destination = check_vertex(destination, nov)
        
        weight = check_weight(weight)
        
        tw += weight
        
        adj_list[source][destination] = weight
        adj_list[destination][source] = weight
    
        
        noe -= 1
    
    return (tw)         

###################################################

no_of_vertices = int(input("Enter the no of vertices: "))

adj_list = [{} for i in range(0, (no_of_vertices))]

no_of_edges = int(input("\nEnter the no of edges: "))    

total_weight = read_edges(no_of_vertices, no_of_edges, adj_list)

start_vertex = int(input("\nEnter the start vertex: "))

print("Calling Dijkstra's algorithm...", end="\n")

dijkstra(adj_list, start_vertex, total_weight)          # Calling the Dijkstra's algorithm        

