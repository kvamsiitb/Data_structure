#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
class Node {
public:
    Node() = delete;
    Node(float data):m_next(nullptr), m_data(data){}
    ~Node(){
         delete[] m_next;
    }
    Node* m_next;
    float m_data;
};

class SLinkedList{
    Node* m_head;
public:
    SLinkedList()=delete;
    // Const
    SLinkedList(float data)
    {
        m_head = new Node(data);
    }
    // Push_front
    void push_front(float data)
    {
        Node* temp = new Node(data);
        temp->m_next = m_head;
        m_head = temp;
    }
    //pop_front
    float pop_front(){
        float r_data = m_head->m_data;
        Node* temp = m_head;
        // new head
        m_head = m_head->m_next; 
        m_head->m_next = nullptr;
        delete temp; 
        return r_data;
    }

    void display(){
        Node* iter = m_head; 
        while(iter->m_next){
            cout << iter->m_data << endl;
            iter = iter->m_next;
        }
        cout << iter->m_data << endl;
    }

    void empty(){
        Node* iter = m_head; 
        while(iter->m_next){
            Node* delNode = iter;
            iter = iter->m_next;
            delete[] delNode;
        }
        delete[] iter;
    }
};


int main() {
    SLinkedList mylist = SLinkedList(-1.f);
    mylist.display();
    cout << " Push data " << endl;
    list<float> stllist {0.f, 1.f, 2.f, 3.f};
    for(auto i : stllist){
        mylist.push_front(i);
    }
    mylist.display();
    mylist.empty();
    return 0;
}
