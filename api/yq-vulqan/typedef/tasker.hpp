////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <functional>
#include <vulkan/vulkan_core.h>
#include <system_error>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    using tasker_fn     = std::function<void(VkCommandBuffer)>;
    
    class ViTasker;
    using ViTaskerPtr   = Ref<ViTasker>;
}
