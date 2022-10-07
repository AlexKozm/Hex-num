#include "stat_hex_num.h"
#include "hex_num_abstract.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace static_hex;

//-----------------Container-----------------------------------
Container::Container() {
  set_len(stat_len);
  set_zeros();
  // std::cout << "Static container constructor" << std::endl;
}


Container::Container(Container &that) {
  set_len(that.get_len());
  for (int i = 0; i < get_len(); ++i) {
    arr[i] = that.arr[i];
  }
}

Container::~Container() {}

void Container::set_zeros() {
  std::fill_n(arr, get_len(), '0');
}

char Container::get(int pos) const {
  if (pos >= get_len()) {
    throw std::overflow_error("Out of index");
  }
  return arr[pos];
}

char Container::weak_get(int pos, char def) const {
  if (pos < get_len() - 1) {
    return arr[pos];
  } else if (pos == get_len() - 1) {
    int val = char_to_int(arr[pos]);
    if (val >= 8) {
      return int_to_char(val - 8);
    } else {
      return val;
    }
  } else if (pos >= get_len()) {
    return def;
  }
  return arr[pos];
}

void Container::set(int pos, char val) {
  if (pos >= get_len() || (pos == get_len() - 1 && char_to_int(val) >= 8)) {
    throw std::overflow_error("Out of index");
  }
  if ((pos == get_len() - 1) && (char_to_int(arr[pos]) >= 8)) {
    arr[pos] = int_to_char(char_to_int(val) + 8);
  } else {
    arr[pos] = val;
  }
}

void Container::force_set(int pos, char val) {
  if (pos >= get_len()) {
    throw std::overflow_error("Out of index");
  }
  arr[pos] = val;
}

hex_num::Container *Container::get_new() const { return new Container; }
hex_num::Container *Container::get_copy() const {
  Container *cont = new Container;
  cont->set_len(get_len());
  for (int i = 0; i < get_len(); ++i) {
    cont->arr[i] = arr[i];
  }
  return cont;
}

void Container::set_minus() {
  char val = arr[get_len() - 1];
  if (val < '8') {
    arr[get_len() - 1] += 8;
  } // else it has minus already
};

void Container::unset_minus(){};

bool Container::get_sign() const {
  if (char_to_int(arr[get_len() - 1]) >= 8) {
    return 1;
  } else {
    return 0;
  }
}
//-------------------------------------------------------------

Hex_num::Hex_num() : hex_num::Hex_num::Hex_num(new Container) {}
Hex_num::Hex_num(int hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::Hex_num(std::string hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::~Hex_num() {
  delete arr;
  arr = nullptr;
  // std::cout << "Static container destructor" << std::endl;
};
