#include "hex_num.h"
#include "string"
#include <functional>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>

using namespace hex_num;
using namespace std;
typedef Container C;

//-----------------Hex_num constructors------------------------
Hex_num::Hex_num(C *arr) : cont(arr) {}

Hex_num::Hex_num(C *arr, int hex) : cont(arr) {
  if (hex < 0) {
    arr->set_minus();
    hex = -hex;
  }
  int i = 0;
  while (hex > 0) {
    arr->set_digit(i++, C::int_to_char(hex));
    hex /= 16;
  }
}

Hex_num::Hex_num(C *arr, string hex) : cont(arr) { str_to_arr(hex); }

Hex_num::Hex_num(const Hex_num &that) {
  cont = that.cont->get_copy();
  std::cout << "Copy constructor of base class" << std::endl;
}
Hex_num::~Hex_num() {
  delete cont;
  cont = nullptr;
}

Hex_num &Hex_num::operator=(const Hex_num &a) {
  delete cont;
  cont = a.cont->get_copy();
  std::cout << "Copy assignment of base class" << std::endl;
  return *this;
}

Hex_num &Hex_num::operator=(Hex_num &&a) {
  swap(cont, a.cont);
  std::cout << "Move assignment of base class" << std::endl;
  return *this;
}

Hex_num::Hex_num(Hex_num &&that) {
  swap(cont, that.cont);
  std::cout << "Move constructor of base class" << std::endl;
}
//-------------------------------------------------------------

//-----------------Protected methods---------------------------

void Hex_num::str_to_arr(string str) {
  size_t len = str.length();
  len = str[0] == '-' ? len - 1 : len;
  if (len == 0) {
    throw C::Wrong_format_exception("Empty string");
  }
  for (size_t i = 0; i < len; ++i) {
    if (string("0123456789ABCDEF").find(str[str.length() - 1 - i]) !=
        str.npos) {
      cont->set_digit(i, str[str.length() - 1 - i]);
    } else {
      throw C::Wrong_format_exception("Wrong format in converting str to arr");
    }
  }
  if (str[0] == '-') {
    cont->set_minus();
  }
  check_for_minus_zero();
}

void Hex_num::check_for_minus_zero() {
  std::stringstream str;
  output(str);
  if (str.str() == "-0\n") {
    cont->unset_minus();
  }
}

//-------------------------------------------------------------
Hex_num Hex_num::move_left(unsigned n) {
  if (n == 0) {
    return *this;
  }
  bool sign = cont->get_sign();
  for (int i = cont->get_len(); i >= 1; --i) {
    cont->set_val(i + n - 1, cont->get_digit(i - 1, '0'));
  }
  for (int i = 0; i < static_cast<int>(n); ++i) {
    cont->set_val(i, '0');
  }
  if (!sign) {
    cont->unset_minus();
  } else {
    cont->set_minus();
  }
  check_for_minus_zero();
  return *this;
}

Hex_num Hex_num::move_right(unsigned n) {
  if (n == 0) {
    return *this;
  }
  bool sign = cont->get_sign();
  for (int i = 1; i < cont->get_len(); ++i) {
    cont->set_digit(i - 1, cont->get_digit(i + n - 1, '0'));
  }
  for (int i = cont->get_len() - 1;
       i > cont->get_len() - 1 - static_cast<int>(n); --i) {
    cont->set_digit(i, '0');
  }
  if (!sign) {
    cont->unset_minus();
  } else {
    cont->set_minus();
  }
  check_for_minus_zero();
  return *this;
}

bool Hex_num::evenness() {
  if (C::char_to_int(cont->get_val(0)) % 2 == 0) {
    return 1;
  } else {
    return 0;
  }
}

istream &Hex_num::input(istream &is) {
  string inp;
  getline(is, inp);
  cont->set_zeros();
  str_to_arr(inp);
  return is;
}

ostream &Hex_num::output(ostream &os) const {

  bool started = 0;
  int i = cont->get_len() - 1;
  if (cont->get_sign()) {
    os << '-';
  }
  for (; i >= 0; --i) {
    int a = C::char_to_int(cont->get_digit(i, '0'));
    if (a != 0) {
      os << C::int_to_char(a);
      started = 1;
    } else if (started) {
      os << C::int_to_char(a);
    }
  }
  if (started == 0) {
    os << '0';
  }
  os << endl;

  return os;
}

void Hex_num::print_container(ostream &out) {
  for (int i = cont->get_len() - 1; i >= 0; --i) {
    out << cont->get_val(i);
  }
  out << endl;
}

Hex_num *Hex_num::reverse_code() {
  int val = C::char_to_int(cont->get_val(cont->get_len() - 1));
  if (cont->get_sign()) {
    cont->unset_minus();
    val -= 8;
    for (int i = 0; i < 3; ++i) {
      int bit = static_cast<int>(pow(2, i));
      if ((val / bit) % 2 == 0) {
        val += bit;
      } else {
        val -= bit;
      }
    }
    cont->set_digit(cont->get_len() - 1, C::int_to_char(val));

    for (int j = cont->get_len() - 2; j >= 0; --j) {
      int val = C::char_to_int(cont->get_val(j));
      for (int i = 0; i < 4; ++i) {
        int bit = static_cast<int>(pow(2, i));
        if ((C::char_to_int(cont->get_val(j)) / bit) % 2 == 0) {
          val += bit;
        } else {
          val -= bit;
        }
      }
      cont->set_digit(j, C::int_to_char(val));
    }
    cont->set_minus();
  }
  return this;
}

Hex_num *Hex_num::to_additional_code() {
  int val = C::char_to_int(cont->get_val(cont->get_len() - 1));
  if (val >= 8) {
    for (int i = 0; i < cont->get_len() - 2; ++i) {
      val = C::char_to_int(cont->get_val(i));
      val += 1;
      if (val == 16) {
        cont->set_digit(i, C::int_to_char(0));
      } else {
        cont->set_digit(i, C::int_to_char(val));
        break;
      }
    }
  }
  return this;
}

Hex_num *Hex_num::from_add_to_rev_code() {
  if (C::char_to_int(cont->get_val(cont->get_len() - 1)) >= 8) {
    int i = 0;
    int val = C::char_to_int(cont->get_val(i));
    while (val == 0 && i < cont->get_len()) {
      ++i;
      val = C::char_to_int(cont->get_val(i));
    }
    if (i == cont->get_len() - 1 && val == 8) {
      throw overflow_error(
          "Such additional code can't be represented as a reversed code");
    } else {
      for (int j = 0; j < 4; ++j) {
        int bit = static_cast<int>(pow(2, j));
        if ((C::char_to_int(cont->get_val(i)) / bit) % 2 == 1) {
          val -= bit;
          for (--j; j >= 0; --j) {
            bit = static_cast<int>(pow(2, i));
            val += bit;
          }
          break;
        }
      }
      cont->set_digit(i, C::int_to_char(val));
      --i;
    }
    for (; i >= 0; --i) {
      cont->set_digit(i, 'F');
    }
  }
  return this;
}

bool Hex_num::equal(Hex_num const &a, Hex_num const &b) {
  if (a.cont->get_sign() != a.cont->get_sign()) {
    return 0;
  }
  for (int i = 0; i < max(a.cont->get_len(), b.cont->get_len()); ++i) {
    if (a.cont->get_digit(i, '0') != b.cont->get_digit(i, '0')) {
      return 0;
    }
  }
  return 1;
}

Hex_num Hex_num::sum_of_additonals(const Hex_num &a, const Hex_num &b) {
  Hex_num ans(a.cont->get_new());
  int i = 0;
  int from_prev = 0;
  while (i < a.cont->get_len() || i < b.cont->get_len()) {
    int s1 = C::char_to_int(a.cont->get_val(i, a.cont->get_sign() ? 'F' : '0'));
    int s2 = C::char_to_int(b.cont->get_val(i, b.cont->get_sign() ? 'F' : '0'));
    int res = s1 + s2 + from_prev;
    from_prev = 0;
    if (res >= 16) {
      from_prev = 1;
      ans.cont->set_val(i, C::int_to_char(res % 16));
      ++i;
    } else {
      ans.cont->set_val(i, C::int_to_char(res));
      ++i;
    }
  }
  if (a.cont->get_sign() == 1 && b.cont->get_sign() == 1 &&
      C::char_to_int(ans.cont->get_val(ans.cont->get_len() - 1)) / 8 % 2 == 0) {
    throw overflow_error("<0 + <0 = >0");
  } else if (a.cont->get_sign() == 0 && b.cont->get_sign() == 0 &&
             C::char_to_int(ans.cont->get_val(ans.cont->get_len() - 1)) / 8 %
                     2 ==
                 1) {
    throw overflow_error(">0 + >0 = <0");
  } else if (a.cont->get_sign() == 1 || b.cont->get_sign() == 1) {
  }
  return ans;
}

Hex_num Hex_num::sum(const Hex_num &a, const Hex_num &b) {
  Hex_num a_add(a);
  a_add.reverse_code()->to_additional_code();
  Hex_num b_add(b);
  b_add.reverse_code()->to_additional_code();
  Hex_num ans = sum_of_additonals(a_add, b_add);
  ans.from_add_to_rev_code()->reverse_code();
  ans.check_for_minus_zero();
  return ans;
}

Hex_num Hex_num::dif(Hex_num const &a, Hex_num const &b) {
  Hex_num minus_b(b);
  if (!minus_b.cont->get_sign()) {
    minus_b.cont->set_minus();
  } else {
    minus_b.cont->unset_minus();
  }
  return sum(a, minus_b);
}
