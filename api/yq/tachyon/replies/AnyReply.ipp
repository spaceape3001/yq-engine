////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AnyReply.hpp"
#include <yq/tachyon/api/ReplyInfoWriter.hpp>

namespace yq::tachyon {
    AnyReply::AnyReply(const RequestCPtr& rq, const Any& val, const Param&p) : Reply(rq, p), m_value(val)
    {
    }
    
    AnyReply::AnyReply(const RequestCPtr& rq, Any&& val, const Param&p) : Reply(rq, p), m_value(std::move(val))
    {
    }
    
    AnyReply::~AnyReply()
    {
    }

    void AnyReply::init_info()
    {
        auto w = writer<AnyReply>();
        w.description("Any Reply");
        w.property("value", &AnyReply::value);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::AnyReply)
