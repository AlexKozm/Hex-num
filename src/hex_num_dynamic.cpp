#include "hex_num_dynamic.h"
#include "vector"
#include <vector>

using namespace hex_num_dynamic;

void print_vect(vector<char> vec) {
  for (int i = 0; i < vec.size(); ++i) {
    cout << vec[i]<< "; ";
  }
  cout<< endl;
}

//-----------------Container-----------------------------------
Container::Container() {
  set_len(def_len);
  set_zeros();
  // std::cout << "Static container constructor" << std::endl;
}

Container::Container(const Container &that) {
  set_len(that.get_len());
  arr.resize(that.get_len());
  for (int i = 0; i < get_len(); ++i) {
    arr[i] = that.arr[i];
  }
}

Container::~Container() {}

void Container::set_zeros() {
  for (int i = 0; i < get_len(); ++i) {
    arr[i] = '0';
  }
}

char Container::get(int pos, char def) const {
  if (pos < get_len()) {
    return arr[pos];
  } else {
    return def;
  }
}

char Container::weak_get(int pos, char def) const {
  if (pos == get_len() - 1) {
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

void Container::set(int pos, char val) {
  // cout << "set" << endl;
  // cout << (int) arr[pos] << " || " << get(pos, '0') << "; val: " << val << endl;
  // cout << "At the begining of set: ";
  // print_vect(arr);
  // cout << "pos: " << pos << "; len: " << get_len() << endl;
  if (pos >= get_len() || (pos == get_len() - 1 && char_to_int(val) >= 8)) {
    // throw std::overflow_error("Out of index");
    // cout << "resizing: size = "<< arr.size() << "; new size = " << pos + 1 << endl;
    bool sgn = get_sign();
    unset_minus();
    arr.resize(pos + 2);
    arr[pos + 1] = '0';
    set_len(pos + 2);
    if (sgn) {
      // cout << "In if" << endl;
      set_minus();
      // cout << "In if 1" << endl;
    } else {
      unset_minus();
    }
  }
  // cout << "Before if: " << (pos == get_len() - 1) << "; " << get(pos, '0') << endl;
  if ((pos == get_len() - 1) && (get_sign() == 1)) {
    // cout << "resizing for minus" << endl;
    arr.resize(pos + 2);
    arr[pos + 1] = '0';
    set_len(pos + 2);
    set_minus();
  }
  arr[pos] = val;
  // cout << "At the end of set: ";
  // print_vect(arr);
  // cout << "Done" << endl;
}

void Container::force_set(int pos, char val) {
  if (pos >= get_len()) {
    // throw std::overflow_error("Out of index");
    arr.resize(pos + 2);
    arr[pos + 1] = '0';
    set_len(pos + 2);
  }
  arr[pos] = val;
}

hex_num::Container *Container::get_new() const { return new Container; }
hex_num::Container *Container::get_copy() const {
  // Container *cont = new Container;
  // cont->set_len(get_len());
  // for (int i = 0; i < get_len(); ++i) {
  //   cont->arr[i] = arr[i];
  // }
  // return cont;
  return new Container(*this);
}

void Container::set_minus() {
  // cout << "len: "<< get_len() << "; set_minus: " << (int) get(get_len() - 1) << endl;
  int val = char_to_int(get(get_len() - 1));
  if (val < 8) {
    arr[get_len() - 1] = int_to_char(val + 8);
  } // else it has minus already
};

void Container::unset_minus() {
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
//-------------------------------------------------------------

Hex_num::Hex_num() : hex_num::Hex_num::Hex_num(new Container) {}
Hex_num::Hex_num(int hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::Hex_num(std::string hex) : hex_num::Hex_num(new Container, hex) {}
Hex_num::Hex_num(const hex_num::Hex_num &that) : hex_num::Hex_num(that){};
Hex_num::~Hex_num() {
  delete arr;
  arr = nullptr;
  // std::cout << "Static container destructor" << std::endl;
};
