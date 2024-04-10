"""
Author: Aditya Upadhye

This is a program for implementing the Caesar cipher. The value of the key can be negative (for left shift) or positive (for right shift).

"""


def print_txt_map(txt_map):
    
    count = 1
    print('\nMapped Letters: \n')
    for key, value in txt_map.items():
        print(key, '<->', value, end="  ")
        
        if count % 8 == 0:
            print('\n')
        elif count == 26:
            print('\n\nDigits:\n')    
        
        count += 1


def shift_text(txt_map, user_input):
    text = ""
    
    for character in user_input:
        
        try:
            text += txt_map[character]   
        
        except KeyError:
            
            if character.isupper():
                text += txt_map[character.lower()].upper()
            else:
                text += character
    return text           


def caesar_cipher(user_input, shift_key=0):
    shift_keyn = shift_key % 10
    shift_key %= 26
    
    txt_map = {chr(i):chr(i) for i in range(97,123)}
    
    for i in range(48, 58):
        
        txt_map[chr(i)] = chr(i)
       
    for key, value in txt_map.items():
        
        if ((ord(value) >= 97) and (ord(value) < 123)):
            
            if ord(value) + shift_key > 122:
                txt_map[key] = chr(shift_key - (123 - ord(value)) + 97)
            
            elif ord(value) + shift_key < 97:
                txt_map[key] = chr(123 - (abs(shift_key) - (ord(value) - 97)))
            
            else:
                txt_map[key] = chr(ord(value) + shift_key)
        
        else:
            
            if (ord(value) + shift_keyn) > 57:
                txt_map[key] = chr((shift_keyn - (58 - ord(value)) + 48))
            
            elif (ord(value) + shift_keyn) < 48:
                txt_map[key] = chr(((ord(value) - 48) + shift_keyn) + 58)
            
            else:
                txt_map[key] = chr(ord(value) + shift_keyn)        
    
    print_txt_map(txt_map)
     
    return shift_text(txt_map, user_input)      
       

user_input = input('Enter the text below:\n')
key = int(input('\nEnter the key (negative value: left shift,'  
                   ' positive value: right shift):\n'))

print('\n\nAfter applying Caeser cipher:\n\n', caesar_cipher(user_input, key), sep="")





