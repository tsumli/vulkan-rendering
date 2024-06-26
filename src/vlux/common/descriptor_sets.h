#ifndef COMMON_DESCRIPTOR_SET_H
#define COMMON_DESCRIPTOR_SET_H

#include "pch.h"

namespace vlux {
class DescriptorSets {
   public:
    DescriptorSets(const VkDevice device, const VkDescriptorSetAllocateInfo& alloc_info) {
        descriptor_sets_.resize(alloc_info.descriptorSetCount);
        if (vkAllocateDescriptorSets(device, &alloc_info, descriptor_sets_.data()) != VK_SUCCESS) {
            throw std::runtime_error("failed to allocate descriptor sets!");
        }
    }
    ~DescriptorSets() = default;
    DescriptorSets(const DescriptorSets&) = delete;
    DescriptorSets& operator=(const DescriptorSets&) = delete;
    DescriptorSets(DescriptorSets&&) = default;
    DescriptorSets& operator=(DescriptorSets&&) = default;

    VkDescriptorSet GetVkDescriptorSet(const size_t idx) const { return descriptor_sets_.at(idx); }
    const VkDescriptorSet* GetVkDescriptorSetPtr() const { return descriptor_sets_.data(); }
    size_t GetSize() const { return descriptor_sets_.size(); }

   private:
    std::vector<VkDescriptorSet> descriptor_sets_;
};
}  // namespace vlux
#endif