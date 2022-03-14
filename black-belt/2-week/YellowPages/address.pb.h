// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: address.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_address_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_address_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_address_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_address_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_address_2eproto;
namespace YellowPages {
class Address;
struct AddressDefaultTypeInternal;
extern AddressDefaultTypeInternal _Address_default_instance_;
class AddressComponent;
struct AddressComponentDefaultTypeInternal;
extern AddressComponentDefaultTypeInternal _AddressComponent_default_instance_;
class Coords;
struct CoordsDefaultTypeInternal;
extern CoordsDefaultTypeInternal _Coords_default_instance_;
}  // namespace YellowPages
PROTOBUF_NAMESPACE_OPEN
template<> ::YellowPages::Address* Arena::CreateMaybeMessage<::YellowPages::Address>(Arena*);
template<> ::YellowPages::AddressComponent* Arena::CreateMaybeMessage<::YellowPages::AddressComponent>(Arena*);
template<> ::YellowPages::Coords* Arena::CreateMaybeMessage<::YellowPages::Coords>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace YellowPages {

enum AddressComponent_Type : int {
  AddressComponent_Type_COUNTRY = 0,
  AddressComponent_Type_REGION = 1,
  AddressComponent_Type_CITY = 2,
  AddressComponent_Type_STREET = 3,
  AddressComponent_Type_HOUSE = 4,
  AddressComponent_Type_AddressComponent_Type_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  AddressComponent_Type_AddressComponent_Type_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool AddressComponent_Type_IsValid(int value);
constexpr AddressComponent_Type AddressComponent_Type_Type_MIN = AddressComponent_Type_COUNTRY;
constexpr AddressComponent_Type AddressComponent_Type_Type_MAX = AddressComponent_Type_HOUSE;
constexpr int AddressComponent_Type_Type_ARRAYSIZE = AddressComponent_Type_Type_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* AddressComponent_Type_descriptor();
template<typename T>
inline const std::string& AddressComponent_Type_Name(T enum_t_value) {
  static_assert(::std::is_same<T, AddressComponent_Type>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function AddressComponent_Type_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    AddressComponent_Type_descriptor(), enum_t_value);
}
inline bool AddressComponent_Type_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, AddressComponent_Type* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<AddressComponent_Type>(
    AddressComponent_Type_descriptor(), name, value);
}
// ===================================================================

class AddressComponent final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:YellowPages.AddressComponent) */ {
 public:
  inline AddressComponent() : AddressComponent(nullptr) {}
  ~AddressComponent() override;
  explicit constexpr AddressComponent(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  AddressComponent(const AddressComponent& from);
  AddressComponent(AddressComponent&& from) noexcept
    : AddressComponent() {
    *this = ::std::move(from);
  }

  inline AddressComponent& operator=(const AddressComponent& from) {
    CopyFrom(from);
    return *this;
  }
  inline AddressComponent& operator=(AddressComponent&& from) noexcept {
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
  static const AddressComponent& default_instance() {
    return *internal_default_instance();
  }
  static inline const AddressComponent* internal_default_instance() {
    return reinterpret_cast<const AddressComponent*>(
               &_AddressComponent_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(AddressComponent& a, AddressComponent& b) {
    a.Swap(&b);
  }
  inline void Swap(AddressComponent* other) {
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
  void UnsafeArenaSwap(AddressComponent* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  AddressComponent* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<AddressComponent>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const AddressComponent& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const AddressComponent& from);
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
  void InternalSwap(AddressComponent* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "YellowPages.AddressComponent";
  }
  protected:
  explicit AddressComponent(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef AddressComponent_Type Type;
  static constexpr Type COUNTRY =
    AddressComponent_Type_COUNTRY;
  static constexpr Type REGION =
    AddressComponent_Type_REGION;
  static constexpr Type CITY =
    AddressComponent_Type_CITY;
  static constexpr Type STREET =
    AddressComponent_Type_STREET;
  static constexpr Type HOUSE =
    AddressComponent_Type_HOUSE;
  static inline bool Type_IsValid(int value) {
    return AddressComponent_Type_IsValid(value);
  }
  static constexpr Type Type_MIN =
    AddressComponent_Type_Type_MIN;
  static constexpr Type Type_MAX =
    AddressComponent_Type_Type_MAX;
  static constexpr int Type_ARRAYSIZE =
    AddressComponent_Type_Type_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Type_descriptor() {
    return AddressComponent_Type_descriptor();
  }
  template<typename T>
  static inline const std::string& Type_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Type>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Type_Name.");
    return AddressComponent_Type_Name(enum_t_value);
  }
  static inline bool Type_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      Type* value) {
    return AddressComponent_Type_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kValueFieldNumber = 1,
  };
  // string value = 1;
  void clear_value();
  const std::string& value() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_value(ArgT0&& arg0, ArgT... args);
  std::string* mutable_value();
  PROTOBUF_NODISCARD std::string* release_value();
  void set_allocated_value(std::string* value);
  private:
  const std::string& _internal_value() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_value(const std::string& value);
  std::string* _internal_mutable_value();
  public:

  // @@protoc_insertion_point(class_scope:YellowPages.AddressComponent)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr value_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_address_2eproto;
};
// -------------------------------------------------------------------

class Coords final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:YellowPages.Coords) */ {
 public:
  inline Coords() : Coords(nullptr) {}
  ~Coords() override;
  explicit constexpr Coords(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Coords(const Coords& from);
  Coords(Coords&& from) noexcept
    : Coords() {
    *this = ::std::move(from);
  }

  inline Coords& operator=(const Coords& from) {
    CopyFrom(from);
    return *this;
  }
  inline Coords& operator=(Coords&& from) noexcept {
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
  static const Coords& default_instance() {
    return *internal_default_instance();
  }
  static inline const Coords* internal_default_instance() {
    return reinterpret_cast<const Coords*>(
               &_Coords_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Coords& a, Coords& b) {
    a.Swap(&b);
  }
  inline void Swap(Coords* other) {
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
  void UnsafeArenaSwap(Coords* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Coords* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Coords>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Coords& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Coords& from);
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
  void InternalSwap(Coords* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "YellowPages.Coords";
  }
  protected:
  explicit Coords(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kLatFieldNumber = 1,
    kLonFieldNumber = 2,
  };
  // double lat = 1;
  void clear_lat();
  double lat() const;
  void set_lat(double value);
  private:
  double _internal_lat() const;
  void _internal_set_lat(double value);
  public:

  // double lon = 2;
  void clear_lon();
  double lon() const;
  void set_lon(double value);
  private:
  double _internal_lon() const;
  void _internal_set_lon(double value);
  public:

  // @@protoc_insertion_point(class_scope:YellowPages.Coords)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double lat_;
  double lon_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_address_2eproto;
};
// -------------------------------------------------------------------

class Address final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:YellowPages.Address) */ {
 public:
  inline Address() : Address(nullptr) {}
  ~Address() override;
  explicit constexpr Address(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Address(const Address& from);
  Address(Address&& from) noexcept
    : Address() {
    *this = ::std::move(from);
  }

  inline Address& operator=(const Address& from) {
    CopyFrom(from);
    return *this;
  }
  inline Address& operator=(Address&& from) noexcept {
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
  static const Address& default_instance() {
    return *internal_default_instance();
  }
  static inline const Address* internal_default_instance() {
    return reinterpret_cast<const Address*>(
               &_Address_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Address& a, Address& b) {
    a.Swap(&b);
  }
  inline void Swap(Address* other) {
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
  void UnsafeArenaSwap(Address* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Address* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Address>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Address& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Address& from);
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
  void InternalSwap(Address* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "YellowPages.Address";
  }
  protected:
  explicit Address(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kComponentsFieldNumber = 2,
    kFormattedFieldNumber = 1,
    kCoordsFieldNumber = 3,
  };
  // repeated .YellowPages.AddressComponent components = 2;
  int components_size() const;
  private:
  int _internal_components_size() const;
  public:
  void clear_components();
  ::YellowPages::AddressComponent* mutable_components(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::AddressComponent >*
      mutable_components();
  private:
  const ::YellowPages::AddressComponent& _internal_components(int index) const;
  ::YellowPages::AddressComponent* _internal_add_components();
  public:
  const ::YellowPages::AddressComponent& components(int index) const;
  ::YellowPages::AddressComponent* add_components();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::AddressComponent >&
      components() const;

  // string formatted = 1;
  void clear_formatted();
  const std::string& formatted() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_formatted(ArgT0&& arg0, ArgT... args);
  std::string* mutable_formatted();
  PROTOBUF_NODISCARD std::string* release_formatted();
  void set_allocated_formatted(std::string* formatted);
  private:
  const std::string& _internal_formatted() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_formatted(const std::string& value);
  std::string* _internal_mutable_formatted();
  public:

  // .YellowPages.Coords coords = 3;
  bool has_coords() const;
  private:
  bool _internal_has_coords() const;
  public:
  void clear_coords();
  const ::YellowPages::Coords& coords() const;
  PROTOBUF_NODISCARD ::YellowPages::Coords* release_coords();
  ::YellowPages::Coords* mutable_coords();
  void set_allocated_coords(::YellowPages::Coords* coords);
  private:
  const ::YellowPages::Coords& _internal_coords() const;
  ::YellowPages::Coords* _internal_mutable_coords();
  public:
  void unsafe_arena_set_allocated_coords(
      ::YellowPages::Coords* coords);
  ::YellowPages::Coords* unsafe_arena_release_coords();

  // @@protoc_insertion_point(class_scope:YellowPages.Address)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::AddressComponent > components_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr formatted_;
  ::YellowPages::Coords* coords_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_address_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// AddressComponent

// string value = 1;
inline void AddressComponent::clear_value() {
  value_.ClearToEmpty();
}
inline const std::string& AddressComponent::value() const {
  // @@protoc_insertion_point(field_get:YellowPages.AddressComponent.value)
  return _internal_value();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void AddressComponent::set_value(ArgT0&& arg0, ArgT... args) {
 
 value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:YellowPages.AddressComponent.value)
}
inline std::string* AddressComponent::mutable_value() {
  std::string* _s = _internal_mutable_value();
  // @@protoc_insertion_point(field_mutable:YellowPages.AddressComponent.value)
  return _s;
}
inline const std::string& AddressComponent::_internal_value() const {
  return value_.Get();
}
inline void AddressComponent::_internal_set_value(const std::string& value) {
  
  value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* AddressComponent::_internal_mutable_value() {
  
  return value_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* AddressComponent::release_value() {
  // @@protoc_insertion_point(field_release:YellowPages.AddressComponent.value)
  return value_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void AddressComponent::set_allocated_value(std::string* value) {
  if (value != nullptr) {
    
  } else {
    
  }
  value_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (value_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    value_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:YellowPages.AddressComponent.value)
}

// -------------------------------------------------------------------

// Coords

// double lat = 1;
inline void Coords::clear_lat() {
  lat_ = 0;
}
inline double Coords::_internal_lat() const {
  return lat_;
}
inline double Coords::lat() const {
  // @@protoc_insertion_point(field_get:YellowPages.Coords.lat)
  return _internal_lat();
}
inline void Coords::_internal_set_lat(double value) {
  
  lat_ = value;
}
inline void Coords::set_lat(double value) {
  _internal_set_lat(value);
  // @@protoc_insertion_point(field_set:YellowPages.Coords.lat)
}

// double lon = 2;
inline void Coords::clear_lon() {
  lon_ = 0;
}
inline double Coords::_internal_lon() const {
  return lon_;
}
inline double Coords::lon() const {
  // @@protoc_insertion_point(field_get:YellowPages.Coords.lon)
  return _internal_lon();
}
inline void Coords::_internal_set_lon(double value) {
  
  lon_ = value;
}
inline void Coords::set_lon(double value) {
  _internal_set_lon(value);
  // @@protoc_insertion_point(field_set:YellowPages.Coords.lon)
}

// -------------------------------------------------------------------

// Address

// string formatted = 1;
inline void Address::clear_formatted() {
  formatted_.ClearToEmpty();
}
inline const std::string& Address::formatted() const {
  // @@protoc_insertion_point(field_get:YellowPages.Address.formatted)
  return _internal_formatted();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Address::set_formatted(ArgT0&& arg0, ArgT... args) {
 
 formatted_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:YellowPages.Address.formatted)
}
inline std::string* Address::mutable_formatted() {
  std::string* _s = _internal_mutable_formatted();
  // @@protoc_insertion_point(field_mutable:YellowPages.Address.formatted)
  return _s;
}
inline const std::string& Address::_internal_formatted() const {
  return formatted_.Get();
}
inline void Address::_internal_set_formatted(const std::string& value) {
  
  formatted_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Address::_internal_mutable_formatted() {
  
  return formatted_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Address::release_formatted() {
  // @@protoc_insertion_point(field_release:YellowPages.Address.formatted)
  return formatted_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Address::set_allocated_formatted(std::string* formatted) {
  if (formatted != nullptr) {
    
  } else {
    
  }
  formatted_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), formatted,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (formatted_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    formatted_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:YellowPages.Address.formatted)
}

// repeated .YellowPages.AddressComponent components = 2;
inline int Address::_internal_components_size() const {
  return components_.size();
}
inline int Address::components_size() const {
  return _internal_components_size();
}
inline void Address::clear_components() {
  components_.Clear();
}
inline ::YellowPages::AddressComponent* Address::mutable_components(int index) {
  // @@protoc_insertion_point(field_mutable:YellowPages.Address.components)
  return components_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::AddressComponent >*
Address::mutable_components() {
  // @@protoc_insertion_point(field_mutable_list:YellowPages.Address.components)
  return &components_;
}
inline const ::YellowPages::AddressComponent& Address::_internal_components(int index) const {
  return components_.Get(index);
}
inline const ::YellowPages::AddressComponent& Address::components(int index) const {
  // @@protoc_insertion_point(field_get:YellowPages.Address.components)
  return _internal_components(index);
}
inline ::YellowPages::AddressComponent* Address::_internal_add_components() {
  return components_.Add();
}
inline ::YellowPages::AddressComponent* Address::add_components() {
  ::YellowPages::AddressComponent* _add = _internal_add_components();
  // @@protoc_insertion_point(field_add:YellowPages.Address.components)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::AddressComponent >&
Address::components() const {
  // @@protoc_insertion_point(field_list:YellowPages.Address.components)
  return components_;
}

// .YellowPages.Coords coords = 3;
inline bool Address::_internal_has_coords() const {
  return this != internal_default_instance() && coords_ != nullptr;
}
inline bool Address::has_coords() const {
  return _internal_has_coords();
}
inline void Address::clear_coords() {
  if (GetArenaForAllocation() == nullptr && coords_ != nullptr) {
    delete coords_;
  }
  coords_ = nullptr;
}
inline const ::YellowPages::Coords& Address::_internal_coords() const {
  const ::YellowPages::Coords* p = coords_;
  return p != nullptr ? *p : reinterpret_cast<const ::YellowPages::Coords&>(
      ::YellowPages::_Coords_default_instance_);
}
inline const ::YellowPages::Coords& Address::coords() const {
  // @@protoc_insertion_point(field_get:YellowPages.Address.coords)
  return _internal_coords();
}
inline void Address::unsafe_arena_set_allocated_coords(
    ::YellowPages::Coords* coords) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(coords_);
  }
  coords_ = coords;
  if (coords) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:YellowPages.Address.coords)
}
inline ::YellowPages::Coords* Address::release_coords() {
  
  ::YellowPages::Coords* temp = coords_;
  coords_ = nullptr;
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
inline ::YellowPages::Coords* Address::unsafe_arena_release_coords() {
  // @@protoc_insertion_point(field_release:YellowPages.Address.coords)
  
  ::YellowPages::Coords* temp = coords_;
  coords_ = nullptr;
  return temp;
}
inline ::YellowPages::Coords* Address::_internal_mutable_coords() {
  
  if (coords_ == nullptr) {
    auto* p = CreateMaybeMessage<::YellowPages::Coords>(GetArenaForAllocation());
    coords_ = p;
  }
  return coords_;
}
inline ::YellowPages::Coords* Address::mutable_coords() {
  ::YellowPages::Coords* _msg = _internal_mutable_coords();
  // @@protoc_insertion_point(field_mutable:YellowPages.Address.coords)
  return _msg;
}
inline void Address::set_allocated_coords(::YellowPages::Coords* coords) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete coords_;
  }
  if (coords) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<::YellowPages::Coords>::GetOwningArena(coords);
    if (message_arena != submessage_arena) {
      coords = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, coords, submessage_arena);
    }
    
  } else {
    
  }
  coords_ = coords;
  // @@protoc_insertion_point(field_set_allocated:YellowPages.Address.coords)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace YellowPages

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::YellowPages::AddressComponent_Type> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::YellowPages::AddressComponent_Type>() {
  return ::YellowPages::AddressComponent_Type_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_address_2eproto
