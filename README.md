# BITCOIN_DSA_MiniProject
This is the repository for group 9 of the Data Structures and Algorithms MiniProject for the UG1 students of IIIT Hyderabad during the year 2020-21.  

# COMPILATION INSTRUCTIONS
Users can execute the following steps to compile and use the Bitcoin software :  
    -> Clone the github repository to your local machine  
    -> If the obj folder is not present in the src folder, create an empty obj folder in src.  
    -> Execute the command "make" or "make bitcoin" - This will compile the src files and create the bitcoin executable using the Makefile.  
    -> Running the executable file using "./bitcoin" will run the application.  

# RUNNING TESTS
Users can execute the following steps to run the tests of the Bitcoin software  
    -> Execute the command "make tests" - This will compile the src files, including test.c and create the tests executable using the Makefile.  
    -> Running the executable file using "./tests" will execute the tests and print the results on the screen.  
    -> The final output line should read "6 test cases out of 6 have passed" if the software is bug-free.  
    
## Tests Description
There are 5 different test functions - 
 1. int test_AddUser(UsersArray* UA, UserHashTable* UHT, double InitialBalance)  
 	This function tests the AddUser function in the program.  
 	First, a user is added into the program using AddUser (which return a pointer to this user).
 	Then, the FindUser function is used to obtain another pointer to this user.
 	If the two pointers are equal, then the AddUser function works.
 	
 2. int test_Transact(BlockChain B, UsersArray* UA, UserHashTable* UHT, double InitialBalance)  
 	This function tests the Transact function in the program.  
 	First, two users (sender and receiver) are added in the program.
 	Then, a random Amount (which is lesser than sender's balance) is generated and Transact function is called. 
    This function will change the balance of both the users.
 	If the sender's balance was decreased by Amount and the receiver's balance increased by Amount, then the Transact function works.
 	
 3. int test_Attack(BlockChain B, UsersArray* UA, UserHashTable* UHT, double InitialBalance)  
 	This function tests the Attack and ValidateBlockChain functions in the program.  
 	First, two users are added. These two users are made to exchange some fixed amount back and forth, 2502 times (Transact function called each time).
 	This ensures that 51 blocks are created.
 	The nonce value of each block is stored in an array.  
	Then, the Attack function is called (which changes the nonce of some block).
	If the nonce of the attacked block is different from its original nonce (accessible from the array), then the Attack function works.  
	Now, the ValidateBlockChain function is invoked. If the nonce of the attacked block has been restored to its original value, then ValidateBlockChain works.
	
 4. int test_PrintAllUIDs(UsersArray* UA, UserHashTable* UHT, double InitialBalance)  
 	This function tests the PrintAllUIDs, resizeUA, and resizeUHT functions in the program.  
 	First, 1600 users are added into the program. Their UIDs are stored in an array.
 	Since the size of the user array and user hash table is 1000 in the test.c file, inserting 1600 users guarantees that the resizeUA (to resize user array) and resizeUHT (to resize user hash table) functions were invoked.
 	Then, the UID values that were stored in the array are compared to the UIDs stored in the user array. If the two values are equal for every user, then all 3 functions work.
 	
 5. int test_PrintNumBlocks(UsersArray* UA, UserHashTable* UHT, double InitialBalance)  
 	This function tests the PrintNumBlocks function in the program.  
 	First, two users are added into the program. These users are made to exchange some amount back and forth for some randomly generated number of times. 
 	This generated number can be used to calculate the expected number of blocks in the blockchain.
 	If the expected number is equal to the actual number of blocks, then the PrintNumBlocks function works.



# PROJECT DESCRIPTION

## V. BITCOIN
In this project, you will simulate the working of Bitcoin
and do various operations.
Assigned to: Aditya Kumar



### A. Description
In the Bitcoin system, transactions are stored in data
blocks like this. Each Block contains 50 transactions, and
it is structured as follows.
Assume PreviousBlockHash of the first block is 0. For
calculating the PreviousBlockHash , you can design your
own Hash Function, which accepts BlockNumber , Trans-
actions, PreviousBlockHash and Nonce of the Previous
block.
You also need to store the user details; you can use any
data structure to do so. It must store details like Unique
ID, Wallet Balance, Transaction History, JoinDateTime.



### B. Task List
You have to implement the following functionalities

1. **Add user to the system -** Assigns a randomly
generated unique ID
2. **Transact -** This takes three input Sender UID, Re-
ceiver UID, and Amount to be transferred. De-
cline the transaction if the sender???s wallet balance
is lower than the Amount entered or invalid UIDs.
Also Update the user???s transaction history
3. **Create Block -** Once you have 50 Transaction, cre-
ate a block and add it to the Chain of blocks. Value
of Nonce can be any random integer between 1 to
500
4. **Attack -** Randomly generate a number between 1-
50, if a Block with BlockNumber == Randomly
Generated number exits then modify its Nonce.
Otherwise, the attack fails
5. **Validate Block-Chain -** Check if Block-chain is
valid, i.e. PreviousBlockHash is correct; if invalid,
it means that the previous Block has been attacked,
adjust its Nonce to match the PreviousBlockHash
of the next Block

_Note -_ Bitcoin is distributed blockchain network, and
It needs a consensus protocol to add new blocks or check
the validity of a node. This Project aims to give you
a smaller picture of Bitcoin and in no way a complete
representation of Bitcoin.

# IMPLEMENTATION

## Data Structures

**Block_Chain**
Data Structure - Linked List of Blocks

The Root Node will contain the total number of blocks in the block-chain in BlockNumber

**Block**
Data Structure - Node of a Linked List which stores the following information-
  1. BlockNumber (int)
  2. PreviousBlockHash (string)
  3. Nonce (int)
  4. Transations (array of TransactionInfo of size 50)
  5. numTransations (int storing current number of transactions filled in the block)

**TransactionInfo**
Data Structure - struct which stores the following information-
  1. SenderUID (int, User ID of the sender)
  2. ReceiverUID (int, User ID of the receiver)
  3. Amount (double, amount of bitcoins given by the sender to the receiver)
  4. NextTransaction (pointer to TransactionInfo) //Will be used for implementing TransactionHistory of each user

**USERS-INFORMATION**
Data Structure - Array of UserInfo

**UserInfo**
Data Structure - struct which stores the following information-
  1. UID (int, User ID of the user)   
  2. Balance (double)
  3. TransactionHistory (Linked List of TransactionInfo)
  4. JoinDateTime ( char * )


## FILES

### block.h
Contains:
  1. struct block (typedefed as Block)
  2. struct blockChain (pointer to blockChain is typedefed as BlockChain)
### block.c
Defines:
  1. PtrToBlock InitBlock() (function to initialize a block; srand used for Nonce)
  2. BlockChain InitBlockChain() (function to initialize the blockchain)
  3. void AddBlock(BlockChain BChain) (function to add a new block to the blockchain after the current block of the block chain gets filled)
  4. void AddBlockTransaction(int S_UID, int R_UID, int amount, BlockChain B) (function to add a transaction to a block)
  5. int Attack(BlockChain B)
  6. int power(int base, int POW_ER) (function to calculate power of a number)
  7. int replace(int digit,int digit_posn, int Original_num) (helper function used to manipulate base_num in getpreviousBlockHash)
  8. int getpreviousBlockHash(PtrToBlock block_node) (function to compute the previousBlockHash of the current block; block_node is pointer to the previous block)
  9. int Validate_BlockChain(BlockChain Chain)
  10. int Transact(int S_UID, int R_UID, int Amount)

### transaction.h
Contains :
 1. struct transaction (corresponding pointer typedefed as Transaction)
 2. struct user_transactions (corresponding pointer typedefed as U_transactions)
 
### transaction.c
Contains:
 1. Transaction InitTransaction() (function to initialize an instance of a transaction)
 2. U_transactions InitU_Transaction() (function to initialize an instance of a user transaction)

### user.h
 Contains :
 1. struct user (typedefed as User)
 2. struct usersArray 
 3. struct userHashTable
 2. added UserHashFunction, ResizeUHT, AddUser, SearchUHT

### user.c
Contains :
 1. char* Get_JoinDateTime (returns a string pointer giving JDT as DAY Month DD HH:MM:SS YYYY)
 2. User InitUser() (function to initialize User)
 3. U_transactions InitUserTransaction(int UID,double amount) (function to initialize a user transaction)
 4. UserArray InitUsersArray(int UASize) (function to initialize the array of Users)
 5. UserHashTable InitUserHashTable(int HTSize) (function to initialize the user hash table)
 6. void ResizeUA(UsersArray* UA) (function to resize the user array when it gets filled)
 7. void DeleteUHT(UserHashTable* UHT) (function to delete a hash table)
 8. UserHashTable ResizeUHT(UsersArray UA, UserHashTable* UHT) (function to resize the user hash table when it gets half filled)
 9. int UserHashFunction(int UID, UserHashTable UHT)
 10. int* SearchUHT(int UID, UserHashTable UHT) (function to search the hash table)
 11. int AddUserUHT(int UserIndex, UsersArray UA, UserHashTable* UHT) (function to insert into the hash table)
 12. User AddUser(UsersArray* UA, UserHashTable* UHT, double InitialBalance) (function to add a user)
 13. User FindUser(int UID, UsersArray UA, UserHashTable UHT) (return a pointer to the User, if the user exists)
 14. void AddUserTH(U_transactions TH, int UID, double amount) (function to add a transaction to the user's transaction history)
 15. void AddUserTransaction(int S_UID, int R_UID, double amount, UsersArray UA, UserHashTable UHT) (function to do a transaction between two users; uses above functions)
 
### UI.h
 Includes transaction.h, user.h, and block.h
 
### UI.c
UI.c contains the nine functions that are to be called in main.
Contains :
 1. int UI_AddUser(UsersArray* UA, UserHashTable* UHT, double InitialBalance)
 2. void UI_Transact(BlockChain B, UsersArray UA, UserHashTable UHT)
 3. void UI_Attack(BlockChain B) 
 4. int UI_ValidateBlockChain(BlockChain B) 
 5. void UI_PrintCurrentBlockInfo(BlockChain B) 
 6. void UI_PrintInfoBlock(BlockChain B) 
 7. void UI_PrintUserInfo(UsersArray UA , UserHashTable UHT)
 8. void UI_PrintAll_UIDs(UsersArray UA) 
 9. void UI_PrintNumBlocks(BlockChain B) 
 
### main.c
The main file. Calls the nine functions contained in UI.c and gives the user a menu based UI.
