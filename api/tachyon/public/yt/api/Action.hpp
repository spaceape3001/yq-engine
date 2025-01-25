////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Delegate.hpp>
#include <yt/typedef/command.hpp>
#include <yt/typedef/post.hpp>

namespace yq::tachyon {
    class Action;
    
    class ActionInfo : public DelegateInfo {
    public:
        template <typename> class Writer;
        template <typename> class Fixer;
        ActionInfo(std::string_view zName, DelegateInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~ActionInfo();
        
        // virtual CommandCPtr execute(const Action*, const PostCPtr&) const { return {}; }
    };

    class Action : public Delegate {
        YQ_OBJECT_INFO(ActionInfo)
        YQ_OBJECT_DECLARE(Action, Delegate)
    public:
        Action();
        ~Action();
        
        static void init_info();
        
        //  somehow...here...?  or action info... more likely
        // virtual CommandCPtr action(const PostCPtr&) const = 0;
        
        // Assuming we go this route
        virtual bool configure(/* TBD */) override;
    };
}
