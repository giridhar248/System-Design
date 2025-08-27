#include "logger.hpp"

#include<iostream>
int Logger::countUsers=0;
Logger* Logger::loggerInstance=nullptr;
mutex Logger::mtx;
Logger::Logger() {
  countUsers++;
  cout<<"A new instance has been created ,No Users :"<<countUsers<<endl;
}
void Logger::log(string msg) {
    cout<<msg<<endl;
}
Logger* Logger::getInstance() {
if(loggerInstance==nullptr) {
  mtx.lock();
  if(loggerInstance==nullptr) {
    loggerInstance=new Logger();
  }
  mtx.unlock();
}
  return loggerInstance;
}