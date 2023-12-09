inp = []
for i in range(4):
    inp.append(int(input()))

result = "answer"
a = (inp[0] == 8) or (inp[0] == 9)
b= (inp[3] == 8) or (inp[3] == 9)
c = (inp[1] == inp[2])
if a and b and c:
    result = "ignore"
print(result)
