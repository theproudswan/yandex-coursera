// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: company.proto

#include "company.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace YellowPages {
constexpr Company::Company(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : names_()
  , phones_()
  , urls_()
  , address_(nullptr)
  , working_time_(nullptr){}
struct CompanyDefaultTypeInternal {
  constexpr CompanyDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CompanyDefaultTypeInternal() {}
  union {
    Company _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CompanyDefaultTypeInternal _Company_default_instance_;
}  // namespace YellowPages
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_company_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_company_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_company_2eproto = nullptr;

const uint32_t TableStruct_company_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::YellowPages::Company, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::YellowPages::Company, address_),
  PROTOBUF_FIELD_OFFSET(::YellowPages::Company, names_),
  PROTOBUF_FIELD_OFFSET(::YellowPages::Company, phones_),
  PROTOBUF_FIELD_OFFSET(::YellowPages::Company, urls_),
  PROTOBUF_FIELD_OFFSET(::YellowPages::Company, working_time_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::YellowPages::Company)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::YellowPages::_Company_default_instance_),
};

const char descriptor_table_protodef_company_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rcompany.proto\022\013YellowPages\032\raddress.pr"
  "oto\032\nname.proto\032\013phone.proto\032\022working_ti"
  "me.proto\032\turl.proto\"\306\001\n\007Company\022%\n\007addre"
  "ss\030\001 \001(\0132\024.YellowPages.Address\022 \n\005names\030"
  "\002 \003(\0132\021.YellowPages.Name\022\"\n\006phones\030\003 \003(\013"
  "2\022.YellowPages.Phone\022\036\n\004urls\030\004 \003(\0132\020.Yel"
  "lowPages.Url\022.\n\014working_time\030\006 \001(\0132\030.Yel"
  "lowPages.WorkingTimeb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_company_2eproto_deps[5] = {
  &::descriptor_table_address_2eproto,
  &::descriptor_table_name_2eproto,
  &::descriptor_table_phone_2eproto,
  &::descriptor_table_url_2eproto,
  &::descriptor_table_working_5ftime_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_company_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_company_2eproto = {
  false, false, 308, descriptor_table_protodef_company_2eproto, "company.proto", 
  &descriptor_table_company_2eproto_once, descriptor_table_company_2eproto_deps, 5, 1,
  schemas, file_default_instances, TableStruct_company_2eproto::offsets,
  file_level_metadata_company_2eproto, file_level_enum_descriptors_company_2eproto, file_level_service_descriptors_company_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_company_2eproto_getter() {
  return &descriptor_table_company_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_company_2eproto(&descriptor_table_company_2eproto);
namespace YellowPages {

// ===================================================================

class Company::_Internal {
 public:
  static const ::YellowPages::Address& address(const Company* msg);
  static const ::YellowPages::WorkingTime& working_time(const Company* msg);
};

const ::YellowPages::Address&
Company::_Internal::address(const Company* msg) {
  return *msg->address_;
}
const ::YellowPages::WorkingTime&
Company::_Internal::working_time(const Company* msg) {
  return *msg->working_time_;
}
void Company::clear_address() {
  if (GetArenaForAllocation() == nullptr && address_ != nullptr) {
    delete address_;
  }
  address_ = nullptr;
}
void Company::clear_names() {
  names_.Clear();
}
void Company::clear_phones() {
  phones_.Clear();
}
void Company::clear_urls() {
  urls_.Clear();
}
void Company::clear_working_time() {
  if (GetArenaForAllocation() == nullptr && working_time_ != nullptr) {
    delete working_time_;
  }
  working_time_ = nullptr;
}
Company::Company(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  names_(arena),
  phones_(arena),
  urls_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:YellowPages.Company)
}
Company::Company(const Company& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      names_(from.names_),
      phones_(from.phones_),
      urls_(from.urls_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_address()) {
    address_ = new ::YellowPages::Address(*from.address_);
  } else {
    address_ = nullptr;
  }
  if (from._internal_has_working_time()) {
    working_time_ = new ::YellowPages::WorkingTime(*from.working_time_);
  } else {
    working_time_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:YellowPages.Company)
}

inline void Company::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&address_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&working_time_) -
    reinterpret_cast<char*>(&address_)) + sizeof(working_time_));
}

Company::~Company() {
  // @@protoc_insertion_point(destructor:YellowPages.Company)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Company::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete address_;
  if (this != internal_default_instance()) delete working_time_;
}

void Company::ArenaDtor(void* object) {
  Company* _this = reinterpret_cast< Company* >(object);
  (void)_this;
}
void Company::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Company::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Company::Clear() {
// @@protoc_insertion_point(message_clear_start:YellowPages.Company)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  names_.Clear();
  phones_.Clear();
  urls_.Clear();
  if (GetArenaForAllocation() == nullptr && address_ != nullptr) {
    delete address_;
  }
  address_ = nullptr;
  if (GetArenaForAllocation() == nullptr && working_time_ != nullptr) {
    delete working_time_;
  }
  working_time_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Company::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .YellowPages.Address address = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_address(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .YellowPages.Name names = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_names(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      // repeated .YellowPages.Phone phones = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_phones(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else
          goto handle_unusual;
        continue;
      // repeated .YellowPages.Url urls = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_urls(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
        } else
          goto handle_unusual;
        continue;
      // .YellowPages.WorkingTime working_time = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 50)) {
          ptr = ctx->ParseMessage(_internal_mutable_working_time(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Company::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:YellowPages.Company)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .YellowPages.Address address = 1;
  if (this->_internal_has_address()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::address(this), target, stream);
  }

  // repeated .YellowPages.Name names = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_names_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_names(i), target, stream);
  }

  // repeated .YellowPages.Phone phones = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_phones_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, this->_internal_phones(i), target, stream);
  }

  // repeated .YellowPages.Url urls = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_urls_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, this->_internal_urls(i), target, stream);
  }

  // .YellowPages.WorkingTime working_time = 6;
  if (this->_internal_has_working_time()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        6, _Internal::working_time(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:YellowPages.Company)
  return target;
}

size_t Company::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:YellowPages.Company)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .YellowPages.Name names = 2;
  total_size += 1UL * this->_internal_names_size();
  for (const auto& msg : this->names_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .YellowPages.Phone phones = 3;
  total_size += 1UL * this->_internal_phones_size();
  for (const auto& msg : this->phones_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .YellowPages.Url urls = 4;
  total_size += 1UL * this->_internal_urls_size();
  for (const auto& msg : this->urls_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // .YellowPages.Address address = 1;
  if (this->_internal_has_address()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *address_);
  }

  // .YellowPages.WorkingTime working_time = 6;
  if (this->_internal_has_working_time()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *working_time_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Company::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Company::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Company::GetClassData() const { return &_class_data_; }

void Company::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Company *>(to)->MergeFrom(
      static_cast<const Company &>(from));
}


void Company::MergeFrom(const Company& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:YellowPages.Company)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  names_.MergeFrom(from.names_);
  phones_.MergeFrom(from.phones_);
  urls_.MergeFrom(from.urls_);
  if (from._internal_has_address()) {
    _internal_mutable_address()->::YellowPages::Address::MergeFrom(from._internal_address());
  }
  if (from._internal_has_working_time()) {
    _internal_mutable_working_time()->::YellowPages::WorkingTime::MergeFrom(from._internal_working_time());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Company::CopyFrom(const Company& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:YellowPages.Company)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Company::IsInitialized() const {
  return true;
}

void Company::InternalSwap(Company* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  names_.InternalSwap(&other->names_);
  phones_.InternalSwap(&other->phones_);
  urls_.InternalSwap(&other->urls_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Company, working_time_)
      + sizeof(Company::working_time_)
      - PROTOBUF_FIELD_OFFSET(Company, address_)>(
          reinterpret_cast<char*>(&address_),
          reinterpret_cast<char*>(&other->address_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Company::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_company_2eproto_getter, &descriptor_table_company_2eproto_once,
      file_level_metadata_company_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace YellowPages
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::YellowPages::Company* Arena::CreateMaybeMessage< ::YellowPages::Company >(Arena* arena) {
  return Arena::CreateMessageInternal< ::YellowPages::Company >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
