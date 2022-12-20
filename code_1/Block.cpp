#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

string Block::getpreviousHash() {
    return previousHash;
}

string Block::getHash() {
    return hash;
}

void Block::setPreviousHash(string _previousHash) {
    
    previousHash = _previousHash;
}

string Block::calculateHash() {

    string build = toString(); //using the toString function to convert the nonce, timestamp and previousHash to a string

    for (unsigned int i = 0; i < transactions.size(); i++) //iterating through the transaction vector
    {
        build = build + transactions[i].toString(); //appending the strings obtained from each transaction to the original string
    }

    return sha256(build); //producing a hash from the provided SHA files
}

void Block::mineBlock(unsigned int difficulty) {

    string compare = ""; //initializing the comparison string for #difficulty digits of 0

    for (unsigned int i = 0; i < difficulty; i++)
    {
        compare = compare + "0"; //building the compare string
    }

    do 
    {
        nonce ++; //incrementing value for nonce
        hash = calculateHash(); //producing a new hash
    }

    while (hash.substr(0,difficulty) != compare); //looping until the conditions are satisified and the #difficulty digits of 0 are equal
}

string Block::toString() {

    stringstream ss;
    ss << "(" << nonce << ", "  << previousHash << ", " << timestamp << ")";
    return ss.str();

}
