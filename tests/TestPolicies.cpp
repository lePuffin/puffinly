/*
 * @file: TestPolicies.cpp
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
TEST_GROUP(Policies) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// ── Tests ────────────────────────────────────────────────
TEST(Policies, RangePolicyAcceptsInsideBounds) {
    const puffinly::range_policy<int> policy(0, 10);
    CHECK_TRUE(policy(7));
}

TEST(Policies, RangePolicyRejectsOutsideBounds) {
    const puffinly::range_policy<int> policy(0, 10);
    CHECK_FALSE(policy(11));
}

TEST(Policies, NonEmptyPolicyRejectsEmptyString) {
    const puffinly::non_empty_policy policy;
    CHECK_FALSE(policy(std::string()));
}

TEST(Policies, MaxLengthPolicyRejectsTooLongString) {
    const puffinly::max_length_policy policy(3);
    CHECK_FALSE(policy(std::string("abcd")));
}

TEST(Policies, RegexMatchPolicyMatchesPattern) {
    const puffinly::regex_match_policy policy("^[a-z]+$");
    CHECK_TRUE(policy("puffin"));
}

// End of file
