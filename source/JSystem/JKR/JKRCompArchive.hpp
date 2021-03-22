#pragma once

#include "JKRArchivePri.hpp"
#include "source/types.h"

class JKRCompArchive : public JKRArchive {
public:
  JKRCompArchive(s32, EMountDirection);
  virtual ~JKRCompArchive();

  virtual void removeResourceAll();
  virtual bool removeResource(void* resource);

  virtual void* fetchResource(SDIFileEntry* entry, u32*);
  virtual void* fetchResource(void* src, size_t len, SDIFileEntry* entry, u32*);

  void open(s32);
};