////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Command.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class Viewer;

    class ViewerCommandInfo : public CommandInfo {
    public:
        ViewerCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ViewerCommand : public Command, public ViewerBind {
        YQ_OBJECT_INFO(ViewerCommandInfo)
        YQ_OBJECT_DECLARE(ViewerCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        ViewerCommand(Viewer*, const Param& p = {});
        virtual ~ViewerCommand();
        
        static void init_info();
    };
}
