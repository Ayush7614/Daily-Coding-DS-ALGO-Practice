import math

def lucky_alive(n:int):
    
    # to calculate the number of bits in
    # the binary equivalent of n
    len = int(math.log2(n)) + 1

    # Finding complement by inverting the
    # bits one by one from last
    n2 = n

    for i in range(len):
    # XOR of n2 with (1<<i) to flip
    # the last (i+1)th bit of binary equivalent of n2
        n2 ^= (1 << i)

    # n2 will be the one's complement of n
    return abs(n2 - n)

if __name__ == "__main__":
    result = lucky_alive(100)
    
    print(result)

#input = 1
#output = 1

#input = 2
#output = 1

#input = 3
#output = 3

#input = 5
#output = 3

#input = 10
#output = 5

#input = 100
#output = 73

