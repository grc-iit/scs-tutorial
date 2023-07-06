#include <stdio.h>
#include <stdlib.h>

void create_data() {
  // Create a new file
  FILE* file = fopen("example.txt", "w");
  if (file == NULL) {
    perror("Error creating the file");
    return 1;
  }

  // Write to the file
  std::string data = "Hello, World!\n";
  if (fwrite(data.c_str(), data.size(), 1, file) < 0) {
    perror("Error writing to the file");
    fclose(file);
    return 1;
  }

  fclose(file);
}

void read_data() {
  // Open file for reading
  file = fopen("example.txt", "r");
  if (file == NULL) {
    perror("Error opening the file for reading");
    return 1;
  }

  // Get the size of the file
  fseek(file, 0L, SEEK_END);
  long file_size = ftell(file);
  if (file_size < 0) {
    perror("Error getting file size");
    fclose(file);
    return 1;
  }
  fseek(file, 0L, SEEK_SET);

  // Read the entire file into memory
  std::string data(file_size + 1, '\0');
  if (fread(data.data(), 1, file_size, file) != file_size) {
    perror("Error reading the file");
    fclose(file);
    return 1;
  }
  fclose(file);

  // Print out the data
  std::cout << data << std::endl;
  return 0;
}

int main() {
  create_data();
  read_data();
}