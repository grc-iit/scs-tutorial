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

int DetermineStart(const std::vector<SensorEntry> &data) {
  for (size_t i = 0; i < data.size(); ++i) {
    if (data[i].co_ > 200.0f) {
      return i;
    }
    if (data[i].temp_ > 95.0f) {
      return i;
    }
  }
  return data.size();
}

int DetermineEnd(int start, const std::vector<SensorEntry> &data) {
  for (size_t i = start; i < data.size(); ++i) {
    if (data[i].co_ < 200.0f && data[i].temp_ < 95.0f) {
      return i;
    }
  }
  return data.size();
}

void FireStats(const std::vector<SensorEntry> &data,
               int start, int end,
               float &avg_temp, float &avg_co) {
  avg_temp = 0;
  avg_co = 0;
  for (int i = start; i < end; ++i) {
    avg_temp += data[i].temp_;
    avg_co += data[i].co_;
  }
  int time = (end - start);
  avg_temp /= time;
  avg_co /= time;
}

int main() {
  // Read kitchen fire dataset into memory
  std::vector<SensorEntry> data(1440);
  std::ifstream in_file("kitchen_fire.bin", std::ios::binary);
  if (in_file.is_open()) {
      in_file.read(reinterpret_cast<char*>(data.data()), data.size() * sizeof(SensorEntry));
      in_file.close();
  } else {
      std::cout << "Error opening the file." << std::endl;
      exit(1);
  }

  // Determine start and end of fire
  int start = DetermineStart(data);
  int end = DetermineEnd(start, data);

  // Determine the avg temperature & CO of the fire
  float avg_temp, avg_co;
  FireStats(data, start, end, avg_temp, avg_co);

  // Print out the results
  std::cout << "Start of fire: " << start << std::endl;
  std::cout << "End of fire: " << end << std::endl;
  std::cout << "Average temperature: " << avg_temp << std::endl;
  std::cout << "Average CO: " << avg_co << std::endl;
}