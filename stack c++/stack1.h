#include <stdlib.h>
class Stack{
  struct Link{
        void* data;
        Link* next;
        //void initialize( void* dat, Link* nxt );
        Link( void* dat, Link* nxt ) : data( dat ), next( nxt ){};
        //~Link();
    } *head;
    public:
    //void initialize();
    Stack() : head( 0 ) {};
    ~Stack(){
        if ( head == 0 ) 
        exit( 1 );
    }
    void push( void* dat ){
        head = new Link( dat, head );
    }
    void* peek(){
        return head ? head -> data : 0;
    }
    void* pop(){
        if ( head == 0 ) 
        return 0;
        void* result = head -> data;
        Link* oldHead = head;
        head = head -> next;
        delete oldHead;
        return result;
    }
    //void cleanup();
};
