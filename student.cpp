#include <iostream> 
#include <string> 
 
using namespace std; 
 
class Student { 
private: 
    int rollno; 
    string name; 
    int oops, net, com, dbms, ds; 
    double per; 
    char grade; 
    double cgpa; 
 
    void calculateGrade(); 
    void calculateCGPA(); 
 
public: 
    void getData(); 
    void displayData() const; 
    int getRollNumber() const; 
    char getGrade() const; 
    double getPercentage() const; 
    double getCGPA() const; 
}; 
 
void Student::calculateGrade() { 
    per = (oops + net + com + dbms + ds) / 5.0; 
    if (per >= 90) { 
        grade = 'A'; 
    } else if (per >= 80) { 
        grade = 'B'; 
    } else if (per >= 70) { 
        grade = 'C'; 
    } else if (per >= 60) { 
        grade = 'D'; 
    } else if (per >= 50) { 
        grade = 'E'; 
    } else { 
        grade = 'F'; 
    } 
} 
 
void Student::calculateCGPA() { 
    if (per >= 90) { 
        cgpa = 10.0; 
    } else if (per >= 80) { 
        cgpa = 9.0; 
    } else if (per >= 70) { 
        cgpa = 8.0; 
    } else if (per >= 60) { 
        cgpa = 7.0; 
    } else if (per >= 50) { 
        cgpa = 6.0; 
    } else { 
        cgpa = 0.0; 
    } 
} 
 
void Student::getData() { 
    cout << "Enter The roll number of student: "; 
    cin >> rollno; 
    cin.ignore(); 
    cout << "Enter The Name of student: "; 
    getline(cin, name); 
    cout << "Enter The marks in Object Oriented Programming out of 100: "; 
    cin >> oops; 
    cout << "Enter The marks in Computer Network out of 100: "; 
    cin >> net; 
    cout << "Enter The marks in M-commerce out of 100: "; 
    cin >> com; 
    cout << "Enter The marks in Data base Management System out of 100: "; 
    cin >> dbms; 
    cout << "Enter The marks in Data Structure out of 100: "; 
    cin >> ds; 
    calculateGrade(); 
    calculateCGPA(); 
} 
 
void Student::displayData() const { 
    cout << "\nRoll number of student: " << rollno; 
    cout << "\nName of student: " << name; 
    cout << "\nMarks in Object Oriented Programming: " << oops; 
    cout << "\nMarks in Computer Network: " << net; 
    cout << "\nMarks in M-commerce: " << com; 
    cout << "\nMarks in Data Base Management System: " << dbms; 
    cout << "\nMarks in Data Structure: " << ds; 
    cout << "\nPercentage of student is: " << per; 
    cout << "\nGrade of student is: " << grade; 
    cout << "\nCGPA of student is: " << cgpa << endl; 
} 
 
int Student::getRollNumber() const { 
    return rollno; 
} 
 
char Student::getGrade() const { 
    return grade; 
} 
 
double Student::getPercentage() const { 
    return per; 
} 
 
double Student::getCGPA() const { 
    return cgpa; 
} 
 
class StudentDatabase { 
private: 
    static const int MAX_STUDENTS = 100; 
    Student students[MAX_STUDENTS]; 
    int numStudents; 
 
public: 
    StudentDatabase() : numStudents(0) {} 
 
    void addStudent(); 
    void displayAllStudents() const; 
    int findStudentIndex(int rollNumber) const; 
    void displayStudent(int rollNumber) const; 
    void modifyStudent(int rollNumber); 
    void deleteStudent(int rollNumber); 
    void displayClassReport() const; 
}; 
 
void StudentDatabase::addStudent() { 
    if (numStudents < MAX_STUDENTS) { 
        students[numStudents].getData(); 
        numStudents++; 
        cout << "\n\nStudent record has been added."; 
    } else { 
        cout << "\n\nStudent database is full. Cannot add more students."; 
    } 
} 
 
void StudentDatabase::displayAllStudents() const { 
    for (int i = 0; i < numStudents; ++i) { 
        students[i].displayData(); 
        cout << "\n\n====================================\n"; 
    } 
} 
 
int StudentDatabase::findStudentIndex(int rollNumber) const { 
    for (int i = 0; i < numStudents; ++i) { 
        if (students[i].getRollNumber() == rollNumber) { 
            return i; 
        } 
    } 
    return -1;  // Student not found 
} 
 
void StudentDatabase::displayStudent(int rollNumber) const { 
    int index = findStudentIndex(rollNumber); 
    if (index != -1) { 
        students[index].displayData(); 
    } else { 
        cout << "\n\nRecord not found."; 
    } 
} 
 
void StudentDatabase::modifyStudent(int rollNumber) { 
    int index = findStudentIndex(rollNumber); 
    if (index != -1) { 
        students[index].getData(); 
        cout << "\n\nRecord updated."; 
    } else { 
        cout << "\n\nRecord not found."; 
    } 
} 
 
void StudentDatabase::deleteStudent(int rollNumber) { 
    int index = findStudentIndex(rollNumber); 
    if (index != -1) { 
        for (int i = index; i < numStudents - 1; ++i) { 
            students[i] = students[i + 1]; 
        } 
        numStudents--; 
        cout << "\n\nRecord deleted."; 
    } else { 
        cout << "\n\nRecord not found."; 
    } 
} 
 
void StudentDatabase::displayClassReport() const { 
    int totalStudents = numStudents; 
    int numA = 0, numB = 0, numC = 0, numF = 0; 
    double totalPercentage = 0; 
 
    for (int i = 0; i < numStudents; ++i) { 
        totalPercentage += students[i].getPercentage(); 
 
        if (students[i].getGrade() == 'A') { 
            numA++; 
        } else if (students[i].getGrade() == 'B') { 
            numB++; 
        } else if (students[i].getGrade() == 'C') { 
            numC++; 
        } else { 
            numF++; 
        } 
    } 
 
    cout << "\n\n\tClass Report"; 
    cout << "\n\n\tTotal Number of Students: " << totalStudents; 
    cout << "\n\tAverage Percentage: " << (totalPercentage / totalStudents); 
    cout << "\n\tNumber of Students with Grade A: " << numA; 
    cout << "\n\tNumber of Students with Grade B: " << numB; 
    cout << "\n\tNumber of Students with Grade C: " << numC; 
    cout << "\n\tNumber of Students with Grade F: " << numF; 
} 
 
int main() { 
    StudentDatabase database; 
    char ch; 
 
    do { 
        cout << "\n\n\n\tMAIN MENU"; 
        cout << "\n\n\t1. Result Menu"; 
        cout << "\n\n\t2. Entry/Edit Menu"; 
        cout << "\n\n\t3. Exit"; 
        cout << "\n\n\tPlease Select Your Option (1-3): "; 
        cin >> ch; 
 
        switch (ch) { 
            case '1': { 
                char resultChoice; 
                do { 
                    cout << "\n\n\n\tRESULT MENU"; 
                    cout << "\n\n\t1. Class Report"; 
                    cout << "\n\n\t2. Student Report"; 
                    cout << "\n\n\t3. Back to Main Menu"; 
                    cout << "\n\n\tPlease Select Your Option (1-3): "; 
                    cin >> resultChoice; 
 
                    switch (resultChoice) { 
                        case '1': 
                            database.displayClassReport(); 
                            break; 
                        case '2': { 
                            int rollNumber; 
                            cout << "\n\n\tEnter Roll Number Of Student: "; 
                            cin >> rollNumber; 
                            database.displayStudent(rollNumber); 
                            break; 
                        } 
                        case '3': 
                            break; 
                        default: 
                            cout << "\a"; 
                    } 
 
                } while (resultChoice != '3'); 
                break; 
            } 
            case '2': { 
                char entryChoice; 
                do { 
                    cout << "\n\n\n\tENTRY/EDIT MENU"; 
                    cout << "\n\n\t1. Create Student Record"; 
                    cout << "\n\n\t2. Display All Students Records"; 
                    cout << "\n\n\t3. Search Student Record"; 
                    cout << "\n\n\t4. Modify Student Record"; 
                    cout << "\n\n\t5. Delete Student Record"; 
                    cout << "\n\n\t6. Back to Main Menu"; 
                    cout << "\n\n\tPlease Enter Your Choice (1-6): "; 
                    cin >> entryChoice; 
 
                    switch (entryChoice) { 
                        case '1': 
                            database.addStudent(); 
                            break; 
                        case '2': 
                            database.displayAllStudents(); 
                            break; 
                        case '3': { 
                            int rollNumber; 
                            cout << "\n\n\tPlease Enter The Roll Number: "; 
                            cin >> rollNumber; 
                            database.displayStudent(rollNumber); 
                            break; 
                        } 
                        case '4': { 
                            int rollNumber; 
                            cout << "\n\n\tPlease Enter The Roll Number: "; 
                            cin >> rollNumber; 
                            database.modifyStudent(rollNumber); 
                            break; 
                        } 
                        case '5': { 
                            int rollNumber; 
                            cout << "\n\n\tPlease Enter The Roll Number: "; 
                            cin >> rollNumber; 
                            database.deleteStudent(rollNumber); 
                            break; 
                        } 
                        case '6': 
                            break; 
                        default: 
                            cout << "\a"; 
                    } 
 
                } while (entryChoice != '6'); 
                break; 
            } 
            case '3': 
                break; 
            default: 
                cout << "\a"; 
        } 
 
    } while (ch != '3'); 
 
    return 0; 
} 
