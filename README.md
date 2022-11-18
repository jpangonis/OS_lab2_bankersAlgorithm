# OS_lab2_bankersAlgorithm

In this programming assignment, you are required to provide the source codes, documents, and examples in details on github. You only need to submit your github project to me.  

 

Requirements:

You are required to use C/C++ in Linux/Unix. You can consider install virtualBox in your non-Linux environment.
Programs must succeed in compilation and execute as required (80 points)
Readme, documentation and example are required (20 points).
 

Banker’s Algorithm for deadlock avoidance.

 

Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken:

![image](https://user-images.githubusercontent.com/117044135/202622849-d8577847-80b8-42dc-aa7c-86005aa289d1.png)


 

Implement the Banker’s algorithm to answer the following question：Is the system in a safe state? If Yes, then what is the safe sequence?

 

What should be included in the submission:

Source codes (C/C++)
Input file (you should create an input file with your customized format that store the data that is provided in the table).
Your code should print out the safe sequence if the system is safe.
Documents and readme.

Implementation: Written in C++, this code is an example of Banker's algorithm. Banker's algorithm is an implementation of deadlock avoidance and is used to allocate resources to every process in a system. There are two files, banker.cpp and banker.txt. Banker.txt holds all the information from the table given. The banker.cpp file is the implementation of the code. It reads the information from the text file and saves it into a corresponding variable. The algorithm loops through each process that is available and checks to see which one the system can take first. That process is saves into another array and is then outputted at the end of the program. 

To run the code:
To compile: g++ banker.cpp -o banker
To run: ./banker banker.txt

Output of the code:
![Screenshot (72)](https://user-images.githubusercontent.com/117044135/202624443-e9cdc0ff-1108-413c-8603-15b46eabe1c6.png)

