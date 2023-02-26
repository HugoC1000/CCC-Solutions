dict = {"Poblano":1500,"Mirasol":6000,"Serrano":15500,"Cayenne":40000,"Thai":75000,"Habanero":125000}

N = int(input())
count = 0
for a in range(N):
  count += dict.get(input())

print(count)