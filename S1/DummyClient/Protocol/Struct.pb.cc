// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#include "Struct.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace Protocol {

inline constexpr PlayerInfo::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : object_id_{::uint64_t{0u}},
        x_{0},
        y_{0},
        z_{0},
        yaw_{0},
        state_{static_cast< ::Protocol::MoveState >(0)},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR PlayerInfo::PlayerInfo(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct PlayerInfoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PlayerInfoDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~PlayerInfoDefaultTypeInternal() {}
  union {
    PlayerInfo _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PlayerInfoDefaultTypeInternal _PlayerInfo_default_instance_;
}  // namespace Protocol
static ::_pb::Metadata file_level_metadata_Struct_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_Struct_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_Struct_2eproto = nullptr;
const ::uint32_t TableStruct_Struct_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _impl_.object_id_),
    PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _impl_.x_),
    PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _impl_.y_),
    PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _impl_.z_),
    PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _impl_.yaw_),
    PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _impl_.state_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::Protocol::PlayerInfo)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::Protocol::_PlayerInfo_default_instance_._instance,
};
const char descriptor_table_protodef_Struct_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\014Struct.proto\022\010Protocol\032\nEnum.proto\"q\n\n"
    "PlayerInfo\022\021\n\tobject_id\030\001 \001(\004\022\t\n\001x\030\002 \001(\002"
    "\022\t\n\001y\030\003 \001(\002\022\t\n\001z\030\004 \001(\002\022\013\n\003yaw\030\005 \001(\002\022\"\n\005s"
    "tate\030\006 \001(\0162\023.Protocol.MoveStateb\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_Struct_2eproto_deps[1] =
    {
        &::descriptor_table_Enum_2eproto,
};
static ::absl::once_flag descriptor_table_Struct_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_Struct_2eproto = {
    false,
    false,
    159,
    descriptor_table_protodef_Struct_2eproto,
    "Struct.proto",
    &descriptor_table_Struct_2eproto_once,
    descriptor_table_Struct_2eproto_deps,
    1,
    1,
    schemas,
    file_default_instances,
    TableStruct_Struct_2eproto::offsets,
    file_level_metadata_Struct_2eproto,
    file_level_enum_descriptors_Struct_2eproto,
    file_level_service_descriptors_Struct_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_Struct_2eproto_getter() {
  return &descriptor_table_Struct_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_Struct_2eproto(&descriptor_table_Struct_2eproto);
namespace Protocol {
// ===================================================================

class PlayerInfo::_Internal {
 public:
};

PlayerInfo::PlayerInfo(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Protocol.PlayerInfo)
}
PlayerInfo::PlayerInfo(
    ::google::protobuf::Arena* arena, const PlayerInfo& from)
    : PlayerInfo(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE PlayerInfo::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void PlayerInfo::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, object_id_),
           0,
           offsetof(Impl_, state_) -
               offsetof(Impl_, object_id_) +
               sizeof(Impl_::state_));
}
PlayerInfo::~PlayerInfo() {
  // @@protoc_insertion_point(destructor:Protocol.PlayerInfo)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void PlayerInfo::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void PlayerInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.PlayerInfo)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.object_id_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.state_) -
      reinterpret_cast<char*>(&_impl_.object_id_)) + sizeof(_impl_.state_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* PlayerInfo::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 6, 0, 0, 2> PlayerInfo::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    6, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967232,  // skipmap
    offsetof(decltype(_table_), field_entries),
    6,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_PlayerInfo_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // uint64 object_id = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(PlayerInfo, _impl_.object_id_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.object_id_)}},
    // float x = 2;
    {::_pbi::TcParser::FastF32S1,
     {21, 63, 0, PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.x_)}},
    // float y = 3;
    {::_pbi::TcParser::FastF32S1,
     {29, 63, 0, PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.y_)}},
    // float z = 4;
    {::_pbi::TcParser::FastF32S1,
     {37, 63, 0, PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.z_)}},
    // float yaw = 5;
    {::_pbi::TcParser::FastF32S1,
     {45, 63, 0, PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.yaw_)}},
    // .Protocol.MoveState state = 6;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(PlayerInfo, _impl_.state_), 63>(),
     {48, 63, 0, PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.state_)}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // uint64 object_id = 1;
    {PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.object_id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
    // float x = 2;
    {PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.x_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // float y = 3;
    {PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.y_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // float z = 4;
    {PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.z_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // float yaw = 5;
    {PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.yaw_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // .Protocol.MoveState state = 6;
    {PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.state_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kOpenEnum)},
  }},
  // no aux_entries
  {{
  }},
};

::uint8_t* PlayerInfo::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.PlayerInfo)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // uint64 object_id = 1;
  if (this->_internal_object_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
        1, this->_internal_object_id(), target);
  }

  // float x = 2;
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_x = this->_internal_x();
  ::uint32_t raw_x;
  memcpy(&raw_x, &tmp_x, sizeof(tmp_x));
  if (raw_x != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(
        2, this->_internal_x(), target);
  }

  // float y = 3;
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_y = this->_internal_y();
  ::uint32_t raw_y;
  memcpy(&raw_y, &tmp_y, sizeof(tmp_y));
  if (raw_y != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(
        3, this->_internal_y(), target);
  }

  // float z = 4;
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_z = this->_internal_z();
  ::uint32_t raw_z;
  memcpy(&raw_z, &tmp_z, sizeof(tmp_z));
  if (raw_z != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(
        4, this->_internal_z(), target);
  }

  // float yaw = 5;
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_yaw = this->_internal_yaw();
  ::uint32_t raw_yaw;
  memcpy(&raw_yaw, &tmp_yaw, sizeof(tmp_yaw));
  if (raw_yaw != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(
        5, this->_internal_yaw(), target);
  }

  // .Protocol.MoveState state = 6;
  if (this->_internal_state() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
        6, this->_internal_state(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.PlayerInfo)
  return target;
}

::size_t PlayerInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.PlayerInfo)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint64 object_id = 1;
  if (this->_internal_object_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
        this->_internal_object_id());
  }

  // float x = 2;
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_x = this->_internal_x();
  ::uint32_t raw_x;
  memcpy(&raw_x, &tmp_x, sizeof(tmp_x));
  if (raw_x != 0) {
    total_size += 5;
  }

  // float y = 3;
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_y = this->_internal_y();
  ::uint32_t raw_y;
  memcpy(&raw_y, &tmp_y, sizeof(tmp_y));
  if (raw_y != 0) {
    total_size += 5;
  }

  // float z = 4;
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_z = this->_internal_z();
  ::uint32_t raw_z;
  memcpy(&raw_z, &tmp_z, sizeof(tmp_z));
  if (raw_z != 0) {
    total_size += 5;
  }

  // float yaw = 5;
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_yaw = this->_internal_yaw();
  ::uint32_t raw_yaw;
  memcpy(&raw_yaw, &tmp_yaw, sizeof(tmp_yaw));
  if (raw_yaw != 0) {
    total_size += 5;
  }

  // .Protocol.MoveState state = 6;
  if (this->_internal_state() != 0) {
    total_size += 1 +
                  ::_pbi::WireFormatLite::EnumSize(this->_internal_state());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData PlayerInfo::_class_data_ = {
    PlayerInfo::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* PlayerInfo::GetClassData() const {
  return &_class_data_;
}

void PlayerInfo::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<PlayerInfo*>(&to_msg);
  auto& from = static_cast<const PlayerInfo&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Protocol.PlayerInfo)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_object_id() != 0) {
    _this->_internal_set_object_id(from._internal_object_id());
  }
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_x = from._internal_x();
  ::uint32_t raw_x;
  memcpy(&raw_x, &tmp_x, sizeof(tmp_x));
  if (raw_x != 0) {
    _this->_internal_set_x(from._internal_x());
  }
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_y = from._internal_y();
  ::uint32_t raw_y;
  memcpy(&raw_y, &tmp_y, sizeof(tmp_y));
  if (raw_y != 0) {
    _this->_internal_set_y(from._internal_y());
  }
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_z = from._internal_z();
  ::uint32_t raw_z;
  memcpy(&raw_z, &tmp_z, sizeof(tmp_z));
  if (raw_z != 0) {
    _this->_internal_set_z(from._internal_z());
  }
  static_assert(sizeof(::uint32_t) == sizeof(float),
                "Code assumes ::uint32_t and float are the same size.");
  float tmp_yaw = from._internal_yaw();
  ::uint32_t raw_yaw;
  memcpy(&raw_yaw, &tmp_yaw, sizeof(tmp_yaw));
  if (raw_yaw != 0) {
    _this->_internal_set_yaw(from._internal_yaw());
  }
  if (from._internal_state() != 0) {
    _this->_internal_set_state(from._internal_state());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void PlayerInfo::CopyFrom(const PlayerInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.PlayerInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool PlayerInfo::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* PlayerInfo::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void PlayerInfo::InternalSwap(PlayerInfo* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.state_)
      + sizeof(PlayerInfo::_impl_.state_)
      - PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.object_id_)>(
          reinterpret_cast<char*>(&_impl_.object_id_),
          reinterpret_cast<char*>(&other->_impl_.object_id_));
}

::google::protobuf::Metadata PlayerInfo::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Struct_2eproto_getter, &descriptor_table_Struct_2eproto_once,
      file_level_metadata_Struct_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
