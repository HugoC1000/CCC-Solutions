N = int(input())
overalist = []
for a in range(N):
  inp = input()
  temp = []
  for b in inp:
    temp.append(b)
  overalist.append(temp)

countlist = [0,0,0,0,0]

for a in range(len(overalist)):
  for b in range(5):
    if overalist[a][b] == "Y":
      countlist[b] += 1

otherlist = []
c = max(countlist)

if countlist.count(c) > 1:
  for a in range(len(countlist)):
    if countlist[a] == c:
      otherlist.append(a+1)
  otherlist.sort()
  for b in range(len(otherlist)):
    if b != len(otherlist)-1:
      print(otherlist[b], ",", sep = "",end = "")
    else:
      print(otherlist[b])
else:
  for a in range(len(countlist)):
    if countlist[a] == c:
      print(a+1)
      break
