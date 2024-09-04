#pragma once
#include <memory>
#include "Util/LockQueue.h"

namespace ServerCore
{

class JobQueue;
/* Passing `std::shared_ptr<JobQueue>` to allow other available threads to process the Jobs in the JobQueue as part of a distributed system.*/
class GlobalJobQueue
{
public:
    void Push(std::shared_ptr<JobQueue> _jobQueue);
    std::shared_ptr<JobQueue> Pop();
    void DoDistributedProcessingFromGlobalJobQueue();

private:
    LockQueue<std::shared_ptr<JobQueue>> m_jobQueues;
};
}
