#include<iostream>
#include<list>
using namespace std;
class Isubscriber {
    public:
      virtual void notify(string msg)=0;
};
class User: public Isubscriber {
  int id;
  public:
  User(int id) {
    this->id=id;
  }
  void notify( string msg) {
    cout<<"User "<<id<<" received this message : "<<msg<<endl;
  }
};
class Group {
  private:
    list<Isubscriber*> users;
  public:
    void subscribe(User* user) {
      users.push_back(user);
    }
    void unsubscribe(User* user) {
      users.remove(user);
    }
    void notify(string msg) {
      for(auto user:users) {
        user->notify(msg);
      }
    }
};

int main() {
  Group* group1=new Group();

  User* user1=new User(1);
  User* user2=new User(2);
  User* user3=new User(3);

  group1->subscribe(user1);
  group1->subscribe(user2);
  group1->subscribe(user3);

  group1->notify(" new msg ");
  group1->unsubscribe(user1);
  group1->notify(" new msg after unsubscribing ");
  return 0;

}
