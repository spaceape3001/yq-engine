////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class WindowCursorHideCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowCursorHideCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowCursorHideCommand(Viewer*, const Param& p = {});
        virtual ~WindowCursorHideCommand();
        
        static void init_info();
    };
}
