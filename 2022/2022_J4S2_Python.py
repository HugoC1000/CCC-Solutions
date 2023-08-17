#A dictionary should be used to take advantage of its fast look up times. Any other method would be too slow. 

# Read the number of constraints where students must be in the same group
numofsamegroup = int(input())
samegroup = {}  # Create a dictionary to store which students must be in the same group. It is stored by this method. {StudentName(Key): [Name 1,Name2](Value_}

# Read and process the same group constraints
for a in range(numofsamegroup):
    tempsamegroup = input().split()
    
    # Update the dictionary for the first student
    if tempsamegroup[0] in samegroup:
        inbetween = samegroup.get(tempsamegroup[0])
        inbetween.append(tempsamegroup[1])
        samegroup.update({tempsamegroup[0]: inbetween})
    else:
        samegroup.update({tempsamegroup[0]: [tempsamegroup[1]]})
    
    # Update the dictionary for the second student
    if tempsamegroup[1] in samegroup:
        inbetween = samegroup.get(tempsamegroup[1])
        inbetween.append(tempsamegroup[0])
        samegroup.update({tempsamegroup[1]: inbetween})
    else:
        samegroup.update({tempsamegroup[1]: [tempsamegroup[0]]})

# Read the number of constraints where students must not be in the same group
numofdiffgroup = int(input())
diffgroup = {}  # Create a dictionary to store which student must be in different groups. It is stored by this method. {StudentName: [Name 1,Name2]}

# Read and process the different group constraints
for a in range(numofdiffgroup):
    tempdiffgroup = input().split()
    
    # Update the dictionary for the first student
    if tempdiffgroup[0] in diffgroup: #If first student is already in the dictionary, we append the second student to the first student's list. Else, we add the first student to the dictionary.
        inbetween = diffgroup.get(tempdiffgroup[0])
        inbetween.append(tempdiffgroup[1])
        diffgroup.update({tempdiffgroup[0]: inbetween})
    else:
        diffgroup.update({tempdiffgroup[0]: [tempdiffgroup[1]]})
    
    # Update the dictionary for the second student
    if tempdiffgroup[1] in diffgroup: #If second student is already in the dictionary, we append the first student to the first student's list. Else, we add the second student to the dictionary.
        inbetween = diffgroup.get(tempdiffgroup[1])
        inbetween.append(tempdiffgroup[0])
        diffgroup.update({tempdiffgroup[1]: inbetween})
    else:
        diffgroup.update({tempdiffgroup[1]: [tempdiffgroup[0]]})

overalist = []  # Create a list to store student groups
numofgroup = int(input())

# Read and store the groups of students
for a in range(numofgroup):
    overalist.append(input().split())

count = 0

# Check for constraint violations within each group of students. 
for a in range(numofgroup):
    for d in range(3):
        # Check same group constraints
        if overalist[a][d] in samegroup:
            for c in samegroup.get(overalist[a][d]):
                if c not in overalist[a]:
                    count += 1
        
        # Check different group constraints
        if overalist[a][d] in diffgroup:
            for c in diffgroup.get(overalist[a][d]):
                if c in overalist[a]:
                    count += 1

# Divide the count by 2 since each constraint is counted twice (once for each student)
print(int(count / 2))
