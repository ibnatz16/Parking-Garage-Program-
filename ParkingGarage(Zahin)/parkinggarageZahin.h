#ifndef PA3_H
#define PA3_H
#include <iostream>
#include <string>
#include "stdio.h"

using namespace std;

class pa3{
private:
    int size;
    //Struct used to make node
    typedef struct node {
        
        string data;
        node *next;
        
    }* nodePtr;
    
    nodePtr head, temp, now;
    
public:
    pa3();
    void push(string add);
    string pop();
    bool empty();
    bool notFree(string data);
    int stackSize();
    void print();
    bool isTrue();
};


#endif

