a = int(input())
b = int(input())

if (a <= 2 and b < 18) or a < 2:
    print("Before")
elif (a == 2 and b > 18) or (a > 2):
    print("After")
elif a == 2 and b ==18:
    print("Special")
