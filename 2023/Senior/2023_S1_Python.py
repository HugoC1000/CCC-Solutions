N = int(input())
overalist = []
for a in range(2):
  inp = input().split()
  overalist.append(inp)
count = 0
for b in range(N):
  subcount = 3
  if overalist[0][b] == "1":
    if b+1 < N:
      #print("subsubcase")
      if overalist[0][b+1] == "1":
        subcount -= 1
    if overalist[1][b] == "1" and b%2 == 0:
      subcount -= 1
    if b-1 > -1:
      if overalist[0][b-1] == "1":
        subcount -= 1
    count += subcount

for c in range(N):
  subcount = 3
  if overalist[1][c] == "1":
    if c+1 < N:
      if overalist[1][c+1] == "1":
        subcount -= 1
    if overalist[0][c] == "1" and c%2 == 0:
      subcount -= 1
    if c-1 > -1:
      if overalist[1][c-1] == "1":
        subcount -= 1
    count += subcount

print(count)
