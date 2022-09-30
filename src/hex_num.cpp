#include "hex_num.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

hex_num::Hex_num::Hex_num(hex_num::Container *arr) : arr(arr) {}
hex_num::Hex_num::Hex_num(hex_num::Container *arr, int hex) : arr(arr) {}
hex_num::Hex_num::Hex_num(hex_num::Container *arr, std::string hex) : arr(arr) {}

using namespace static_hex;

Container::Container() {
  std::fill_n(arr, len, '0');
}

char Container::get(int pos) {
  if (pos >= len) {
    throw std::overflow_error("Out of index");
  }
  return arr[pos];
}

void Container::set(int pos, char val) { arr[pos] = val; }

Hex_num::Hex_num() : hex_num::Hex_num::Hex_num(new Container()) {}
Hex_num::Hex_num(int hex) : hex_num::Hex_num(new Container) {}
Hex_num::Hex_num(std::string hex) : hex_num::Hex_num(new Container) {}
// hex_num::Hex_num::~Hex_num() {};

// char Hex_num::get(int pos) {
//   return arr->get(pos);
// }
