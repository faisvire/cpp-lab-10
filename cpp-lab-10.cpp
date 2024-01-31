#include <iostream>
using namespace std;
template <typename T>
class MyPriorityQueue {
protected:
    struct Node {
        T data;
        Node* next;
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
    Node* head;
public:
    MyPriorityQueue() {
        head = nullptr;
    }
    void push(T data) {
        Node* Node1 = new Node(data, nullptr);
        if (head == nullptr) {
            head = Node1;
        }
        else {
            Node* now = head;
            while (now->next != nullptr) {
                now = now->next;  //до конца очереди
            }
            now->next = Node1;  // новый элемент после последнего узла
        }
    }
    void pop() {
        if (head != nullptr) {
            Node* now = head;
            head = head->next;
            cout << now->data << " was deleted" << endl;
            delete now;
        }
        else {
            cout << "Queue is empty. Nothing to delete" << endl;
        }
    }
    T peek() const {
        if (head != nullptr) {
            return head->data;
        }
        else {
            cerr << "Queue is empty" << endl;
        }
    }
    size_t size() const {
        size_t cnt = 0;
        Node* now = head;
        while (now != nullptr) {
            ++cnt;
            now = now->next;
        }
        return cnt;
    }
    friend ostream& operator << (ostream& ostream, MyPriorityQueue queue) {
        if (queue.head != nullptr) {
            ostream << "Head element of the queue: " << queue.head->data << endl;
        }
        ostream << "Size of the queue: " << queue.size() << endl;
        ostream << "All elements of the queue: ";
        Node* now = queue.head;
        while (now != nullptr) {
            ostream << now->data << " ";
            now = now->next;
        }
        ostream << endl;
        return ostream;
    }
};
int main() {
    char data1 = 'a';
    char data2 = 'b';
    char data3 = 'c';
    MyPriorityQueue <char> queue;
    queue.push(data1);
    queue.push(data2);
    queue.push(data3);
    cout << "Queue size: " << queue.size() << endl;
    cout << queue.peek() << endl;
    queue.pop();
    cout << queue.peek() << endl;
    cout << "-----------------------" << endl;
    cout << queue;
    cout << "-----------------------" << endl;
    MyPriorityQueue<int> queue2;
    queue2.pop();
    queue2.peek();
    cout << queue2;
}
