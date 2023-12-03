def function(i):
    hcount = 0
    scount = 0
    L = []

    for a in range(len(i)):
        L.append(i[a])

    for b in range(len(L)):
        if (L[b] == ":") and (len(L)-b != 2) and (L[b+1] == "-"):
            if L[b+2] == ")":
                hcount += 1
            elif L[b+2] == "(":
                scount += 1
    if hcount > scount:
        print("happy")
    elif hcount < scount:
        print("sad")
    elif hcount == 0 and scount == 0:
        print("none")
    elif hcount == scount:
        print("unsure")
      
i = input()
function(i)
