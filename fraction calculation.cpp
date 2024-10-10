// file : CS112_A2_T3_section(23,24)_ 20230475 _20230650_20230121.cpp
// purpose : fraction calculation
//Author : Youssef Aboalyouser Afeed - Ahmed Mohamed - Hossam Mohamed
// Emails : youssefaboalyouser@gmail.com
            // ahmedmahmoudpes41@gmail.com
            // saulgoodman2005@gmail.com
// ID1 : 20230475      make the minue and take the user input , check the validation of it,convert strings to integers
// ID2 : 20230650      make addition and subtraction
// ID3 : 20230121      make multiplication and division


// =================================================================================================================================



//                                         algorithem
// 1.ask the user for using the programm or exit
// 2.if the answer is no ==> exit the programm
// 3.if the answer is yes ===> take the mathmaical expresion as input from the user(string type)
// 4.make function to check the validation of the programm 
// 5. use regex libarary to make pattern of the expression and compare with the user input 
// 6.pattern divided in 3 parts==> 6.1) take one digit with optional sign(+,-) for numinator and denomenator
// 6.2) take the mathmatic operation and make sure that is only one opertation not(++,--,+- ...egx) and check the spaces
// 6.3) like the first term of checking number and sign of numinator and denomenator
// 7.if user input is valid then convert numbers to integes 
// 8.initialize first operation which is first fraction
// 9.initialize second operation which is second fraction
// 10.make functions for addition , subtraction , multiplication and division
// 11.check the operation and by switch method call the needed function




// =================================================================================================================================




#include<iostream>
#include<cstring>
#include<string>
#include<regex>
#include<limits>
#include<cstdlib>
#include<cmath>

using namespace std;
//function to deal with simple numbers (not fraction)
void simple_calculation(string math_oper, double& result) {
    regex singleOpPattern(R"((\d+)\s([\+\-\*\/])\s(\d+))");
    smatch matches;

    if (regex_match(math_oper, singleOpPattern) && regex_search(math_oper, matches, singleOpPattern)) {
        int num1 = stoi(matches.str(1));
        int num2 = stoi(matches.str(3));
        char op = matches.str(2)[0];
        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if(num2 != 0) { 
                    result = num1 / num2;
                } else {
                    cout << "Error: Division by zero!" << endl;
                    return;
                }
                break;
            default:
                cout << "Invalid operation." << endl;
        }
    } else {
        cout << "Invalid input. Please enter a valid operation with integers." << endl;
    }
}


//dfine the gcd method
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//make function that convert decimal point number to fraction number
void decimaltofraction(double result , int& numerator , int& denominator )
{
    double intpart;
    double fracpart = modf(result , &intpart);
    const int prefactor = 1000000;
    int gcdvlaue;

    numerator = static_cast<int>(fracpart * prefactor + intpart * prefactor);
    denominator = prefactor;
    gcdvlaue = gcd(numerator,denominator);
    numerator /= gcdvlaue;
    denominator /= gcdvlaue;
}

//function to add the tow terms
double addition(double num1 , double num2) {
    return num1 + num2;
}

//function to subtract the tow terms
double subtraction(double num1 , double num2) {
    return num1 - num2;
}

//function to multiplay the tow terms
double multiplication(double num1 , double num2) {
    return num1 * num2;
}

//function to divide the tow terms
double division(double num1 , double num2) {
    return num1 / num2;
}

void check_validation(string math_oper, double& result) {
    // Regular expression for matching fractions and operations
   regex singleOpPattern1(R"(([+-]?\d+(?:\/[+-]?\d+)?)\s([\+\-\*\/])\s([+-]?\d+(?:\/[+-]?\d+)?))");

    // Check if the input matches the fraction pattern
    smatch matches;
    if (regex_match(math_oper, singleOpPattern1) && regex_search(math_oper, matches, singleOpPattern1)) {

        // Extract numerators and denominators
        string numin1_s = matches.str(1).substr(0, matches.str(1).find('/'));
        string denomen1_s = matches.str(1).substr(matches.str(1).find('/') + 1);
        string numin2_s = matches.str(3).substr(0, matches.str(3).find('/'));
        string denomen2_s = matches.str(3).substr(matches.str(3).find('/') + 1);

        // Convert strings to doubles
        double numin1 = stod(numin1_s);
        double denomen1 = stod(denomen1_s);
        double numin2 = stod(numin2_s);
        double denomen2 = stod(denomen2_s);
        if(denomen1 == 0 || denomen2 == 0)
        {
            cout << "Error.division by zero!" << endl;
            return;
        }

        // Perform operations
        double first_oper = numin1 / denomen1;
        double second_oper = numin2 / denomen2;

        // Determine the operation
        char op = matches.str(2)[0];
        switch (op) {
            case '+':
                result = addition(first_oper, second_oper);
                break;
            case '-':
                result = subtraction(first_oper, second_oper);
                break;
            case '*':
                result = multiplication(first_oper, second_oper);
                break;
            case '/':
                result = division(first_oper, second_oper);
                break;
            default:
                cout << "Invalid operation." << endl;
        }
    } else {//if the user input are invaled 
        cout << "Invalid input. Please enter a valid fraction operation.\n(make sure to write space before and after mathematical operation)\n or write just one mathmatic operation" << endl;
    }
}

int main() {
    while(true) {
        //ask the user for using the programm or exit 
        string chooce;
        cout << "Do you want to use fraction calculation [y/n]: ";
        cin >> chooce;
        //ignotre the new line to write the input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(chooce == "y" || chooce == "yes") {
            string math_oper;
            cout << "Please enter your mathematical operation (write spaces between them): " << endl;;
            getline(cin, math_oper); //take the mathmatical expression from the user
            double result = 0;
            check_validation(math_oper, result); // call the function to check validation of the input
            simple_calculation(math_oper, result);
            int numerator , denomiator;
            decimaltofraction(result,numerator,denomiator);
            cout << "The result is: " << numerator << " / " << denomiator << endl;

            
        } else if(chooce == "n" || chooce == "no") { // if the user chooce not to use exit the programm
            cout << "*** GOOD BYE ***";
            exit(EXIT_SUCCESS);
        }
    }
}
