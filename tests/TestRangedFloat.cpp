/*
 * @file: TestBoundedFloat.cpp
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
TEST_GROUP(RangedFloat) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// ── Tests ────────────────────────────────────────────────
TEST(RangedFloat, AcceptsRangedValue) {
    const puffinly::ranged_value<double, 0, 10> value(3.5);
    DOUBLES_EQUAL(3.5, value.value(), 0.00001);
}

TEST(RangedFloat, ThrowsWhenOutsideRange) {
    typedef puffinly::ranged_value<double, 0, 10> ranged_value_double_0_10;
    CHECK_THROWS(std::out_of_range, ranged_value_double_0_10(10.5));
}

// End of file
