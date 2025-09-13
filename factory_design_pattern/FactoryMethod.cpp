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
class BasicWheatBurger:public Burger {
  void prepare() {
    cout<<"Preparing Basic Wheat Burger"<<endl;
  }
};
class StandardWheatBurger:public Burger {
  void prepare() {
    cout<<"Preparing Standard Wheat Burger"<<endl;
  }
};
class PremiumWheatBurger:public Burger {
  void prepare() {
    cout<<"Preparing Premium Wheat Burger"<<endl;
  }
};

class BurgerFactory {
  public:
    virtual Burger* CreateBurger(string& type)=0;
    virtual ~BurgerFactory(){};
};
class KingBurger:public BurgerFactory {
  public:
    Burger* CreateBurger(string& type) {
      if(type=="Basic") {
        return new BasicWheatBurger();
      }
      else if(type=="Standard") {
        return new StandardWheatBurger();
      }
      else if(type=="Premium") {
        return new PremiumWheatBurger();
      }
      else {
        cout<<"Invalid Burger type!"<<endl;
        return nullptr;
      }
    }
  
};
class SinghBurger:public BurgerFactory {
  public:
    Burger* CreateBurger(string& type) {
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
  BurgerFactory* burgerFactory=new KingBurger();
  Burger* burger=burgerFactory->CreateBurger(type);
  burger->prepare();
  return 0;
  
}