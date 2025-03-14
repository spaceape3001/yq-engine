////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/ViewerRequest.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerRequest)

namespace yq::tachyon {
    ViewerRequest::ViewerRequest(const Header&h) : Request(h)
    {
    }
    
    ViewerRequest::ViewerRequest(const ViewerRequest& cp, const Header& h) : Request(cp, h)
    {
    }

    ViewerRequest::~ViewerRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerRequest::init_info()
    {
        auto w = writer<ViewerRequest>();
        w.description("Viewer request base class");
    }
}
