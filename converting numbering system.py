#student 1: Youssef Aboalyouser Afeed                ID:20230475
#student 2: Abdallah Mohamed Abdallah                ID:20230231
#student 3:Hossam Muhamed Ahmed                      ID:20230121
 #=================================================================================================================================
def main():
    while True:
        # a menue for ask the user if he want to exit the programm or make a converting
        prompt = input("""A)Insert new number  \nB)Exit :  """).upper()  # its use to make every characters capital


        if prompt == "A":
            print("which base you want convert from ")  # a menue for asking the user the base he want convert from
            base_from = input(
                """  A)Decimal\n  B)Binary\n  C)Octal\n  D)hexadecimal\n  :  """).upper()  


            if base_from == "A":  # if the user input is a decimal number we must make sure that the number is actually decimal
                while True:
                    try:
                        num_dec = input("write a Decimal number: ")
                        int(num_dec, 10)  # int function can compare and decide if number is base 10 or not
                        break  # if return true get out from while loop
                    except ValueError:  # if return false we ask him again
                        print("invalid value ,please try again")


            if base_from == "B":  # if the user input is a binary number we must make sure that the number is actually binary
                while True:
                    try:
                        num_bin = input("write a Binary number: ")
                        int(num_bin, 2)  # it's compare if number is base 2 return true and get out from while loop
                        break
                    except ValueError:  # if return flase ask the user again for real binary number
                        print("invalid value ,please try again")


            if base_from == "C":  # if the user input is a octal number we must make sure that the number is actually octal
                while True:
                    try:
                        num_oc = input("write a Octal number: ")
                        int(num_oc, 8)  # it's compare if number is base 8 return true and get out from while loop
                        break
                    except ValueError:  # if return flase ask the user again for real octal number
                        print("invalid value ,please try again")



            if base_from == "D":  # if the user input is a hexadecimal number we must make sure that the number is actually hexadecima
                while True:
                    try:
                        num_hex = input("write a Hexdecimal number: ").upper()
                        int(num_hex, 16) #it's compare if number is base 16 
                        break
                    except ValueError:
                        print("invalid value ,please try again")


            print("which base you want convert to")
            base_to = input("""  A)Decimal\n  B)Binary\n  C)Octal\n  D)Hexdecimal:\n   """).upper()
            count = res = 0
            #if base_from == base_to :we must print invalid value
            if base_from == base_to:
                print("invaled value ,please choose diffrent basses")

            if base_from == "A" and base_to == "B":  # convert from decimal to binary
                while num_dec != 0:
                    res = res + (int(num_dec) % 2) * (10 ** count)
                    num_dec = int(num_dec) // 2
                    count += 1
                print(f"the equivalent value is {res}")


            if base_from == "B" and base_to == "A":  # convert from binary to decimal
                while num_bin != 0:
                    res = res + (int(num_bin) % 10) * (2 ** count)
                    num_bin = int(num_bin) // 10
                    count += 1
                print(f"the equivalent value is {res}")


            if base_from == "A" and base_to == "C":  # convert from decimal to ocatal
                while num_dec != 0:
                    res = res + (int(num_dec) % 8) * (10 ** count)
                    num_dec = int(num_dec) // 8
                    count += 1
                print(f"the equivalent value is {res}")

            if base_from == "C" and base_to == "A":  # convert from octal to decimal
                while num_oc != 0:
                    res = res + (int(num_oc) % 10) * (8 ** count)
                    num_oc = int(num_oc) // 10
                    count += 1
                print(f"the equivalent value is {res}")


            if base_from == "A" and base_to == "D":  # convert from decimal to hexadecimal
                dec_list = [] #make a empty list to store the hexdecimal digits 
                while int(num_dec) > 0: #while loop to calculate the reminder of decimal when divide by 16 
                    #and using the reminder to determine the corisponding hex deimal number 
                    remendier = int(num_dec) % 16
                    temp = remendier
                    if remendier == 10:
                        temp = "A"            #Define 'A' as 10
                    elif remendier == 11:
                        temp = "B"           #Define 'B' as 11
                    elif remendier == 12:
                        temp = "C"           #Define 'C' as 12
                    elif remendier == 13:
                        temp = "D"           #Define 'D' as 13
                    elif remendier == 14:
                        temp = "E"           #Define 'E' as 14
                    elif remendier == 15:
                        temp = "F"           #Define 'F' as 15
                    else:
                        temp = remendier 
                    dec_list.insert(0, str(temp))
                    num_dec = int(num_dec) // 16
                hstr = ""
                for i in dec_list:
                    hstr = hstr + str(i)
                print(f"the equivalent value is {hstr}")


            if base_from == "D" and base_to == "A":  # convert from hexadecimal to decimal
                hex_list = []
                for i in str(num_hex):
                    if i == 'A':
                        x = 10
                    elif i == 'B':
                        x = 11
                    elif i == 'C':
                        x = 12
                    elif i == 'D':
                        x = 13
                    elif i == 'E':
                        x = 14
                    elif i == 'F':
                        x = 15
                    else:
                        x = int(i)
                    hex_list = hex_list + [x]
                lenth = len(hex_list) - 1
                for i in range(len(hex_list)):
                    res = res + hex_list[i] * 16 ** (lenth - i)
                print(f"the equivalent valu is {res}")
            if base_from == "D" and base_to == "B":  # convert from hex to binary
                # convert from hex to decimal
                hex_list = []
                for i in str(num_hex):
                    if i == 'A':
                        x = 10
                    elif i == 'B':
                        x = 11
                    elif i == 'C':
                        x = 12
                    elif i == 'D':
                        x = 13
                    elif i == 'E':
                        x = 14
                    elif i == 'F':
                        x = 15
                    else:
                        x = int(i)
                    hex_list = hex_list + [x]
                lenth = len(hex_list) - 1
                for i in range(len(hex_list)):
                    res = res + hex_list[i] * 16 ** (lenth - i)
                    # now the hex become decimal at res
                    # convert from decimal to binary
                res3 = count3 = 0
                while res != 0:
                    res3 = res3 + (int(res) % 2) * (10 ** count3)
                    res = int(res) // 2
                    count3 += 1
                print(f"the equivalent value is {res3}")


            if base_from == "B" and base_to == "D":  # convert from binary to hexdecimal
                # 1.convert from binary to decimal
                while num_bin != 0:
                    res = res + (int(num_bin) % 10) * (2 ** count)
                    num_bin = int(num_bin) // 10
                    count += 1
                    # convert from decimal to hex
                res4 = count4 = 0
                dec_list = []
                while int(res) > 0:
                    remendier = int(res) % 16
                    temp = remendier
                    if remendier == 10:
                        temp = "A"
                    elif remendier == 11:
                        temp = "B"
                    elif remendier == 12:
                        temp = "C"
                    elif remendier == 13:
                        temp = "D"
                    elif remendier == 14:
                        temp = "E"
                    elif remendier == 15:
                        temp = "F"
                    else:
                        temp = remendier
                    dec_list.insert(0, str(temp))
                    res = int(res) // 16
                hstr = ""
                for i in dec_list:
                    hstr = hstr + str(i)
                print(f"the equivalent value is {hstr}")


            if base_from == "B" and base_to == "C":  # convert from binary to octal
                # convert from binary to decimal
                while num_bin != 0:
                    res = res + (int(num_bin) % 10) * (2 ** count)
                    num_bin = int(num_bin) // 10
                    count += 1
                # convert from decimal to octal
                res5 = count5 = 0
                while res != 0:
                    res5 = res5 + (int(res) % 8) * (10 ** count5)
                    res = int(res) // 8
                    count5 += 1
                print(f"the equivalent value is {res5}")


            if base_from == "C" and base_to == "B":  # convert from octal to binary
                # 1.convert from octal to decimal
                while num_oc != 0:
                    res = res + (int(num_oc) % 10) * (8 ** count)
                    num_oc = int(num_oc) // 10
                    count += 1
                # 2.convert from decimal to binary
                res6 = count6 = 0
                while res != 0:
                    res6 = res6 + (int(res) % 2) * (10 ** count6)
                    res = int(res) // 2
                    count6 += 1
                print(f"the equivalent value is {res6}")

            if base_from == "D" and base_to == "C":  # convert from hexdecimal to octal
                # 1.cnvert from hexadecimal to decimal
                hex_list = []
                for i in str(num_hex):
                    if i == "A":
                        x = 10
                    elif i == "B":
                        x = 11
                    elif i == "C":
                        x = 12
                    elif i == "D":
                        x = 13
                    elif i == "E":
                        x = 14
                    elif i == "F":
                        x = 15
                    else:
                        x = int(i)
                    hex_list = hex_list + [x]
                lenth = len(hex_list) - 1
                for i in range(len(hex_list)):
                    res = res + hex_list[i] * 16 ** (lenth - i)
                
                # 2.convert from decimal to octal
                res7 = count7 = 0
                while res != 0:
                    res7 = res7 + (int(res) % 8) * (10 ** count7)
                    res = int(res) // 8
                    count7 += 1
                print(f"the equivalent value is {res7}")


            if base_from == "C" and base_to == "D":  # convert from octal to hexdecimal
                # 1.convert from octal to decimal
                while num_oc != 0:
                    res = res + (int(num_oc) % 10) * (8 ** count)
                    num_oc = int(num_oc) // 10
                    count += 1
                # convert from decimal to hexadecimal
                dec_list = []
                while int(res) > 0:
                    remendier = int(res) % 16
                    temp = remendier
                    if remendier == 10:
                        temp = "A"
                    elif remendier == 11:
                        temp = "B"
                    elif remendier == 12:
                        temp = "C"
                    elif remendier == 13:
                        temp = "D"
                    elif remendier == 14:
                        temp = "E"
                    elif remendier == 15:
                        temp = "F"
                    else:
                        temp = remendier
                    dec_list.insert(0, str(temp))
                    res = int(res) // 16
                hstr = ""
                for i in dec_list:
                    hstr = hstr + str(i)
                print(f"the equivalent value is {hstr}")


            print ("")
            main()

        elif prompt == "B":
            print("Goodbye")
            exit()


if __name__ == "__main__":
    main()
