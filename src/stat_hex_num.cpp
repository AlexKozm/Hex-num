#include "stat_hex_num.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "hex_num_abstract.h"
#include <string>

using namespace static_hex;

Container::Container() {
  set_len(stat_len);
  std::fill_n(arr, get_len(), '0');
}

char Container::get(int pos) {
  // if (pos == get_len() - 1 && int_hex arr[get_len() - 1] ) {
    
  // }
  if (pos >= get_len()) {
    throw std::overflow_error("Out of index");
  }
  return arr[pos];
}

void Container::set(int pos, char val) {
  if (pos >= get_len()) {
    throw std::overflow_error("Out of index");
  }
  arr[pos] = val; 
}
void Container::set_minus() {
  if (arr[get_len() - 1] < '8') {
    arr[get_len() - 1] += 8;
  }
};
void Container::unset_minus() {};
hex_num::Container *Container::get_new() {}

Hex_num::Hex_num() : hex_num::Hex_num::Hex_num(new Container) {}
Hex_num::Hex_num(int hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::Hex_num(std::string hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::~Hex_num() {
  free(arr);
};

// char Hex_num::get(int pos) {
//   return arr->get(pos);
// }
