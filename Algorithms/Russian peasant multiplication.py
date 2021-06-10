def russian_peasant_multiplication(a, b):
    product = 0
    while b > 0:
        if b % 2 != 0:
            product += a
        a = a * 2
        b = b // 2
    return product

a = 54
b = 75
print(russian_peasant_multiplication(a, b))