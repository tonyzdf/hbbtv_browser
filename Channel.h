// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef Channel_h
#define Channel_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"
#include <utility>

namespace blink {


class ExceptionState;
class ScriptState;
class ScriptValue;

class CORE_EXPORT Channel final: public GarbageCollectedFinalized<Channel>,
                                     public ScriptWrappable {
  DEFINE_WRAPPERTYPEINFO();

 public:
  Channel() {}
  static Channel* create(unsigned long  channelType, unsigned long  idType, String      ccid, unsigned long  onid);
  static Channel* create() { return new Channel; }

  double channelType() const { return m_channelType; }
  double idType() const { return m_idType; }
  String ccid() const { return m_ccid; }
  double onid() const { return m_onid; }
 void setCcid(String ccid){m_ccid=ccid;}
  DEFINE_INLINE_TRACE() {/*visitor->trace(m_ccid);*/}

  Channel(Channel &ch)
  {
      Channel(ch.m_channelType, ch.m_idType,ch.m_ccid,ch.m_onid);
  }

  
Channel(unsigned long  channelType, unsigned long  idType, String      ccid, unsigned long  onid);

 protected:
  
  unsigned long  m_channelType;
  unsigned long  m_idType;
  String             m_ccid;
  unsigned long  m_onid;
  /*unsigned long  nid;
  unsigned long  tsid;
  unsigned long  sid;*/
};

}  // namespace blink

#endif


