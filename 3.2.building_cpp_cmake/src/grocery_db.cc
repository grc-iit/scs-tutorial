#include "database_lib.h"

int main() {
  Database db("grocery");
  db.create();
  db.read();
  db.update();
  db.del();
}
