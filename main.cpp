/***************************************************************
Program Name: (Name for C++ program you are developing)
Version: 1.0
Last Revised: 12/22/2023
Project name: Practical_Project_PoS
Filename: main.cpp
Student: (Abdulla Yusuf)
Student ID: ( 202101197 )
Course and Assignment Numbers: (EN6001 Program point-of-sale (PoS))





-------------------------------------------------------------------------------------------------
                         Some important information to start the program
-------------------------------------------------------------------------------------------------

1- Cashier ID – (B0131801) Cashier password – (RJ318001).
2- Admin ID – (AD131801) Admin password – (RJ318AD1).
3- All card number will work with the program.
4- Just one card have a balance of 1000BD for the purpose of verification of the account balance
(Card number: 4556737586899855, The PIN:9 855, The balance:1000).
5- All other card will work fine withe no limit of balance.
6- The PIN of the card will be the last 4 number of the card number
for instance ( Card number: 4342077277183288 ) ( The PIN: 3288 ).
7- The card number must entered with no spaces.





-------------------------------------------------------------------------------------------------
                                     Input-Output Description
-------------------------------------------------------------------------------------------------

Input-Output Description: (Describe your input and outputs)

1- (User_Input) used to choice from the Main_Page:
if the user enter one the program go the Admin_Page
    (Admin_Input) used to choice from the Admin_Page:
In this part the are three choices:
if the admin choice 1:
    All of the transaction will appear with the corresponding data.
if the admin choice 2:
    All of the declined transaction will appear with the corresponding data.
if the admin choice 3:
    The program will ask if you want to exit admin mode


if the user enter one the program go the Customer mode:
    In the Customer mode the inputs are:
    the amount of the transaction and the card number and the PIN of the card
    The output will be: a message will be shown about the transaction states.




and will ask for the ID and the password of the admin
using the authenticateAdmin() function. Moreover, if the user
enter 2 the program will ask for the ID and the password of the cashier using the
authenticateCashier() function. The output of this two functions are true if the ID and
the password are correct and false if not.





-------------------------------------------------------------------------------------------------
                                      Test input & results
-------------------------------------------------------------------------------------------------

Test input & results: (For XYZ as input, the program produces output)
The following information has been used to test the program
(card number: 4556737586899855 and card PIN:9855 the amount to pay: 15.250 BD)

The out put was:
The entered PIN number is correct
Transaction ID BAH31800001 is completed
Transaction attempt date: 1/1/2024 & time: 12:28 am
Transaction amount: 15.250BHD

and for the admin mode the Total transaction has been chaked by using the input 1 and the out put was:
######################################################################
             All transactions in terminal ID: BAH31801

Date         Time    Transaction ID Card no.   Amount in BHD   Status

1/1/2024  12:28 AM   BAH31800001    9855          15.000    Success
######################################################################

More details:
To test the program lets say:
The program has been started with the main page and the user
choice 2 to enter the (Customer mode). In this case the program will ask
to inter the ID and the password for the customer if the customer has entered
a wrong information the program will give him 3 chaoses and return to the main page
the corccet ID and password for the Customer are (B0131801 & RJ318001). After the customer
entered the correct ID and Password the program will ask for the data of the transaction
first the amount of the transaction then the card number and the PIN of the card
if the is corccet the program will show the data and save them.

for the admin mode the program will ask for entering the ID and the password for the admin
if the customer has entered a wrong information the program will give him 3 chaoses and return
to the main page the corccet ID and password for the Customer are (AD131801 & RJ318AD1). After that the admin can choses to do:
1- Total transaction
2- Review declined transaction
3- Exit admin mode





-------------------------------------------------------------------------------------------------
                                        Brief description
-------------------------------------------------------------------------------------------------

The program has been built using different functions to perform the work required. And the
main function of the program was containing the logic to navigate in the part of the program.

In the main function after declaring all the wanted variables the program starts with a while loop [while (true)]
to make the program back to the main page every time. In the main page the program prompts the user to
enter 1 (admin mode) or 2 (customer mode). If the user enters a wrong input the program will start
another while loop to ask the user to enter the correct input. And that will be by declaring a Boolean variable
and assigned true to it. Then while the variable is true the loop will work and if the user enters a correct
input the variable condition will change to false so after the loop finishes it will not start again. All the program
will work in the same concept.

To save the data of the transaction a structure, vector, and a function has been built to serve that purpose. Friars
the data of the transaction will be saved organized using the structure then the function
(Add_Transaction_Details(const TransactionDetails& transaction)) has been used to push the information of the transaction
into the vector. After that another function has been used (Print_All_Transactions()) to print the saved transaction in the vector.

In the admin mode, and after the admin enter the correct ID and password. The admin will have 3 choices and each one will start a
 function to show the wanted data.





***************************************************************/




#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

    // The deification of the colors
#define RED_COLOR     "\x1b[31m"
#define PURPLE_COLOR  "\033[35m"
#define RESET_COLOR   "\033[0m"


using namespace std;

    // Declaring a strut for the declined transaction
struct TransactionDeclinedDetails {
    string date;
    string time;
    string transactionID;
    string cardLastFourDigits;
    double amount;
    string Reason;
};

    // Declaring a vector to save the declined transaction information in it
vector<TransactionDeclinedDetails> allDeclinedTransactions;

    // Declaring a strut for the card information
struct card_info {
    string Card_s_num;
    string Card_s_pin;
    double Card_s_amount;
    };

    //Declaring a strut for the all transactions
struct TransactionDetails {
    string date;
    string time;
    string transactionID;
    string cardLastFourDigits;
    double amount;
    string status;
};

    // Declaring a vector to save transactions information in it
vector<TransactionDetails> allTransactions;


    // The authenticateCashier function check if the cashier's ID and password is correct or not
bool authenticateCashier() {

        // Declaring some var to use in the function later
        // The var (Is_Done) has been cashier to check if some condition has been done or not
        // The var (remainingAttempts) store 3, so the cashier has 3 chances
    bool Is_Done;
    int remainingAttempts = 3;
    string Cashier_Id;
    string password;

        // The while loop has been used to check if the cashier take the 3 attempts if he dose the loop will stop
    while (remainingAttempts > 0) {

            // In the first part the program will ask the used for the id & password
        cout <<PURPLE_COLOR << "Enter the cashier id & password" <<endl;
        cout <<RED_COLOR << "---> ";
        cin >> Cashier_Id;
        cout << "---> ";
        cin >> password;

    /* ------------------------------------------------------------- */

            // If the cashier enter the correct id & password the (Is_Done) will be true and return it
        if (Cashier_Id == "B0131801" && password == "RJ318001") {
            cout <<PURPLE_COLOR;
            Is_Done = true;
            return Is_Done;
            break;
        } else {
            cout <<PURPLE_COLOR << "Incorrect credentials" << endl;
            remainingAttempts--;

    /* ------------------------------------------------------------- */

                // If the cashier enter wronger the id & password the program will check if the is enough attempts
            if (remainingAttempts > 0) {
                cout <<PURPLE_COLOR << "You have " << remainingAttempts << " more chance\n" << endl;
            } else {
                    // If there are no enough attempts the program will stop loop by making the var (Is_Done) = to false
                cout <<PURPLE_COLOR << "Your credentials are locked\n" << endl;
                Is_Done = false;
                return Is_Done;

            }
        }
    }

}

    // The authenticateAdmin function check if the Admin's ID and password is correct or not
bool authenticateAdmin() {

        // Declaring some var to use in the function later
        // The var (Is_Done) has been used to check if some condition has been done or not
        // The var (remainingAttempts) store 3, so the user has 3 chances
    bool Is_Done;
    int remainingAttempts = 3;
    string Admin_Id;
    string Admin_password;

        // The while loop has been used to check if the user take the 3 attempts if he dose the loop will stop
    while (remainingAttempts > 0) {

            // In the first part the program will ask the admin for the id & password
        cout <<PURPLE_COLOR << "Enter the admin id & password" <<endl;
        cout <<RED_COLOR << "---> ";
        cin >> Admin_Id;
        cout << "---> ";
        cin >> Admin_password;


    /* ------------------------------------------------------------- */


        if (Admin_Id == "AD131801" && Admin_password == "RJ318AD1") {
            cout <<PURPLE_COLOR;
            Is_Done = true;
            return Is_Done;
            break;
        } else {
            cout <<PURPLE_COLOR << "Incorrect credentials" << endl;
            remainingAttempts--;

    /* ------------------------------------------------------------- */

            if (remainingAttempts > 0) {
                cout <<PURPLE_COLOR << "You have " << remainingAttempts << " more chance\n" << endl;
            } else {
                cout <<PURPLE_COLOR << "Your credentials are locked\n" << endl;
                Is_Done = false;
                return Is_Done;

            }
        }
    }

}

    // The printCurrentDateTime function used to print the current date time
void printCurrentDateTime() {

    // Get the current system time
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());

    // Convert it to a struct tm (time information)
    tm* localTime = localtime(&now);

    // Format and print the current date
    cout << "Date: "
         << localTime->tm_mday << "/" << (localTime->tm_mon + 1) << "/" << (localTime->tm_year + 1900)
         << endl;

    // Format and print the current time in AM/PM format
    cout << "Time: ";
    if (localTime->tm_hour >= 12) {
        if (localTime->tm_hour > 12)
            cout << localTime->tm_hour - 12 << ":" << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << " pm";
        else
            cout << localTime->tm_hour << ":" << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << " pm";
    } else {
        if (localTime->tm_hour == 0)
            cout << 12 << ":" << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << " am";
        else
            cout << localTime->tm_hour << ":" << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << " am";
    }
    cout << endl;
}

    //The Main_Page function used to print the main page of the PoS
void Main_Page() {



    cout << PURPLE_COLOR
         << "#######################"   <<endl
         << "Welcome to PoS"            <<endl
         << "Terminal ID: BAH31801"     <<endl;
            printCurrentDateTime();
    cout << "Press"                     <<endl
         << "1. Admin mode"             <<endl
         << "2. Customer mode"          <<endl
         << "#######################" <<endl;

             cout << RED_COLOR;


    cout <<endl;
}

    //The Admin_Screen function used to print the admin screen
void Admin_Screen() {

    cout << PURPLE_COLOR
         << "\n#######################"         <<endl
         << "Admin screen - PoS"                <<endl
         << "Terminal ID: BAH31801"             <<endl;
            printCurrentDateTime();
    cout << "Press"                             <<endl
         << "1. Total transaction"              <<endl
         << "2. Review declined transaction"    <<endl
         << "3. Exit admin mode"                <<endl
         << "#######################\n"         <<endl;

             cout << RED_COLOR;


}

    //The validateCardNumber used the Luhn Algorithm to check if the entered card is correct or not
bool validateCardNumber(const string& cardNumber) {
    string normalizedCardNumber = cardNumber;

    // remove the spaces in the number if there is any
    normalizedCardNumber.erase(remove(normalizedCardNumber.begin(), normalizedCardNumber.end(), ' '), normalizedCardNumber.end());

    int sum = 0;
    bool isSecondDigit = false;

    for (int i = normalizedCardNumber.length() - 1; i >= 0; i--) {
        int digit = normalizedCardNumber[i] - '0';

        if (isSecondDigit) {
            digit *= 2;

            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        isSecondDigit = !isSecondDigit;
    }

    return (sum % 10 == 0);
}

    // This function taks the number of card as a string and return the last 4 number (the last 4 number will be the password of the card)
string card_pass_creater(const string& Input_Card_num) {
    int The_Length = Input_Card_num.length();
    string last_four_num;

    for (int i =The_Length - 4; i<The_Length; i++) {
        last_four_num = last_four_num + Input_Card_num[i];
    }
    return last_four_num;
}

    //This function will generate unique number for each transaction
string getNextUniqueNumber(unsigned int& currentNumber) {
    currentNumber = currentNumber + 1;
    string prefix = "BAH318";
    string number = to_string(currentNumber);
    string uniqueNumber = prefix + string(5 - number.length(), '0') + number;
    return uniqueNumber;
}

    //This function will print the current date and time
void time_date () {
    // Get the current system time
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());

    // Convert it to a struct tm (time information)
    tm* localTime = localtime(&now);

    // Format and print the current date
    cout <<"date: " << localTime->tm_mday << "/" << (localTime->tm_mon + 1) << "/" << (localTime->tm_year + 1900);

    // Format and print the current time in AM/PM format
    cout << " & time: ";
    if (localTime->tm_hour >= 12) {
        if (localTime->tm_hour > 12)
            cout << localTime->tm_hour - 12 << ":" << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << " pm";
        else
            cout << localTime->tm_hour << ":" << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << " pm";
    } else {
        if (localTime->tm_hour == 0)
            cout << 12 << ":" << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << " am";
        else
            cout << localTime->tm_hour << ":" << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << " am";
    }
    cout << endl;
}

    //This function will print current date as a string
string date_trans_now() {
    // Get the current system time
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());

    // Convert it to a struct tm (time information)
    tm* localTime = localtime(&now);

    // Format the current date as a string
    ostringstream oss;
    oss << localTime->tm_mday << "/" << (localTime->tm_mon + 1) << "/" << (localTime->tm_year + 1900);
    return oss.str();
}

    //This function will print current time as a string
string time_trans_now() {
    // Get the current system time
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());

    // Convert it to a struct tm (time information)
    tm localTime{};
    localtime_s(&localTime, &now);

    // Format the current time in AM/PM format
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%I:%M %p", &localTime);

    return string(buffer);
}

    //This function has been used to add transaction details to a vector
void Add_Transaction_Details(const TransactionDetails& transaction) {
        allTransactions.push_back(transaction);
    }

    //This function will print the data in the vector for all transactions
void Print_All_Transactions() {
    cout << PURPLE_COLOR
    << "\n######################################################################" << endl;

    cout << setw(55) << "All transactions in terminal ID: BAH31801\n" << endl;
    cout << "Date" << setw(13) << "Time" << setw(18) << "Transaction ID" << setw(9) << "Card no."
         << setw(16) << "Amount in BHD" << setw(9) << "Status" <<endl <<endl;


    for (const auto& transaction : allTransactions) {
        cout << transaction.date <<" " <<setw(9) << transaction.time <<" " <<setw(13)
             << transaction.transactionID <<" " <<setw(7) <<transaction.cardLastFourDigits << " " <<setw(15)
             << fixed << setprecision(3) << transaction.amount << " " <<setw(10) << transaction.status <<endl;
    }
    cout << "######################################################################" << endl;
}

    //This function has been used to add declined transaction details to a vector
void Add_Declined_Transaction_Details(const TransactionDeclinedDetails& transactionDeclined) {
    allDeclinedTransactions.push_back(transactionDeclined);
}

    //This function will print the data in the vector for declined transactions
void Print_All_Declined_Transactions() {

    cout << PURPLE_COLOR
    << "\n######################################################################" << endl;

    cout << setw(55) << "Declined transactions in terminal ID: BAH31801\n" << endl;
    cout << "Date" << setw(13) << "Time" << setw(18) << "Transaction ID" << setw(9) << "Card no."
         << setw(16) << "Amount-BHD" << setw(9) << "Reason" <<endl <<endl;


    for (const auto& transactionDD : allDeclinedTransactions) {
        cout << transactionDD.date <<" " <<setw(9) << transactionDD.time <<" " <<setw(13)
             << transactionDD.transactionID <<" " <<setw(7) <<transactionDD.cardLastFourDigits << " " <<setw(15)
             << fixed << setprecision(3) << transactionDD.amount << " " <<setw(10) << transactionDD.Reason <<endl;
    }
    cout << "######################################################################" << endl;


}








    // the main body of the program
int main()
{

    // Save some var as string to use them later
string lastFourDigits;
string current_time;
string currentDate;


    // declaring the info for card 1 with 1000BD balance
    // (all of the other cards will work but with no limit of balance)
card_info card_one = {"4556737586899855", "9855", 1000};


    // for the unique number
    // the unique number enshlize as 0 and will increase by 1 every time it has been used in the function
unsigned int currentNumber = 0;
string uniqueNumber;


    //input var for the user and admin choises
string User_Input;
string Admin_Input;


    //boolean var for navigation in the program
bool is_true = true;
bool is_true_A = true;
bool is_true_Admin_Screen = true;


    //other vars
string Amount_For_Paying;
double Amount_To_Pay;
string card_number;
string Card_PIN;
string Exit_mod;





/*-------------------------------------------------------------------------------------------------*/
/**/                                /* The starting of the program */                            /**/
/*-------------------------------------------------------------------------------------------------*/

// There the while loop has been used to back the the Main Page every time a part of the program has been done
while (true) {

    is_true_Admin_Screen = true;

    Main_Page();

    cin >> User_Input;
    cout <<endl;

        // if the user enter a wronger input the program will start a loop
        // asking the user to enter the correctly
        // the while loop will stop after the user inter 1 or 2
        // and that will happen by changing the (is_true) to be false to make the loop stop
        // other wise the loop will continue until the user enter the right input
    if (User_Input != "1" && User_Input != "2") {

        while (is_true) {

            cout <<PURPLE_COLOR
                 << "Incorrect user input"  <<endl
                 << "Press either 1 or 2"   <<endl;

            cout <<RED_COLOR;
            cin >> User_Input;
                if (User_Input == "1" || User_Input =="2") {
                    is_true = false;
                } else {
                    continue;
                }
        }

    }




/*-------------------------------------------------------------------------------------------------*/
/**/                                  /* Entering admin mode */                                  /**/
/*-------------------------------------------------------------------------------------------------*/
        // If the user inter is 1 with the correct password and userID a while loop will start to loop in the Admin Screen
        // And to exit the loop the (is_true_Admin_Screen) far will be change to false and that done if 3 was chosen
    if (User_Input == "1") {
        is_true = true;


        if (authenticateAdmin()) {
           while (is_true_Admin_Screen) {

                Admin_Screen();
                cin >> Admin_Input;
                    // If the user enter a wrong input the program will start a while loop until the user inter a correct input
                if ( Admin_Input != "1" && Admin_Input != "2" && Admin_Input != "3" ) {
                    while (is_true_A) {

                        cout <<PURPLE_COLOR
                             << "Incorrect user input"  <<endl
                             << "Press either 1 or 2 or 3"   <<endl;
                        cout <<RED_COLOR;
                        cin >> Admin_Input;
                        if (Admin_Input == "1" || Admin_Input =="2" || Admin_Input == "3" ) {
                            is_true_A = false;
                        } else {
                            continue;
                        }
                    }
                }

                    // if 1 has been entered All Transactions will be printed using a created function
                if ( Admin_Input == "1" ) {
                    is_true_A = true;

                    Print_All_Transactions();

                    // if 2 has been entered All Declined Transactions will be printed using a created function
                } else if ( Admin_Input == "2" ) {
                    is_true_A = true;

                    Print_All_Declined_Transactions();

                    // if 3 has been entered the program will ask if you want to exit the Admin Mode
                } else if ( Admin_Input == "3" ) {
                    is_true_A = true;
                    cout <<PURPLE_COLOR << "\nExiting Admin Mode"     <<endl
                         << "Are you sure you want to exit Admin Mode? (y/n)"                           <<endl;

                    cout <<RED_COLOR;
                    cin >> Exit_mod;
                    cout <<endl;


                    if (Exit_mod == "y" || Exit_mod == "Y" || Exit_mod == "Yes" || Exit_mod == "yes" || Exit_mod == "YES") {
                        is_true_Admin_Screen = false;
                    } else if (Exit_mod == "n" || Exit_mod == "N" || Exit_mod == "No" || Exit_mod == "no" || Exit_mod == "NO") {
                        is_true_Admin_Screen = true;
                    } else {
                        continue;
                    }



                }
           }

        }




/*-------------------------------------------------------------------------------------------------*/
/**/                                 /* Entering customer mode */                                /**/
/*-------------------------------------------------------------------------------------------------*/
        // if the user enter 2 in the main page cashier verification function will start
        // if the cashier enter the correct userID and password the payment proses will start
    } else if (User_Input == "2") {
        is_true = true;
        if (authenticateCashier()) {
            cout << "Credentials match"                     <<endl;
            cout << "Enter the transaction amount in BHD:"  <<endl
                 << RED_COLOR << "---> ";
            cin >> Amount_For_Paying;

                //convert the string to number ((stod) has been used to convert the string input to number with double type)
                // This part has been done to be able to use the Amount_To_Pay in the code as a number (to check the balance)
            Amount_To_Pay = stod(Amount_For_Paying);

                // ask the user to enter the card number
            cout << PURPLE_COLOR<<"\nEnter the card number" <<endl
                 << RED_COLOR << "---> ";
            cin >> card_number;

                // use the Luhns_Algorithm to check if the enter card number is correct or not
                // if the card number is correct the program will ask for the PIN of the card
            if (validateCardNumber(card_number)) {
                cout <<PURPLE_COLOR
                     << "\nThe entered card is valid"     <<endl
                     << "Enter the PIN number"            <<endl
                     <<RED_COLOR << "--->";
                cin >> Card_PIN;
                cout <<endl;

                    // The card_pass_creater function takes the last 4 number of the card number
                    // And make it as a PIN for the card
                string pin_of_card = card_pass_creater(card_number);

                    // If tha password (PIN) is correct the transaction will be done if there enough money in the card
                    // In the bottom code the program will make the transaction based on some condition
                if (Card_PIN == pin_of_card)  {

                        if (card_one.Card_s_num == "4556737586899855" && card_one.Card_s_amount >= Amount_To_Pay ) {

                            cout <<PURPLE_COLOR;
                            uniqueNumber = getNextUniqueNumber(currentNumber);
                            cout <<"The entered PIN number is correct"                                              <<endl
                                 <<"Transaction ID " <<uniqueNumber  <<" is completed"                              <<endl
                                 <<"Transaction attempt ";
                            time_date();
                            cout <<"Transaction amount: " <<Amount_To_Pay <<"BHD\n\n";

                            // Debit the account from the card
                            card_one.Card_s_amount = card_one.Card_s_amount - Amount_To_Pay;


                            // Save some var as string to use them later
                            lastFourDigits = card_number.substr(card_number.length() - 4);
                            current_time = time_trans_now();
                            currentDate = date_trans_now();

// To save the data of the transaction using a structure when push the data to vector
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
    TransactionDetails transaction1 = { currentDate, current_time, uniqueNumber, lastFourDigits, Amount_To_Pay, "Success" };
    Add_Transaction_Details(transaction1);
/*-----------------------------------------------------------------------------------------------------------------------------------------*/





                        } else if (card_one.Card_s_num == "4556737586899855" && card_one.Card_s_amount < Amount_To_Pay){
                            cout <<PURPLE_COLOR;
                            uniqueNumber = getNextUniqueNumber(currentNumber);
                            cout <<"The entered PIN number is correct"                                              <<endl
                                 <<"Transaction ID " <<uniqueNumber  <<" is declined due to insufficient balance"   <<endl
                                 <<"Transaction attempt ";
                            time_date();
                            cout <<"Transaction amount: " <<Amount_To_Pay <<"BHD\n\n";

                            lastFourDigits = card_number.substr(card_number.length() - 4);
                            current_time = time_trans_now();
                            currentDate = date_trans_now();

// To save the data of the transaction using a structure when push the data to vector
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
    TransactionDetails transaction1 = { currentDate, current_time, uniqueNumber, lastFourDigits, Amount_To_Pay, "declined" };
    Add_Transaction_Details(transaction1);

    TransactionDeclinedDetails transaction2 = { currentDate, current_time, uniqueNumber, lastFourDigits, Amount_To_Pay, "insufficient balance" };
    Add_Declined_Transaction_Details(transaction2);
/*-----------------------------------------------------------------------------------------------------------------------------------------*/





                        } else {
                            cout <<PURPLE_COLOR;
                            uniqueNumber = getNextUniqueNumber(currentNumber);
                            cout <<"The entered PIN number is correct"                                              <<endl
                                 <<"Transaction ID " <<uniqueNumber  <<" is completed"                              <<endl
                                 <<"Transaction attempt ";
                            time_date();
                            cout <<"Transaction amount: " <<Amount_To_Pay <<"BHD\n\n";

                            lastFourDigits = card_number.substr(card_number.length() - 4);
                            current_time = time_trans_now();
                            currentDate = date_trans_now();

// To save the data of the transaction using a structure when push the data to vector
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
    TransactionDetails transaction1 = { currentDate, current_time, uniqueNumber, lastFourDigits, Amount_To_Pay, "Success" };
    Add_Transaction_Details(transaction1);
/*-----------------------------------------------------------------------------------------------------------------------------------------*/





                        }
                } else {
                    cout <<PURPLE_COLOR;
                    uniqueNumber = getNextUniqueNumber(currentNumber);
                    cout <<"The entered PIN number is incorrect"                                            <<endl
                         <<"Transaction ID " <<uniqueNumber  <<" is declined due to incorrect PIN"          <<endl
                         <<"Transaction attempt ";
                         time_date();
                    cout <<"Transaction amount: " <<Amount_To_Pay <<"BHD\n\n"                               <<endl;

                            lastFourDigits = card_number.substr(card_number.length() - 4);
                            current_time = time_trans_now();
                            currentDate = date_trans_now();

// To save the data of the transaction using a structure when push the data to vector
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
    TransactionDetails transaction1 = { currentDate, current_time, uniqueNumber, lastFourDigits, Amount_To_Pay, "declined" };
    Add_Transaction_Details(transaction1);

    TransactionDeclinedDetails transaction2 = { currentDate, current_time, uniqueNumber, lastFourDigits, Amount_To_Pay, "incorrect PIN" };
    Add_Declined_Transaction_Details(transaction2);
/*-----------------------------------------------------------------------------------------------------------------------------------------*/





                }
            } else {
                    cout <<PURPLE_COLOR;
                    uniqueNumber = getNextUniqueNumber(currentNumber);
                    cout <<"The entered card " <<card_number <<" number is invalid"                         <<endl
                         <<"Transaction ID " <<uniqueNumber  <<" is declined due to invalid card"           <<endl
                         <<"Transaction attempt ";
                         time_date();
                    cout <<"Transaction amount: " <<Amount_To_Pay <<"BHD\n\n"                               <<endl;

                            lastFourDigits = card_number.substr(card_number.length() - 4);
                            current_time = time_trans_now();
                            currentDate = date_trans_now();

// To save the data of the transaction using a structure when push the data to vector
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
    TransactionDetails transaction1 = { currentDate, current_time, uniqueNumber, lastFourDigits, Amount_To_Pay, "declined" };
    Add_Transaction_Details(transaction1);

    TransactionDeclinedDetails transaction2 = { currentDate, current_time, uniqueNumber, lastFourDigits, Amount_To_Pay, "invalid card" };
    Add_Declined_Transaction_Details(transaction2);
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
            }
        }
    }
}


}
