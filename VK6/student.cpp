#include "Student.h"
#include <iostream>

Student::Student() : name(""),age(0)
{
}
Student::Student(std::string name,int age): name(name),age(age)
{
}
string Student::getName()const {
    return name;
}

int Student::getAge()const
{
    return age;
}

void Student::PrintStudentInfo()const{
    cout << "Name: " << name << ", Age:" << age << endl;
}
