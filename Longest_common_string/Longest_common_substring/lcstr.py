def lcw(str1, str2):
    
    r = len(str1)
    c = len(str2)
    
    mat = [[0 for j in range(c + 1)] for i in range(r + 1)]
    
    max_len = 0
    
    for i in range(c - 1, -1, -1):
        
        for j in range(r - 1, -1, -1):
             
             if str1[j] == str2[i]:
                 
                 mat[j][i] = mat[j + 1][i + 1] + 1
             
             if mat[j][i] > max_len:
               
               max_len = mat[j][i]
               
    return (max_len)
    
###########################################

str_one = input("Enter string one:\n")
str_two = input("Enter string two:\n")

maximum_length = lcw(str_one, str_two)

print("\nLength of longest common substring is:\n", maximum_length, sep="")


