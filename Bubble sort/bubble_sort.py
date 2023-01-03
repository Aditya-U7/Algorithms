def bubble_sort(arr):
    for i in range(0,j-1):
        for k in range(i+1,j):
            if arr[i]>arr[k]:
               arr[i],arr[k]=arr[k],arr[i]  # A function should be defined before it is called. 
                                            #The body of the function can be defined anywhere in the program.
    return(arr)

siz=input("Enter the no of elements:")
arr=list(input().split())
j=0
for i in arr:
    arr[j]=int(i)
    j=j+1
    
    
print(bubble_sort(arr))    
     
