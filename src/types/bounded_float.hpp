/*
 * @file: bounded_float.hpp
 * @brief: Floating-point wrapper validated against compile-time bounds.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_TYPES_BOUNDED_FLOAT_HPP_
#define SRC_TYPES_BOUNDED_FLOAT_HPP_

// ── Includes ─────────────────────────────────────────────
#include <stdexcept>

#include "src/core/validate.hpp"
#include "src/policies/range_policy.hpp"

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <int Min, int Max>
class bounded_float {
 private:
    double value_;

 public:
    explicit bounded_float(double value) : value_(value) {
        if (!validate(value_, range_policy<double>(static_cast<double>(Min), static_cast<double>(Max)))) {
            throw std::out_of_range("bounded_float value is out of bounds");
        }
    }

    ~bounded_float() = default;

    double value() const { return value_; }
};

}  // namespace puffinly

#endif  // SRC_TYPES_BOUNDED_FLOAT_HPP_

// End of file
