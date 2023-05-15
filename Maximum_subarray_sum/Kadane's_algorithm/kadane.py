def kadane(val):

    prev_sum = 0
    
    try:
        
        max_sum = val[0]
    
    except IndexError:
        
        return "Array is empty."
        
    for x in val:
    
        prev_sum = max(prev_sum + x, x)

        max_sum = max(max_sum, prev_sum)        


    return max_sum

###########################

values = list(input("Enter the elements:\n").split())

values = [int(x) for x in values]

max_sum = kadane(values)

print("\n", max_sum, sep="", end="\n")
