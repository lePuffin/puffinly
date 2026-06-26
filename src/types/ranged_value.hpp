/*
 * @file: ranged_value.hpp
 * @brief: Generic value wrapper with compile-time integer bounds.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_TYPES_RANGED_VALUE_HPP_
#define SRC_TYPES_RANGED_VALUE_HPP_

// ── Includes ─────────────────────────────────────────────
#include <stdexcept>

#include "src/core/validate.hpp"
#include "src/policies/range_policy.hpp"

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <typename T, int Min, int Max>
class ranged_value {
 private:
    T value_;

 public:
    explicit ranged_value(T value) : value_(value) {
        if (!validate(value_, range_policy<T>(static_cast<T>(Min), static_cast<T>(Max)))) {
            throw std::out_of_range("ranged_value is out of bounds");
        }
    }

    ~ranged_value() = default;

    T value() const { return value_; }
};

}  // namespace puffinly

#endif  // SRC_TYPES_RANGED_VALUE_HPP_

// End of file
