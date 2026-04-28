#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int id, age, semester;
    string name, gender, course;
    float marks, cgpa;

    void input() {
        cout << "\nEnter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Gender: ";
        getline(cin, gender);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Semester: ";
        cin >> semester;

        cout << "Enter Marks: ";
        cin >> marks;

        cout << "Enter CGPA: ";
        cin >> cgpa;
        cin.ignore();
    }

    void display() {
        cout << "\n-----------------------------";
        cout << "\nID        : " << id;
        cout << "\nName      : " << name;
        cout << "\nAge       : " << age;
        cout << "\nGender    : " << gender;
        cout << "\nCourse    : " << course;
        cout << "\nSemester  : " << semester;
        cout << "\nMarks     : " << marks;
        cout << "\nCGPA      : " << cgpa;
        cout << "\n-----------------------------\n";
    }
};

// ADD
void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    s.input();

    file << s.id << endl;
    file << s.name << endl;
    file << s.age << endl;
    file << s.gender << endl;
    file << s.course << endl;
    file << s.semester << endl;
    file << s.marks << endl;
    file << s.cgpa << endl;

    file.close();
    cout << "\nRecord Added Successfully!\n";
}

// DISPLAY
void displayStudents() {
    ifstream file("students.txt");

    if (!file) {
        cout << "\nNo records found!\n";
        return;
    }

    Student s;

    cout << "\n===== STUDENT RECORDS =====\n";

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.gender);
        getline(file, s.course);

        file >> s.semester;
        file >> s.marks;
        file >> s.cgpa;

        file.ignore();

        s.display();
    }

    file.close();
}

// UPDATE
void updateStudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    Student s;
    int id;
    bool found = false;

    cout << "Enter ID to update: ";
    cin >> id;

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.gender);
        getline(file, s.course);

        file >> s.semester;
        file >> s.marks;
        file >> s.cgpa;
        file.ignore();

        if (s.id == id) {
            cout << "\nEnter new details:\n";
            s.input();
            found = true;
        }

        temp << s.id << endl;
        temp << s.name << endl;
        temp << s.age << endl;
        temp << s.gender << endl;
        temp << s.course << endl;
        temp << s.semester << endl;
        temp << s.marks << endl;
        temp << s.cgpa << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nRecord Updated Successfully!\n";
    else
        cout << "\nRecord Not Found!\n";
}

// DELETE
void deleteStudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    Student s;
    int id;
    bool found = false;

    cout << "Enter ID to delete: ";
    cin >> id;

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.gender);
        getline(file, s.course);

        file >> s.semester;
        file >> s.marks;
        file >> s.cgpa;
        file.ignore();

        if (s.id != id) {
            temp << s.id << endl;
            temp << s.name << endl;
            temp << s.age << endl;
            temp << s.gender << endl;
            temp << s.course << endl;
            temp << s.semester << endl;
            temp << s.marks << endl;
            temp << s.cgpa << endl;
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nRecord Deleted Successfully!\n";
    else
        cout << "\nRecord Not Found!\n";
}

// MAIN
int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
