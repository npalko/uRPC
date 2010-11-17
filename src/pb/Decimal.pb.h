// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Decimal.proto

#ifndef PROTOBUF_Decimal_2eproto__INCLUDED
#define PROTOBUF_Decimal_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2003001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace urpc {
namespace pb {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Decimal_2eproto();
void protobuf_AssignDesc_Decimal_2eproto();
void protobuf_ShutdownFile_Decimal_2eproto();

class Decimal;

// ===================================================================

class Decimal : public ::google::protobuf::Message {
 public:
  Decimal();
  virtual ~Decimal();
  
  Decimal(const Decimal& from);
  
  inline Decimal& operator=(const Decimal& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Decimal& default_instance();
  
  void Swap(Decimal* other);
  
  // implements Message ----------------------------------------------
  
  Decimal* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Decimal& from);
  void MergeFrom(const Decimal& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // optional uint64 mantissa_msb = 1;
  inline bool has_mantissa_msb() const;
  inline void clear_mantissa_msb();
  static const int kMantissaMsbFieldNumber = 1;
  inline ::google::protobuf::uint64 mantissa_msb() const;
  inline void set_mantissa_msb(::google::protobuf::uint64 value);
  
  // optional uint32 mantissa_lsb = 2;
  inline bool has_mantissa_lsb() const;
  inline void clear_mantissa_lsb();
  static const int kMantissaLsbFieldNumber = 2;
  inline ::google::protobuf::uint32 mantissa_lsb() const;
  inline void set_mantissa_lsb(::google::protobuf::uint32 value);
  
  // required sint32 exponent_and_sign = 3;
  inline bool has_exponent_and_sign() const;
  inline void clear_exponent_and_sign();
  static const int kExponentAndSignFieldNumber = 3;
  inline ::google::protobuf::int32 exponent_and_sign() const;
  inline void set_exponent_and_sign(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:urpc.pb.Decimal)
 private:
  inline void set_has_mantissa_msb();
  inline void clear_has_mantissa_msb();
  inline void set_has_mantissa_lsb();
  inline void clear_has_mantissa_lsb();
  inline void set_has_exponent_and_sign();
  inline void clear_has_exponent_and_sign();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::uint64 mantissa_msb_;
  ::google::protobuf::uint32 mantissa_lsb_;
  ::google::protobuf::int32 exponent_and_sign_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  friend void  protobuf_AddDesc_Decimal_2eproto();
  friend void protobuf_AssignDesc_Decimal_2eproto();
  friend void protobuf_ShutdownFile_Decimal_2eproto();
  
  void InitAsDefaultInstance();
  static Decimal* default_instance_;
};
// ===================================================================


// ===================================================================

// Decimal

// optional uint64 mantissa_msb = 1;
inline bool Decimal::has_mantissa_msb() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Decimal::set_has_mantissa_msb() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Decimal::clear_has_mantissa_msb() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Decimal::clear_mantissa_msb() {
  mantissa_msb_ = GOOGLE_ULONGLONG(0);
  clear_has_mantissa_msb();
}
inline ::google::protobuf::uint64 Decimal::mantissa_msb() const {
  return mantissa_msb_;
}
inline void Decimal::set_mantissa_msb(::google::protobuf::uint64 value) {
  set_has_mantissa_msb();
  mantissa_msb_ = value;
}

// optional uint32 mantissa_lsb = 2;
inline bool Decimal::has_mantissa_lsb() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Decimal::set_has_mantissa_lsb() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Decimal::clear_has_mantissa_lsb() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Decimal::clear_mantissa_lsb() {
  mantissa_lsb_ = 0u;
  clear_has_mantissa_lsb();
}
inline ::google::protobuf::uint32 Decimal::mantissa_lsb() const {
  return mantissa_lsb_;
}
inline void Decimal::set_mantissa_lsb(::google::protobuf::uint32 value) {
  set_has_mantissa_lsb();
  mantissa_lsb_ = value;
}

// required sint32 exponent_and_sign = 3;
inline bool Decimal::has_exponent_and_sign() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Decimal::set_has_exponent_and_sign() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Decimal::clear_has_exponent_and_sign() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Decimal::clear_exponent_and_sign() {
  exponent_and_sign_ = 0;
  clear_has_exponent_and_sign();
}
inline ::google::protobuf::int32 Decimal::exponent_and_sign() const {
  return exponent_and_sign_;
}
inline void Decimal::set_exponent_and_sign(::google::protobuf::int32 value) {
  set_has_exponent_and_sign();
  exponent_and_sign_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb
}  // namespace urpc

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Decimal_2eproto__INCLUDED
