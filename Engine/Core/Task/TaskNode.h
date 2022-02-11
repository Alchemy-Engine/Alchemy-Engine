#pragma once

#include <atomic>
#include <functional>
#include <memory>
#include <vector>

namespace Alchemy
{


template<typename ResultType, typename... T>
class TaskNode
{
public:
    TaskNode(const std::function<ResultType(T...)>&);

    template<typename Res, typename... U>
    void DependOn(TaskNode<Res, U...>);

    void Execute();

private:
    // mFunction holds the task to be executed
    std::function<ResultType(T...)> mFunction;

    // mPreTaskCount records the remaining depended tasks
    std::atomic_int8_t mPreTaskCount;
};

    
} // namespace Alchemy
