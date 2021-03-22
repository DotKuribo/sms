#pragma once

#include "JKRArchivePri.hpp"
#include "JKRFileLoader.hpp"
#include "JKRHeap.hpp"
#include "source/types.h"


class JKRAramArchive : public JKRFileLoader {
public:
  JKRAramArchive(s32, JKRArchive::EMountDirection);
  virtual ~JKRAramArchive();

  virtual void* fetchResource(JKRArchive::SDIFileEntry*, u32*);
  virtual void* fetchResource(void*, u32, JKRArchive::SDIFileEntry*, u32*);

  bool open(s32, JKRArchive::EMountDirection);

private:
  u32* fetchResource_subroutine(u32, u32, JKRHeap*, int, u8**);
  u32* fetchResource_subroutine(u32, u32, u8*, u32, int);
};