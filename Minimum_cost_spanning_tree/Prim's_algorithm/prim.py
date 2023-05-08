def prim(adj_list, tw):
    
    distance = [tw for i in range(len(adj_list))]
    
    neighbour = [-1 for i in range(len(adj_list))]
    
    visited = [False for i in range(len(adj_list))]
   
    for neighbour_v, weight in adj_list[0].items():
    
        distance[neighbour_v] = weight
        neighbour[neighbour_v] = 0
    
    visited[0] = True    
        
    
    for i in range(1, len(adj_list)):
    
        minimum_weight = tw
        
        
        for j in range(1, len(distance)):
        
            if ((not visited[j]) and (distance[j] < minimum_weight)):
            
                minimum_weight = distance[j]
                
                mw_vertex = j
                
        visited[mw_vertex] = True
        
        for neighbour_v, weight in adj_list[mw_vertex].items():
        
            if (not visited[neighbour_v]) and (distance[neighbour_v] > weight):
                
                distance[neighbour_v] = weight
                neighbour[neighbour_v] = mw_vertex             
    
    for i in range(1, len(neighbour)):
        
        print(neighbour[i], " <--> ", i, " with distance ", distance[i])
        
                 
def check_vertex(vertex, nov):
    
    while(1):
        
        if (vertex >= nov or vertex < 0):
            
            print("Invalid vertex: ", vertex)
            
            vertex = int(input("Re-enter the vertex: "))
        
        else:
            return vertex


def read_edges(nov, noe, adj_list):                  # noe = no_of_edges
    
    tw = 1
    
    print("\nProvide the edges and their weights: \nvertex1 vertex2 weight", end="\n")
    
    while (noe):

        vertex = list(input().split(" "))
        source, destination, weight = int(vertex[0]), int(vertex[1]), int(vertex[2])     
    
        source = check_vertex(source, nov)
        destination = check_vertex(destination, nov)
        
        tw += abs(weight)
        
        adj_list[source][destination] = weight
        adj_list[destination][source] = weight
    
        
        noe -= 1
    
    return (tw)         

###################################################

no_of_vertices = int(input("Enter the no of vertices: "))

adj_list = [{} for i in range(0, (no_of_vertices))]

no_of_edges = int(input("\nEnter the no of edges: "))    

total_weight = read_edges(no_of_vertices, no_of_edges, adj_list)

print("\n\nCalling Prim's algorithm...", end="\n")

prim(adj_list, total_weight)          # Calling the Prim's algorithm        

