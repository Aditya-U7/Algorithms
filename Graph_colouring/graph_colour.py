def check_vertex(vertex, nov):
    
    while (True):
        
        if (vertex >= nov or vertex < 0):
            
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
        adj_list[destination].append(source)
    
        noe -= 1
    
    return adj_list    


def graph_colour(adj_list):
    
    coloured = [1 for i in range(len(adj_list))]    
    min_col_req = 1
    current_vertex = 0
    
    for neighbour_list in adj_list:
           
        for neighbour in neighbour_list:
              
            if coloured[neighbour] == coloured[current_vertex]:
                coloured[neighbour] += 1
                                                                    
                if coloured[neighbour] > min_col_req:
                        min_col_req = coloured[neighbour]
                                      
        current_vertex += 1        
    
    print("The minimum colour(s) required is/are: ", min_col_req)      
          
###################
 
no_of_vertices = int(input("Enter the no of vertices: "))

adj_list = [[] for i in range(0, (no_of_vertices))]

no_of_edges = int(input("Enter the no of edges: "))    

if no_of_edges > 0:
    adj_list = read_edges(no_of_vertices, no_of_edges, adj_list)

graph_colour(adj_list) 




