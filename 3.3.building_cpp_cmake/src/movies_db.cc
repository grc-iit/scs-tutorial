#include "database_lib.h"

int main() {
  Database db("movies");
  db.create();
  db.read();
  db.update();
  db.del();
}
