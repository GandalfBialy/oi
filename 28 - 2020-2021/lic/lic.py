def handleOperation(type, input1, input2):
    # print("funkcja updateDigits")
    digitNumber = digitsQuantity - 1 - input1
    totalDigitNumber = digitNumber + 1

    if type == "W":
        previousDigit = internalDigits[digitNumber]
        internalDigits[digitNumber] = input2
        # print(internalDigits[digitNumber], previousDigit)
        change = -(internalDigits[digitNumber] - previousDigit)
    else:
        previousDigit = externalDigits[digitNumber]
        externalDigits[digitNumber] = input2
        # print(externalDigits[digitNumber], previousDigit)
        change = -(externalDigits[digitNumber] - previousDigit)

    # print("wewnętrzne", internalDigits)
    # print("zewnętrzne", externalDigits)
    # print("zmiana", change)
    # print("wszystkie przed", totalDigits)

    if change < totalDigits[totalDigitNumber]:
        totalDigits[totalDigitNumber] -= change
        # print("opcja 1", totalDigits[totalDigitNumber], totalDigits[totalDigitNumber] >= 10)
        while totalDigits[totalDigitNumber] >= 10:
            # print("opcja 1.1")
            totalDigits[totalDigitNumber] -= 10
            totalDigits[totalDigitNumber - 1] += 1
            totalDigitNumber -= 1
    else:
        # print("opcja 2", totalDigits[totalDigitNumber], totalDigits[totalDigitNumber] < 0)
        totalDigits[totalDigitNumber] -= change
        while totalDigits[totalDigitNumber] < 0:
            # print("opcja 2.1")
            totalDigits[totalDigitNumber] += 10
            totalDigits[totalDigitNumber - 1] -= 1
            totalDigitNumber -= 1


inputLine = input()

digitsQuantity, operationsQuantity = inputLine.split()
digitsQuantity = int(digitsQuantity)
operationsQuantity = int(operationsQuantity)

internal = input()
external = input()
total = int(internal) + int(external)

internalDigits = []
externalDigits = []
totalDigits = []

# print(internal, external, total)

for digit in internal:
    internalDigits.append(int(digit))

for digit in external:
    externalDigits.append(int(digit))

if len(str(total)) < digitsQuantity:
    totalDigits = [0]

for digit in str(total):
    totalDigits.append(int(digit))

# print(internalDigits, externalDigits, totalDigits)

for i in range(0, operationsQuantity):
    inputLine = input()
    if inputLine[0] == "S":
        operationType, input1 = inputLine.split()
        print(totalDigits[digitsQuantity - int(input1)])
    else:
        operationType, x, y = inputLine.split()
        handleOperation(operationType, int(x), int(y))
