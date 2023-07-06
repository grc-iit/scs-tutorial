#include "timer.h"
#include <iostream>

// Data will be copied to the function
// This can be expensive for large objects
void GetSumByValue(std::string data) {
  int sum = 0;
  for (const char &c : data) {
    sum += c;
  }
}

// Data will be passed by reference
// This is more efficient than passing by value
// data can be modified by the function
void GetSumByLvalReference(std::string &data) {
  int sum = 0;
  for (const char &c : data) {
    sum += c;
  }
}

// Data will be passed by reference
// Same as above, but data cannot be modified by the function
void GetSumByConstReference(const std::string &data) {
  int sum = 0;
  for (const char &c : data) {
    sum += c;
  }
}

// Data will be moved to the function without copying
// The original data object is no longer valid after this function
// NOTE: && is a single operator, not two ampersands.
void GetSumByRvalReference(std::string &&data) {
  int sum = 0;
  for (const char &c : data) {
    sum += c;
  }
}

int main() {
  // Create a string of 16 MB
  std::string data(16 * (1 << 20), 'a');
  Timer timer[3];

  timer[0].Resume();
  GetSumByValue(data);
  timer[0].Pause();

  timer[1].Resume();
  GetSumByLvalReference(data);
  timer[1].Pause();

  timer[2].Resume();
  GetSumByRvalReference(std::move(data));
  timer[2].Pause();

  std::cout << "By value: " << timer[0].GetUsec() << std::endl;
  std::cout << "By lval reference: " << timer[1].GetUsec() << std::endl;
  std::cout << "By rval reference: " << timer[2].GetUsec() << std::endl;
}
