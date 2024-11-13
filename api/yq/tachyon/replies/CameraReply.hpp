////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Reply.hpp>
#include <yq/tachyon/camera/CameraBind.hpp>

namespace yq::tachyon {
    class Camera;
    class CameraRequest;

    class CameraReplyInfo : public ReplyInfo {
    public:
        CameraReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class CameraReply : public Reply, public CameraBind {
        YQ_OBJECT_INFO(CameraReplyInfo)
        YQ_OBJECT_DECLARE(CameraReply, Reply)
    public:
    
        struct Param : public Reply::Param {
        };
    
        CameraReply(const RequestCPtr&, Camera*, const Param& p = {});
        virtual ~CameraReply();
        
        static void init_info();
    };
}
