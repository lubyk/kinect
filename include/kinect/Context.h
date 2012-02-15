/*
  ==============================================================================

   This file is part of the LUBYK project (http://lubyk.org)
   Copyright (c) 2007-2012 by Gaspard Bucher (http://teti.ch).

  ------------------------------------------------------------------------------

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.

  ==============================================================================
*/
#ifndef LUBYK_INCLUDE_KINECT_CONTEXT_H_
#define LUBYK_INCLUDE_KINECT_CONTEXT_H_

#include "lubyk.h"
using namespace lubyk;

#include "XnCppWrapper.h"

namespace kinect {

/** Connects to kinect sensor and provide callbacks to access skeleton
 * information.
 *
 * @dub destructor: 'luaDestroy'
 *      lib_name:   'Context_core'
 */
class Context : public ThreadedLuaObject {
  /** OpenNI Context.
   */
  xn::Context xn_context_;
public:
  Context() {
    XnStatus err = XN_STATUS_OK;
    err = xn_context_.Init();
    if (err != XN_STATUS_OK) {
      throw dub::Exception("Could not initialize kinect Context (%s).", xnGetStatusString(err));
    }
  }

  ~Context() {
    xn_context_.Shutdown();
  }

};

} // kinect
#endif // LUBYK_INCLUDE_KINECT_CONTEXT_H_



