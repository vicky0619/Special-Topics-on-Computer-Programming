t = int(input())

for i in range(t):
    n = input()
    n = int(input())
    if i>0:
        print('')
    x=1
    y=n
    while abs(x-y)>0.001:
        x=(x+y)//2
        y=n//x
    print(x)
