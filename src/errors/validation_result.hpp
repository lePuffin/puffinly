/*
 * @file: validation_result.hpp
 * @brief: Minimal result carrier for model-level validation.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_ERRORS_VALIDATION_RESULT_HPP_
#define SRC_ERRORS_VALIDATION_RESULT_HPP_

// ── Includes ─────────────────────────────────────────────
#include <optional>
#include <stdexcept>
#include <utility>

#include "src/errors/field_error.hpp"

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <typename T>
class validation_result {
 private:
    std::optional<T>           value_;
    std::optional<field_error> error_;

 public:
    validation_result() = delete;

    explicit validation_result(const T& value) : value_(value), error_(std::nullopt) {}
    explicit validation_result(T&& value) : value_(std::move(value)), error_(std::nullopt) {}
    explicit validation_result(const field_error& error) : value_(std::nullopt), error_(error) {}
    explicit validation_result(field_error&& error) : value_(std::nullopt), error_(std::move(error)) {}

    static validation_result ok(const T& value) { return validation_result(value); }

    static validation_result ok(T&& value) { return validation_result(std::move(value)); }

    static validation_result fail(const field_error& error) { return validation_result(error); }

    static validation_result fail(field_error&& error) { return validation_result(std::move(error)); }

    bool is_ok() const { return value_.has_value(); }

    bool is_error() const { return !is_ok(); }

    const T& value() const {
        if (!value_.has_value()) {
            throw std::logic_error("validation_result does not contain a value");
        }

        return value_.value();
    }

    const field_error& error() const {
        if (!error_.has_value()) {
            throw std::logic_error("validation_result does not contain an error");
        }

        return error_.value();
    }
};

}  // namespace puffinly

#endif  // SRC_ERRORS_VALIDATION_RESULT_HPP_

// End of file
