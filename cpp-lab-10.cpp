#include <iostream>
// добавить приоритет +
// исправить метод push с учетом приоритета  +
// деструктор добавить (чтобы удалял все Node)  +
using namespace std;
template <typename T>
class MyPriorityQueue {
protected:
    struct Node {
        int priority;
        T data;
        Node* next;
        Node(T data, Node* next, int priority) {
            this->data = data;
            this->next = next;
            this->priority = priority;
        }
    };
    Node* head;
public:
    MyPriorityQueue() {
        head = nullptr;
    }
    void push(T data, int priority) {
        Node* Nodepushed = new Node(data, nullptr, priority);
        if (head == nullptr || head->priority > Nodepushed->priority) {
            if (head == nullptr ) head = Nodepushed;
            else {
                Nodepushed->next = head;
                head = Nodepushed;
            }
        }
        else {
            Node* now = head;
            while (now->next != nullptr && now->next->priority <= Nodepushed->priority) {
                now = now->next;
            }
            if (now->next == nullptr) now->next = Nodepushed;
            else { Nodepushed->next = now->next; now->next = Nodepushed; }
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
    friend ostream& operator << (ostream& ostream, const MyPriorityQueue& queue) {
        if (queue.head != nullptr) {
            ostream << "Head element of the queue: " << queue.head->data << endl;
        }
        ostream << "Size of the queue: " << queue.size() << endl;
        ostream << "All elements of the queue: " << endl;
        Node* now = queue.head;
        while (now != nullptr) {
            ostream << "Element: " << now->data << ", priority: " << now->priority << endl;
            now = now->next;
        }
        ostream << endl;
        return ostream;
    }
    ~MyPriorityQueue() {
        Node* now = head;
        Node* next;
        while (now != nullptr) {
            next = now->next;
            delete now;
            now = next;
        }
        head = nullptr;
    }
};
int main() {
    char data1 = 'a';
    char data2 = 'b';
    char data3 = 'c';
    char data4 = 'd';
    MyPriorityQueue <char> queue;
    queue.push(data1, 1);
    queue.push(data2, 3);
    queue.push(data3, 1);
    queue.push(data4, 1);
    cout << "Queue size: " << queue.size() << endl;
    cout << queue.peek() << endl;
    queue.pop();
    cout << queue.peek() << endl;
    cout << "-----------------------" << endl;
    cout << queue;
}
