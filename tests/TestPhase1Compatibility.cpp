/*
 * @file: TestPhase1Compatibility.cpp
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
TEST_GROUP(Phase1Compatibility) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// ── Tests ────────────────────────────────────────────────
TEST(Phase1Compatibility, ValuePolicyValidationIsUnchanged) {
    const puffinly::range_policy<int> range(0, 10);
    const auto                        even = puffinly::make_custom_policy([](int value) { return value % 2 == 0; });

    CHECK_TRUE(puffinly::validate(8, range, even));
    CHECK_FALSE(puffinly::validate(11, range, even));
}

TEST(Phase1Compatibility, ExistingValidatedTypesRemainUsable) {
    const puffinly::ranged_value<int, 0, 10> age(8);
    const puffinly::non_empty_string         name("Puffin");

    CHECK_EQUAL(8, age.value());
    STRCMP_EQUAL("Puffin", name.value().c_str());
}

// End of file
