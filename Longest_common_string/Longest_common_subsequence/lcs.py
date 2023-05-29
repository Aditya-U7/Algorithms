def lcs(str1, str2):
    
    r = len(str1)
    c = len(str2)
    
    mat = [[0 for j in range(c+1)] for i in range(r+1)]
    
    max_len = 0
    
    for i in range(c-1, -1, -1):
        
        for j in range(r-1, -1, -1):
             
             if str1[j] == str2[i]:
                 
                 mat[j][i] = mat[j+1][i+1] + 1
             
             else:
             
                 mat[j][i] = max(mat[j][i+1], mat[j+1][i])     
             
             if mat[j][i] > max_len:
               
               max_len = mat[j][i]
               
    return (mat[0][0])
    
###########################################

str_one = input("Enter string one:\n")
str_two = input("Enter string two:\n")

maximum_length = lcs(str_one, str_two)

print("\nLength of longest common subsequence is:\n", maximum_length, sep="")
