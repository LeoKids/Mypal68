/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef frontend_SharedContext_inl_h
#define frontend_SharedContext_inl_h

#include "frontend/SharedContext.h"
#include "frontend/ParseContext.h"

namespace js {
namespace frontend {

inline Directives::Directives(ParseContext* parent)
    : strict_(parent->sc()->strict()), asmJS_(parent->useAsmOrInsideUseAsm()) {}

inline JSAtom* SharedContext::liftParserAtomToJSAtom(JSContext* cx,
                                                     const ParserAtom* atomId) {
  return atomId->toJSAtom(cx, compilationInfo_.input.atomCache);
}

}  // namespace frontend

}  // namespace js

#endif  // frontend_SharedContext_inl_h
