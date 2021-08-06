def check(my_string): 

    brackets = ['()', '{}', '[]'] 

    while any(x in my_string for x in brackets): 

        for br in brackets: 

            my_string = my_string.replace(br, '') 

    return not my_string 
    
    
string =input(" Enter parenthesis ")

print(string, "-", "Balanced" 

      if check(string) else "Unbalanced")