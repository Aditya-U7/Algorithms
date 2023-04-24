arr = []


def accept_user_input():
    
    global arr
    
    print("Enter the elements: ", end="\n")
    arr = list(input().split())
    arr = [int(i) for i in arr]
    

def binary_search(arr, key):
    
    low = 0
    high = len(arr) - 1
    found = False
    index_of_element = -1
    
    if ((high == low) and (arr[0] == key)):
        
        index_of_element = 0
        found = True
    
    mid = (high+low) // 2
   
    while ((low <= high) and (not found)):
    
        if arr[mid] == key:
            
            found = True
            index_of_element = mid
            
        else:
            
            if key < arr[mid]:
                high = mid - 1
            elif key > arr[mid]:
                low = mid + 1
            
            mid = (low+high) // 2    
                       
    print("Element", key, end="")
    
    if found:
        
        print(" found at index: ", index_of_element, end="\n")
    
    else:
        
        print(" not found.", end="\n")                    
        

accept_user_input()

key = int(input("Enter the search element: "))
    
binary_search(arr, key)    
