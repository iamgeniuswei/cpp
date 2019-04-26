// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: meta.proto

#ifndef PROTOBUF_INCLUDED_meta_2eproto
#define PROTOBUF_INCLUDED_meta_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3007000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3007001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_meta_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_meta_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_meta_2eproto();
namespace echo {
class RpcMeta;
class RpcMetaDefaultTypeInternal;
extern RpcMetaDefaultTypeInternal _RpcMeta_default_instance_;
}  // namespace echo
namespace google {
namespace protobuf {
template<> ::echo::RpcMeta* Arena::CreateMaybeMessage<::echo::RpcMeta>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace echo {

// ===================================================================

class RpcMeta :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:echo.RpcMeta) */ {
 public:
  RpcMeta();
  virtual ~RpcMeta();

  RpcMeta(const RpcMeta& from);

  inline RpcMeta& operator=(const RpcMeta& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RpcMeta(RpcMeta&& from) noexcept
    : RpcMeta() {
    *this = ::std::move(from);
  }

  inline RpcMeta& operator=(RpcMeta&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const RpcMeta& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RpcMeta* internal_default_instance() {
    return reinterpret_cast<const RpcMeta*>(
               &_RpcMeta_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(RpcMeta* other);
  friend void swap(RpcMeta& a, RpcMeta& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RpcMeta* New() const final {
    return CreateMaybeMessage<RpcMeta>(nullptr);
  }

  RpcMeta* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RpcMeta>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RpcMeta& from);
  void MergeFrom(const RpcMeta& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RpcMeta* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string service_name = 1;
  bool has_service_name() const;
  void clear_service_name();
  static const int kServiceNameFieldNumber = 1;
  const ::std::string& service_name() const;
  void set_service_name(const ::std::string& value);
  #if LANG_CXX11
  void set_service_name(::std::string&& value);
  #endif
  void set_service_name(const char* value);
  void set_service_name(const char* value, size_t size);
  ::std::string* mutable_service_name();
  ::std::string* release_service_name();
  void set_allocated_service_name(::std::string* service_name);

  // optional string method_name = 2;
  bool has_method_name() const;
  void clear_method_name();
  static const int kMethodNameFieldNumber = 2;
  const ::std::string& method_name() const;
  void set_method_name(const ::std::string& value);
  #if LANG_CXX11
  void set_method_name(::std::string&& value);
  #endif
  void set_method_name(const char* value);
  void set_method_name(const char* value, size_t size);
  ::std::string* mutable_method_name();
  ::std::string* release_method_name();
  void set_allocated_method_name(::std::string* method_name);

  // optional int32 data_size = 3;
  bool has_data_size() const;
  void clear_data_size();
  static const int kDataSizeFieldNumber = 3;
  ::google::protobuf::int32 data_size() const;
  void set_data_size(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:echo.RpcMeta)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr service_name_;
  ::google::protobuf::internal::ArenaStringPtr method_name_;
  ::google::protobuf::int32 data_size_;
  friend struct ::TableStruct_meta_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RpcMeta

// optional string service_name = 1;
inline bool RpcMeta::has_service_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RpcMeta::clear_service_name() {
  service_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const ::std::string& RpcMeta::service_name() const {
  // @@protoc_insertion_point(field_get:echo.RpcMeta.service_name)
  return service_name_.GetNoArena();
}
inline void RpcMeta::set_service_name(const ::std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  service_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:echo.RpcMeta.service_name)
}
#if LANG_CXX11
inline void RpcMeta::set_service_name(::std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  service_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:echo.RpcMeta.service_name)
}
#endif
inline void RpcMeta::set_service_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  service_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:echo.RpcMeta.service_name)
}
inline void RpcMeta::set_service_name(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  service_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:echo.RpcMeta.service_name)
}
inline ::std::string* RpcMeta::mutable_service_name() {
  _has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_mutable:echo.RpcMeta.service_name)
  return service_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RpcMeta::release_service_name() {
  // @@protoc_insertion_point(field_release:echo.RpcMeta.service_name)
  if (!has_service_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return service_name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RpcMeta::set_allocated_service_name(::std::string* service_name) {
  if (service_name != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  service_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), service_name);
  // @@protoc_insertion_point(field_set_allocated:echo.RpcMeta.service_name)
}

// optional string method_name = 2;
inline bool RpcMeta::has_method_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RpcMeta::clear_method_name() {
  method_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const ::std::string& RpcMeta::method_name() const {
  // @@protoc_insertion_point(field_get:echo.RpcMeta.method_name)
  return method_name_.GetNoArena();
}
inline void RpcMeta::set_method_name(const ::std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  method_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:echo.RpcMeta.method_name)
}
#if LANG_CXX11
inline void RpcMeta::set_method_name(::std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  method_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:echo.RpcMeta.method_name)
}
#endif
inline void RpcMeta::set_method_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  method_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:echo.RpcMeta.method_name)
}
inline void RpcMeta::set_method_name(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  method_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:echo.RpcMeta.method_name)
}
inline ::std::string* RpcMeta::mutable_method_name() {
  _has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_mutable:echo.RpcMeta.method_name)
  return method_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RpcMeta::release_method_name() {
  // @@protoc_insertion_point(field_release:echo.RpcMeta.method_name)
  if (!has_method_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return method_name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RpcMeta::set_allocated_method_name(::std::string* method_name) {
  if (method_name != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  method_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), method_name);
  // @@protoc_insertion_point(field_set_allocated:echo.RpcMeta.method_name)
}

// optional int32 data_size = 3;
inline bool RpcMeta::has_data_size() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RpcMeta::clear_data_size() {
  data_size_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::google::protobuf::int32 RpcMeta::data_size() const {
  // @@protoc_insertion_point(field_get:echo.RpcMeta.data_size)
  return data_size_;
}
inline void RpcMeta::set_data_size(::google::protobuf::int32 value) {
  _has_bits_[0] |= 0x00000004u;
  data_size_ = value;
  // @@protoc_insertion_point(field_set:echo.RpcMeta.data_size)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace echo

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_meta_2eproto