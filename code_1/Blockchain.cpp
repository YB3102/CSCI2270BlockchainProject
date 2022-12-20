#include<iostream>
#include <sstream>
#include <string>
#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {

    int balanceCheck = getBalanceOfAddress(src); //calling get balance address

    if (balanceCheck < coins)  //case checking for amount being more than user balance
    {   
        cout << "This is an error message" << endl;
        cout << "Balance of source does not permit the transaction to take place." << endl;
        return;
    }

    else if (src == dst)
    {
        cout << "You cannot transfer BFC from and to the same address." << endl;
        cout << "Transaction denied." << endl;
        return;
    }

    else if (coins <= 0)
    {
        cout << "You are attempting to transfer a negative or null amount." << endl;
        cout << "Transaction denied." << endl;
        return;
    }

    else //otherwise pushing the transaction to pending list of transactions
    {
        Transaction newPendingTrade(src, dst, coins);

        pending.push_back(newPendingTrade);

        return;
    }
}

bool Blockchain::isChainValid() { 

    for (unsigned int i = 1; i < chain.size(); i++) //starting the check from the 1st position of hash
    {   

        //cout << chain[i-1].getHash() << "      " << chain[i].getpreviousHash() << endl;

        //cout << endl; 

        if (chain[i-1].getHash() != chain[i].getpreviousHash()) //comparing hashes 
        {
            return false;
        }

        string temporaryHash = chain[i].getHash(); //temporarily storing the hash

        for (unsigned int j = 0; j < difficulty; j++) //verifying the first difficulty number of digits are 0 
        {
            if (temporaryHash[j] != '0')
            {
                return false;
            }
        }   
    }

    //cout << "I survived." << endl;
    return true; //if all cases satisfied then returning true
}

bool Blockchain::minePendingTransactions(string minerAddress) {

    if (isChainValid() == false)
    {
        return false;
    }

    string latestHash = getLatestBlock().getHash(); //getting the hash for the last block in list

    Block pushPending(pending, time(nullptr), latestHash); //creating a new block

    pushPending.mineBlock(difficulty); //getting a hash for this block as well as mining

    pending.clear(); //clearing out the pending list of transaction vectors

    chain.push_back(pushPending); //adding the newly created block to the list

    Transaction hardWorkReward ("BFC" , minerAddress, miningReward); //rewarding the miner address

    pending.push_back(hardWorkReward); //pushing the reward transaction to the pending list

    return true;
}

int Blockchain::getBalanceOfAddress(string address) {

    int totalBalance = 0;

    for (unsigned int i=0; i < pending.size(); i++) //initially traversing the pending list of approved transactions
    {
        if (pending[i].getSender() == address)
        {
            totalBalance = totalBalance - pending[i].getAmount(); 
        }

        else if (pending[i].getReceiver() == address)
        {
            totalBalance = totalBalance + pending[i].getAmount();
        }
    }

    for (unsigned int j=0; j < chain.size(); j++) //traversing each block in the chain
    {
        for (unsigned int k=0; k < chain[j].transactions.size(); k++) //traversing each transaction list for each block
        {
            if (chain[j].transactions[k].getSender() == address) //adding and subtracting from the balance accordingly
            {
                totalBalance = totalBalance - chain[j].transactions[k].getAmount();
            }

            else if (chain[j].transactions[k].getReceiver() == address)
            {
                totalBalance = totalBalance + chain[j].transactions[k].getAmount();
            }
        }
    }

    if (totalBalance < 0) //if totalbalance goes negative then returning 0
    {
        return 0;
    }

    else 
    {
    return totalBalance; //otherwise returning the newly calculated totalbalance
    }
}

void Blockchain::prettyPrint() {

    cout << "The list of verified transactions is as follows: " << endl;

    for (unsigned int i = 1; i < chain.size(); i++) //printing the list of transactions using toString() for each block
    {
        for (unsigned int j = 0; j < chain[i].transactions.size(); j++)
        {
            cout << chain[i].transactions[j].toString() << endl;
        }
    }

    cout << endl;

    cout << "A list of pending transactions is also available: " << endl; //also printing the pending list of transactions

    for (unsigned int k =0; k < pending.size(); k++)
    {
        cout << pending[k].toString() << endl;
    }

    cout << endl;
}
