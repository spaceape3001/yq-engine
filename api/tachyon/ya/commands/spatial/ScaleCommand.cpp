////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/ScaleCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ScaleCommand)

namespace yq::tachyon {

    ScaleCommand::ScaleCommand(const Header&h) : SpatialCommand(h)
    {
    }

    ScaleCommand::ScaleCommand(const ScaleCommand& cp, const Header& h) : SpatialCommand(cp, h)
    {
    }
    
    ScaleCommand::~ScaleCommand()
    {
    }

    PostCPtr    ScaleCommand::clone(rebind_k, const Header&h) const 
    {
        return new ScaleCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ScaleCommand::init_info()
    {
        auto w = writer<ScaleCommand>();
        w.description("Scale Command");
    }
}
