# Refer attached docx for help

for _ in range(int(input())):
    a, b = map(int, input().split())
    c, d = map(int, input().split())

    n1, d1 = (b*c - a*d), (b - c)
    n2, d2 = (b*c + a*d), (b + c)

    if not n1 and not d1: x = n1 / d1
    else: x = n2 / d2

    print(round(x, 2))
