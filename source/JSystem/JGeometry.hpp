#pragma once

namespace JGeometry {

template <typename T> struct TVec2 {
  TVec2();

  f32 dot(const TVec2& operand) const;
  void sub(const TVec2& translate);

  T x;
  T y;
};

template <typename T> struct TVec3 {
  TVec3();
  TVec3(const TVec3&);

  template <typename TY> TVec3(TY, TY, TY);

  TVec3& operator=(const TVec3&);
  TVec3& operator*=(const TVec3& operand);
  TVec3& operator-=(const TVec3& operand);

  void add(const TVec3& operand);
  void div(f32 divisor);
  f32 dot(const TVec3& operand) const;
  void negate();
  void scale(f32 scale);
  void scale(f32 scale, const TVec3& operand);
  void scaleAdd(f32 scale, const TVec3& operand, const TVec3& translate);
  void set(const Vec&);

  template <typename TY> void set(TY x, TY y, TY z);
  template <typename TY> void set(const TVec3<TY>&);

  void setLength(const TVec3& operand, f32 length);
  void setMax(const TVec3& other);
  void setMin(const TVec3& other);
  void sub(const TVec3& translate);
  void sub(const TVec3& base, const TVec3& translate);

  T x;
  T y;
  T z;
};

template <typename T> struct TVec4 {
  TVec4();
  TVec4(const TVec4&);

  TVec4& operator=(const TVec4&);

  f32 dot(const TVec4& operand) const;
  void scale(f32 scale, const TVec4& operand);

  template <typename TY> void set(TY x, TY y, TY z, TY w);

  void xyz();

  T x;
  T y;
  T z;
  T w;
};

template <typename T> struct TQuat4 {
  void rotate(const TVec3& rotate, const TVec3& dst) const;
  void setRotate(const TVec3& base, const TVec3& rotate, f32 scalar);
  void slerp(const TQuat4& operand, f32 lerp);

  T x;
  T y;
  T z;
  T w;
};

} // namespace JGeometry