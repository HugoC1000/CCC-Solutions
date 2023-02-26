numofsamegroup = int(input())
samegroup = {}
for a in range(numofsamegroup):
  tempsamegroup = input().split()
  if tempsamegroup[0] in samegroup:
    inbetween = samegroup.get(tempsamegroup[0])
    inbetween.append(tempsamegroup[1])
    samegroup.update({tempsamegroup[0]:inbetween})
  else:
    samegroup.update({tempsamegroup[0]:[tempsamegroup[1]]})
  if tempsamegroup[1] in samegroup:
    inbetween = samegroup.get(tempsamegroup[1])
    inbetween.append(tempsamegroup[0])
    samegroup.update({tempsamegroup[1]:inbetween})
  else:
    samegroup.update({tempsamegroup[1]:[tempsamegroup[0]]})
numofdiffgroup = int(input())
diffgroup = {}
for a in range(numofdiffgroup):
  tempdiffgroup = input().split()
  if tempdiffgroup[0] in diffgroup:
    inbetween = diffgroup.get(tempdiffgroup[0])
    inbetween.append(tempdiffgroup[1])
    diffgroup.update({tempdiffgroup[0]:inbetween})
  else:
    diffgroup.update({tempdiffgroup[0]:[tempdiffgroup[1]]})
  if tempdiffgroup[1] in diffgroup:
    inbetween = diffgroup.get(tempdiffgroup[1])
    inbetween.append(tempdiffgroup[0])
    diffgroup.update({tempdiffgroup[1]:inbetween})
  else:
    diffgroup.update({tempdiffgroup[1]:[tempdiffgroup[0]]})
overalist = []
numofgroup = int(input())
for a in range(numofgroup):
  overalist.append(input().split())

count = 0

for a in range(numofgroup):
  for d in range(3):
    if overalist[a][d] in samegroup:
      for c in samegroup.get(overalist[a][d]):
        if c not in overalist[a]:
          count += 1

    if overalist[a][d] in diffgroup:
      for c in diffgroup.get(overalist[a][d]):
       # print("c",c)
        if c in overalist[a]:
          count += 1
            
print(int(count/2))
