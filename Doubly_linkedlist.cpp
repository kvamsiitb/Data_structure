// Online C++ compiler to run C++ program online
#include <iostream>
#include <list>
#include <cassert>

using namespace std;
class Node {
public:
    Node() = delete;
    Node(float data):n_next(nullptr), n_prev(nullptr), n_data(data){}
    ~Node(){
         // delete n_next; delete n_prev; // @R leads to recursive deletion of all Nodes
    }
    Node* n_next;
    Node* n_prev;
    float n_data;
};

class DoLinkedList{
    Node* m_head;
public:
    DoLinkedList()=delete;
    // Const
    DoLinkedList(float data)
    {
        m_head = new Node(data);
    }
    // Push_front
    void push_front(float data) // * -> next -> next^2
    {    
        if(m_head==nullptr)
            m_head = new Node(data);
        else
        {
            Node* temp = new Node(data);
            temp->n_next = m_head;
            m_head->n_prev = temp;
            m_head = temp;
        }
    }
    //pop_front
    float pop_front(){
        float r_data = m_head->n_data;
        Node* temp = m_head;
        m_head = m_head->n_next;
        m_head->n_prev = nullptr; 
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
        m_head = nullptr;
    }

    void insertLastPos(float data){
        Node* iter = m_head; 
        while(iter->n_next){
            iter = iter->n_next;
        }
        Node* temp = new Node(data);
        iter->n_next = temp;
    }

    void insertPos(int pos, float data){
        Node* iter = m_head;
        int iter_pos = 0;
        bool found_pos = false;
        while(iter){
            if(iter_pos == pos)
            {
                // create a temp node
                Node* temp = new Node(data);
                if(pos == 0)
                    temp->n_prev = nullptr;
                else
                    temp->n_prev = iter;
                if(iter->n_next==nullptr)
                    temp->n_next = nullptr;
                else
                {
                    temp->n_next = iter->n_next;
                    iter->n_next->n_prev = temp;
                }
                iter->n_next = temp;
                found_pos = true;
            }
            iter_pos++;
            iter = iter->n_next;
        }
        if(found_pos == false)
            cout << " out of range position " << endl;
        
    }
};

int main() {
    cout << "Testing DoLinkedList class:" << endl;

    // Test constructor and display
    cout << "Creating list with initial data: -1.0" << endl;
    DoLinkedList mylist(-1.0);
    cout << "Initial list contents:" << endl;
    mylist.display();
    cout << "------------------------------" << endl;

    // Test push_front
    cout << "Pushing data to the front of the list:" << endl;
    mylist.push_front(0.0);
    mylist.push_front(1.0);
    mylist.push_front(2.0);
    mylist.push_front(3.0);
    cout << "List after pushing data:" << endl;
    mylist.display();
    cout << "------------------------------" << endl;

    // Test pop_front
    cout << "Popping data from the front of the list:" << endl;
    float popped_data = mylist.pop_front();
    assert(popped_data == 3.0);
    popped_data = mylist.pop_front();
    assert(popped_data == 2.0);
    popped_data = mylist.pop_front();
    assert(popped_data == 1.0);
    popped_data = mylist.pop_front();
    assert(popped_data == 0.0);
    cout << "List after popping data:" << endl;
    mylist.display();
    cout << "------------------------------" << endl;

    // Test insertLastPos
    cout << "Inserting data at the last position:" << endl;
    mylist.insertLastPos(4.0);
    mylist.insertLastPos(5.0);
    cout << "List after inserting at last position:" << endl;
    mylist.display();
    cout << "------------------------------" << endl;

    // Test insertPos
    cout << "Inserting data at position 2:" << endl;
    mylist.insertPos(2, 6.0);
    cout << "List after inserting at position 2:" << endl;
    mylist.display();
    cout << "Inserting data at out of range position:" << endl;
    mylist.insertPos(10, 7.0); // Should print "out of range position"
    cout << "List after attempting to insert at out of range position:" << endl;
    mylist.display();
    cout << "------------------------------" << endl;

    // Test empty
    cout << "Emptying the list:" << endl;
    mylist.empty();
    cout << "List after emptying:" << endl;
    mylist.push_front(9.f);
    mylist.display();
    cout << "------------------------------" << endl;
}
