def determine_group(results):
    wins = results.count('W')

    if wins >= 5:
        return 1
    elif wins >= 3:
        return 2
    elif wins >= 1:
        return 3
    else:
        return -1

# Taking input for six games
results = []
for _ in range(6):
    result = input().strip()
    results.append(result)

group = determine_group(results)
print(group)
