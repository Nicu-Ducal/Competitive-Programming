t = int(input())
for case in range(t):
    s = input()
    numbers = '0123456789'
    if (s[0] == 'R' and (s[1] in numbers) and ('C' in s)):
        iC = 0
        for i in range(len(s)):
            if (s[i] == 'C'):
                iC = i
                break
        row = s[1:iC]
        col = int(s[iC + 1:])
        cols = ''
        rem = 0
        while (col > 0):
            rem = col % 26
            col //= 26
            if rem == 0:
                col -= 1
            cols = (chr(rem + 64) if rem != 0 else 'Z') + cols
        print(cols + row)
    else:
        iN = 0
        for i in range(len(s)):
            if (s[i] in numbers):
                iN = i
                break
        pow = 0
        cols = s[:iN]
        row = s[iN:]
        col = 0
        for i in range(len(cols) - 1, -1, -1):
            col += (26 ** pow) * (ord(cols[i]) - 64)
            pow += 1
        print('R' + row + 'C' + str(col))
