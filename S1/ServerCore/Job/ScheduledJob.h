#pragma once
#include "Core/Types.h"



namespace ServerCore
{
struct JobData;

struct ScheduledJob
{
    bool operator<(const ScheduledJob& _other) const;

    uint64 m_scheduledTime;
    // The reason for using a raw pointer for `m_jobData` instead of `shared_ptr`
    // is to avoid changes in the reference count
    // when the `JobData` object is moved around.
    JobData* m_jobData;
};
}
