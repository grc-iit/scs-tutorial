#include "timer.h"
#include <iostream>

// Data will be copied to the function
void GetSumByValue(std::string data) {
  int sum = 0;
  for (char &c : data) {
    sum += c;
  }
}

// Data will be passed by reference
void GetSumByReference(std::string &data) {
  int sum = 0;
  for (char &c : data) {
    sum += c;
  }
}

// Data will be passed by reference
void GetSumByConstReference(const std::string &data) {
  int sum = 0;
  for (char &c : data) {
    sum += c;
  }
}

// Data will be moved to the function
void GetSumByMove(std::string &&data) {
  int sum = 0;
  for (char &c : data) {
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
  GetSumByReference(data);
  timer[1].Pause();

  timer[2].Resume();
  GetSumByMove(std::move(data));
  timer[2].Pause();

  std::cout << "By value: " << timer[0].GetUsec() << std::endl;
  std::cout << "By reference: " << timer[1].GetUsec() << std::endl;
  std::cout << "By move: " << timer[2].GetUsec() << std::endl;
}
