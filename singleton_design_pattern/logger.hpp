#pragma once
#include<mutex>
#include<iostream>
using namespace std;
class Logger {
  static mutex mtx;
  static int countUsers;
  static Logger* loggerInstance;
  Logger();
  public:
  static Logger* getInstance();
    void log(string msg);
};