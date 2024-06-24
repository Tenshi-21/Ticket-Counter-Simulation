#include <iostream>
#include <cstdlib>  // Required for system() function

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = nullptr;
        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Customer " << value << " arrives: Added ticket number " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, no song to play." << endl;
            return;
        }
        Node* temp = front;
        cout << "Now playing song number " << front->data << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty, no song to play." << endl;
        } else {
            cout << "Currently playing song number " << front->data << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue status: [";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << "]" << endl;
    }
};

void displayMenu() {
    cout << "   ----------------------------";
    cout << "\n   | Jasmin's Karaoke Machine | \n";
    cout << "   ---------------------------- ";
    cout << "\n1. Add song to queue \n";
    cout << "2. Play song \n";
    cout << "3. Display currently playing song \n";
    cout << "4. Display queue status\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseAndClearScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();  // Clear any previous input
    cin.get();     // Wait for Enter key press
    clearScreen();
}

int main() {
    Queue q;
    int choice, songNumber;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song number: ";
                cin >> songNumber;
                q.enqueue(songNumber);
                pauseAndClearScreen();
                break;
            case 2:
                q.dequeue();
                pauseAndClearScreen();
                break;
            case 3:
                q.peek();
                pauseAndClearScreen();
                break;
            case 4:
                q.display();
                pauseAndClearScreen();
                break;
            case 5:
                cout << "Exiting karaoke. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
                pauseAndClearScreen();
                break;
        }
    }

    return 0;
}

