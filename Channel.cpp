#include "Channel.h"
namespace blink {

 Channel* Channel::create(unsigned long  channelType, unsigned long  idType, String      ccid, unsigned long  onid)
 {
     return new Channel(channelType, idType, ccid, onid);
 }

Channel::Channel(unsigned long  channelType, unsigned long  idType, String      ccid, unsigned long  onid)
:m_channelType(channelType),
m_idType(idType),
m_ccid(ccid),
m_onid(onid)
{

}

}
