#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Telefon {
protected:
    string name;
    string company;
    double price;
public:
    Telefon(string n, string c, double p) : name(n), company(c), price(p) {}
    virtual void printInfo() = 0;
    double getPrice() const { return price; } // Метод для отримання ціни
};


class MobilynyiTelefon : public Telefon {
    string color;
    int memory;
public:
    MobilynyiTelefon(string n, string c, double p, string clr, int mem) : Telefon(n, c, p), color(clr), memory(mem) {}
    void printInfo() override { // Перевизначення методу від батьківського класу
        cout << "Мобільний телефон " << name << " від " << company << " з ціною " << price << endl;
        cout << "Колір: " << color << ", Об'єм пам'яті: " << memory << endl;
    }
};


class Radiotelefon : public Telefon {
    double radius;
    bool answeringMachine;
public:
    Radiotelefon(string n, string c, double p, double r, bool am) : Telefon(n, c, p), radius(r), answeringMachine(am) {}
    void printInfo() override { // Перевизначення методу від батьківського класу
        cout << "Радіо телефон " << name << " від " << company << " з ціною " << price << endl;
        cout << "Радіус дії: " << radius << ", Наявність автовідповідача: " << (answeringMachine ? "Так" : "Ні") << endl;
    }
    bool hasAnsweringMachine() const { return answeringMachine; } // Метод для перевірки наявності автовідповідача
};

// Функція для зчитування даних з файлу
vector<Telefon*> readData(string phone1) {
    vector<Telefon*> phones;
    ifstream input("/Users/solomia/Desktop/3 завд/3 завд/phones1.txt");
    if (!input) {
        cout <<"Помилка відкриття файлу " << phone1 << endl;
        return phones;
        }
        string type, name, company, color, line;
        double price, radius;
        int memory;
        bool answeringMachine;
        while (getline(input, line)) {
        type = line;
        getline(input, name);
        getline(input, company);
        input >> price;
        input.ignore();
        if (type == "Мобільний") {getline(input, color);
            input >> memory;
            input.ignore();
            phones.push_back(new MobilynyiTelefon(name, company, price, color, memory));
            }
            else if (type == "Радіо") {
            input >> radius;
            input >> answeringMachine;
            input.ignore();
            phones.push_back(new Radiotelefon(name, company, price, radius, answeringMachine));
            }
            }
            input.close();
            return phones;
            }

// Функція для сортування телефонів за ціною
bool sortByPrice(Telefon* a, Telefon* b) {
return a->getPrice() < b->getPrice();
}
// Функція для виведення відсортованого списку телефонів
void printPhones(vector<Telefon*>& phones) {
    // Сортування телефонів за ціною
    sort(phones.begin(), phones.end(), sortByPrice);
   
    for (Telefon* phone : phones) {
        phone->printInfo();
        cout << endl;
    }
}
int main() {
vector<Telefon*> phones = readData("/Users/solomia/Desktop/3 завд/3 завд/phones1.txt");
printPhones(phones);


for (Telefon* phone : phones) {
    delete phone;
}
return 0;
}
