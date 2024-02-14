#include <iostream>
#include <string>
#include <list>

using namespace std;
class Node {
public:
    Node() = delete;
    Node(float data):n_next(nullptr), n_data(data){}
    ~Node(){
         // delete n_next; // @R causes recursive deletion
    }
    Node* n_next;
    float n_data;
};

class SLinkedList{
    Node* m_head;
public:
    SLinkedList()=delete;
    // Const
    SLinkedList(float data) :  m_head ( new Node(data))  {}
    // Push_front
    void push_front(float data)
    {
        Node* temp = new Node(data);
        temp->n_next = m_head;
        m_head = temp;
    }
    //pop_front
    float pop_front(){
        float r_data = m_head->n_data;
        Node* temp = m_head;
        // new head
        m_head = m_head->n_next; 
        delete temp; 
        return r_data;
    }

    void display(){
        Node* iter = m_head; 
        while(iter->n_next){
            cout << iter->n_data << endl;
            iter = iter->n_next;
        }
        cout << iter->n_data << endl;
    }

    void empty(){
        Node* iter = m_head; 
        while(iter->n_next){
            Node* delNode = iter;
            iter = iter->n_next;
            delete delNode;
        }
        delete iter;
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
    while (true) {
        float data = mylist.pop_front();
        if (data == 1.0) break; // Stop when the initial data is reached
        cout << "Popped: " << data << endl;
    }
    cout << " remaining data " << endl;
    mylist.display();
    mylist.empty();
    return 0;
}
