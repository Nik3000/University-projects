n = 0
'ввод первого числа'
in1 = input()
a = []
a = list(in1)
a.insert(0,0)

'ввод второго числа'
in2 = input()
b = []
b = list(in2)
b.insert(0,0)

'подгон чисел под максимальный размер'
if len(in1) >= len(in2):
    n = len(in1)
    i = 0
    while i < abs(len(in1)-len(in2)):
        b.insert(0,0)
        i += 1
else:
    n = len(in2)
    i = 0
    while i < abs(len(in2)-len(in1)):
        a.insert(0,0)
        i += 1

i = 0
z = 0
z1 = 0
z2 = 0
'удаление запятой'
while i < n:
    if a[i] == ',':
        z1 = n-i
        a.remove(',')
    if b[i] == ',':
        z2 = n-i
        b.remove(',')
    i += 1

'добавление нулей в случае с вещественными числами'
i = 0
if z1 > z2:
    while i < abs(z1 - z2):
        b.append(0)
        z = z1
        i += 1
if z2 > z1:
    while i < abs(z2 - z1):
        a.append(0)
        z = z2
        i += 1
else:
    z = z1

i = 0
if n-z1 > n-z2:
    while i < abs((n-z1)-(n-z2)):
        b.insert(0,0)
        i+=1
if n-z1 < n-z2:
    while i < abs((n-z2)-(n-z1)):
        a.insert(0,0)
        i+=1

if z > 0:
    n-=1
n = len(a)-1

'ввод системы счисления'
cc = int(input())

'вычитание'
i = n
s = []
while i >= 0:
    s.append(int(a[i]) - int(b[i]))
    if s[n-i] < 0:
        s[n-i] = cc + s[n-i]
        a[i-1] = int(a[i-1]) - 1
    i -= 1

'вставляем ,'
if z > 0:
    s.insert(z,',')
    n+=1
'вывод'
i = n
while i >= 0:
    print(s[i])
    i = i - 1
print(s)
