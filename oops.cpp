#include<iostream>
#include<string>
using namespace std;

class Person {
  public:
  int age;
  string name;
  Person() {
    cout<<"Parent constructor is Called "<<endl;
  }
  Person(int age,string name) {
    this->age=age;
    this->name=name;
  }
  void getInfo() {
    cout<<"Age :"<<age<<endl;
    cout<<"Name :"<<name<<endl;
  }
};
class Student:public Person {
  public:
    int rollNo;
    double cgpa;
  Student() {
    cout<<"Student constructor called"<<endl;
  }
  Student(int age,string name,int rollNo,double cgpa):Person(age,name) {
    this->rollNo=rollNo;
    this->cgpa=cgpa;
  }
  void getInfo() {
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"RollNo: "<<rollNo<<endl;
    cout<<"cgpa: "<<cgpa<<endl;
  }
  
};

int main() {
  Student s1(22,"Giridhar",24,4.0);
  s1.getInfo();
}
