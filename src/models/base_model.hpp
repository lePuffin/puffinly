/*
 * @file: base_model.hpp
 * @brief: Optional CRTP base contract for Phase 2 models.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_MODELS_BASE_MODEL_HPP_
#define SRC_MODELS_BASE_MODEL_HPP_

// ── Includes ─────────────────────────────────────────────
#include "src/errors/validation_result.hpp"

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <typename Derived>
class base_model {
 public:
    using validation_type = validation_result<Derived>;

    validation_type validate() const { return static_cast<const Derived*>(this)->validate(); }
};

}  // namespace puffinly

#endif  // SRC_MODELS_BASE_MODEL_HPP_

// End of file
