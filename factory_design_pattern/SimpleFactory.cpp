#include<iostream>
using namespace std;

class Burger {
  public:
  virtual void prepare()=0;
  virtual ~Burger() {}
};

class BasicBurger:public Burger {
  void prepare() {
    cout<<"Preparing Basic Burger"<<endl;
  }
};
class StandardBurger:public Burger {
  void prepare() {
    cout<<"Preparing Standard Burger"<<endl;
  }
};
class PremiumBurger:public Burger {
  void prepare() {
    cout<<"Preparing Premium Burger"<<endl;
  }
};
class BurgerFactory {
  public:
    Burger* createBurger(string& type) {
      if(type=="Basic") {
        return new BasicBurger();
      }
      else if(type=="Standard") {
        return new StandardBurger();
      }
      else if(type=="Premium") {
        return new PremiumBurger();
      }
      else {
        cout<<"Invalid Burger type!"<<endl;
        return nullptr;
      }
    }
};
int main() {
  string type="Standard";
  BurgerFactory* burgerFactory=new BurgerFactory();
  Burger* burger=burgerFactory->createBurger(type);
  burger->prepare();
  return 0;
}