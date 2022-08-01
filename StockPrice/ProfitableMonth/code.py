stockPrice = [19,18,17,16,15,14]

minis = [stockPrice[0]]
for i in range(1, len(stockPrice)):
    minis.append(min(minis[-1], stockPrice[i]))

right_mins = []
for i in range(len(stockPrice)-1, -1, -1):
    if i == len(stockPrice)-1:
        right_mins.append(len(stockPrice)-1)
    else:
        if stockPrice[i] < stockPrice[right_mins[0]]:
            right_mins.insert(0, i+1)
        else:
            right_mins.insert(0, right_mins[0])
right_mins[-1] = 9999999
result = []

for i in range(len(stockPrice)-1):
    j = i
    while j < len(stockPrice)-1 and minis[i] >= stockPrice[right_mins[j]]:
        j = right_mins[j]
    if j >= len(stockPrice)-1:
        result.append(-1)
    else:
        result.append(right_mins[j])
result.append(-1)
print(result)
