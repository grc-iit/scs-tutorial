//
// Created by lukemartinlogan on 7/6/23.
//

#include <iostream>
#include <fstream>
#include <vector>

struct SensorEntry {
  float temp_;
  float co_;
};

int main() {
  std::vector<SensorEntry> data(1440);
  for (int i = 0; i < 1440; ++i) {
    if (i < 600) {
      data[i].temp_ = 85.0f;
      data[i].co_ = 0;
    } else if (i < 650) {
      data[i].temp_ = 85.0f + (i - 600) * 0.5f;
      data[i].co_ = (i - 600) * 200.0f / 25;
    } else {
      data[i].temp_ = 85.0f;
      data[i].co_ = 0.0f;
    }
  }

  std::ofstream out_file("kitchen_fire.bin", std::ios::binary);
  if (out_file.is_open()) {
    out_file.write(reinterpret_cast<char*>(data.data()), data.size() * sizeof(SensorEntry));
    out_file.close();
  } else {
    std::cout << "Error opening the file." << std::endl;
    exit(1);
  }
}