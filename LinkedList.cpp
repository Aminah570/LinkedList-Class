#include "list.h"

LinkedList::LinkedList(){
    m_head=nullptr;
}

LinkedList::~LinkedList(){
    while(m_head!=nullptr){
        Node* temp=m_head;
        m_head=temp->m_next;
        delete temp;
    }
    m_head=nullptr;
}

bool LinkedList::empty() const{
    if(m_head==nullptr){
        return true;
    }
    return false;
}

const string& LinkedList::front() const	{// get front element
    if(!empty()){
        return m_head->m_elem;
    }
}

void LinkedList::addFront(const string& toInsert) {
        Node* newNode= new Node;
        newNode->m_elem= toInsert;
    if(empty()){
        newNode->m_next=nullptr;
        m_head=newNode;
    }else{
        newNode->m_next=m_head;
        m_head=newNode;
    }

    /*
    Possible cases:
    both= create a new node
        1. empty  
        2. Not empty
    */

    
}

void LinkedList::removeFront() {
    if(!empty()){
        Node* toDelete= m_head;
        m_head=toDelete->m_next;
        delete toDelete;
    }

    
}

void LinkedList::addInBetween(const string& e, 
                                const string& toInsert){
    /*
    Possible Cases:
        1. list is empty
        2. list is not empty
            3. e does not exist
                3.1 e is head
                3.2 e is not head
    */
   if(!empty()){
        if(m_head->m_elem==e){
            Node* newN= new Node;
            newN->m_elem=toInsert;
            newN->m_next=m_head->m_next;
            m_head->m_next=newN;
        }else{
            Node* temp= m_head;
            while(temp!=nullptr && temp->m_elem!=e){
                temp=temp->m_next;
            }
            if(temp!=nullptr){
                Node* newNode=new Node;
                newNode->m_elem=toInsert;
                newNode->m_next=temp->m_next;
                temp->m_next=newNode;
            }else{
                cout<<"The element e does not exist"<<endl;
            }
        }
 }
}




void LinkedList::remove(const string& e){
    /*
    Possible Cases:
        1. empty list
        2. not empty
            2.1. e is at head
            2.1. e DNE
            2.2 e does exist
    */
   if(!empty()){
        if(m_head->m_elem==e){
            Node *temp= m_head;
            m_head=m_head->m_next;
            delete temp;
        }else{
            Node* temp=m_head;
            while(temp->m_next!=nullptr && temp->m_next->m_elem!=e){
                temp=temp->m_next;
            }
            if(temp->m_next!=nullptr){
                Node* toDelete=temp->m_next;
                temp->m_next=toDelete->m_next;
                delete toDelete;
            }else{
                cout<<"Sorry, e was not found"<<endl;
            }
        }
   }
}

void LinkedList::printList(){
    //to test this function:
    //case: the list is empty
    //case: the list is not empty
    Node* temp = m_head;
    cout << "The current list is:" << endl;
    while(temp != nullptr){
        cout << temp->m_elem << " => ";
        temp = temp->m_next;
    }
    cout << "END" << endl;
}

void LinkedList::append(const string& toInsert){
    if(empty()){
        addFront(toInsert);
    }else{
        Node* temp= m_head;
        while(temp->m_next!=nullptr){
            temp=temp->m_next;
        }
        Node* newN= new Node;
        newN->m_elem=toInsert;
        temp->m_next=newN;
        newN->m_next=nullptr;
    }
}


    void LinkedList::removeTail(){
        if(!empty()){
            if(m_head->m_next==nullptr){
                removeFront();
            }else{
                Node* temp=m_head;
                while(temp->m_next->m_next!=nullptr){
                    temp=temp->m_next;
                }
                Node* toDelete= temp->m_next;
                temp->m_next=nullptr;
                delete toDelete;

            }

        }
    }
