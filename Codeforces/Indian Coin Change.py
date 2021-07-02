denominations = [1, 2, 5, 10, 20, 50, 100, 500, 1000]  #denominations of indian currency
n=len(denominations)

def Coin_Change(V):

    change = []    # to store the change currencies

    for deno in range(n-1 , -1, -1):    #reverse for loop

        while (V >= denominations[deno]):
            V -= denominations[deno]
            change.append(denominations[deno])

    print("Minimal no. of coins needed:", len(change))
    print("Changed currency: ", end=" ")
    for i in change:
        print(i, end="  ")


# Driver Code
V= int(input("Enter the amount: "))
Coin_Change(V)


# Sample

# Enter the amount: 72
# Minimal no. of coins needed: 3
# Changed currency:  50  20  2