/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* Queuing strategies. */

#ifndef builtin_stream_QueueingStrategies_h
#define builtin_stream_QueueingStrategies_h

#include "js/Class.h"         // JSClass, js::ClassSpec
#include "js/Value.h"         // JS::Value
#include "vm/JSContext.h"     // JSContext
#include "vm/NativeObject.h"  // js::NativeObject

namespace js {

class ByteLengthQueuingStrategy : public NativeObject {
 public:
  static bool constructor(JSContext* cx, unsigned argc, JS::Value* vp);
  static const ClassSpec classSpec_;
  static const JSClass class_;
  static const ClassSpec protoClassSpec_;
  static const JSClass protoClass_;
};

class CountQueuingStrategy : public NativeObject {
 public:
  static bool constructor(JSContext* cx, unsigned argc, JS::Value* vp);
  static const ClassSpec classSpec_;
  static const JSClass class_;
  static const ClassSpec protoClassSpec_;
  static const JSClass protoClass_;
};

}  // namespace js

#endif  // builtin_stream_QueueingStrategies_h
