# BITCOIN_DSA_MiniProject
This is the repository for group 9 of the Data Structures and Algorithms MiniProject for the UG1 students of IIIT Hyderabad during the year 2020-21. Our topic is-

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
cline the transaction if the sender’s wallet balance
is lower than the Amount entered or invalid UIDs.
Also Update the user’s transaction history
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
Data Structure - Array of UserInfo (***TBD***)

**UserInfo**
Data Structure - struct which stores the following information-
  1. UID (int, User ID of the user)   
  2. Balance (double)
  3. TransactionHistory (Linked List of TransactionInfo)
  4. JoinDateTime ( char * )

## Functions

**AddUser**
Assigns a fixed value to the balance of the new user (***TBD***)
Initialises the node of the TransactionHistory
Accesses systime to generate the JoinDateTime of the user

**Transact**
Takes input SenderUID, ReceiverUID and Amount
Checks if Sender's Balance >= Amount, and both UID's are valid, Decline Transaction if not
Add the Transaction to Current Block
  If current transaction in current Block == 50th transaction, Initialise a new block
Update the TransactionHistory of the Sender and Receiver

**CreateBlock**
Creates a new Block and adds it to the BlockChain
Assigns a random integer between 1 and 500 to Nonce
Calculates PreviousBlockHash using HashFunction

**Attack**
Generate a random number between 1 to 50
Check if number of blocks >= randomNum, Attack fails if not
Modify the Nonce of the Block

**ValidateBlockChain**
Iterate over the BlockChain
Chaeck if the PreviousBlockHash matches the output of the Hash Function
  If not, adjust it's Nonce   (***TBD*** How to find the correct Nonce)
  
**HashFunction**
Uses the information of a Block- BlockNumber, Transactions, PreviousBlockHash, Nonce (of the Previous Block)
to generate a Hash value    (***TBD*** Which Hash function to use)

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

### Transaction.h
Contains :
 1. struct transaction (corresponding pointer typedefed as Transaction)
 2. struct user_transactions (corresponding pointer typedefed as U_transactions)
 
### Transaction.c
Contains:
 1. Transaction InitTransaction() (function to initialize an instance of a transaction)
 2. U_transactions InitU_Transaction() (function to initialize an instance of a user transaction)

### User.h
 Contains :
 1. struct user (typedefed as User)
 2. struct usersArray 
 3. 
 2. added UserHashFunction, ResizeUHT, AddUser, SearchUHT

### User.c
 1. Get_JoinDateTime (return char * - a string pointer giving JDT as DAY Month DD HH:MM:SS YYYY)
 2. InitUser() (function to initialize User)
 3. makeUserTransaction(int UID,double Amount) (function to create a node that is to be added to a user's transaction history)
 4. addUserTransaction(U_transactions TH, int UID, double Amount) (function to add a transaction to a user's transaction history)
 5. InitUserHashTable() (initializes a hash table)
 6. SearchUHT() (Searches the created Hash Table for existing entry values)
 7. AddUser() (Adds a user to the index)
