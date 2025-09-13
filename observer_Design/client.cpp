#include<iostream>
using namespace std;
class IButton {
    public:
      virtual void press()=0;
};
class ITextBox {
    public:
    virtual void showText()=0;
};
class MacTextBox: public ITextBox {
    void showText() {
      cout<<"This is the text inside the Mac textBox "<<endl;
    }
};
class WinTextBox: public ITextBox {
    void showText() {
      cout<<"This is the text inside the Win textBox "<<endl;
    }
};
class MacButton:public IButton {
  public:
    void press() {
      cout<<"the button from Mac has been pressed"<<endl;
    }
};
class WinButton:public IButton {
  public:
    void press() {
      cout<<"the button from Windows has been pressed"<<endl;
    }
};
class IFactory {
    public:
    virtual IButton* createButton()=0;
    virtual ITextBox* createTextBox()=0;
};
class MacFactory:public IFactory {
  IButton* createButton() {
    IButton* macbutton=new MacButton();
    return macbutton;
  }
  ITextBox* createTextBox() {
    return new MacTextBox();
  }
};
class WinFactory:public IFactory {
  IButton* createButton() {
    IButton* winbutton=new WinButton();
    return winbutton;
  }
  ITextBox* createTextBox() {
    return new WinTextBox();
  }
};
class GUIabstractFactory {
  public:
    static IFactory* createFactory(string osType) {
      if(osType=="windows") {
        return new WinFactory();
      }
      else  {
        return new MacFactory();
      }
    }
};


int main() {
  cout<<"specify your machine os";
  string osType;
  cin>>osType;
  IFactory* factory=GUIabstractFactory::createFactory(osType);
  IButton* button=factory->createButton();
  button->press();

  ITextBox* testBox=factory->createTextBox();
  testBox->showText();
}