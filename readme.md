# CSCI 2270 – Data Structures - Final Project 

Start by carefully reading the write-up contained in `CSCI2270_Spring22_Project.pdf`.

Please include a thorough description of your program's functionality. Imagine that you are publishing this for users who know nothing about this project. Also, include the names of the team-members/authors.

---

CSCI 2270 Final Project - README 

Authors: Yatharth Brahmbhatt (me)

This program essentially maintains a massive chain of transactions. The chain itself is divided into smaller chunks called blocks.
The transactions are stored within these blocks. 
When a transaction is made originally within the chain; it is first set aside for verification.
Verifying a transaction is an intensive process which is facilitated by mining. Mining is likewise just as difficult but it 
provides a reward incentive to the miner. 
Hence, whenever a new block is mined, the yet-to-be verified list of transactions is finally verified and pushed into a block. 
The miner is rewarded by the blockchain as well. These reward is again pushed to the pending list of transactions to be verified. 

The process of mining and pushing a new block to the chain is performed by generating an unique hash. This hash is generated via a secure hash algorithm (SHA). A special nonce value is also used to ensure that the generated hash is in standards with the blockchain's special difficulty number. 

This hash can be used to safely traverse through the chain and keep a track of the blocks in the chain. 

One of the .hpp files for this program was modified by me.
In Block.hpp;
* The vector of transactions was moved to public instead of private.
* Getter functions for previousHash and Hash were also defined and added by me.

I also made a main_2.cpp file separate from main_1.cpp in the app_1 folder.
The main_2.cpp file is the menu style program for the project as recommended in the reading document.
main_1.cpp has been left unedited except for some testing comments.

The files and code have been compiled using the following command in wsl terminal:
g++ -std=c++17 code_1/Blockchain.cpp code_1/Block.cpp code_1/sha256.cpp code_1/Transaction.cpp app_1/main_1.cpp
g++ -std=c++17 code_1/Blockchain.cpp code_1/Block.cpp code_1/sha256.cpp code_1/Transaction.cpp app_1/main_2.cpp

They have also been confirmed to work with cmake. 