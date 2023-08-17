# Read the number of people attending the event
N = int(input())

# Initialize a list to store the availability of each person for each day
overalist = []

# Read the availability for each person and store it in overalist
for a in range(N):
    inp = input()
    temp = []
    for b in inp:
        temp.append(b)
    overalist.append(temp)

# Initialize a list to store the count of available people for each day
countlist = [0, 0, 0, 0, 0]

# Count the number of available people for each day
for a in range(len(overalist)):
    for b in range(5):
        if overalist[a][b] == "Y":
            countlist[b] += 1

# Initialize a list to store days with the maximum count of available people
otherlist = []

# Find the maximum count of available people
c = max(countlist)

# Check if there are multiple days with the same maximum count
if countlist.count(c) > 1:
    # Store days with the maximum count in otherlist
    for a in range(len(countlist)):
        if countlist[a] == c:
            otherlist.append(a + 1)
    otherlist.sort()
    # Output the days with maximum count
    for b in range(len(otherlist)):
        if b != len(otherlist) - 1:
            print(otherlist[b], ",", sep="", end="")
        else:
            print(otherlist[b])
else:
    # Output the day with the highest count
    for a in range(len(countlist)):
        if countlist[a] == c:
            print(a + 1)
            break
