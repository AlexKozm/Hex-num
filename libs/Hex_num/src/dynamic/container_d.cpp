#include "container_d.h"

namespace hex_num_dynamic {

//-----------------Container-----------------------------------
Container::Container() {
  set_len(def_len);
  set_zeros();
}

Container::Container(const Container &that) {
  set_len(that.get_len());
  arr.resize(that.get_len());
  for (int i = 0; i < get_len(); ++i) {
    arr[i] = that.arr[i];
  }
}

Container::Container(Container &&that) {
  set_len(that.get_len());
  std::swap(arr, that.arr);
}


Container &Container::operator=(const Container &that) {
  set_len(that.get_len());
  arr = that.arr;
  return *this;
}

Container &Container::operator=(Container &&that) {
  set_len(that.get_len());
  std::swap(arr, that.arr);
  return *this;
}

void Container::set_zeros() {
  for (int i = 0; i < get_len(); ++i) {
    arr[i] = '0';
  }
}

char Container::get_val(int pos, char def) const {
  if (pos < get_len()) {
    return arr[pos];
  } else {
    return def;
  }
}

char Container::get_digit(int pos, char def) const {
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

void Container::set_digit(int pos, char val) {
  if (pos >= get_len() || (pos == get_len() - 1 && char_to_int(val) >= 8)) {
    bool sgn = get_sign();
    unset_minus();
    arr.resize(pos + 2);
    arr[pos + 1] = '0';
    set_len(pos + 2);
    if (sgn) {
      set_minus();
    } else {
      unset_minus();
    }
  }
  if ((pos == get_len() - 1) && (get_sign() == 1)) {
    arr.resize(pos + 2);
    arr[pos + 1] = '0';
    set_len(pos + 2);
    set_minus();
  }
  if (pos < 0) {
    return;
  }
  arr[pos] = val;
}

void Container::set_val(int pos, char val) {
  if (pos >= get_len()) {
    arr.resize(pos + 2);
    arr[pos + 1] = '0';
    set_len(pos + 2);
  }
  arr[pos] = val;
}

hex_num::Container *Container::get_new() const { return new Container; }
hex_num::Container *Container::get_copy() const { return new Container(*this); }

void Container::set_minus() {
  int val = char_to_int(get_val(get_len() - 1));
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
} // namespace hex_num_dynamic

