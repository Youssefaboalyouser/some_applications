#include <iostream>
#include <map>

using namespace std;

// Hussam Muhammed Ahmed Abdelaziz
// ID: 20230121

string ch2[100];

void clearMatrix(int key) {                   //func that clears the matrix with every initialization and fills it all with 'x's
    for (int i = 0; i < 100; ++i) {          //and set the dimensions of the matrix by taking columns as input(key).
        ch2[i] = "";
    }
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < key; ++j) {
            ch2[i] += 'x';
        }
    }
}

void initializeMatrixE(int key, string input) {         //func that fills every char of the input into the matrix one by one.
    clearMatrix(key);
    for (int i = 0; i < (input.size() + (key - 1)) / key; ++i) {
        for (int j = 0; j < key; ++j) {
            ch2[i][j] = input[j + i * key];
            if (j + i * key == input.size() - 1)break;
        }
    }
}

string routeEncryption(string inputE, int key) {    //func that does the Encryption and returns the output
    initializeMatrixE(key, inputE);
//    showMatrix(key, inputE);
    cout << endl;
    string encrypt = "";              //string that will have the output of the Encryption
    int top = 0, bot = ((inputE.size() + (key - 1)) / key) - 1, left = 0, right =
            key - 1;          //setting variables to traverse through every column and row.
    while (top <= bot && left <=
                         right) {               //doing the actual spiral movement through the matrix and adding it to our string.
        // Traversing right column
        for (int i = top; i <= bot; ++i) {
            encrypt += ch2[i][right];
        }
        right--;                                //removing the row or column that we already traversed through every time we finish one so that we update the array's dimensions and making it smaller.
        // Traversing bottom row
        if (top <= bot) {
            for (int i = right; i >= left; --i) {
                encrypt += ch2[bot][i];
            }
            bot--;
        }
        // Traversing left column
        if (left <= right) {
            for (int i = bot; i >= top; --i) {
                encrypt += ch2[i][left];
            }
            left++;
        }
        // Traversing top row
        for (int i = left; i <= right; ++i) {
            encrypt += ch2[top][i];
        }
        top++;
    }
    return encrypt;
}

string routDecrypt(int key, string input) {                 //func that does the Decryption and returns the output.
    initializeMatrixE(key, input);                           //using same func of initializing.
    int top = 0, bot = ((input.size() + (key - 1)) / key) - 1, left = 0, right =
            key - 1; //setting variables to traverse through every column and row.
    int cntr = 0;
    while (top <= bot && left <=right) {                   //basically doing the same spiral movement but instead of adding it too a string we fill the matrix with the input.
        for (int i = top; i <= bot; ++i) {
            ch2[i][right] = input[cntr];
            cntr++;
        }
        right--;
        if (top <= bot) {
            for (int i = right; i >= left; --i) {
                ch2[bot][i] = input[cntr];
                cntr++;
            }
            bot--;
        }
        if (left <= right) {
            for (int i = bot; i >= top; --i) {
                ch2[i][left] = input[cntr];
                cntr++;
            }
            left++;
        }
        for (int i = left; i <= right; ++i) {
            ch2[top][i] = input[cntr];
            cntr++;
        }
        top++;
    }
    string dec = "";        //string that will have the decrypted text.
    for (int i = 0; i < 100; ++i) {         //filling it with the text in the matrix until an 'x' appears.
        for (int j = 0; j < key; ++j) {
            if (ch2[i][j] == 'x')break;
            dec += ch2[i][j];
        }
    }
    return dec;
}

void routeCipher(int choice, string inputD) {//func that takes inputs and runs the routeCipher
    cout<<"Enter your key (number of columns): ";
    cin.ignore();
    int key;                            //erasing spaces from input.
    cin >> key;
    for (int i = 0; i < inputD.size() ; ++i) {
        if (inputD[i] == ' ') {
            inputD.erase(inputD.begin() + i);
            i--;
        }
    }
    for (int i = 0; i < inputD.size(); ++i) {                   //upper-casing the input.
        inputD[i] = toupper(inputD[i]);
    }

    if (choice == 1) {
        cout << routeEncryption(inputD, key) << endl;
    } else {
        cout << routDecrypt(key, inputD) << endl;
    }
}


//-------------------------------------------------------------------------------------------------------------------
//Ahmed Mahmoud Ibrahim Mahmoud
//Id:20230650
string encryptAffine(const string &text,int a, int b) {
    string encrypted = "";
    for (char q : text) {
        if (isalpha(q)) {
            char base = isupper(q) ? 'A' : 'a';
            int x = q - base;
            int E = (a * x + b) % 26;// E(x) = (a x + b) mod 26 where x is the numeric value
            encrypted += base + E;

        } else {
            encrypted += q;
        }
    }
    return encrypted;
}
//this function for decipher the massage
string decryptAffine(const string &text, int b, int c) {
    string decrypted = "";
    for (char q : text) {
        if (isalpha(q)) {
            char base = isupper(q) ? 'A' : 'a';
            int y = q - base;
            int D = (c * (y - b + 26)) % 26;//D(y) = c (y - b) mod 26 where x is the numeric value
            decrypted += base + D;
        } else {
            decrypted += q;
        }
    }
    return decrypted;
}
void affineCipher(int choice, string word){
    int a, b, c;
    do {
        cin.ignore(); // Clear the input buffer
        cout << "Enter the values for a, b, and c (where (a * c) mod 26 = 1): ";
        cin >> a >> b >> c;
        cin.ignore(); // Ignore the newline character left in the input stream
        switch (choice) {
            case 1:
                cout << "Encrypted text: " << encryptAffine(word,a,b) << endl;
                break;
            case 2:
                cout << "Decrypted text: " << decryptAffine(word,b,c) << endl;
                break;
            case 3:
                cout << "Thanks for using affine cipher." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}
//---------------------------------------------------------------------------------------------------------
//Youssef Abo El-Yosr
//20230475
string encodeSS(string input, string key) {
    map<char, int> map1; // mapping the alphabet to the encrypted text
    map<char, int> map2; // counts the number of character occurences in the key so we dont use those letters later
    char cntr = 'a';  // start of the alphabet
    for (int i = 0; i < key.size(); ++i) {
        map1[cntr++] = key[i];  //mapping the first few letters to the key
        map2[key[i]]++;
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        if (map2[i] != 0)continue; // if letter is in the key then dont use it
        map1[cntr++] = i; // iterate and move the cntr forward int the alphabet
    }
    string ans = "";
    for (int i = 0; i < input.size(); ++i) {
        ans += map1[input[i]];  // add every mapped letter to the answer
    }
    return ans;
}


string decodeSS(string input, string key) {
    map<char, int> map1; // counts the number of character occurences in the key so we dont use those letters later
    map<char, int> map2;
    for (int i = 0; i < key.size(); ++i) {
        map1[key[i]]++;
    }
    char cntr = 'a';
    for (int i = 0; i < key.size(); ++i) {
        map2[key[i]] = cntr++;  //map the key letters to the first few letters
    }
    for (char i = 'a'; i <= 'z'; i++) {
        if (map1[i] != 0)continue; //  if letter is used in the key then don't use it
        map2[i] = cntr++; // map every alphabet letter to its corresponding letter
    }
    string ans = "";
    for (int i = 0; i < input.size(); ++i) {
        ans += map2[input[i]];  // add every mapped letter to the answer
    }
    return ans;
}

void SSCipher(int choice, string input){
    cin >> choice;
    choice = toupper(choice); // make the answer upper
    cout<<"enter your key: "<<endl;
    string key;
    cin>>key;
    if (choice == 1) { // if user want to incode
        cout << encodeSS(input, key);
    }else{
        cout << decodeSS(input, key);
    }
}

void menu() {
    cout << "Ahlan ya user ya habibi." << endl << "What do you want to do today?"<<endl;
    cout << "1- Cipher a message" << endl << "2-Decipher a message" << endl << "3-End" <<endl;
    int choice1;
    cin >> choice1;
    while (choice1 != 1 && choice1 != 2 && choice1 != 3) {
        cout << "invalid choice, re-enter ur choice: ";
        cin >> choice1;
    }
    if (choice1 == 3)return void(cout<<"goodbye :("<<endl);
    if (choice1 == 1) {
        cout << "Please enter the message to Cipher: ";
    }else if (choice1 == 2) {
        cout << "Please enter the message to decipher: ";
    }
    cin.ignore();
    string input;
    getline(cin,input);

    cout << "Which Cipher do you want to choose?"<<endl;
    cout << "1-Affine Cipher" << endl << "2-Route Cipher" << endl << "3-Simple Substitution Cipher"<<endl<<"any other number- exit"<<endl;
    int choice2;
    cin >> choice2;
    switch (choice2) {
        case 1:
            affineCipher(choice1, input);
        case 2:
            routeCipher(choice1, input);
        case 3:
            SSCipher(choice1, input);
        default:
            cout<<"goodbye :("<<endl;
            break;
    }
}

int main() {
    while (true)menu();
}
