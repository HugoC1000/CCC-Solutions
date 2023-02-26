M = int(input())
N = int(input())
row = [0]*M
col = [0]*N

K = int(input())
for c in range(K):
  twopart = input().split()
  partwo = int(twopart[1])-1
  if twopart[0] == "R":
      row[partwo] += 1
  else:
      col[partwo]+= 1
count = 0
for e in range(M):
  for f in range(N):
    if (row[e]+col[f]) % 2 == 1:
      count += 1
print(count)
  
