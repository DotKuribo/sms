#pragma once

#include "../JSU/JSUList.hxx"
#include "JKRAramHeap.hxx"
#include "source/types.h"

class JKRAramBlock {
public:
  JKRAramBlock(u32, size_t size, u32, u8, bool);
  virtual ~JKRAramBlock();

  JKRAramBlock* allocHead(size_t size, u8, JKRAramHeap*);
  JKRAramBlock* allocTail(size_t size, u8, JKRAramHeap*);

  JSUPtrLink mBlockPtr; // _4
  u32 _14;
  size_t mSize;
  u32 _18;
  u8 _20;
  bool _21;
};