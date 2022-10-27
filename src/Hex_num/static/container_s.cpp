#include "hex_num_s.h"
#include "Hex_num/base/hex_num.h"
#include "container_s.h"
// #include <algorithm>
// #include <iostream>
// #include <stdexcept>
// #include <string>

typedef static_hex::Container Container;
typedef static_hex::Hex_num Hex_num;

//-----------------Container-----------------------------------
Container::Container() {
  set_len(stat_len);
  set_zeros();
  // std::cout << "Static container constructor" << std::endl;
}


Container::Container(const Container &that) {
  set_len(that.get_len());
  for (int i = 0; i < get_len(); ++i) {
    arr[i] = that.arr[i];
  }
}

Container::~Container() {}

void Container::set_zeros() {
  std::fill_n(arr, get_len(), '0');
}

char Container::get_val(int pos, char def) const {
  if (pos < get_len()) {
    return arr[pos];
  } else {
    return def;
  }
}

char Container::get_digit(int pos, char def) const {
  if (pos < get_len() - 1) {
    return arr[pos];
  } else if (pos == get_len() - 1) {
    int val = char_to_int(arr[pos]);
    if (val >= 8) {
      return int_to_char(val - 8);
    } else {
      return int_to_char(val);
    }
  } else if (pos >= get_len()) {
    return def;
  }
  return arr[pos];
}

void Container::set_digit(int pos, char val) {
  if (pos >= get_len() || (pos == get_len() - 1 && char_to_int(val) >= 8)) {
    throw std::overflow_error("Out of index");
  }
  // TODO may be err: should be < 8 
  if ((pos == get_len() - 1) && (char_to_int(arr[pos]) >= 8)) {
    arr[pos] = int_to_char(char_to_int(val) + 8);
  } else {
    arr[pos] = val;
  }
}

void Container::set_val(int pos, char val) {
  if (pos < get_len()) {
    arr[pos] = val;
  }
}

hex_num::Container *Container::get_new() const { return new Container; }
hex_num::Container *Container::get_copy() const {
  return new Container(*this);
}

void Container::set_minus() {
  int val = char_to_int(arr[get_len() - 1]);
  if (val < 8) {
    arr[get_len() - 1] = int_to_char(val + 8);
  } // else it has minus already
};

void Container::unset_minus(){
  int val = char_to_int(arr[get_len() - 1]);
  if (val >= 8) {
    arr[get_len() - 1] = int_to_char(val - 8);
  } // else it has not minus already
};

bool Container::get_sign() const {
  if (char_to_int(arr[get_len() - 1]) >= 8) {
    return 1;
  } else {
    return 0;
  }
}

