numofplayers = int(input())
count = 0
for a in range(numofplayers):
    points = int(input())
    fouls = int(input())
    stars = points*5-fouls*3
    if stars > 40:
        count += 1
print(count,end = "")
if count == numofplayers:
    print("+")
               
