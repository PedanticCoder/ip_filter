#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using strVectIP = std::vector<std::string>;
using intVectIP = std::vector<int>;

std::vector<std::string> split(const std::string &str, char d);

std::vector<intVectIP> initializeIpPoolInt(std::vector<strVectIP> &pool);

void readAllPool(std::vector<strVectIP> &pool);

void writeAllPool(std::vector<strVectIP> &pool);

void writeAllPoolIP(std::vector<intVectIP> &pool);

void writeIpToConsole(intVectIP& tmp);

void filterAny(uint8_t anyByte, std::vector<intVectIP> &pool);

void reverseIpSort(std::vector<intVectIP> &pool);

void filterModified(intVectIP &partIp, std::vector<intVectIP> &pool);

