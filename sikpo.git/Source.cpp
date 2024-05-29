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

    setlocale(LC_ALL, "ru");

    // Открываем входной файл
    ifstream inFile("catalog.txt");
    if (!inFile.is_open()) {
        cerr << "Ошибка при открытии файла catalog.txt" << endl;
        return 1;
    }

    // Считываем информацию о товарах
    Product products[100];
    int numProducts = 0;
    while (inFile >> products[numProducts].name >> products[numProducts].category >> products[numProducts].price >> products[numProducts].quantity) {
        numProducts++;
    }
    inFile.close();

    // Выводим товары в категории "Промтовары"
    cout << "Tovari in categoria \"Promtovari\":" << endl;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].category == "Promtovari") {
            cout << products[i].name << endl;
        }
    }

    // Выводим товары стоимостью выше 100 рублей
    cout << "\nTovari cost more 100rub:" << endl;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].price > 100) {
            cout << products[i].name << endl;
        }
    }

    return 0;
}
