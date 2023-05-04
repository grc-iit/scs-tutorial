#include <iostream>
#include "database_lib.h"

void Database::create() {
  std::cout << file_ << ": in create" << std::endl;
}

void Database::read() {
  std::cout << file_ << ": in read" << std::endl;
}

void Database::update() {
  std::cout << file_ << ": in update" << std::endl;
}

void Database::del() {
  std::cout << file_ << ": in delete" << std::endl;
}
