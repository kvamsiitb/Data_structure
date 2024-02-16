// Online C++ compiler to run C++ program online
#include <iostream>
#include <list>
#include <cassert>

using namespace std;

template<typename T>
class Node {
public:
    Node() = delete;
    Node(T data):n_next(nullptr), n_prev(nullptr), n_data(data){}
    ~Node(){
         // delete n_next; delete n_prev; // @R leads to recursive deletion of all Nodes
    }
    Node<T>* n_next;
    Node<T>* n_prev;
    T n_data;
};

template<typename T>
class Queue{
    Node<T>* p_head;
    Node<T>* p_rear;
public:
    Queue(){p_rear = p_head = nullptr;}
    // Const

    Queue(T data)
    {
        p_head = new Node<T>(data);
        p_rear = p_head;
    }


    void push_front(T data) // * -> next -> next^2
    {    
        if( (p_head==nullptr) && (p_rear==nullptr) )
        {
            p_head = new Node<T>(data);
            p_rear = p_head;
        }
        else{
            Node<T>* temp = new Node<T>(data);
            temp->n_next = p_head;
            p_head->n_prev = temp;
            p_head = temp;
        }
    }

    T pop_back(){
        
        Node<T>* temp = p_rear;
        T r_data = p_rear->n_data;
        p_rear = temp->n_prev;
        temp->n_prev = nullptr;
        delete temp;            
        return r_data;
    }

    void display(){
        Node<T>* iter = p_head; 
        while(iter){
            cout << iter->n_data << endl;
            iter = iter->n_next;
        }
    }

    void empty(){
        Node<T>* iter = p_head; 
        while(iter){
            Node<T>* delNode = iter;
            iter = iter->n_next;
            delete delNode;
        }
        p_head = nullptr;
        p_rear = nullptr;
    }

    void insertLastPos(T data){
        Node<T>* temp = new Node<T>(data);
        temp->n_prev = p_rear;
        p_rear->n_next = temp;
        p_rear = temp;
    }

#if 1 // error
    void insertPos(int pos, T data){
      if(pos == 0)
      {
        this->push_front(data);
          return;
      }
      else
      {
          Node<T>* iter = p_head;
          int iter_pos = 0;
          bool found_pos = false;
          while(iter){
              if( (iter_pos) == (pos-1) )
              {
                found_pos = true;
                Node<T>* temp = new Node(data);
                if(iter->n_next == nullptr){
                    temp->n_prev = p_rear;
                    p_rear->n_next = temp;
                    p_rear = temp;
                }
                else{
                    temp->n_prev = iter;
                    temp->n_next = iter->n_next;
                    if(iter->n_next != nullptr){
                        iter->n_next->n_prev = temp;
                    }
                    iter->n_next = temp;
                 }
                  break;
               }
              iter = iter->n_next;
              iter_pos++;
          }
          if(found_pos==false)
          {
            cout << " out of range position " << endl;
          }
      }
    }
#endif
   
};


int main() {
        // Test Case 1: Pushing elements onto the queue and then popping them
    Queue<int> q1(10);
    q1.push_front(20);
    q1.push_front(30);
    q1.display();
    assert(q1.pop_back() == 10);   
    assert(q1.pop_back() == 20);
    assert(q1.pop_back() == 30);
    cout << "Empty" << endl;
    // Test Case 2: Inserting elements at specific positions
    Queue<int> q2(10);
    q2.insertPos(1, 20);
    q2.insertPos(2, 30);
    q2.insertPos(1, 40);
    q2.insertPos(1, -1);
    q2.display(); // Expected output: 10 40 20 30
    cout << "Expected output: 10 40 20 30" << endl;
    // Test Case 3: Inserting elements at the last position
    Queue<int> q3(10);
    q3.insertLastPos(20);
    q3.insertLastPos(30);
    q3.insertLastPos(40);
    q3.display(); // Expected output: 10 20 30 40
    cout << "Expected output: 10 20 30 40" << endl;
    
    // Edge Case 1: Empty Queue
    Queue<int> q4;
    q4.push_front(10);
    q4.pop_back(); // Verify pop operation on an empty queue
    cout << "Verify pop operation on an empty queue" << endl;
    
    // Edge Case 2: Insertion at Position 0
    Queue<int> q5(10);
    q5.insertPos(0, 20); // Insert at the front
    q5.display(); // Expected output: 20 10
    cout << "Expected output: 20 10" << endl;
    
    // Edge Case 3: Insertion at Last Position
    Queue<int> q6(10);
    q6.insertLastPos(20);
    q6.insertLastPos(30);
    q6.display(); // Expected output: 10 20 30
    cout << "Expected output: 10 20 30" << endl;
    
    // Edge Case 4: Out-of-Range Position
    Queue<int> q7(10);
    q7.insertPos(10, 20); // Attempt to insert at position 10 (out of range)
    // Should print "out of range position" message
    return 0;
}
