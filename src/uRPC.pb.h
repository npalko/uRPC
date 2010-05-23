// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: uRPC.proto

#ifndef PROTOBUF_uRPC_2eproto__INCLUDED
#define PROTOBUF_uRPC_2eproto__INCLUDED

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
#include "Log.pb.h"
// @@protoc_insertion_point(includes)

namespace urpc {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_uRPC_2eproto();
void protobuf_AssignDesc_uRPC_2eproto();
void protobuf_ShutdownFile_uRPC_2eproto();

class Request;
class Response;

// ===================================================================

class Request : public ::google::protobuf::Message {
 public:
  Request();
  virtual ~Request();
  
  Request(const Request& from);
  
  inline Request& operator=(const Request& from) {
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
  static const Request& default_instance();
  
  void Swap(Request* other);
  
  // implements Message ----------------------------------------------
  
  Request* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Request& from);
  void MergeFrom(const Request& from);
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
  
  // optional string service = 1;
  inline bool has_service() const;
  inline void clear_service();
  static const int kServiceFieldNumber = 1;
  inline const ::std::string& service() const;
  inline void set_service(const ::std::string& value);
  inline void set_service(const char* value);
  inline void set_service(const char* value, size_t size);
  inline ::std::string* mutable_service();
  
  // optional int32 version = 2;
  inline bool has_version() const;
  inline void clear_version();
  static const int kVersionFieldNumber = 2;
  inline ::google::protobuf::int32 version() const;
  inline void set_version(::google::protobuf::int32 value);
  
  // optional bytes message = 3;
  inline bool has_message() const;
  inline void clear_message();
  static const int kMessageFieldNumber = 3;
  inline const ::std::string& message() const;
  inline void set_message(const ::std::string& value);
  inline void set_message(const char* value);
  inline void set_message(const void* value, size_t size);
  inline ::std::string* mutable_message();
  
  // @@protoc_insertion_point(class_scope:urpc.Request)
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::std::string* service_;
  static const ::std::string _default_service_;
  ::google::protobuf::int32 version_;
  ::std::string* message_;
  static const ::std::string _default_message_;
  friend void  protobuf_AddDesc_uRPC_2eproto();
  friend void protobuf_AssignDesc_uRPC_2eproto();
  friend void protobuf_ShutdownFile_uRPC_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static Request* default_instance_;
};
// -------------------------------------------------------------------

class Response : public ::google::protobuf::Message {
 public:
  Response();
  virtual ~Response();
  
  Response(const Response& from);
  
  inline Response& operator=(const Response& from) {
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
  static const Response& default_instance();
  
  void Swap(Response* other);
  
  // implements Message ----------------------------------------------
  
  Response* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Response& from);
  void MergeFrom(const Response& from);
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
  
  // optional bool error = 1;
  inline bool has_error() const;
  inline void clear_error();
  static const int kErrorFieldNumber = 1;
  inline bool error() const;
  inline void set_error(bool value);
  
  // optional bytes message = 2;
  inline bool has_message() const;
  inline void clear_message();
  static const int kMessageFieldNumber = 2;
  inline const ::std::string& message() const;
  inline void set_message(const ::std::string& value);
  inline void set_message(const char* value);
  inline void set_message(const void* value, size_t size);
  inline ::std::string* mutable_message();
  
  // repeated .Log log = 3;
  inline int log_size() const;
  inline void clear_log();
  static const int kLogFieldNumber = 3;
  inline const ::Log& log(int index) const;
  inline ::Log* mutable_log(int index);
  inline ::Log* add_log();
  inline const ::google::protobuf::RepeatedPtrField< ::Log >&
      log() const;
  inline ::google::protobuf::RepeatedPtrField< ::Log >*
      mutable_log();
  
  // @@protoc_insertion_point(class_scope:urpc.Response)
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  bool error_;
  ::std::string* message_;
  static const ::std::string _default_message_;
  ::google::protobuf::RepeatedPtrField< ::Log > log_;
  friend void  protobuf_AddDesc_uRPC_2eproto();
  friend void protobuf_AssignDesc_uRPC_2eproto();
  friend void protobuf_ShutdownFile_uRPC_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static Response* default_instance_;
};
// ===================================================================


// ===================================================================

// Request

// optional string service = 1;
inline bool Request::has_service() const {
  return _has_bit(0);
}
inline void Request::clear_service() {
  if (service_ != &_default_service_) {
    service_->clear();
  }
  _clear_bit(0);
}
inline const ::std::string& Request::service() const {
  return *service_;
}
inline void Request::set_service(const ::std::string& value) {
  _set_bit(0);
  if (service_ == &_default_service_) {
    service_ = new ::std::string;
  }
  service_->assign(value);
}
inline void Request::set_service(const char* value) {
  _set_bit(0);
  if (service_ == &_default_service_) {
    service_ = new ::std::string;
  }
  service_->assign(value);
}
inline void Request::set_service(const char* value, size_t size) {
  _set_bit(0);
  if (service_ == &_default_service_) {
    service_ = new ::std::string;
  }
  service_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Request::mutable_service() {
  _set_bit(0);
  if (service_ == &_default_service_) {
    service_ = new ::std::string;
  }
  return service_;
}

// optional int32 version = 2;
inline bool Request::has_version() const {
  return _has_bit(1);
}
inline void Request::clear_version() {
  version_ = 0;
  _clear_bit(1);
}
inline ::google::protobuf::int32 Request::version() const {
  return version_;
}
inline void Request::set_version(::google::protobuf::int32 value) {
  _set_bit(1);
  version_ = value;
}

// optional bytes message = 3;
inline bool Request::has_message() const {
  return _has_bit(2);
}
inline void Request::clear_message() {
  if (message_ != &_default_message_) {
    message_->clear();
  }
  _clear_bit(2);
}
inline const ::std::string& Request::message() const {
  return *message_;
}
inline void Request::set_message(const ::std::string& value) {
  _set_bit(2);
  if (message_ == &_default_message_) {
    message_ = new ::std::string;
  }
  message_->assign(value);
}
inline void Request::set_message(const char* value) {
  _set_bit(2);
  if (message_ == &_default_message_) {
    message_ = new ::std::string;
  }
  message_->assign(value);
}
inline void Request::set_message(const void* value, size_t size) {
  _set_bit(2);
  if (message_ == &_default_message_) {
    message_ = new ::std::string;
  }
  message_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Request::mutable_message() {
  _set_bit(2);
  if (message_ == &_default_message_) {
    message_ = new ::std::string;
  }
  return message_;
}

// -------------------------------------------------------------------

// Response

// optional bool error = 1;
inline bool Response::has_error() const {
  return _has_bit(0);
}
inline void Response::clear_error() {
  error_ = false;
  _clear_bit(0);
}
inline bool Response::error() const {
  return error_;
}
inline void Response::set_error(bool value) {
  _set_bit(0);
  error_ = value;
}

// optional bytes message = 2;
inline bool Response::has_message() const {
  return _has_bit(1);
}
inline void Response::clear_message() {
  if (message_ != &_default_message_) {
    message_->clear();
  }
  _clear_bit(1);
}
inline const ::std::string& Response::message() const {
  return *message_;
}
inline void Response::set_message(const ::std::string& value) {
  _set_bit(1);
  if (message_ == &_default_message_) {
    message_ = new ::std::string;
  }
  message_->assign(value);
}
inline void Response::set_message(const char* value) {
  _set_bit(1);
  if (message_ == &_default_message_) {
    message_ = new ::std::string;
  }
  message_->assign(value);
}
inline void Response::set_message(const void* value, size_t size) {
  _set_bit(1);
  if (message_ == &_default_message_) {
    message_ = new ::std::string;
  }
  message_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Response::mutable_message() {
  _set_bit(1);
  if (message_ == &_default_message_) {
    message_ = new ::std::string;
  }
  return message_;
}

// repeated .Log log = 3;
inline int Response::log_size() const {
  return log_.size();
}
inline void Response::clear_log() {
  log_.Clear();
}
inline const ::Log& Response::log(int index) const {
  return log_.Get(index);
}
inline ::Log* Response::mutable_log(int index) {
  return log_.Mutable(index);
}
inline ::Log* Response::add_log() {
  return log_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Log >&
Response::log() const {
  return log_;
}
inline ::google::protobuf::RepeatedPtrField< ::Log >*
Response::mutable_log() {
  return &log_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace urpc

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_uRPC_2eproto__INCLUDED
