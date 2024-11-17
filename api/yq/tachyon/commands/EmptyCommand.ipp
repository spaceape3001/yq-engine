////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "EmptyCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

namespace yq::tachyon {
    EmptyCommand::EmptyCommand(const Param&p) : Command(p) 
    {
    }
    
    EmptyCommand::~EmptyCommand()
    {
    }
    
    void EmptyCommand::init_info()
    {
        auto w = writer<EmptyCommand>();
        w.description("Empty Command");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyCommand)
