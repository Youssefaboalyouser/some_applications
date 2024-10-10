//===========================================================================================================================
// file: T1_A1__20230475.cpp
// purpose: solve assignment1
// Author: Youssef Aboalyouser Afeed
// ID:20230475
//                                                                         algorithems
// in the minue ask the user if he want to use the program or not, if 'y' show the user the program and ask whcich one to use

// first programm spelling corrector => make a helper function to remove any triallign space and chek if the first character is capital or not

// second program is to get the prime numbers between zero and N(givien)-if the number is smaller than 2 then return empty list- by make a bolean least
//  iterate through the sqr of n and make nested for loop to remove the multiples of the number but true for the multiples number and then return the index of
// false item + 2 as a prime number!

// third programm is the dominos =>Initialize the list of dominoes (vector<domino_str>).
//  Call the wrapper function domino_chain:
//  If the domino list is empty, return false (no valid chain).
//  Otherwise, proceed with the recursive chain-building process starting with the first domino.
//  Recursive domino placement (domino_chain):
//  For each index i, swap dominoes to explore all possible permutations.
//  If the current domino can follow the last placed domino (matching values), proceed to the next level of recursion to try placing the next domino.
//  If a valid chain is found, return true.
//  If no chain is possible for a given sequence, backtrack by restoring the original domino order and try a new permutation.
//  Return the result:
//  If the recursion completes successfully, the wrapper function returns true, indicating that a valid domino chain was found.
//  If no valid chain is possible, the function returns false.
//  Print the valid chain:
//  Once a valid chain is confirmed, use print_domino_chain to print the domino sequence

// fourth program is alternate bias word => make a map with 30 bias word and it's repleacing
//  read the input file word by word if it is not a biased word put it in the output file
//  if it is replace the word with the coresponding in the map and put it in the output file
// return the output file

//

// ==========================================================================================================================
#include <iostream>
#include <cstring>
#include <string>
#include <limits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#include <codecvt>
#include <locale>
#include <sstream>
#include <fstream>
using namespace std;
// quistion-4 messeage alternating

// Function to create a map of biased words and their replacements (in Arabic)
unordered_map<wstring, wstring> replacing_bias_words()
{
    unordered_map<wstring, wstring> biasMap;

    // Add biased words and their replacements (in Arabic)
    biasMap[L"كسول"] = L"غير نشيط";
    biasMap[L"عدواني"] = L"حازم";
    biasMap[L"أناني"] = L"مستقل";
    biasMap[L"فاسد"] = L"غير مسؤول";
    biasMap[L"غبي"] = L"غير متمرس";
    biasMap[L"قاسي"] = L"صارم";
    biasMap[L"متطرف"] = L"مختلف";
    biasMap[L"جبان"] = L"حذر";
    biasMap[L"غضب"] = L"امتعاض";
    biasMap[L"حقير"] = L"غير لطيف";
    biasMap[L"اسرائيل"] = L"فلسطين";
    biasMap[L"متشائم"] = L"واقعي";
    biasMap[L"قذر"] = L"غير نظيف";
    biasMap[L"مغرور"] = L"واثق";
    biasMap[L"متوتر"] = L"قلق";
    biasMap[L"ضعيف"] = L"لطيف";
    biasMap[L"متشدد"] = L"ملتزم";
    biasMap[L"متسلط"] = L"موجه";
    biasMap[L"جاهل"] = L"قليل المعرفة";
    biasMap[L"صامت"] = L"هادئ";
    biasMap[L"بطيء"] = L"غير مستعجل";
    biasMap[L"ساخر"] = L"منتقد";
    biasMap[L"مجنون"] = L"مختلف";
    biasMap[L"فظيع"] = L"غير ملائم";
    biasMap[L"بشع"] = L"غير جميل";
    biasMap[L"خائن"] = L"غير مخلص";
    biasMap[L"كذاب"] = L"غير صادق";
    biasMap[L"حقير"] = L"غير نبيل";
    biasMap[L"متهور"] = L"جريء";

    return biasMap;
}

// Function to process the input file, replace biased words with alternatives, and output the result to a new file
void proccess_file(const string &inputFile, const string &outputFile, const unordered_map<wstring, wstring> &biasMap)
{
    wifstream inFile(inputFile);
    inFile.imbue(locale(inFile.getloc(), new codecvt_utf8<wchar_t>)); // For Arabic/UTF-8

    wofstream outFile(outputFile);
    outFile.imbue(locale(outFile.getloc(), new codecvt_utf8<wchar_t>)); // For Arabic/UTF-8
    // check if files were opened successfuly
    if (!inFile.is_open() || !outFile.is_open())
    {
        wcerr << L"Error opening file!" << endl;
        return;
    }

    wstring word;
    // read word by word from the input file
    while (inFile >> word)
    {
        // Check if the word is in the bias map
        if (biasMap.find(word) != biasMap.end())
        {
            // Replace the biased word with its replacement
            word = biasMap.at(word);
        }
        // Write the processed word to the output file
        outFile << word << L" ";
    }
    // close files
    inFile.close();
    outFile.close();
}
// quistion-1 is to recorrect the sentence
// ============================================================
// Helper function to trim leading and trailing spaces
string trim(const string &str) // Helper function to trim leading and trailing spaces from a string
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
// Function to correct the sentence
string correctSentence(string sentence)
{
    // Remove leading and trailing spaces
    sentence = trim(sentence);

    // Ensure the first character is capitalized
    if (!sentence.empty() && islower(sentence[0]))
    {
        sentence[0] = toupper(sentence[0]);
    }

    // Process the sentence to fix spacing and capitalization
    bool capitalizeNext = false;
    string result;

    for (size_t i = 0; i < sentence.length(); i++)
    {
        // Fix multiple spaces
        if (isspace(sentence[i]) && (i == 0 || isspace(sentence[i - 1])))
        {
            continue;
        }

        // Capitalize the first letter after a period
        if (capitalizeNext && isalpha(sentence[i]))
        {
            result += toupper(sentence[i]);
            capitalizeNext = false;
        }
        else if (sentence[i] == '.')
        {
            result += sentence[i];
            capitalizeNext = true;
        }
        else
        {
            result += sentence[i];
        }
    }

    // Fix common uppercase issues
    size_t pos = result.find(" IS ");
    if (pos != string::npos)
    {
        result.replace(pos, 4, " is ");
    }

    return result;
}
// ============================================================
// quistion-2 is to find prime numbers

// Function to find all prime numbers less than a given number `n`
vector<int> primeOFnumber(int n)
{
    if (n <= 2)
    {
        return {0}; // No primes if n is <= 2
    }

    vector<int> prime_numbers;
    vector<bool> composites(n, false); // Mark composites as false
    int limit = sqrt(n);               // Limit to check for prime factors

    // Mark all composites using the Sieve of Eratosthenes
    for (int i = 2; i <= limit; i++)
    {
        if (!composites[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                composites[j] = true; // Mark as composite
            }
        }
    }

    // Collect all prime numbers
    for (int i = 2; i < n; i++)
    {
        if (!composites[i])
        {
            prime_numbers.push_back(i);
        }
    }
    return prime_numbers;
}

// ============================================================
// quisiton-3 is to check domino chain

// Structure to define a domino with two values (left and right)
struct domino_str
{
    int left;
    int right;
};
// Function to check if two dominoes can be placed next to each other (matching)
bool matchDomino(domino_str &a, domino_str &b)
{
    return a.right == b.left;
}

bool domino_chain(vector<domino_str> &dominos, int index, int ch_end)
{
    if (index == dominos.size())
    {
        return true;
    }

    for (int i = index; i < dominos.size(); ++i)
    {
        // Try each domino at the current position
        swap(dominos[index], dominos[i]);

        // Check if the domino at currentIndex can follow the previous domino
        if (matchDomino(dominos[ch_end], dominos[index]))
        {
            // Recursive step
            if (domino_chain(dominos, index + 1, index))
            {
                return true;
            }
        }

        // Backtrack and swap back
        swap(dominos[index], dominos[i]);
    }

    return false;
}

bool domino_chain(vector<domino_str> &dominos)
{
    if (dominos.empty())
        return false;
    return domino_chain(dominos, 1, 0);
}
void print_domino_chain(const vector<domino_str> &dominos)
{
    for (int i = 0; i < dominos.size(); ++i)
    {
        cout << dominos[i].left << "|" << dominos[i].right;
        if (i < dominos.size() - 1)
        {
            cout << " - "; // Print separator between dominos
        }
    }
    cout << endl;
}
// ============================================================

int main()
{
    while (true)
    {
        // Ask the user if they want to use the program or exit
        string choice;
        cout << "Do you want to use the program [y/n]: ";
        cin >> choice;

        // Ignore the new line after the input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == "y" || choice == "yes")
        {
            int res = 0;

            // Display available programs
            cout << "We have 4 Programs!\n"
                 << "1) Recorrect the sentence\n"
                 << "2) Find prime numbers\n"
                 << "3) The game of dominos\n"
                 << "4) Message alternating" << endl;

            // Ask the user to choose a program
            cout << "Choose one: ";
            cin >> res;

            // Check if the input is valid and within the range
            if (cin.fail() || res < 1 || res > 4)
            {
                cin.clear();                                         // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
                cout << "Invalid input. Please try again." << endl;
                continue; // Start the loop again
            }

            // Handle the selected program
            if (res > 0 && res <= 4)
            {
                if (res == 1)
                {
                    string sen;
                    cout << "Write your sentence: ";
                    cin >> ws; // Clear any leading whitespace
                    getline(cin, sen);
                    cout << "Original: " << sen << endl;
                    string correctedSentence = correctSentence(sen);
                    cout << "Corrected: " << correctedSentence << endl;
                }
                if (res == 2)
                {
                    int n;
                    cout << "write ur Number: ";
                    cin >> n;
                    for (int nn : primeOFnumber(n))
                    {
                        cout << nn << " ";
                    }
                    cout << "\n";
                }
                if (res == 3)
                {
                    int num_of_dominos;
                    cout << "enter number of dominos: ";
                    cin >> num_of_dominos;
                    vector<domino_str> dominos(num_of_dominos);
                    for (int i = 0; i < num_of_dominos; ++i)
                    {
                        cout << "enter left & right dots for ur domino " << i + 1 << ": ";
                        cin >> dominos[i].left >> dominos[i].right;
                    }
                    if (domino_chain(dominos))
                    {
                        cout << "ur dominos can make a chain!" << endl;
                        cout << "here those are: ";
                        print_domino_chain(dominos);
                    }
                    else
                    {
                        cout << "ur dominos can't make a chain >=" << endl;
                    }
                }
                if (res == 4)
                {
                    auto biaswords = replacing_bias_words();
                    string iFile = "input.txt";
                    string oFile = "output.txt";
                    proccess_file(iFile, oFile, biaswords);
                    wcout << L"File processed successfully!" << endl;
                    return 0;
                }
            }
        }
        else if (choice == "n" || choice == "no")
        {
            // If the user chooses not to use the program, exit
            cout << "*** GOODBYE ***" << endl;
            exit(EXIT_SUCCESS);
        }
        else
        {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }
    }
}