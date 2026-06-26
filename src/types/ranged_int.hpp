/*
 * @file: ranged_int.hpp
 * @brief: Strong integer wrapper with compile-time range bounds.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_TYPES_RANGED_INT_HPP_
#define SRC_TYPES_RANGED_INT_HPP_

// ── Includes ─────────────────────────────────────────────
#include <stdexcept>

#include "src/core/validate.hpp"
#include "src/policies/range_policy.hpp"

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <int Min, int Max>
class ranged_int {
 private:
    int value_;

 public:
    explicit ranged_int(int value) : value_(value) {
        if (!validate(value_, range_policy<int>(Min, Max))) {
            throw std::out_of_range("ranged_int value is out of bounds");
        }
    }

    ~ranged_int() = default;

    int value() const { return value_; }
};

}  // namespace puffinly

#endif  // SRC_TYPES_RANGED_INT_HPP_

// End of file
