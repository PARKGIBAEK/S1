#include "pch.h"
#include "ScheduledJob.h"
#include "Job/JobData.h"



namespace ServerCore
{

bool ScheduledJob::operator<(const ScheduledJob& _other) const
{
    return m_scheduledTime > _other.m_scheduledTime;
}
}
