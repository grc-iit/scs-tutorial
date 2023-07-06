#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void create_data() {
  // Create a new file
  int out_fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
  if (out_fd == -1) {
    perror("Error creating the file");
    return 1;
  }

  // Write to the file
  std::string data = "Hello, World!\n";
  ssize_t bytes_written = write(out_fd, data.c_str(), data.size());
  if (bytes_written < 0) {
    perror("Error writing to the file");
    close(out_fd);
    return 1;
  }
  close(out_fd);
}

void read_data() {
  // Get the size of the file
  struct stat st;
  if (stat("example.txt", &st) == -1) {
    perror("Error getting file size");
    return 1;
  }
  off_t file_size = st.st_size;

  // Open the file in read-only mode
  out_fd = open("example.txt", O_RDONLY);
  if (out_fd == -1) {
    perror("Error opening the file for reading");
    return 1;
  }

  // Read the entire file into memory
  std::string data(file_size + 1, '\0');  // NOTE: +1 for null-terminator
  ssize_t bytes_read = read(out_fd, data.data(), file_size);
  if (bytes_read < 0) {
    perror("Error reading the file");
    close(out_fd);
    return 1;
  }
  close(out_fd);

  // Print the data
  std::cout << data << std::endl;
}

int main() {
  create_data();
  read_data();
}