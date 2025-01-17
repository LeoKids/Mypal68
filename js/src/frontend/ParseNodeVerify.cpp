/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "frontend/ParseNodeVerify.h"

#include "frontend/ParseNodeVisitor.h"

using namespace js;

#ifdef DEBUG

namespace js {
namespace frontend {

class ParseNodeVerifier : public ParseNodeVisitor<ParseNodeVerifier> {
  using Base = ParseNodeVisitor<ParseNodeVerifier>;

  const LifoAlloc& alloc_;

 public:
  ParseNodeVerifier(JSContext* cx, const LifoAlloc& alloc)
      : Base(cx), alloc_(alloc) {}

  MOZ_MUST_USE bool visit(ParseNode* pn) {
    // pn->size() asserts that pn->pn_kind is valid, so we don't redundantly
    // assert that here.
    JS_PARSE_NODE_ASSERT(alloc_.contains(pn),
                         "start of parse node is in alloc");
    JS_PARSE_NODE_ASSERT(alloc_.contains((unsigned char*)pn + pn->size()),
                         "end of parse node is in alloc");
    if (pn->is<ListNode>()) {
      pn->as<ListNode>().checkConsistency();
    }
    return Base::visit(pn);
  }
};

}  // namespace frontend
}  // namespace js

bool frontend::CheckParseTree(JSContext* cx, const LifoAlloc& alloc,
                              ParseNode* pn) {
  ParseNodeVerifier verifier(cx, alloc);
  return verifier.visit(pn);
}

#endif  // DEBUG
