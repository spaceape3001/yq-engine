////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/cursor/CursorCaptureCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorCaptureCommand)

namespace yq::tachyon {

    CursorCaptureCommand::CursorCaptureCommand(const Header&h) : CursorCommand(h)
    {
    }
    
    CursorCaptureCommand::CursorCaptureCommand(const CursorCaptureCommand& cp, const Header&h) : CursorCommand(cp, h)
    {
    }

    CursorCaptureCommand::~CursorCaptureCommand()
    {
    }
    
    PostCPtr    CursorCaptureCommand::clone(rebind_k, const Header&h) const
    {
        return new CursorCaptureCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void CursorCaptureCommand::init_info()
    {
        auto w = writer<CursorCaptureCommand>();
        w.description("Cursor Capture Command");
    }
}
