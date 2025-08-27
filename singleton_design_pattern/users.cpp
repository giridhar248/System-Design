#include "logger.hpp"
#include<iostream>
#include<thread>
using namespace std;

void user1log() {
  Logger* user1=Logger::getInstance();
  user1->log("this is user1 ");
}
void user2log() {
  Logger* user2=Logger::getInstance();
  user2->log("This is user2 ");
}
int main() {
  thread t1(user1log);
  thread t2(user2log);
  t1.join();
  t2.join();

  return 0;
}