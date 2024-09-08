////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Pipeline;
    using PipelinePtr     = Ref<Pipeline>;
    using PipelineCPtr    = Ref<const Pipeline>;
}
