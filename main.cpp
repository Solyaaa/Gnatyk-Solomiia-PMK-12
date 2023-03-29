#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;
class Triangle {
public:
    double a, b, c;

    Triangle(double a = 0, double b = 0, double c = 0) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
     double getArea() const {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
     double getPerimeter() const {
        return a + b + c;
    }
};

   // функція для зчитування трикутників з файлу у динамічний масив
    Triangle* readTrianglesFromFile(const string& fileName, int& count) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout<< "Error: Could not open file " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    file >> count;
     Triangle* triangles = new Triangle[count];
     // зчитуємо дані про трикутники з файлу
    for (int i = 0; i < count; i++) {
        double a, b, c;
        file >> a >> b >> c;
        triangles[i] = Triangle(a, b, c);
    }

    file.close();
    return triangles;
}

//  сортування масиву трикутників за площею
void sortTrianglesByArea(Triangle* triangles, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (triangles[i].getArea() > triangles[j].getArea()) {
                swap(triangles[i], triangles[j]);
            }
        }
    }
}

// функція за периметром
Triangle* filterTrianglesByPerimeter(Triangle* triangles, int count, double minPerimeter, double maxPerimeter, int& newCount) {
    Triangle* filteredTriangles = new Triangle[count]; //динамічний
    newCount = 0;

    for (int i = 0; i < count; i++) {
        double perimeter = triangles[i].getPerimeter();
        if (perimeter >= minPerimeter && perimeter <= maxPerimeter) {
            filteredTriangles[newCount] = triangles[i];
            newCount++;
        }
    }

    return filteredTriangles;
}

void writeTrianglesToFile(const string& fileName, Triangle* triangles, int count) {
ofstream file(fileName);
if (!file.is_open()) {
cout << "Error: Could not open file " << fileName << endl;
exit(EXIT_FAILURE);
}

file << count << endl;
// записуємо дані про трикутники у файл
for (int i = 0; i < count; i++) {
    file << triangles[i].a << " " << triangles[i].b << " " << triangles[i].c << endl;
}
    file.close();
    }

    int main() {
    int count;
    Triangle* triangles = readTrianglesFromFile("/Users/solomia/Desktop/list/list/input.txt", count);
    sortTrianglesByArea(triangles, count);
    int newCount;
    Triangle* filteredTriangles = filterTrianglesByPerimeter(triangles, count, 10, 20, newCount);
   writeTrianglesToFile("/Users/solomia/Desktop/list/list/output.txt", filteredTriangles, newCount);
        delete[] triangles;
        delete[] filteredTriangles;

        return 0;
        }
