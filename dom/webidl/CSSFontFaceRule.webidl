/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * The origin of this IDL file is
 * https://drafts.csswg.org/css-fonts/#om-fontface
 */

// https://drafts.csswg.org/css-fonts/#om-fontface
// But we implement a very old draft, apparently....
// See bug 1058408 for implementing the current spec.
[Exposed=Window]
interface CSSFontFaceRule : CSSRule {
  [SameObject] readonly attribute CSSStyleDeclaration style;
};
