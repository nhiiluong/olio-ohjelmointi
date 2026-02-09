#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
    private:
    string name;
    int age;

    public:
    Student();
    Student(string name , int age);

    string getName() const;
    int getAge()const;

    void PrintStudentInfo()const;

};


#endif
