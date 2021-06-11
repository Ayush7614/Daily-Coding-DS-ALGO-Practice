# Function to perform Russian peasant multiplicatioin
def russian_peasant_multiplication(a, b):
    # Initialize product as 0
    product = 0
    # Loop to maintain b >= 1
    while b > 0:
        # When b is an odd number:
        if b % 2 != 0:
            # a is added to the product
            product += a
        # a is doubled
        a = a * 2
        # b is halved
        b = b // 2
    # Returns the prooduct between a and b
    return product

# a and b are to be multipilied
a = 54
b = 75
# Prints the product of a and b using russian_peasant_multiplication()
print(russian_peasant_multiplication(a, b))