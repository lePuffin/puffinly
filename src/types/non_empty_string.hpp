/*
 * @file: non_empty_string.hpp
 * @brief: String wrapper that enforces non-empty values.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_TYPES_NON_EMPTY_STRING_HPP_
#define SRC_TYPES_NON_EMPTY_STRING_HPP_

// ── Includes ─────────────────────────────────────────────
#include <stdexcept>
#include <string>
#include <utility>

#include "src/core/validate.hpp"
#include "src/policies/non_empty_policy.hpp"

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

class non_empty_string {
 private:
    std::string value_;

 public:
    explicit non_empty_string(std::string value) : value_(std::move(value)) {
        if (!validate(value_, non_empty_policy())) {
            throw std::invalid_argument("non_empty_string cannot be empty");
        }
    }

    ~non_empty_string() = default;

    const std::string& value() const { return value_; }
};

}  // namespace puffinly

#endif  // SRC_TYPES_NON_EMPTY_STRING_HPP_

// End of file
