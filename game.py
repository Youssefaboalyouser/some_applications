# proogramed by: Youssef Aboalyouser Afeed
# ID ======> 20230475
# CS112 course ===> Dr.ELramly
# ============================================================================================================================================================

while True:
    print("Do you want to play")
    start = input("A) Play \nB) exit\n").strip().upper()
    if start == "A":

        # make intro about the game inform and the rules
        print("wellcome to the 'Number scrabble' game\nare you ready to get some fun\nlets begain  :) ")
        print("*" * 10)
        print("in this game we have numbers from 1 to 9 \nevery player have to chooce a number\nplayer who the sum of 3 numbers of  his numbers = 15 are the winner")
        print("if all number are used and no one collect 15 , the game is a draw")
        print("*" * 10)

        #ask the players for thier name
        player1_name = input("player one name: ")
        player2_name= input("player two name: ")
        #declar the main list
        arr = [1,2,3,4,5,6,7,8,9]

        # make a empty list for each player to store the number that they used 
        player1_arr = []
        player2_arr = []
        # declar target value and empty list called result to store values that sum == 15(target value)
        target = 15
        result = []



        while len(arr) != 0:       #make for loop to turn on all item in the list 

            # take a number from the player and check if the number is in the list and if the number taken or not
            move_player1 = int(input(f"move for {player1_name} is ====> "))
            while 1 <= move_player1 <= 9 and move_player1 in arr:
                player1_arr.append(move_player1)
                arr.remove(move_player1)
                break
            while 0 > move_player1 > 9 or move_player1 not in arr:
                move_player1 = int(input(f"move for {player1_name} is ====> "))

        # when the player chooce 3 numbers at least make nested loop to find the target value 
            if len(player1_arr) >= 3:
                for a in range(len(player1_arr)-2):
                    for s in range(a + 1 , len(player1_arr)-1 ):
                        for d in range(s + 1 , len(player1_arr)):
                            if player1_arr[a] + player1_arr[s] + player1_arr[d] == target:
                                result.append((player1_arr[a],player1_arr[s],player1_arr[d]))
                                print(f"the winner is {player1_name} , congratulation")
                                print(f"you collect {result} as the sum of them equal {target}")
                                exit()


        # take a number from the player and check if the number is in the list and if the number taken or not

            move_player2 = int(input(f"move for {player2_name} is ====> "))
            while 1 <= move_player2 <= 9 and move_player2 in arr:
                player2_arr.append(move_player2)
                arr.remove(move_player2)
                break
            while 0 > move_player2 > 9 or move_player2 not in arr:
                move_player2 = int(input(f"move for {player1_name} is ====> "))

        # when the player chooce 3 numbers at least make nested loop to find the target value
            if len(player2_arr) >= 3:
                for j in range(len(player2_arr)-2):
                    for k in range(j + 1 , len(player2_arr)-1 ):
                        for l in range(k + 1 , len(player2_arr)):
                            if player2_arr[j] + player2_arr[k] + player2_arr[l] == target:
                                result.append((player2_arr[j],player2_arr[k],player2_arr[l]))
                                print(f"the winner is {player2_name} , congratulation")
                                print(f"you collect {result} as the sum of them equal {target}")
                                exit()
        # if the tow player cannot collect the target value then the game become draw
        else:
            print("--DRAW--")
    if start == "B":
        print("__GAME OVER__")
        exit()



