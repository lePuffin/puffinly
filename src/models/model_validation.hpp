/*
 * @file: model_validation.hpp
 * @brief: Helpers for member-based model validation orchestration.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_MODELS_MODEL_VALIDATION_HPP_
#define SRC_MODELS_MODEL_VALIDATION_HPP_

// ── Includes ─────────────────────────────────────────────

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <typename Model>
auto run_member_validate(const Model& model) -> decltype(model.validate()) {
    return model.validate();
}

}  // namespace puffinly

#endif  // SRC_MODELS_MODEL_VALIDATION_HPP_

// End of file
