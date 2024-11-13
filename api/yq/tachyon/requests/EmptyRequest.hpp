////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Request.hpp>

namespace yq::tachyon {

    //! Test/general post type that's empty
    class EmptyRequest : public Request {
        YQ_OBJECT_DECLARE(EmptyRequest, Request)
    public:
        
        //  contributing nothing extra....
        using Request::Param;
        
        EmptyRequest(const Param& p = {});
        ~EmptyRequest();
        
        static void init_info();
    };
}
