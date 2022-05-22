from random import randint

with open("a.txt", 'w') as f:
    n = randint(0, 1000)
    lst = [randint(0, 10**4) for i in range(n)]
    f.write(str(n)+'\n')
    f.write(' '.join(str(i) for i in lst))