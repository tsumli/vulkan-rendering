#ifndef DEVICE_RESOURCE_H
#define DEVICE_RESOURCE_H
#include "pch.h"
//
#include "debug_messenger.h"
#include "device.h"
#include "instance.h"
#include "surface.h"
#include "swapchain.h"
#include "sync_object.h"
#include "window.h"

namespace vlux {

class DeviceResource {
   public:
    DeviceResource(const Window& window, const bool vsync);
    ~DeviceResource();  // TODO: destructor order

    // accessor
    GLFWwindow* GetGLFWwindow() const { return window_.GetGLFWwindow(); }
    const Window& GetWindow() const { return window_; }
    const Device& GetDevice() const {
        if (!device_.has_value()) {
            throw std::runtime_error("`DeviceResource::device_` has no values.");
        }
        return device_.value();
    }
    const Surface& GetSurface() const {
        if (!surface_.has_value()) {
            throw std::runtime_error("`DeviceResource::surface_` has no values.");
        }
        return surface_.value();
    }
    VkPhysicalDevice GetVkPhysicalDevice() const {
        if (physical_device_ == VK_NULL_HANDLE) {
            throw std::runtime_error("`DeviceResource::physical_device_ == `VK_NULL_HANDLE`");
        }
        return physical_device_;
    }
    const Instance& GetInstance() const {
        if (!instance_.has_value()) {
            throw std::runtime_error("`DeviceResource::instance_ has no values.");
        }
        return instance_.value();
    }
    const SyncObject& GetSyncObject() const {
        if (!sync_object_.has_value()) {
            throw std::runtime_error("`DeviceResource::sync_object_` has no values.");
        }
        return sync_object_.value();
    }
    const Swapchain& GetSwapchain() const {
        if (!swapchain_.has_value()) {
            throw std::runtime_error("`DeviceResource::swapchain_` has no values.");
        }
        return swapchain_.value();
    }
    const VkQueue& GetGraphicsComputeQueue() const { return queues_.graphics_compute; }
    const VkQueue& GetPresentQueue() const { return queues_.present; }

    // method
    void DeviceWaitIdle() const;

    void RecreateSwapChain();

   private:
    const Window window_;
    VkPhysicalDevice physical_device_ = VK_NULL_HANDLE;
    Queues queues_;

    std::optional<Instance> instance_ = std::nullopt;
    std::optional<Device> device_ = std::nullopt;
    std::optional<Surface> surface_ = std::nullopt;
    std::optional<Swapchain> swapchain_ = std::nullopt;
    std::optional<DebugMessenger> debug_messenger_ = std::nullopt;
    std::optional<SyncObject> sync_object_ = std::nullopt;
};
}  // namespace vlux

#endif