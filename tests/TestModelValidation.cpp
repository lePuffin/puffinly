/*
 * @file: TestModelValidation.cpp
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

// ── Includes ─────────────────────────────────────────────
#include <string>
#include <utility>

#include "libs/puffinly.hpp"

// ── CppUTest Includes ────────────────────────────────────
#include "CppUTest/TestHarness.h"

// ── Defines ──────────────────────────────────────────────

// ── Test Group ───────────────────────────────────────────
namespace puffinly {
struct user_model : public base_model<user_model> {
    int         age;
    std::string name;
    int*        evaluated_counter;

    user_model(int age_value, std::string name_value, int* counter)
        : age(age_value), name(std::move(name_value)), evaluated_counter(counter) {}

    validation_result<user_model> validate() const {
        if (evaluated_counter != nullptr) {
            ++(*evaluated_counter);
        }

        if (!puffinly::validate(age, range_policy<int>(0, 150))) {
            return validation_result<user_model>::fail({"age", "value outside [0, 150]", "RANGE_ERROR"});
        }

        if (evaluated_counter != nullptr) {
            ++(*evaluated_counter);
        }

        if (!puffinly::validate(name, non_empty_policy())) {
            return validation_result<user_model>::fail({"name", "value cannot be empty", "EMPTY_ERROR"});
        }

        return validation_result<user_model>::ok(*this);
    }
};
}  // namespace puffinly

// clang-format off
TEST_GROUP(ModelValidation) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// ── Tests ────────────────────────────────────────────────
TEST(ModelValidation, ValidModelReturnsOk) {
    int                        evaluated = 0;
    const puffinly::user_model model{24, "Puffin", &evaluated};

    const auto result = model.validate();

    CHECK_TRUE(result.is_ok());
    CHECK_EQUAL(2, evaluated);
}

TEST(ModelValidation, FailFastStopsAtFirstFailure) {
    int                        evaluated = 0;
    const puffinly::user_model model{200, "Puffin", &evaluated};

    const auto result = model.validate();

    CHECK_TRUE(result.is_error());
    STRCMP_EQUAL("age", result.error().field_name.c_str());
    CHECK_EQUAL(1, evaluated);
}

TEST(ModelValidation, ValidateModelHelperDelegatesToMemberApi) {
    int                        evaluated = 0;
    const puffinly::user_model model{31, "Puffin", &evaluated};

    CHECK_TRUE(puffinly::validate_model(model).is_ok());
    CHECK_TRUE(puffinly::is_valid_model(model));
}

// End of file
