#include<iostream>
#include<mutex>
using namespace std;

class Singleton {
  private:
    static Singleton* Instance;
   // static mutex mtx;
    Singleton() {
        cout<<"A new Object has been created"<<endl;
    }
  public:
    static Singleton* getInstance() {
     /* if(Instance==nullptr) {
        lock_guard<mutex> lock(mtx);
        if(Instance==nullptr) Instance = new Singleton();
      } */
      return Instance;
    }
};
Singleton* Singleton::Instance=new Singleton(); 
//mutex Singleton::mtx;                       

int main() {
  Singleton* obj1 = Singleton::getInstance();
  Singleton* obj2 = Singleton::getInstance();

    cout << "Address of obj1: " << obj1 << endl;
    cout << "Address of obj2: " << obj2 << endl;

    cout << boolalpha << "Are they the same object? " << (obj1 == obj2) << endl;
    return 0;

}