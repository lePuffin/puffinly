/*
 * @file: validate.hpp
 * @brief: Fail-fast validation composition helpers.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_CORE_VALIDATE_HPP_
#define SRC_CORE_VALIDATE_HPP_

// ── Includes ─────────────────────────────────────────────
#include "src/models/model_validation.hpp"

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <typename Value, typename... Policies>
constexpr bool validate(const Value& value, const Policies&... policies) {
    return (policies(value) && ...);
}

template <typename Model>
auto validate_model(const Model& model) -> decltype(model.validate()) {
    return run_member_validate(model);
}

template <typename Model>
bool is_valid_model(const Model& model) {
    return validate_model(model).is_ok();
}

}  // namespace puffinly

#endif  // SRC_CORE_VALIDATE_HPP_

// End of file
