t = int(input())
while t:
    t -= 1
    s = input()
    if '1' not in s or '0' not in s:
        print(0)
        continue
    else:
        fi = -13
        n = 0
        for i in range(len(s) - 1):
            print(i, n)
            if s[i] == '1' and fi == -1 and s[i + 1] == '0':
                fi = i
            elif s[i] == '1' and fi != -1:
                n += (i - fi)
                fi = i
    print(n)