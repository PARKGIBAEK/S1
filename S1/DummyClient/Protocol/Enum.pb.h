// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Enum.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_Enum_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_Enum_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025001 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_Enum_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_Enum_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_Enum_2eproto;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace Protocol {
enum PlayerType : int {
  PLAYER_TYPE_NONE = 0,
  PLAYER_TYPE_KNIGHT = 1,
  PLAYER_TYPE_MAGE = 2,
  PLAYER_TYPE_ARCHER = 3,
  PlayerType_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  PlayerType_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool PlayerType_IsValid(int value);
extern const uint32_t PlayerType_internal_data_[];
constexpr PlayerType PlayerType_MIN = static_cast<PlayerType>(0);
constexpr PlayerType PlayerType_MAX = static_cast<PlayerType>(3);
constexpr int PlayerType_ARRAYSIZE = 3 + 1;
const ::google::protobuf::EnumDescriptor*
PlayerType_descriptor();
template <typename T>
const std::string& PlayerType_Name(T value) {
  static_assert(std::is_same<T, PlayerType>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to PlayerType_Name().");
  return PlayerType_Name(static_cast<PlayerType>(value));
}
template <>
inline const std::string& PlayerType_Name(PlayerType value) {
  return ::google::protobuf::internal::NameOfDenseEnum<PlayerType_descriptor,
                                                 0, 3>(
      static_cast<int>(value));
}
inline bool PlayerType_Parse(absl::string_view name, PlayerType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PlayerType>(
      PlayerType_descriptor(), name, value);
}
enum MoveState : int {
  MOVE_STATE_NONE = 0,
  MOVE_STATE_IDLE = 1,
  MOVE_STATE_RUN = 2,
  MOVE_STATE_JUMP = 3,
  MoveState_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  MoveState_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool MoveState_IsValid(int value);
extern const uint32_t MoveState_internal_data_[];
constexpr MoveState MoveState_MIN = static_cast<MoveState>(0);
constexpr MoveState MoveState_MAX = static_cast<MoveState>(3);
constexpr int MoveState_ARRAYSIZE = 3 + 1;
const ::google::protobuf::EnumDescriptor*
MoveState_descriptor();
template <typename T>
const std::string& MoveState_Name(T value) {
  static_assert(std::is_same<T, MoveState>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to MoveState_Name().");
  return MoveState_Name(static_cast<MoveState>(value));
}
template <>
inline const std::string& MoveState_Name(MoveState value) {
  return ::google::protobuf::internal::NameOfDenseEnum<MoveState_descriptor,
                                                 0, 3>(
      static_cast<int>(value));
}
inline bool MoveState_Parse(absl::string_view name, MoveState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MoveState>(
      MoveState_descriptor(), name, value);
}

// ===================================================================



// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::Protocol::PlayerType> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::Protocol::PlayerType>() {
  return ::Protocol::PlayerType_descriptor();
}
template <>
struct is_proto_enum<::Protocol::MoveState> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::Protocol::MoveState>() {
  return ::Protocol::MoveState_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_Enum_2eproto_2epb_2eh
