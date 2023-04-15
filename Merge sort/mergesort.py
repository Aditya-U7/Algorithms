arr=[]           

def create_the_halfs (arr, start, end):
 
 half = []
 for i in range ( start, (end+1)):
  half.append(arr[i])
 return (half)

def merge ( arr, start, mid, end):
 
 
 lower_half=[]
 upper_half=[]
 lower_half = create_the_halfs(arr, start, mid)
 upper_half = create_the_halfs(arr, (mid+1), end)

 
 llimit = len(lower_half)
 
 ulimit = len(upper_half) 
 
 i=0
 j=0
 pos=start

 while ( (i < llimit) and (j < ulimit) ): 
  
  if lower_half[i] == upper_half[j]:
   
   arr[pos] = lower_half[i]
   i=i+1
   
   pos=pos+1
   
   arr[pos] = upper_half[j]
   
   j=j+1
  
  elif lower_half[i] < upper_half[j]:
   
   arr[pos] = lower_half[i] 
   i = i + 1
  
  else:
    
   arr[pos] = upper_half[j]
   j = j + 1
    
  pos = pos + 1 
  
 while ( i < llimit):
   
   arr[pos] = lower_half[i]
   i=i+1
   pos = pos + 1
 
 while (j < ulimit):
   arr[pos] = upper_half[j]
   j= j + 1
   pos = pos + 1
  

def mergesort (arr, start, end):
 
 if ( (end -start) < 1):
  return
 
 mid = (start + end) // 2; 

 
 mergesort (arr, start, mid)
 mergesort (arr, mid+1, end)
 merge (arr, start, mid, end)
 





def accept_user_input():
 
 global arr
 print("Enter the elements: ",end="\n")
 arr=list(input().split())      
 arr=[int(i) for i in arr]
 
def print_sorted_list():
 
 print("\nElements after sorting by Mergesort:",end="\n")
 for item in arr:
  print(item,end=' ')
 print("\n") 


accept_user_input()

mergesort (arr, 0, (len(arr)-1))

print_sorted_list() 
