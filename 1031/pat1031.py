def calculate(m):
    weights = [7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2]
    L = ['1','0','X','9','8','7','6','5','4','3','2']
    sum = 0
    for i in range(17):
        if m[i] > '9' or m[i] < '0':
            return 0
        n = int(m[i])
        sum = (weights[i] * n) + sum
        test = sum % 11
    if str(m[-1]) == L[test]:
        return 1
    else:
        return 0

n = input()
e = 0
for j in range(n):
    num = raw_input()
    if calculate(num) == 0:
        print(num)
        e = 1
if e == 0:
    print('All passed')