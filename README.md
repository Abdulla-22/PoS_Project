# Point-of-Sale (PoS) Simulation

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

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)

## Features

List the main features or functionalities of your C++ program.

## Getting Started

Provide instructions on how to get started with the project. Include any prerequisites, installation steps, or configuration instructions.

To run the programe `main.exe` use the following line:

```shell
./main
```


## Usage

Explain how to use the program, including any command-line options or arguments that need to be provided.

## Contributing

Specify if you are open to contributions and provide guidelines for how other developers can contribute to your project.
