#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
protected:
    string country_code;
    float price;
public:
    Product(string code, float pr) {
        country_code = code;
        price = pr;
    }
    string getCountryCode() {
        return country_code;
    }
    float getPrice() {
        return price;
    }
};

class Toy : public Product {
private:
    string name;
    int min_age;
    int max_age;
public:
    Toy(string code, float pr, string nm, int mina, int maxa) : Product(code, pr) {
        name = nm;
        min_age = mina;
        max_age = maxa;
    }
    string getName() {
        return name;
    }
    int getMinAge() {
        return min_age;
    }
    int getMaxAge() {
        return max_age;
    }
};

int main() {
    vector<Toy> toys;
    toys.push_back(Toy("US", 10.5, "Car", 3, 5));
    toys.push_back(Toy("CN", 20.0, "Doll", 4, 8));
    toys.push_back(Toy("FR", 5.5, "Puzzle", 6, 10));
    toys.push_back(Toy("JP", 15.0, "Robot", 8, 12));

    int min_age, max_age;
    float min_price, max_price;
    cout << "Enter minimum age: ";
    cin >> min_age;
    cout << "Enter maximum age: ";
    cin >> max_age;
    cout << "Enter minimum price: ";
    cin >> min_price;
    cout << "Enter maximum price: ";
    cin >> max_price;

    for (Toy t : toys) {
        if (t.getMinAge() >= min_age && t.getMaxAge() <= max_age && t.getPrice() >= min_price && t.getPrice() <= max_price) {
            cout << t.getName() << " (Age: " << t.getMinAge() << "-" << t.getMaxAge() << ", Price: $" << t.getPrice() << ")" << endl;
        }
    }

    string answer;
    cout << "Do you want to see the country codes of the toys? (yes/no): ";
    cin >> answer;

    if (answer == "yes") {
        for (Toy t : toys) {
            cout << t.getName() << ": " << t.getCountryCode() << endl;
        }
    }

    return 0;
}

