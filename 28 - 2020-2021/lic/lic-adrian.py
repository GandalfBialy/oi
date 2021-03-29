n, z = map(int , input().split()) 
dw = input()
dz = input()
operacja = 0
#wyniki = []
wejscie = []

#Definicje operacji
def funkcjaW(i, c, l):
    a = (len(l)- i)
    l = l[:a] + str(c) + l[(a+1):]
    return l

def funkcjaZ(i, c, l):
    a = (len(l)- i)
    l = l[:a] + str(c) + l[(a+1):]
    return l

def funkcjaS(i, l, d):
    dp = int(l) + int(d)
    dp = str(dp)
    return dp[len(dp) - i]


#Wykonywanie q operacji
for i in range(z):
    a = 0
    b = 0
    c = 0
    operacja = input()

    if operacja[0] == "W":
        a, b, c = operacja.split()
        b = int(b)
        c = int(c)
        dw = funkcjaW(b, c, dw)
    elif operacja[0] == "Z":
        a, b, c = operacja.split()
        b = int(b)
        c = int(c)
        dz = funkcjaZ(b, c, dz)
    elif operacja[0] == "S":
        a, b = operacja.split()
        b = int(b)
        print(funkcjaS(b, dw, dz))



#for i in wyniki:
 #   print(i)