#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using strVector = std::vector<std::string>;

std::vector<std::string> split(const std::string &str, char d);

void readAllPool(std::vector<strVector> &pool);

void writeAllPool(std::vector<strVector> &pool);

void writeIpToConsole(strVector& tmp);

void filter(uint8_t firstByte, std::vector<strVector> &pool);

void filter(uint8_t firstByte, uint8_t secondByte, std::vector<strVector> &pool);

void filterAny(uint8_t anyByte, std::vector<strVector> &pool);

void reverseIpSort(std::vector<strVector> &pool);

