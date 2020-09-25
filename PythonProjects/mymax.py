num1=input("Enter an integer: ")
num2=input("Enter an integer: ")
num3=input("Enter an integer: ")

print("\nSmallest value entered:", end=' ')

if (num1<num2) and (num1<num3):
    print (num1)
elif(num2<num1) and (num2<num3):
    print (num2)
else:
    print (num3)

print("Largest value entered:", end=' ')

if (num1>num2) and (num1>num3):
    print (num1)
elif(num2>num1) and (num2>num3):
    print (num2)
else:
    print (num3)
