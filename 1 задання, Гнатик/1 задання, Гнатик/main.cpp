#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Talon {
public:
    string subject;
    int score;
    string instructor;
};

class Student {
public:
    string name;
    string group;
    vector<Talon> talons;
};

vector<Student> readData(string filename) {
    vector<Student> students;
    ifstream input("/Users/solomia/Desktop/1 задання, Гнатик/1 задання, Гнатик/file.txt");
    if (!input) {
        cout << "Помилка відкриття файлу " << filename << endl;
        return students;
    }

    string line;
    while (getline(input, line)) {
        Student student;
        student.name = line;
        getline(input, student.group);

        int num_talons;
        input >> num_talons;
        input.ignore(); // ignore newline character

        for (int i = 0; i < 4; i++) {
            Talon talon;
            getline(input, talon.subject);
            input >> talon.score;
            input.ignore(); // ignore newline character
            getline(input, talon.instructor);
            
            student.talons.push_back(talon);
        }
        if (student.talons.size() > 1) {
            students.push_back(student);
        }
    }
    return students;
}

int main() {
    vector<Student> students = readData("/Users/solomia/Desktop/1 задання, Гнатик/1 задання, Гнатик/file.txt");
    
    // Виведення списку студентів, які мають більше одного талону
    for (const auto& student : students) {
        if (student.talons.size() > 1) {
            cout << "Студент: " << student.name << endl;
            cout << "Група: " << student.group << endl;
            cout << "Кількість талонів: " << student.talons.size() << endl;
            for (const auto& talon : student.talons) {
                cout << "Предмет: " << talon.subject << endl;
                cout << "Бали: " << talon.score << endl;
                cout << "Викладач: " << talon.instructor << endl;
            }
            cout << endl;
        }
        return 0;
    }
    
}



