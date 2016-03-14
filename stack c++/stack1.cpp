/*#include "stack1.h"
#include <stdlib.h>
//using namespace std;*/
/*void Stack::Link::initialize( void* dat, Link* nxt ){
    data = dat;
    next = nxt;
}

void Stack::initialize(){
    head = 0;
}*/

/*Stack::Link::Link( void* dat, Link* nxt){
    data = dat;
    next = nxt;
}

Stack::Link::~Link(){}

Stack::Stack(){
    head = 0;
}

void Stack::push( void* dat ){
    //Link* newLink = new Link;
    //newLink -> initialize(  dat, head );
    //head = newLink;
    head = new Link( dat, head );
}

void* Stack::peek(){
    if ( head != 0)
    return head -> data;
    else exit(1);
    return 0;    
}

void* Stack::pop(){
    if ( head == 0 ) 
    return 0;
    void* result = head -> data;
    Link* oldHead = head;
    head = head -> next;
    delete oldHead;
    return result;
}*/

/*void Stack::cleanup(){
    if ( head == 0 )
    exit(1);
}*/

/*Stack::~Stack(){
    if ( head == 0 )
    exit(1);
}*/
