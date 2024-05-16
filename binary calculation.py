#student 1:Youssef Aboalyouser Afeed                ID:20230475
#student 2:Abdallah Mohamed Abdallah                ID:20230231
#student 3:Hossam Muhamed Ahmed                     ID:20230121
 #=================================================================================================================================
def ones_comp(num):#function to compute the one's complement of binary number
    mylist = []
    for x in num:
        if x != '1' and x != '0':
            print("invalid number")
            ones_comp(num)
            return
        else:
            mylist.append('1' if x == '0' else '0')
    print("1st complement : ", "".join(mylist))



def twos_comp(num):#function to compute two's complement of binary number
    mylist = []
    for x in num:
      if x != '1' and x != '0':
        print("invalid number")
        twos_comp(num)
        return
      mylist.append(x)

    flag = False
    for x in range(len(mylist)-1, -1, -1):
        if flag:
            if mylist[x] == '0':
              mylist[x] = '1'
            else:
              mylist[x] = '0'
        elif mylist[x] == '1':
            flag = True

    return mylist
#when the addition function gets called from the subtraction function "subtraction" will be true and it will not add the carry as an additional bit
def add_binary(num1, num2, subtraction = False):#function to compute the addition of two binary numbers.
    carry = '0'
    num1list = []
    num2list = []
    result = []
    for x in num1:
        num1list.append(x)
    for x in num2:
        num2list.append(x)

    size = abs(len(num1list) - len(num2list))
    if len(num1list) > len(num2list):
        for i in range(size):
            num2list.insert(0,'0')
    elif len(num1list) < len(num2list):
        for i in range(size):
            num1list.insert(0, '0')
    for x in range(len(num1list) - 1, -1, -1):

         if num1list[x] == num2list[x]:
                if num1list[x] == '0':
                    if  carry == '0':
                        result.append('0')
                    else:
                        result.append('1')
                        carry = '0'
                else:
                    if carry == '0':
                        result.append('0')
                        carry = '1'
                    else:
                        result.append('1')
                        carry = '1'
         else:
             if carry == '0':
                 result.append('1')
             else:
                 result.append('0')
                 carry = '1'

    if carry=='1' and subtraction == False:
        result.append('1')
    return result

def sub_binary(num1,num2):#function to compute the subtraction of two binary numbers.
    #adding zeros to the front of the binary number with fewer bits
    num1list = []
    num2list = []
    for x in num1:
        num1list.append(x)
    for x in num2:
        num2list.append(x)
    size = abs(len(num1list) - len(num2list))
    if len(num1list) > len(num2list):
        for i in range(size):
            num2list.insert(0, '0')
    elif len(num1list) < len(num2list):
        for i in range(size):
            num1list.insert(0, '0')
    negative_num2 = twos_comp(num2list)
    return add_binary(num1list,negative_num2,True)
def main():
    while True:
        # a menue for ask the user if he want to exit the programm or do an opreation.
        print("**binary calculator** \nA)Insert new number. \nB)Exit. ")
        operation1 = str(input("Please select a choice (A/B):  ")).upper()
        if operation1 == "A":
            while True:
                try:
                    num1 = input("Insert your number : ")
                    int(num1, 2)  # int function can compare and decide if number is base 10 or not
                    break  # if return true get out from while loop
                except ValueError:  # if return false we ask him again
                    print("Invalid value ,please try again")



            while True: # a menu  asking the user to select the action he want to do. .
                print("** please select the operation **")
                print("  A) Compute one's complement\n  B) Compute two's complement")
                print("  C) Addition\n  D) Subtraction   ")
                operation2 = str(input(":")).upper()
                if operation2 == "A":
                    ones_comp(num1) #recall the one's complement function.
                    break
                elif operation2 == "B":
                    print("2's complement : ", "".join(twos_comp(num1)))
                    break

                elif operation2 == "C" or operation2 =="D" :
                    while True:
                        try:
                            num2 = input("Please insert the second number : ")
                            int(num2, 2)  # int function can compare and decide if number is base 10 or not
                            break  # if return true get out from while loop

                        except ValueError:  # if return false we ask him again
                            print("Invalid value ,please try again")
                    if operation2 == "C" :     # to calculate the sum of the two numbers.
                        print("The addition is : ", "".join((reversed(add_binary(num1, num2)))))
                        break

                    elif operation2 == "D": # to calculate the subtraction of the two numbers.
                        print("The subtraction is : ", "".join((reversed(sub_binary(num1, num2)))))
                        break
        elif operation1 == "B":
            print("Goodbye!")
            exit()
        else:
            print("Please select a valid choice.\n")
            main()


if __name__ == "__main__":
    main()



