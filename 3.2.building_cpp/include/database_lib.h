#ifndef DATABASE_LIB_H
#define DATABASE_LIB_H

#include <string>

class Database {
 public:
  std::string file_;

  Database(const std::string &file) : file_(file) {}

  void create();
  void read();
  void update();
  void del();
};

#endif