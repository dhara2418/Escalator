#include <iostream>
using namespace std;

class Stack {
private:
    int *data;
    int topIndex;
    int maxSize;

public:
    Stack(int size) {
        maxSize = size;
        data = new int[maxSize];
        topIndex = -1;
    }

    ~Stack() {
        delete[] data;
    }

    void addElement() {
        if (isFull()) {
            cout << "[Error] Stack Overflow!" << endl;
        } else {
            int val;
            cout << "Enter number: ";
            cin >> val;
            topIndex++;
            data[topIndex] = val;
            cout << val << " inserted into stack." << endl;
        }
    }

    void removeElement() {
        if (isEmpty()) {
            cout << "[Error] Stack Underflow!" << endl;
        } else {
            cout << data[topIndex] << " removed from stack." << endl;
            topIndex--;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty, nothing on top." << endl;
        } else {
            cout << "Top element is: " << data[topIndex] << endl;
        }
    }

    bool isEmpty() {
        return (topIndex == -1);
    }

    bool isFull() {
        return (topIndex == maxSize - 1);
    }
};

int main() {
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;

    Stack s(n);
    int option;

    do {
        cout << "\n==== STACK MENU ====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek Top\n";
        cout << "4. Is Empty?\n";
        cout << "5. Is Full?\n";
        cout << "6. Exit\n";
        cout << "Choose option: ";
        cin >> option;

        switch (option) {
            case 1: s.addElement(); break;
            case 2: s.removeElement(); break;
            case 3: s.peek(); break;
            case 4: cout << (s.isEmpty() ? "Yes, stack is empty." : "No, stack has elements.") << endl; break;
            case 5: cout << (s.isFull() ? "Yes, stack is full." : "No, stack has space.") << endl; break;
            case 6: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid option, try again!" << endl;
        }
    } while (option != 6);

    return 0;
}
