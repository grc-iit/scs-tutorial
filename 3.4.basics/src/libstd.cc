#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void create_data() {
  // Write to a file using ofstream
  std::ofstream out_file("example.txt");
  if (out_file.is_open()) {
    out_file << "Hello, World!" << std::endl;
    out_file.close();
  } else {
    std::cout << "Error opening the file." << std::endl;
    exit(1);
  }
}

void read_data() {
  // Get the size of the file
  size_t file_size = std::filesystem::file_size("example.txt");

  // Read from the file using ifstream
  std::ifstream in_file("example.txt");
  if (in_file.is_open()) {
    std::string data(file_size, '\0');
    // Read the entire file into data string
    in_file.read(data.data(), file_size);
    in_file.close();
    // Print out the data
    std::cout << data << std::endl;
  } else {
    std::cout << "Error opening the file." << std::endl;
    exit(1);
  }
}

int main() {
  create_data();
  read_data();
}