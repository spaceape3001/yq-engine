////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Reply.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class Viewer;
    class ViewerRequest;

    class ViewerReplyInfo : public ReplyInfo {
    public:
        ViewerReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ViewerReply : public Reply, public ViewerBind {
        YQ_OBJECT_INFO(ViewerReplyInfo)
        YQ_OBJECT_DECLARE(ViewerReply, Reply)
    public:
    
        struct Param : public Reply::Param {
        };
    
        ViewerReply(const RequestCPtr&, Viewer*, const Param& p = {});
        virtual ~ViewerReply();
        
        static void init_info();
    };
}
