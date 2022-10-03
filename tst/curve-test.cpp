#include "hex_num_abstract.h"
#include "stat_hex_num.h"
#include <catch2/catch_test_macros.hpp>

using namespace Catch;
using namespace static_hex;

TEST_CASE("Constructors") {
  SECTION("Empty") {
    REQUIRE_NOTHROW(Hex_num());
  }
  
  SECTION("Int") {
    REQUIRE_NOTHROW(Hex_num(0xFFFFFFFF));
    REQUIRE_NOTHROW(Hex_num(0x123AF));
    REQUIRE_NOTHROW(Hex_num(100000));
    REQUIRE_NOTHROW(Hex_num(0));
    REQUIRE_NOTHROW(Hex_num(-100000));
    REQUIRE_NOTHROW(Hex_num(-0x123AF));
    REQUIRE_NOTHROW(Hex_num(-0xFFFFFFFF));
  }

  SECTION("String") {
    REQUIRE_NOTHROW(Hex_num("FFFFFFFF"));
    REQUIRE_NOTHROW(Hex_num("123AF"));
    REQUIRE_NOTHROW(Hex_num("100000"));
    REQUIRE_NOTHROW(Hex_num("0"));
    REQUIRE_NOTHROW(Hex_num("-0"));
    REQUIRE_NOTHROW(Hex_num("-100000"));
    REQUIRE_NOTHROW(Hex_num("-123AE"));
    REQUIRE_NOTHROW(Hex_num("-FFFFFFFF"));
  }
  SECTION("Wrong format") {
    REQUIRE_THROWS_AS(Hex_num(""), hex_num::Hex_num::Wrong_format_exception);
    REQUIRE_THROWS_AS(Hex_num("-"), hex_num::Hex_num::Wrong_format_exception);
    REQUIRE_THROWS_AS(Hex_num("123o123"), hex_num::Hex_num::Wrong_format_exception);
    REQUIRE_THROWS_AS(Hex_num("-123o123"), hex_num::Hex_num::Wrong_format_exception);
    REQUIRE_THROWS_AS(Hex_num("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"),
                      std::overflow_error);
    REQUIRE_THROWS_AS(Hex_num("-FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"),
                      std::overflow_error);
  }
}

