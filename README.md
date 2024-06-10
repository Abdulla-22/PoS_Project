# Practical Project Point-of-Sale (PoS)

## Program Overview

**Program Name:** Practical_Project_PoS  
**Version:** 1.0  
**Last Revised:** December 22, 2023  
**Filename:** `main.cpp`  
**Student:** Abdulla Yusuf  
**Student ID:** 202101197  
**Course:** EN6001 - Program Point-of-Sale (PoS)

---

## Important Information

To use this Point-of-Sale (PoS) program effectively, please note the following credentials and guidelines:

1. **Cashier Access:**
   - **ID:** B0131801
   - **Password:** RJ318001
2. **Admin Access:**
   - **ID:** AD131801
   - **Password:** RJ318AD1
3. **Card Transactions:**
   - Any card number format is accepted.
   - For verification purposes, use the card number **4556737586899855**.
   - The corresponding PIN for the verification card is **9855**.
   - The balance on this card is **1000 BD**.
   - For all other cards, there is no balance limit.
   - **PIN Calculation:** The PIN is derived from the last four digits of the card number.
   - **Example:** For card number 4342077277183288, the PIN is 3288.
4. **Card Entry:** Enter card numbers without spaces.

---

## Input and Output Description

### General User Inputs:

1. **Main Page Options:**
   - Enter **1** to access **Admin Mode**.
   - Enter **2** to access **Customer Mode**.

### Admin Mode:

1. **Admin Authentication:**
   - Prompted for Admin ID and Password.
   - Correct credentials will allow access to Admin functions.

2. **Admin Choices:**
   - **1:** View all transactions with complete details.
   - **2:** View only declined transactions.
   - **3:** Exit Admin Mode.

### Customer Mode:

1. **Cashier Authentication:**
   - Prompted for Cashier ID and Password.
   - Correct credentials will allow access to Customer functions.

2. **Transaction Process:**
   - Enter the transaction amount.
   - Enter the card number.
   - Enter the card PIN.
   - The program will validate the transaction and display the status.

---

## Test Inputs and Expected Results

### Example Test Case:

**Inputs:**
- Card number: 4556737586899855
- PIN: 9855
- Transaction amount: 15.250 BD

**Expected Output:**
```
The entered PIN number is correct.
Transaction ID BAH31800001 is completed.
Transaction attempt date: 1/1/2024 & time: 12:28 AM
Transaction amount: 15.250 BHD
```

### Admin Mode Test:

By choosing option **1** in Admin Mode, the following output should be displayed:
```
######################################################################
             All transactions in terminal ID: BAH31801

Date         Time     Transaction ID   Card no.    Amount in BHD   Status
1/1/2024  12:28 AM   BAH31800001     9855         15.000         Success
######################################################################
```

### Detailed Steps for Testing:

1. **Starting the Program:**
   - The program initiates on the Main Page.
   - Choose **2** to enter Customer Mode.

2. **Customer Mode:**
   - Enter the Cashier ID and Password (B0131801 & RJ318001).
   - After successful authentication, input the transaction amount, card number, and PIN.
   - If inputs are correct, transaction details are displayed and stored.

3. **Admin Mode:**
   - Enter Admin ID and Password (AD131801 & RJ318AD1).
   - Admin has three choices:
     - **1:** View all transactions.
     - **2:** Review declined transactions.
     - **3:** Exit Admin Mode.

---

## Brief Description

This program is designed to manage transactions in a Point-of-Sale (PoS) system. It features various modes and functionalities handled through distinct functions, enabling smooth navigation and operations.

### Program Structure:

1. **Main Function:** 
   - Initializes required variables.
   - Runs a perpetual loop to return to the Main Page after each operation.
   - Prompts users for mode selection (Admin or Customer).
   - Validates user input to proceed to the corresponding mode.

2. **Transaction Handling:**
   - Utilizes a combination of structures and vectors to manage and store transaction details.
   - The function `Add_Transaction_Details(const TransactionDetails& transaction)` adds transaction data to the vector.
   - The function `Print_All_Transactions()` displays stored transactions.

3. **Admin Mode Operations:**
   - Requires correct Admin credentials for access.
   - Provides options to view all transactions, declined transactions, or exit Admin Mode.

By encapsulating functionality within specific functions and utilizing structured data storage, the program ensures efficient handling of PoS operations.

---

For further details or assistance, please refer to the program source code in `main.cpp` or contact the student developer, Abdulla Yusuf.
