/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * The origin of this IDL file is
 * http://www.w3.org/TR/2012/WD-dom-20120105/
 *
 * Copyright © 2012 W3C® (MIT, ERCIM, Keio), All Rights Reserved. W3C
 * liability, trademark and document use rules apply.
 */

[Exposed=(Window, Worker)]
interface CustomEvent : Event
{
  constructor(DOMString type, optional CustomEventInit eventInitDict = {});

  readonly attribute any detail;

  // initCustomEvent is a Gecko specific deprecated method.
  void initCustomEvent(DOMString type,
                       optional boolean canBubble = false,
                       optional boolean cancelable = false,
                       optional any detail = null);
};

dictionary CustomEventInit : EventInit
{
  any detail = null;
};
