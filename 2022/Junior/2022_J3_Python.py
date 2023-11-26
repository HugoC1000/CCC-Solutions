inp = input()
last = 0
numbers = ["1","2","3","4","5","6","7","8","9","0"]
for a in range(len(inp)):
    if inp[a] == "+":
        outputPartA = inp[last:a]
        outputPartB = "tighten"
        for b in range(a+1,len(inp)):
            if inp[b] not in numbers:
                outputPartC = inp[a+1:b]
                break
            elif b == len(inp)-1:
                outputPartC = inp[a+1:b+1]

        print(outputPartA,outputPartB,outputPartC)
        last = b
                
    elif inp[a] == "-":
        outputPartA = inp[last:a]
        outputPartB = "loosen"
        for b in range(a+1,len(inp)):
            if inp[b] not in numbers:
                outputPartC = inp[a+1:b]
                break
            elif b == len(inp)-1:
                outputPartC = inp[a+1:b+1]
        print(outputPartA,outputPartB,outputPartC)
        last = b
