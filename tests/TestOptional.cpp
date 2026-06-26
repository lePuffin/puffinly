/*
 * @file: TestOptional.cpp
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

// ── Includes ─────────────────────────────────────────────
#include "libs/puffinly.hpp"

// ── CppUTest Includes ────────────────────────────────────
#include "CppUTest/TestHarness.h"

// ── Defines ──────────────────────────────────────────────

// ── Test Group ───────────────────────────────────────────
// clang-format off
TEST_GROUP(OptionalType) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// ── Tests ────────────────────────────────────────────────
TEST(OptionalType, StartsEmptyByDefault) {
    const puffinly::optional<int> value;
    CHECK_FALSE(value.has_value());
}

TEST(OptionalType, StoresAndReturnsValue) {
    const puffinly::optional<int> value(42);
    CHECK_TRUE(value.has_value());
    CHECK_EQUAL(42, value.value());
    CHECK_EQUAL(42, value.value_or(-1));
}

// End of file
