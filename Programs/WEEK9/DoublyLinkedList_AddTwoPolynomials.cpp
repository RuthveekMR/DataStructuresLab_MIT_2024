#include <iostream>
using namespace std;

// Node class to represent each term in the polynomial
class Node {
public:
    int coefficient;
    int exponent;
    Node* next;
    Node* prev;

    Node(int c, int e) {
        coefficient = c;
        exponent = e;
        next = nullptr;
        prev = nullptr;
    }
};

// Class for doubly linked list to store polynomial terms
class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = nullptr;
    }

    // Function to insert a term at the end of the list
    void insertTerm(int coefficient, int exponent) {
        Node* newNode = new Node(coefficient, exponent);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to print the polynomial
    void printPolynomial() {
        if (head == nullptr) {
            cout << "0";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->coefficient > 0 && temp != head)
                cout << " + ";
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to add two polynomials
    Polynomial add(Polynomial& p2) {
        Polynomial result;
        Node* p1Node = head;
        Node* p2Node = p2.head;

        while (p1Node != nullptr && p2Node != nullptr) {
            if (p1Node->exponent == p2Node->exponent) {
                result.insertTerm(p1Node->coefficient + p2Node->coefficient, p1Node->exponent);
                p1Node = p1Node->next;
                p2Node = p2Node->next;
            } else if (p1Node->exponent > p2Node->exponent) {
                result.insertTerm(p1Node->coefficient, p1Node->exponent);
                p1Node = p1Node->next;
            } else {
                result.insertTerm(p2Node->coefficient, p2Node->exponent);
                p2Node = p2Node->next;
            }
        }

        // If one polynomial has remaining terms, add them to the result
        while (p1Node != nullptr) {
            result.insertTerm(p1Node->coefficient, p1Node->exponent);
            p1Node = p1Node->next;
        }
        while (p2Node != nullptr) {
            result.insertTerm(p2Node->coefficient, p2Node->exponent);
            p2Node = p2Node->next;
        }

        return result;
    }
};

// Main program to demonstrate polynomial addition
int main() {
    Polynomial p1, p2;

    // Insert terms into the first polynomial
    p1.insertTerm(5, 2);
    p1.insertTerm(4, 1);
    p1.insertTerm(2, 0);

    // Insert terms into the second polynomial
    p2.insertTerm(3, 2);
    p2.insertTerm(2, 1);
    p2.insertTerm(6, 0);

    cout << "First polynomial: ";
    p1.printPolynomial();

    cout << "Second polynomial: ";
    p2.printPolynomial();

    // Add the two polynomials
    Polynomial result = p1.add(p2);

    // Print the result
    cout << "Result of addition: ";
    result.printPolynomial();

    return 0;
}
