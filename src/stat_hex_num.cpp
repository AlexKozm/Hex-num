#include "stat_hex_num.h"
#include "hex_num_abstract.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace static_hex;

//-----------------Container-----------------------------------
Container::Container() {
  set_zeros();
  // std::cout << "Static container constructor" << std::endl;
}

Container::~Container(){}

void Container::set_zeros() {
  set_len(stat_len);
  std::fill_n(arr, get_len(), '0');
}

char Container::get(int pos) const {
  if (pos >= get_len()) {
    throw std::overflow_error("Out of index");
  }
  return arr[pos];
}

void Container::set(int pos, char val) {
  if (pos >= get_len() || (pos == get_len() - 1 && char_hex_to_int(val) >= 8)) {
    throw std::overflow_error("Out of index");
  }
  if ((pos == get_len() - 1) && (char_hex_to_int(arr[pos]) >= 8)) {
    arr[pos] = int_hex_to_char(char_hex_to_int(val) + 8);
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
  for (int i = 0; i < get_len() - 1; ++i) {
    cont->set(i, get(i));
  }
  if (Container::char_hex_to_int(get(get_len() - 1)) >= 8) {
    cont->set_minus();
    cont->set(get_len() - 1,
              Container::int_hex_to_char(
                  Container::char_hex_to_int(get(get_len() - 1)) - 8));
  } else {
    cont->set(get_len() - 1, get(get_len() - 1));
  }
  return cont;
}

void Container::set_minus() {
  char val = arr[get_len() - 1];
  if (val < '8') {
    arr[get_len() - 1] += 8;
  } // else it has minus already
};
//-------------------------------------------------------------

Hex_num::Hex_num() : hex_num::Hex_num::Hex_num(new Container) {}
Hex_num::Hex_num(int hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::Hex_num(std::string hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::~Hex_num() {
  delete arr;
  arr = nullptr;
  // std::cout << "Static container destructor" << std::endl;
};
