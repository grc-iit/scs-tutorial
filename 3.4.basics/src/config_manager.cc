//
// Created by lukemartinlogan on 7/7/23.
//

#include <iostream>
#include "easy_singleton.h"

#define CONFIG scs::EasySingleton<ConfigurationManager>::GetInstance()

struct ConfigurationManager {
  int a;
  int b;
};

void func1() {
  // Print 25
  std::cout << CONFIG->a << std::endl;
  // Print 30
  std::cout << CONFIG->b << std::endl;
}

int main() {
  // Config instance will be allocated here
  // Set the "a" entry to 25
  CONFIG->a = 25;
  // Set the "b" entry to 30
  CONFIG->b = 30;
  // Call func1
  func1();
}