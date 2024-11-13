////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Reply.hpp"
#include "ReplyInfoWriter.hpp"
#include <yq/tachyon/post/Request.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Reply)

namespace yq::tachyon {
    ReplyInfo::ReplyInfo(std::string_view zName, PostInfo& base, const std::source_location& sl) :
        PostInfo(zName, base, sl)
    {
        set(Flag::REPLY);
    }

    ////////////////////////////////////////////////////////////////////////////

    Reply::Reply(const RequestCPtr& req, const Param& p) : Post(p), m_request(req)
    {
    }
    
    Reply::~Reply()
    {
    }

    const Request*  Reply::request() const
    {
        return m_request.ptr();
    }

    ////////////////////////////////////////////////////////////////////////////

    void Reply::init_info()
    {
        auto w = writer<Reply>();
        w.description("Abstract Reply Class");
    }
}
