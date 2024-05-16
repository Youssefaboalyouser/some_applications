# ====================================================================================================================

# Mohamed Ahmed Abdallah Mohamed: solved problems 1,2,3
# ID: 20220985

# Youssef Aboalyouser Afeed Abrahim:solved problems 4 , 5 , 6
# ID: 20230475

# Mohamed Gamal Sabra Sayed
# ID: 20230327

# version: last one 
# date: feb_22


# ====================================================================================================================

def calculate_pi(n):
    """This function calculates an approximation of π using the Leibniz formula.

    Parameters:
    n (int): The number of terms to use in the series.

    Returns:
    float: The approximate value of π.
    """
    sum = 0 # Initialize the sum of the series
    sign = 1 # Initialize the sign of the terms
    for i in range(n):
        denominator = 2 * i + 1 # Calculate the denominator of the current term
        term = sign / denominator # Calculate the current term
        sum += term # Add the current term to the sum
        sign *= -1 # Flip the sign for the next term
    pi = 4 * sum # Multiply the sum by 4 to get the approximation of π
    return pi # Return the result



def is_armstrong_number(number):
    # Convert the number to a string to iterate through its digits
    num_str = str(number)
    # Get the length of the number
    num_length = len(num_str)
    
    # Calculate the sum of cubes of individual digits
    armstrong_sum = sum(int(digit) ** num_length for digit in num_str)
    
    # Check if the sum equals the original number
    if armstrong_sum == number:
        return True
    else:
        return False
    


def compare(li1,li2):
    for elemnt in li1: #itrate in all elemnts in list1 and if not found one elemnt in common retrun false
        if elemnt not in li2:
            return False
    for ele in li2: #itrate in all elemnts in list2 and if not found one elemnt in common retrun false
        if ele not in li1:
            return False
    return True   #if found all elemnt in common return false


def main():
     while True:
           ask = input("do you want to open the program[y/n]: ").strip().upper()
           if ask == "Y":
            print("which programm do you want to run?")
            print("*" * 40)
            #make menu to ask the user for which programm want to use 
            answer = input("""      A)take the grade and return mark
                              
      B)check a given number is armstrong or not
                              
      C)now the acurate value of pi
                              
      D)a Encryption program
                              
      E)check if tow given list have same elemnts
                              
      F)find the factors of given numbers\n""").strip().upper()
         
            if answer == 'A': #programm_one which convert degree to grade
                  user_input = input("Please enter a number: ")
                  while not user_input.isdigit():#make sure that user input is +ve number
                        user_input = input("That is not a number. Please enter a number: ")
                  number = int(user_input)
                  while number>100: #make sure that user input not > maximum value
                        print("invaled number ,please enter correct number")
                  if number >= 90:
                        print("GRDE: A+")
                  elif 90>number>=85:
                        print("GRDE: A")
                  elif 85>number>=75:
                        print("GRDE: B+")
                  elif 75>number>=70:
                        print("GRDE: B")
                  elif 70>number>=60:
                        print("GRDE: C+")
                  elif 60>number>= 50:
                        print("GRDE: C")
                  else:
                        print("GRDE: F")
      

            elif answer == 'B':
                  number = int(input("Enter a number to check if it's an Armstrong number: "))
                  if is_armstrong_number(number):
                        print(number, "is an Armstrong number.")
                  else:
                        print(number, "is not an Armstrong number.")
                  

            elif answer == 'C':
                 n = int(input("Enter the number of terms to calculate π: ")) # Get the input from the user
                 pi = calculate_pi(n) # Call the calculate_pi function with the input
                 print("The approximate value of π using", n, "terms is:", pi) # Print the output

            elif answer == 'D':
                  sent_before = input("write your sentense: ").strip() #ask the user for sentence before decode process
                  sent_before_list = list(sent_before) #convert the sentence to list to make every character endixed
                  sent_after_list=[] #make empty list to store characters after incode
                  count = 0
                  for i in sent_before_list:
                   if ord(sent_before_list[count])==32: #if character equal space leave it and don't convert it
                        count+=1
                        sent_after_list.append(" ")
                        continue
                   sent_after_list.append(chr(ord(sent_before_list[count])+1))  #ord(sent_before_list[count])+1===> take character and convert to opposite value in ascii code and then add one to the value
                   #make chr() function to return value to char and add it to the list
                   count+=1
                  print(sent_after_list)
                  

            elif answer == 'E':
                  list_one = input("plese write list_one elemnts in one line ,put(,) between elemnts\n").strip().split(",")
                  list_two = input("plese write list_two elemnts in one line ,put(,) between elemnts\n").strip().split(",")
                  print(compare(list_one,list_two))
                  

            elif answer == 'F':
                  num = input("Please enter a number: ")
                  while not num.isdigit(): #make sure that user input is +ve number
                        num = input("That is not a number. Please enter a number: ")
                  num_new = int(num)
                  num_list = [] #make empty list to store the factors of the number
                  counter = 1
                  #the algorithem depend on devide the number about number less than the number
                  while counter <= 12: 
                        if num_new % counter ==0: 
                         num_list.append(counter)
                        counter+=1
                  print(f"the factor of the number:{num_new} is {num_list}")
           if ask == "N":
                 print("__GODE BYE__")
                 exit()
                  
                 

      

if __name__ == "__main__":
      main()