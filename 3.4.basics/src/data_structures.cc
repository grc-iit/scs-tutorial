//
// Created by lukemartinlogan on 7/6/23.
//
#include <cassert>

#include <vector>
void TestVectorConstruct() {
  // An empty vector, no space allocated
  std::vector<int> vec1;
  // A vector of 100 ints, ints can be any value
  std::vector<int> vec2(100);
  // A vector of 100 ints, ints are initialized to 0
  std::vector<int> vec3(100, 0);
  // A vector of 5 ints, initialized to 0, 1, 2, 3, 4
  std::vector<int> vec4{0, 1, 2, 3, 4};
}

#include <vector>
void TestVectorModify() {
  std::vector<int> vec(100);
  // Add element to the back of a vector
  // Size of the vector increases by 1 (now 101)
  vec.emplace_back(2);
  // Insert element at index 1.
  // Size of the vector increases by 1 (now 102)
  vec.emplace(vec.begin() + 1, 1);
  // Modify first element of vector
  // Size of the vector does not change (still 102)
  vec[0] = 1;
}

#include <vector>
void TestVectorAccess() {
  std::vector<int> vec(100);
  // Get first element (operator)
  int val1 = vec[0];
  // Get first element (method)
  int val2 = vec.front();
  // Get first element (iterator)
  std::vector<int>::iterator it3 = vec.begin();
  int val3 = *it3;

  // Get last element (operator)
  int val4 = vec[vec.size() - 1];
  // Get last element (method)
  int val5 = vec.back();
  // Get last element (iterator)
  std::vector<int>::iterator it5 = vec.end() - 1;
  int val6 = *it5;

  // Get element at index 10 (operator)
  int val7 = vec[10];
  // Get element at index 10 (iterator)
  std::vector<int>::iterator it8 = vec.begin() + 10;
  int val8 = *it8;

  // Iterate over all elements of the vector
  for (int &val : vec) {
      // Do something with val
  }
  // Iterate over all elements of the vector
  for (auto it = vec.begin(); it != vec.end(); ++it) {
      int &val = *it;
  }
}

#include <vector>
void TestVectorErase() {
  // Removes the element at index 2 (value 3)
  std::vector<int> vec1{1, 2, 3, 4, 5};
  vec1.erase(vec1.begin() + 2);
  // Removes values 2 through 4
  // Note, erase does NOT erase the value at vec.begin() + 4
  std::vector<int> vec2{1, 2, 3, 4, 5};
  vec2.erase(vec2.begin() + 1, vec2.begin() + 4);
  // Removes all elements from the vector
  std::vector<int> vec3{1, 2, 3, 4, 5};
  vec3.clear();
}

#include <vector>
void TestVectorStatistic() {
  std::vector<int> vec;
  // Initially empty
  assert(vec.size() == 0);
  // Increase to capacity 100
  vec.reserve(100);
  assert(vec.size() == 0);
  assert(vec.capacity() == 100);
  // Add elements to the vector
  // emplace_back is fast since there is capacity
  vec.emplace_back(0);
  vec.emplace_back(1);
  assert(vec.size() == 2);
  // Increase size to 150
  // Capacity is not necessarily equal to 150
  vec.resize(150);
  assert(vec.size() == 150);
  // Resize can be called with a smaller value
  vec.resize(50);
  assert(vec.size() == 50);
}

#include <list>
void TestListConstruct() {
  // An empty list
  std::list<int> list1;
  // A list of 100 ints, ints can be any value
  std::list<int> list2(100);
  // A list of 100 ints, ints are initialized to 0
  std::list<int> list3(100, 0);
  // A list of 5 ints, initialized to 0, 1, 2, 3, 4
  std::list<int> list4{0, 1, 2, 3, 4};
}

#include <list>
#include <iterator>
void TestListModify() {
  // Add element at front of list
  // List becomes 0, 1, 2, 3, 4
  std::list<int> list1{1, 2, 3, 4};
  list1.emplace_front(0);
  // Add element at back of list
  // List becomes 0, 1, 2, 3, 4
  std::list<int> list2{0, 1, 2, 3};
  list2.emplace_back(4);
  // Add element at index 4 in the list
  // List becomes 0, 1, 2, 3, 4, 5
  std::list<int> list3{0, 1, 2, 4, 5};
  list3.emplace(std::next(list3.begin(), 4), 2);
  // Modify element at index 2 in the list
  std::list<int> list4{0, 1, 3, 3, 4};
  std::list<int>::iterator it = std::next(list4.begin(), 2);
  (*it) = 2;
}

void TestListAccess() {
  std::list<int> list{0, 1, 2, 3, 4};
  // Get first element (method)
  int val1 = list.front();
  // Get first element (iterator)
  std::list<int>::iterator it1 = list.begin();
  int val2 = *it1;
  // Get last element (method)
  int val3 = list.back();
  // Get last element (iterator)
  std::list<int>::iterator it2 = list.end();
  int val4 = *(--it2);
  // Get element at index 2 (iterator)
  std::list<int>::iterator it3 = std::next(list.begin(), 2);
  int val5 = *it3;
  // Iterate over all elements in the list
  for (int &val : list) {
      // Do something with val
  }
  // Iterate over all elements in the list
  for (auto it = list.begin(); it != list.end(); ++it) {
      int &val = *it;
  }
}

void TestListErase() {
  // Removes the element at index 2 (value 3)
  std::list<int> list1{1, 2, 3, 4, 5};
  list1.erase(std::next(list1.begin(), 2));
  // Removes values 2 through 4
  // Note, erase does NOT erase the value at vec.begin() + 4
  std::list<int> list2{1, 2, 3, 4, 5};
  list2.erase(std::next(list2.begin(), 1), std::next(list2.begin(), 4));
  // Removes all elements from the list
  std::list<int> list3{1, 2, 3, 4, 5};
  list3.clear();
}

void TestListStatistic() {
  std::list<int> list;
  // Initially empty
  assert(list.size() == 0);
  assert(list.empty());
}

#include <utility>
void TestPairConstruct() {
  // A pair of ints, initialized to 0, 0
  std::pair<int, int> pair1;
  // A pair of ints, initialized to 1, 2
  std::pair<int, int> pair2(1, 2);
  // A pair of ints, initialized to 1, 2
  std::pair<int, int> pair3 = {1, 2};
  // A pair of ints, initialized to 1, 2
  std::pair<int, int> pair4 = std::make_pair(1, 2);
}

void TestPairModify() {
    std::pair<int, int> pair(1, 2);
    pair.first = 3;
    pair.second = 4;
}

#include <unordered_map>
void TestUnorderedMapConstruct() {
  // An empty unordered_map
  std::unordered_map<int, int> map1;
  // An unordered_map with 100 elements
  std::unordered_map<int, int> map2(100);
  // An unordered_map with 5 elements, initialized to 0, 1, 2, 3, 4
  std::unordered_map<int, int> map3{{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};
}

#include <unordered_map>
void TestUnorderedMapModify() {
  // Add a key-value pair to the unordered_map
  std::unordered_map<int, int> map1;
  map1.emplace(0, 0);
  // Modify the value of a key-value pair
  std::unordered_map<int, int> map2{{0, 0}};
  map2[0] = 1;
}

#include <unordered_map>
void TestUnorderedMapAccess() {
  std::unordered_map<int, int> map{{0, 0}, {1, 1}, {2, 2}};
  // Get value associated with key 1 (method)
  int val1 = map.at(1);
  // Get value associated with key 1 (operator[])
  int val2 = map[1];
  // Get value associated with key 1 (iterator)
  std::unordered_map<int, int>::iterator it = map.find(1);
  int val3 = it->second;

  // Iterate over the entire unordered map
  for (const std::pair<int, int> &pair : map) {
    // Do something with the pair
  }
  // Iterate over the entire unordered map
  // auto &[key, value] is a special syntax for std::pair
  for (auto &[key, value] : map) {
    // Do something with the pair
  }
  // Iterate over the entire unordered map
  for (auto it = map.begin(); it != map.end(); ++it) {
      const std::pair<int, int> &pair = *it;
  }
}

#include <unordered_map>
void TestUnorderedMapStatistic() {
  std::unordered_map<int, int> map;
  // Initially empty
  assert(map.size() == 0);
  assert(map.empty());
}

#include <string>
void TestStringConstruct() {
  // An empty string
  std::string str1;
  // A string with 100 'a' characters
  std::string str2(100, 'a');
  // A string with 5 elements, initialized to abcde
  std::string str4 = "abcde";
}

#include <string>
void TestStringAccess() {
  std::string str = "abcde";
  // Get first character (method)
  char val1 = str.front();
  // Get first character (operator[])
  char val2 = str[0];
  // Get last character (method)
  char val3 = str.back();
  // Get last character (operator[])
  char val4 = str[str.size() - 1];
  // Get character at index 2 (operator[])
  char val5 = str[2];
  // Get a c-style string
  const char *c_str = str.c_str();
  const char *c_str2 = str.data();
  char *data = &str[0];
  // Iterate over all characters in the string
  for (char &c : str) {
      // Do something with c
  }
  // Iterate over all characters in the string
  for (auto it = str.begin(); it != str.end(); ++it) {
      char &c = *it;
  }
}

#include <string>
void TestStringModification() {
  std::string str = "abcde";
  // Append a character to the end of the string
  str.push_back('f');
  // Append a string to the end of the string
  str.append("ghijk");
  // Insert a character at index 2
  str.insert(2, "l");
  // Insert a string at index 3
  str.insert(3, "mnopq");
  // Modify the character at index 2
  str[2] = 'r';
  // Resize a string
  std::string str2;
  str2.resize(10);
  // Reserve space for a string
  std::string str3;
  str2.reserve(10);
}

#include <string>
void TestStringConcatenation() {
  std::string str1 = "abc";
  std::string str2 = "def";
  // Concatenate two strings
  std::string str3 = str1 + str2;
  // Concatenate a string and a character
  std::string str4 = str1 + 'g';
  // Concatenate a string and a C-style string
  std::string str5 = str1 + "hij";
  // Concatenate a string and a number
  std::string str6 = str1 + std::to_string(7);
  // Concatenate a string and a number
  std::string str7 = str1 + std::to_string(8.9);
}

#include <string>
void TestStringToNumberConversion() {
  std::string str = "123";
  // Convert a string to an int
  int val1 = std::stoi(str);
  // Convert a string to a long
  long val2 = std::stol(str);
  // Convert a string to a long long
  long long val3 = std::stoll(str);
  // Convert a string to an unsigned long
  unsigned long val4 = std::stoul(str);
  // Convert a string to an unsigned long long
  unsigned long long val5 = std::stoull(str);
  // Convert a string to a float
  float val6 = std::stof(str);
  // Convert a string to a double
  double val7 = std::stod(str);
  // Convert a string to a long double
  long double val8 = std::stold(str);
}

#include <string>
void TestNumberToStringConversion() {
  int val1 = 123;
  long val2 = 123;
  long long val3 = 123;
  unsigned long val4 = 123;
  unsigned long long val5 = 123;
  float val6 = 123.456;
  double val7 = 123.456;
  long double val8 = 123.456;
  // Convert an int to a string
  std::string str1 = std::to_string(val1);
  // Convert a long to a string
  std::string str2 = std::to_string(val2);
  // Convert a long long to a string
  std::string str3 = std::to_string(val3);
  // Convert an unsigned long to a string
  std::string str4 = std::to_string(val4);
  // Convert an unsigned long long to a string
  std::string str5 = std::to_string(val5);
  // Convert a float to a string
  std::string str6 = std::to_string(val6);
  // Convert a double to a string
  std::string str7 = std::to_string(val7);
  // Convert a long double to a string
  std::string str8 = std::to_string(val8);
}

int main() {
  TestVectorConstruct();
  TestVectorAccess();
  TestVectorModify();
  TestVectorErase();
  TestVectorStatistic();
  TestListConstruct();
  TestListAccess();
  TestListModify();
  TestListErase();
  TestListStatistic();
  TestPairConstruct();
  TestPairModify();
  TestUnorderedMapConstruct();
  TestUnorderedMapModify();
  TestUnorderedMapAccess();
  TestUnorderedMapStatistic();
  TestStringConstruct();
  TestStringAccess();
  TestStringModification();
  TestStringConcatenation();
  TestStringToNumberConversion();
  TestNumberToStringConversion();
}