/*
 * @file: TestRangedInt.cpp
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

// ── Includes ─────────────────────────────────────────────
#include <stdexcept>

#include "libs/puffinly.hpp"

// ── CppUTest Includes ────────────────────────────────────
#include "CppUTest/TestHarness.h"

// ── Defines ──────────────────────────────────────────────

// ── Test Group ───────────────────────────────────────────
// clang-format off
TEST_GROUP(RangedInt) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// ── Tests ────────────────────────────────────────────────
TEST(RangedInt, AcceptsInRangeValue) {
    const puffinly::ranged_int<1, 5> value(3);
    CHECK_EQUAL(3, value.value());
}

TEST(RangedInt, ThrowsWhenOutOfRange) {
    typedef puffinly::ranged_int<1, 5> ranged_int_1_5;
    CHECK_THROWS(std::out_of_range, ranged_int_1_5(6));
}

// End of file
