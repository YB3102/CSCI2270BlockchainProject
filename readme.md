# CSCI 2270 – Data Structures - Final Project 

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

The files and code have been compiled using the following command in wsl terminal: <br>
g++ -std=c++17 code_1/Blockchain.cpp code_1/Block.cpp code_1/sha256.cpp code_1/Transaction.cpp app_1/main_1.cpp <br>
g++ -std=c++17 code_1/Blockchain.cpp code_1/Block.cpp code_1/sha256.cpp code_1/Transaction.cpp app_1/main_2.cpp <br>
