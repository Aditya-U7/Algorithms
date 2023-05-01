arr = []


def accept_user_input():
    
    global arr
    
    print("Enter the elements: ", end="\n")
    arr = list(input().split())
    arr = [int(i) for i in arr]
    

def linear_search(arr, key):
    
    found = False
    index_of_element = -1
    
    for i in arr:
        
        index_of_element += 1
        
        if i == key:
            
            found = True
            break
            
    print("Element ", key, end="")
            
    if (found):
        
        print(" found at index: ", index_of_element)
    
    else:
         
        print(" not found.") 
                      

accept_user_input()

key = int(input("Enter the search element: "))

linear_search(arr, key)    
