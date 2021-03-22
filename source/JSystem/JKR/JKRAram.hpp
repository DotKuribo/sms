#pragma once

#include "../JSU/JSUList.hpp"
#include "JKRDvdRipper.hpp"
#include "JKRThread.hpp"
#include "source/types.h"

class JKRAram : public JKRThread {
public:
  JKRAram(size_t size, u32, s32);
  virtual ~JKRAram();

  virtual void run();

  static u32* create(size_t size, u32, s32 streamPriority, s32 decompPriority);
  static s32 mainRamToAram(u8*, u32, u32, JKRExpandSwitch, u32, JKRHeap*, int);
  static s32 aramToMainRam(u32, u8*, u32, JKRExpandSwitch, u32, JKRHeap*, int,
                           u32*);
  static s32 aramToMainRam(JKRAramBlock*, u8*, u32, u32, JKRExpandSwitch, u32,
                           JKRHeap*, int, u32*);

  u32 _60;
  u32 _64;
  u32 _68;
  u32 _6C;
  u32 _70;
  u32 _74;
  JKRAramHeap* mAramHeap;
  u32 _7C;
  u32 _80;
  u32 _84;

  static JSUPtrList sAramCommandList;
  static JKRAram* sAramObject;
  static u8 sMessageBuffer[12];
  static OSMessageQueue sMessageQueue;
};

void JKRDecompressFromAramToMainRam(u32, void*, u32, u32, u32);