#ifndef COMMON_COMMAND_POOL_H
#define COMMON_COMMAND_POOL_H
#include "pch.h"

namespace vlux {
class CommandPool {
   public:
    CommandPool() = delete;
    CommandPool(const VkDevice device, const VkPhysicalDevice physical_device,
                const VkSurfaceKHR surface);
    ~CommandPool();

    // accessor
    VkCommandPool GetVkCommandPool() const { return command_pool_; }

   private:
    const VkDevice device_;
    VkCommandPool command_pool_;
};

}  // namespace vlux

#endif