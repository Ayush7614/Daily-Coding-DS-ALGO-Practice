def balancedStringSplit(s):
    balancedStringCount = 0
    count = 0  # to count No. of L's and R's in the string
    for c in s:
        if c == 'L':
            count += 1
        else:
            count -= 1
        if count == 0:
            balancedStringCount += 1

    return balancedStringCount


print(balancedStringSplit("RLRRLLRLRL"))
