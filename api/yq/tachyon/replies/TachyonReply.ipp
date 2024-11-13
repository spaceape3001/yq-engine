////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonReply.hpp"

#include <yq/tachyon/post/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonReply)

namespace yq::tachyon {
    TachyonReplyInfo::TachyonReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl) :
        ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    TachyonReply::TachyonReply(const RequestCPtr& rq, Tachyon* v, const Param& p) : Reply(rq, p), TachyonBind(v)
    {
    }
    
    TachyonReply::~TachyonReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void TachyonReply::init_info()
    {
        auto w = writer<TachyonReply>();
        w.description("Tachyon reply base class");
    }
}
