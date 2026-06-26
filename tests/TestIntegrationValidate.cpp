/*
 * @file: TestIntegrationValidate.cpp
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

// ── Includes ─────────────────────────────────────────────
#include <string>

#include "libs/puffinly.hpp"

// ── CppUTest Includes ────────────────────────────────────
#include "CppUTest/TestHarness.h"

// ── Defines ──────────────────────────────────────────────

// ── Test Group ───────────────────────────────────────────
// clang-format off
TEST_GROUP(IntegrationValidate) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// ── Tests ────────────────────────────────────────────────
TEST(IntegrationValidate, FailFastValidationReturnsFalseOnFirstFailure) {
    int evaluated = 0;

    const auto first = puffinly::make_custom_policy([&evaluated](int value) {
        ++evaluated;
        return value > 0;
    });

    const auto second = puffinly::make_custom_policy([&evaluated](int value) {
        ++evaluated;
        return value < 10;
    });

    const auto third = puffinly::make_custom_policy([&evaluated](int value) {
        ++evaluated;
        return value % 2 == 0;
    });

    CHECK_FALSE(puffinly::validate(11, first, second, third));
    CHECK_EQUAL(2, evaluated);
}

TEST(IntegrationValidate, CombinedPoliciesPassWhenAllChecksPass) {
    const puffinly::range_policy<int> range(1, 10);
    const auto                        even = puffinly::make_custom_policy([](int value) { return value % 2 == 0; });

    CHECK_TRUE(puffinly::validate(8, range, even));
}

TEST(IntegrationValidate, StringPoliciesCompose) {
    const puffinly::non_empty_policy  non_empty;
    const puffinly::max_length_policy max_length(8);

    CHECK_TRUE(puffinly::validate(std::string("puffin"), non_empty, max_length));
    CHECK_FALSE(puffinly::validate(std::string(""), non_empty, max_length));
}

// End of file
