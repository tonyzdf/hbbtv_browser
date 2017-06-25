/*
 * Copyright (C) 2010 Google Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ChannelList_h
#define ChannelList_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "core/CoreExport.h"
#include "core/dom/Channel.h"

#include "platform/heap/Handle.h"

namespace blink {

// FIXME: Some consumers of this class may benefit from lazily fetching items
// rather than creating the list statically as is currently the only option.
class CORE_EXPORT ChannelList final
    : public GarbageCollectedFinalized<ChannelList>,
      public ScriptWrappable {
  DEFINE_WRAPPERTYPEINFO();

 public:
  static ChannelList* create() { return new ChannelList(); }

  bool isEmpty() const { return m_channels.isEmpty(); }
  void clear() { m_channels.clear(); }
  void  append(Channel *p_channel) { m_channels.push_back(p_channel); }


  // Implements the IDL.
  size_t length() const { return m_channels.size(); }

  Channel* item(unsigned index) ;

  Channel* anonymousIndexedGetter(unsigned index) { return item(index); }



  DECLARE_TRACE();
//void trace(Visitor* visitor) ;
 private:
  explicit ChannelList() {}
  HeapVector<Member<Channel>> m_channels;
  
};

}  // namespace blink

#endif  // ChannelList_h

