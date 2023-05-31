/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef vm_BytecodeFormatFlags_h
#define vm_BytecodeFormatFlags_h

/*
 * [SMDOC] Bytecode Format flags (JOF_*)
 */
enum {
  JOF_BYTE = 0,         /* single bytecode, no immediates */
  JOF_UINT8 = 1,        /* unspecified uint8_t argument */
  JOF_UINT16 = 2,       /* unspecified uint16_t argument */
  JOF_UINT24 = 3,       /* unspecified uint24_t argument */
  JOF_UINT32 = 4,       /* unspecified uint32_t argument */
  JOF_INT8 = 5,         /* int8_t literal */
  JOF_INT32 = 6,        /* int32_t literal */
  JOF_JUMP = 7,         /* int32_t jump offset */
  JOF_TABLESWITCH = 8,  /* table switch */
  JOF_ENVCOORD = 9,     /* embedded ScopeCoordinate immediate */
  JOF_ARGC = 10,        /* uint16_t argument count */
  JOF_QARG = 11,        /* function argument index */
  JOF_LOCAL = 12,       /* var or block-local variable */
  JOF_RESUMEINDEX = 13, /* yield, await, or gosub resume index */
  JOF_ATOM = 14,        /* uint32_t constant index */
  JOF_OBJECT = 15,      /* uint32_t object index */
  JOF_REGEXP = 16,      /* uint32_t regexp index */
  JOF_DOUBLE = 17,      /* inline DoubleValue */
  JOF_SCOPE = 18,       /* uint32_t scope index */
  JOF_ICINDEX = 19,     /* uint32_t IC index */
  JOF_LOOPHEAD = 20,    /* JSOp::LoopHead, combines JOF_ICINDEX and JOF_UINT8 */
  JOF_BIGINT = 21,      /* uint32_t index for BigInt value */
  JOF_CLASS_CTOR = 22,  /* uint32_t atom index, sourceStart, sourceEnd */
  JOF_CODE_OFFSET = 23, /* int32_t bytecode offset */
  JOF_TYPEMASK = 0x001f, /* mask for above immediate types */

  JOF_NAME = 1 << 5,     /* name operation */
  JOF_PROP = 2 << 5,     /* obj.prop operation */
  JOF_ELEM = 3 << 5,     /* obj[index] operation */
  JOF_MODEMASK = 3 << 5, /* mask for above addressing modes */

  JOF_PROPSET = 1 << 7,  /* property/element/name set operation */
  JOF_PROPINIT = 1 << 8, /* property/element/name init operation */
  // (1 << 9) is unused.
  JOF_CHECKSLOPPY = 1 << 10, /* op can only be generated in sloppy mode */
  JOF_CHECKSTRICT = 1 << 11, /* op can only be generated in strict mode */
  JOF_INVOKE = 1 << 12,      /* any call, construct, or eval instruction */
  JOF_CONSTRUCT = 1 << 13,   /* invoke instruction using [[Construct]] entry */
  JOF_SPREAD = 1 << 14,      /* invoke instruction using spread argument */
  JOF_GNAME = 1 << 15,       /* predicted global name */
  JOF_TYPESET = 1 << 16,     /* has an entry in a script's type sets */
  JOF_IC = 1 << 17,          /* baseline may use an IC for this op */
};

#endif /* vm_BytecodeFormatFlags_h */