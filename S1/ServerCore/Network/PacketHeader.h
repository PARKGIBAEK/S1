﻿#pragma once

#include "Core/Types.h"

namespace ServerCore
{
constexpr int16 HEADER_SIZE = 4;

struct PacketHeader
{
    int16 size;
    int16 id;
};
}