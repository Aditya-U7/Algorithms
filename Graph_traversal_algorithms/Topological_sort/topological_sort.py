from collections import deque             # For deque()

def topological_sort(adj_list):

    indegree = [0 for i in range(len(adj_list))]   
    
    vertices_with_indegree_zero = deque()
    
    visiting_order = []
    
    for each_vertex in adj_list:
    
        for each_neighbour in each_vertex:
        
            indegree[each_neighbour] += 1
            
    count = 0
    
    for each_vertex in indegree:
    
        if each_vertex == 0:
        
           vertices_with_indegree_zero.append(count)
           
        count += 1
           
    while (vertices_with_indegree_zero):
    
        vertex = vertices_with_indegree_zero.popleft()
        
        visiting_order.append(vertex)
        
        for each_neighbour in adj_list[vertex]:
        
            indegree[each_neighbour] -= 1
            
            if indegree[each_neighbour] == 0:
            
                vertices_with_indegree_zero.append(each_neighbour)
    
    if (visiting_order):
    
        print("\nThe visitng order is as follows:", end="\n")
    
    for vertex in visiting_order:
    
        print(vertex, end=" ")
    
    print("\n")        
                                

def check_vertex(vertex, nov):
    
    while(1):
        
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
    
        noe -= 1 
           
    return adj_list

########################################################

no_of_vertices = int(input("Enter the no of vertices: "))

adj_list = [[] for i in range(0, no_of_vertices)]

no_of_edges = int(input("Enter the no of edges: "))

adj_list = read_edges(no_of_vertices, no_of_edges, adj_list)

topological_sort(adj_list)    

