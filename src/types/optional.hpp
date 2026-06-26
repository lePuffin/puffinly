/*
 * @file: optional.hpp
 * @brief: Lightweight optional wrapper for validated-type symmetry.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_TYPES_OPTIONAL_HPP_
#define SRC_TYPES_OPTIONAL_HPP_

// ── Includes ─────────────────────────────────────────────
#include <optional>

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <typename T>
class optional {
 private:
    std::optional<T> value_;

 public:
    optional() = default;
    explicit optional(const T& value) : value_(value) {}
    ~optional() = default;

    bool has_value() const { return value_.has_value(); }

    const T& value() const { return value_.value(); }

    T value_or(const T& fallback) const { return value_.value_or(fallback); }

    void reset() { value_.reset(); }
};

}  // namespace puffinly

#endif  // SRC_TYPES_OPTIONAL_HPP_

// End of file
