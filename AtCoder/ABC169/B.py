n = int(input())
a = [int(x) for x in input().split()]
ans = 1
ok = True
for i in a:
    if (i == 0):
        print(0)
        ok = False
if (ok):
    for i in range(n):
        ans = ans * a[i]
        if (ans > 10 ** 18):
            print (-1)
            ok = False
            break
    
    if (ok):
        print (ans)