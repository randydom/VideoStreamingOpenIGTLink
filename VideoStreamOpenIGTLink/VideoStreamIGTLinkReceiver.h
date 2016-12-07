/*=========================================================================
 
 Program:   OpenIGTLink
 Language:  C++
 
 Copyright (c) Insight Software Consortium. All rights reserved.
 
 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notices for more information.
 
 =========================================================================*/

#include <fstream>
#include <climits>
#include <cstring>
#include <stdlib.h>
#include "api/svc/codec_api.h"
#include "api/svc/codec_app_def.h"
#include "sha1.h"
#include "igtlOSUtil.h"
#include "igtlMessageHeader.h"
#include "igtlVideoMessage.h"
#include "igtlServerSocket.h"
#include "igtlMultiThreader.h"
#include "igtlUDPClientSocket.h"
#include "igtlMessageRTPWrapper.h"
#include "igtlConditionVariable.h"


#include "H264Decoder.h"

class VideoStreamIGTLinkReceiver
{
public:
  VideoStreamIGTLinkReceiver();
  ~VideoStreamIGTLinkReceiver(){};
  
  int ProcessVideoStream(uint8_t* bitStream);
  
  void SendStopMessage();
  
  std::string deviceName;
  
  ISVCDecoder*  pSVCDecoder;
  
  SDecodingParam decParam;
  
  unsigned char* decodedFrame;
  
  char* kpOuputFileName;
  
  char* pOptionFileName;
  
  igtl::MutexLock::Pointer glock;
  
  igtl::ClientSocket::Pointer socket;
  
  igtl::UDPClientSocket::Pointer UDPSocket;
  
  uint8_t * videoMessageBuffer;
  
  int   interval;
  
  bool  useCompress;
  
  std::string  hostname;
  
  int port;
  
  igtl::MessageRTPWrapper::Pointer rtpWrapper;
  
  char codecType[IGTL_VIDEO_CODEC_NAME_SIZE];
  
  int argc;
  
  std::string augments;
  
  void SetWidth(int iWidth);
  
  void SetHeight(int iHeight);
  
  void SetStreamLength(int iStreamLength);
  
  void SetDecodedFrame();
  
  int Width;
  
  int Height;
  
  int StreamLength;
  
  int RunOnTCPSocket();
  
  int RunOnUDPSocket();
  
  H264Decode* H264DecodeInstance;
  
  int YUV420ToRGBConversion(uint8_t *RGBFrame, uint8_t * YUV420Frame, int iHeight, int iWidth);
  
  bool flipAtX;

};
