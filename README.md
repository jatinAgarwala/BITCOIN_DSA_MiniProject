# BITCOIN_DSA_MiniProject
This is the repository for group 9 of the Data Structures and Algorithms MiniProject for the UG1 students of IIIT Hyderabad during the year 2020-21. Our topic is-

**V. BITCOIN**
In this project, you will simulate the working of Bitcoin
and do various operations.
Assigned to: Aditya Kumar



**A. Description**
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



**B. Task List**
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
