////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/ui/RefreshRequest.hpp>
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RefreshRequest)

namespace yq::tachyon {

    RefreshRequest::RefreshRequest(const Header&h) : UIRequest(h)
    {
    }

    RefreshRequest::RefreshRequest(const RefreshRequest& cp, const Header& h) : UIRequest(cp, h)
    {
    }
    
    RefreshRequest::~RefreshRequest()
    {
    }

    PostCPtr    RefreshRequest::clone(rebind_k, const Header&h) const 
    {
        return new RefreshRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void RefreshRequest::init_info()
    {
        auto w = writer<RefreshRequest>();
        w.description("Refresh Request");
    }
}
