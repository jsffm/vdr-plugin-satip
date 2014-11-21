/*
 * rtp.h: SAT>IP plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 */

#ifndef __SATIP_RTP_H_
#define __SATIP_RTP_H_

#include "socket.h"
#include "tunerif.h"
#include "pollerif.h"

class cSatipRtp : public cSatipSocket, public cSatipPollerIf {
private:
  enum {
    eReportIntervalS = 300 // in seconds
  };
  cSatipTunerIf &tunerM;
  unsigned int bufferLenM;
  unsigned char *bufferM;
  time_t lastErrorReportM;
  int packetErrorsM;
  int sequenceNumberM;
  int GetHeaderLenght(int lengthP);

public:
  cSatipRtp(cSatipTunerIf &tunerP, unsigned int bufferLenP);
  virtual ~cSatipRtp();
  virtual void Close(void);

  // for internal poller interface
public:
  virtual int GetFd(void);
  virtual void Process(int fdP);
};

#endif /* __SATIP_RTP_H_ */