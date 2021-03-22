#pragma once

#include "../JSU/JSUList.hpp"
#include "JKRDisposer.hpp"
#include "JKRHeap.hpp"
#include "source/types.h"


class JKRAramHeap : public JKRDisposer {
public:
  enum EAllocMode { HEAD = 0, TAIL = 1 };

  JKRAramHeap(u32, u32);
  virtual ~JKRAramHeap();

  void* alloc(size_t size, EAllocMode allocMode);

private:
  void* allocFromHead(size_t size);
  void* allocFromTail(size_t size);

  OSMutex mMutex; // 18
  JKRHeap* mHeap; // 30
  size_t mSize;
  u32 _38;
  u32 _3C;
  u8 _40;
  u8 _41;
  u8 _42;
  u8 _43;
  u8 _44;

public:
  static JSUPtrList sAramList;
};