arr=[] 

def insertion_sort():
 for i in range(len(arr)):
  for j in range(i,0,-1):
    if arr[j]<arr[j-1]:
       arr[j],arr[j-1]=arr[j-1],arr[j]
        
def accept_user_input():
 global arr
 print("Enter the elements: ",end="\n")
 arr=list(input().split())      
 arr=[int(i) for i in arr]
 
def print_sorted_list():
 print("Elements after sorting by Insertion sort:",end="\n")
 for item in arr:
  print(item,end=' ')
 print("\n") 


accept_user_input()

insertion_sort()

print_sorted_list() 
 
