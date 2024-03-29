// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: company.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_company_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_company_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "address.pb.h"
#include "name.pb.h"
#include "phone.pb.h"
#include "working_time.pb.h"
#include "url.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_company_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_company_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_company_2eproto;
namespace YellowPages {
class Company;
struct CompanyDefaultTypeInternal;
extern CompanyDefaultTypeInternal _Company_default_instance_;
}  // namespace YellowPages
PROTOBUF_NAMESPACE_OPEN
template<> ::YellowPages::Company* Arena::CreateMaybeMessage<::YellowPages::Company>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace YellowPages {

// ===================================================================

class Company final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:YellowPages.Company) */ {
 public:
  inline Company() : Company(nullptr) {}
  ~Company() override;
  explicit constexpr Company(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Company(const Company& from);
  Company(Company&& from) noexcept
    : Company() {
    *this = ::std::move(from);
  }

  inline Company& operator=(const Company& from) {
    CopyFrom(from);
    return *this;
  }
  inline Company& operator=(Company&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Company& default_instance() {
    return *internal_default_instance();
  }
  static inline const Company* internal_default_instance() {
    return reinterpret_cast<const Company*>(
               &_Company_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Company& a, Company& b) {
    a.Swap(&b);
  }
  inline void Swap(Company* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Company* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Company* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Company>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Company& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Company& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Company* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "YellowPages.Company";
  }
  protected:
  explicit Company(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNamesFieldNumber = 2,
    kPhonesFieldNumber = 3,
    kUrlsFieldNumber = 4,
    kAddressFieldNumber = 1,
    kWorkingTimeFieldNumber = 6,
  };
  // repeated .YellowPages.Name names = 2;
  int names_size() const;
  private:
  int _internal_names_size() const;
  public:
  void clear_names();
  ::YellowPages::Name* mutable_names(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Name >*
      mutable_names();
  private:
  const ::YellowPages::Name& _internal_names(int index) const;
  ::YellowPages::Name* _internal_add_names();
  public:
  const ::YellowPages::Name& names(int index) const;
  ::YellowPages::Name* add_names();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Name >&
      names() const;

  // repeated .YellowPages.Phone phones = 3;
  int phones_size() const;
  private:
  int _internal_phones_size() const;
  public:
  void clear_phones();
  ::YellowPages::Phone* mutable_phones(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Phone >*
      mutable_phones();
  private:
  const ::YellowPages::Phone& _internal_phones(int index) const;
  ::YellowPages::Phone* _internal_add_phones();
  public:
  const ::YellowPages::Phone& phones(int index) const;
  ::YellowPages::Phone* add_phones();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Phone >&
      phones() const;

  // repeated .YellowPages.Url urls = 4;
  int urls_size() const;
  private:
  int _internal_urls_size() const;
  public:
  void clear_urls();
  ::YellowPages::Url* mutable_urls(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Url >*
      mutable_urls();
  private:
  const ::YellowPages::Url& _internal_urls(int index) const;
  ::YellowPages::Url* _internal_add_urls();
  public:
  const ::YellowPages::Url& urls(int index) const;
  ::YellowPages::Url* add_urls();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Url >&
      urls() const;

  // .YellowPages.Address address = 1;
  bool has_address() const;
  private:
  bool _internal_has_address() const;
  public:
  void clear_address();
  const ::YellowPages::Address& address() const;
  PROTOBUF_NODISCARD ::YellowPages::Address* release_address();
  ::YellowPages::Address* mutable_address();
  void set_allocated_address(::YellowPages::Address* address);
  private:
  const ::YellowPages::Address& _internal_address() const;
  ::YellowPages::Address* _internal_mutable_address();
  public:
  void unsafe_arena_set_allocated_address(
      ::YellowPages::Address* address);
  ::YellowPages::Address* unsafe_arena_release_address();

  // .YellowPages.WorkingTime working_time = 6;
  bool has_working_time() const;
  private:
  bool _internal_has_working_time() const;
  public:
  void clear_working_time();
  const ::YellowPages::WorkingTime& working_time() const;
  PROTOBUF_NODISCARD ::YellowPages::WorkingTime* release_working_time();
  ::YellowPages::WorkingTime* mutable_working_time();
  void set_allocated_working_time(::YellowPages::WorkingTime* working_time);
  private:
  const ::YellowPages::WorkingTime& _internal_working_time() const;
  ::YellowPages::WorkingTime* _internal_mutable_working_time();
  public:
  void unsafe_arena_set_allocated_working_time(
      ::YellowPages::WorkingTime* working_time);
  ::YellowPages::WorkingTime* unsafe_arena_release_working_time();

  // @@protoc_insertion_point(class_scope:YellowPages.Company)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Name > names_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Phone > phones_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Url > urls_;
  ::YellowPages::Address* address_;
  ::YellowPages::WorkingTime* working_time_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_company_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Company

// .YellowPages.Address address = 1;
inline bool Company::_internal_has_address() const {
  return this != internal_default_instance() && address_ != nullptr;
}
inline bool Company::has_address() const {
  return _internal_has_address();
}
inline const ::YellowPages::Address& Company::_internal_address() const {
  const ::YellowPages::Address* p = address_;
  return p != nullptr ? *p : reinterpret_cast<const ::YellowPages::Address&>(
      ::YellowPages::_Address_default_instance_);
}
inline const ::YellowPages::Address& Company::address() const {
  // @@protoc_insertion_point(field_get:YellowPages.Company.address)
  return _internal_address();
}
inline void Company::unsafe_arena_set_allocated_address(
    ::YellowPages::Address* address) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(address_);
  }
  address_ = address;
  if (address) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:YellowPages.Company.address)
}
inline ::YellowPages::Address* Company::release_address() {
  
  ::YellowPages::Address* temp = address_;
  address_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::YellowPages::Address* Company::unsafe_arena_release_address() {
  // @@protoc_insertion_point(field_release:YellowPages.Company.address)
  
  ::YellowPages::Address* temp = address_;
  address_ = nullptr;
  return temp;
}
inline ::YellowPages::Address* Company::_internal_mutable_address() {
  
  if (address_ == nullptr) {
    auto* p = CreateMaybeMessage<::YellowPages::Address>(GetArenaForAllocation());
    address_ = p;
  }
  return address_;
}
inline ::YellowPages::Address* Company::mutable_address() {
  ::YellowPages::Address* _msg = _internal_mutable_address();
  // @@protoc_insertion_point(field_mutable:YellowPages.Company.address)
  return _msg;
}
inline void Company::set_allocated_address(::YellowPages::Address* address) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(address_);
  }
  if (address) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(address));
    if (message_arena != submessage_arena) {
      address = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, address, submessage_arena);
    }
    
  } else {
    
  }
  address_ = address;
  // @@protoc_insertion_point(field_set_allocated:YellowPages.Company.address)
}

// repeated .YellowPages.Name names = 2;
inline int Company::_internal_names_size() const {
  return names_.size();
}
inline int Company::names_size() const {
  return _internal_names_size();
}
inline ::YellowPages::Name* Company::mutable_names(int index) {
  // @@protoc_insertion_point(field_mutable:YellowPages.Company.names)
  return names_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Name >*
Company::mutable_names() {
  // @@protoc_insertion_point(field_mutable_list:YellowPages.Company.names)
  return &names_;
}
inline const ::YellowPages::Name& Company::_internal_names(int index) const {
  return names_.Get(index);
}
inline const ::YellowPages::Name& Company::names(int index) const {
  // @@protoc_insertion_point(field_get:YellowPages.Company.names)
  return _internal_names(index);
}
inline ::YellowPages::Name* Company::_internal_add_names() {
  return names_.Add();
}
inline ::YellowPages::Name* Company::add_names() {
  ::YellowPages::Name* _add = _internal_add_names();
  // @@protoc_insertion_point(field_add:YellowPages.Company.names)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Name >&
Company::names() const {
  // @@protoc_insertion_point(field_list:YellowPages.Company.names)
  return names_;
}

// repeated .YellowPages.Phone phones = 3;
inline int Company::_internal_phones_size() const {
  return phones_.size();
}
inline int Company::phones_size() const {
  return _internal_phones_size();
}
inline ::YellowPages::Phone* Company::mutable_phones(int index) {
  // @@protoc_insertion_point(field_mutable:YellowPages.Company.phones)
  return phones_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Phone >*
Company::mutable_phones() {
  // @@protoc_insertion_point(field_mutable_list:YellowPages.Company.phones)
  return &phones_;
}
inline const ::YellowPages::Phone& Company::_internal_phones(int index) const {
  return phones_.Get(index);
}
inline const ::YellowPages::Phone& Company::phones(int index) const {
  // @@protoc_insertion_point(field_get:YellowPages.Company.phones)
  return _internal_phones(index);
}
inline ::YellowPages::Phone* Company::_internal_add_phones() {
  return phones_.Add();
}
inline ::YellowPages::Phone* Company::add_phones() {
  ::YellowPages::Phone* _add = _internal_add_phones();
  // @@protoc_insertion_point(field_add:YellowPages.Company.phones)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Phone >&
Company::phones() const {
  // @@protoc_insertion_point(field_list:YellowPages.Company.phones)
  return phones_;
}

// repeated .YellowPages.Url urls = 4;
inline int Company::_internal_urls_size() const {
  return urls_.size();
}
inline int Company::urls_size() const {
  return _internal_urls_size();
}
inline ::YellowPages::Url* Company::mutable_urls(int index) {
  // @@protoc_insertion_point(field_mutable:YellowPages.Company.urls)
  return urls_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Url >*
Company::mutable_urls() {
  // @@protoc_insertion_point(field_mutable_list:YellowPages.Company.urls)
  return &urls_;
}
inline const ::YellowPages::Url& Company::_internal_urls(int index) const {
  return urls_.Get(index);
}
inline const ::YellowPages::Url& Company::urls(int index) const {
  // @@protoc_insertion_point(field_get:YellowPages.Company.urls)
  return _internal_urls(index);
}
inline ::YellowPages::Url* Company::_internal_add_urls() {
  return urls_.Add();
}
inline ::YellowPages::Url* Company::add_urls() {
  ::YellowPages::Url* _add = _internal_add_urls();
  // @@protoc_insertion_point(field_add:YellowPages.Company.urls)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Url >&
Company::urls() const {
  // @@protoc_insertion_point(field_list:YellowPages.Company.urls)
  return urls_;
}

// .YellowPages.WorkingTime working_time = 6;
inline bool Company::_internal_has_working_time() const {
  return this != internal_default_instance() && working_time_ != nullptr;
}
inline bool Company::has_working_time() const {
  return _internal_has_working_time();
}
inline const ::YellowPages::WorkingTime& Company::_internal_working_time() const {
  const ::YellowPages::WorkingTime* p = working_time_;
  return p != nullptr ? *p : reinterpret_cast<const ::YellowPages::WorkingTime&>(
      ::YellowPages::_WorkingTime_default_instance_);
}
inline const ::YellowPages::WorkingTime& Company::working_time() const {
  // @@protoc_insertion_point(field_get:YellowPages.Company.working_time)
  return _internal_working_time();
}
inline void Company::unsafe_arena_set_allocated_working_time(
    ::YellowPages::WorkingTime* working_time) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(working_time_);
  }
  working_time_ = working_time;
  if (working_time) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:YellowPages.Company.working_time)
}
inline ::YellowPages::WorkingTime* Company::release_working_time() {
  
  ::YellowPages::WorkingTime* temp = working_time_;
  working_time_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::YellowPages::WorkingTime* Company::unsafe_arena_release_working_time() {
  // @@protoc_insertion_point(field_release:YellowPages.Company.working_time)
  
  ::YellowPages::WorkingTime* temp = working_time_;
  working_time_ = nullptr;
  return temp;
}
inline ::YellowPages::WorkingTime* Company::_internal_mutable_working_time() {
  
  if (working_time_ == nullptr) {
    auto* p = CreateMaybeMessage<::YellowPages::WorkingTime>(GetArenaForAllocation());
    working_time_ = p;
  }
  return working_time_;
}
inline ::YellowPages::WorkingTime* Company::mutable_working_time() {
  ::YellowPages::WorkingTime* _msg = _internal_mutable_working_time();
  // @@protoc_insertion_point(field_mutable:YellowPages.Company.working_time)
  return _msg;
}
inline void Company::set_allocated_working_time(::YellowPages::WorkingTime* working_time) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(working_time_);
  }
  if (working_time) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(working_time));
    if (message_arena != submessage_arena) {
      working_time = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, working_time, submessage_arena);
    }
    
  } else {
    
  }
  working_time_ = working_time;
  // @@protoc_insertion_point(field_set_allocated:YellowPages.Company.working_time)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace YellowPages

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_company_2eproto
