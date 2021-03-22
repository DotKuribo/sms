#pragma once

#include "JKRFileFinder.hpp"
#include "JKRFileLoader.hpp"
#include "JKRHeap.hpp"
#include "types.h"

class JKRArchive : public JKRFileLoader {
public:
  enum EMountDirection {};
  enum EMountMode {};

  class SDIFileEntry {
  public:
    u32 _0;
    u32 _4;
    s32 _8; // offset to something
    u32 _C;
    u32* mEntry; // _10
  };

  JKRArchive();
  JKRArchive(u32, EMountMode);
  virtual ~JKRArchive();

  virtual s32 becomeCurrent(const char*);
  virtual void* getResource(const char* path);
  virtual void* getResource(u32, const char* path);
  virtual void* readResource(void* dst, u32, const char* path);
  virtual void* readResource(void* dst, u32, u32, const char* path);
  virtual void removeResourceAll();
  virtual bool removeResource(void* path);
  virtual void detachResource(void* path);
  virtual s32 getResSize(const void* resource) const;
  virtual s16 countFile(const char*);
  virtual JKRArcFinder* getFirstFile(const char*) const;

  u32 findDirectory(const char* path, u32) const;
  void* findFsResource(const char* path, u32) const;
  void* findIdxResource(u32 index) const;
  void* findNameResource(const char* name) const;
  void* findPtrResource(const void* resource) const;
  void* findTypeResource(u32, const char*) const;
  bool getDirEntry(JKRArchive::SDirEntry*, u32) const;

  static void* getGlbResource(u32, const char* path, JKRArchive*);
  static JKRArchive* mount(const char* path, EMountMode, JKRHeap*,
                           EMountDirection);

private:
  void* check_mount_already(s32);

  u32* _38;
  u8 _3C;
  u32 _40;
  u32 _44;
  u32 _48;
  u32 _4C;
  u32 _50;
  u32 _54;
  u32 _58;
  EMountDirection mMountDirection;

  static s32** sCurrentDirID;
};