def bellmanford(adj_list, start_vertex, tw, noe):
    
    distance = [tw for i in range(len(adj_list))]
   
    distance[start_vertex] = 0
    
    while(noe):
    
        for i in range(len(adj_list)):
        
            for key, value in adj_list[i].items():
        
                distance[key] = min(distance[key], (distance[i] + value))
                             
        
        noe -= 1
        
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
        
        noe -= 1
    
    return (tw)         

###################################################

no_of_vertices = int(input("Enter the no of vertices: "))

adj_list = [{} for i in range(0, (no_of_vertices))]

no_of_edges = int(input("\nEnter the no of edges: "))    

total_weight = read_edges(no_of_vertices, no_of_edges, adj_list)

start_vertex = int(input("\nEnter the start vertex: "))

print("\nCalling BellmanFord's algorithm...", end="\n")

bellmanford(adj_list, start_vertex, total_weight, no_of_edges)
