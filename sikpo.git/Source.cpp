#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Product {
    string name;
    string category;
    double price;
    int quantity;
};

int main() {

    ifstream inFile("catalog.txt");
    if (!inFile.is_open()) {
        cerr << "Oshybka pri otkrytii faila catalog.txt" << endl;
        return 1;
    }

    Product products[100];
    int numProducts = 0;
    while (inFile >> products[numProducts].name >> products[numProducts].category >> products[numProducts].price >> products[numProducts].quantity) {
        numProducts++;
    }
    inFile.close();

    cout << "Tovari in categoria \"Promtovari\":" << endl;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].category == "Promtovari") {
            cout << products[i].name << endl;
        }
    }

    cout << "\nTovari cost more 100rub:" << endl;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].price > 100) {
            cout << products[i].name << endl;
        }
    }

    return 0;
}
