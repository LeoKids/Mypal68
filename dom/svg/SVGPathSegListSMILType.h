/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef MOZILLA_SVGPATHSEGLISTSMILTYPE_H_
#define MOZILLA_SVGPATHSEGLISTSMILTYPE_H_

#include "mozilla/Attributes.h"
#include "mozilla/SMILType.h"

namespace mozilla {

class SMILValue;

////////////////////////////////////////////////////////////////////////
// SVGPathSegListSMILType
//
// Operations for animating an SVGPathData.
//
class SVGPathSegListSMILType : public SMILType {
 public:
  // Singleton for SMILValue objects to hold onto.
  static SVGPathSegListSMILType* Singleton() {
    static SVGPathSegListSMILType sSingleton;
    return &sSingleton;
  }

 protected:
  // SMILType Methods
  // -------------------

  virtual void Init(SMILValue& aValue) const override;

  virtual void Destroy(SMILValue& aValue) const override;
  virtual nsresult Assign(SMILValue& aDest,
                          const SMILValue& aSrc) const override;
  virtual bool IsEqual(const SMILValue& aLeft,
                       const SMILValue& aRight) const override;
  virtual nsresult Add(SMILValue& aDest, const SMILValue& aValueToAdd,
                       uint32_t aCount) const override;
  virtual nsresult ComputeDistance(const SMILValue& aFrom, const SMILValue& aTo,
                                   double& aDistance) const override;
  virtual nsresult Interpolate(const SMILValue& aStartVal,
                               const SMILValue& aEndVal, double aUnitDistance,
                               SMILValue& aResult) const override;

 private:
  // Private constructor: prevent instances beyond my singleton.
  constexpr SVGPathSegListSMILType() = default;
};

}  // namespace mozilla

#endif  // MOZILLA_SVGPATHSEGLISTSMILTYPE_H_