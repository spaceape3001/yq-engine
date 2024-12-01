////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class MovePosition2I : public TachyonCommand {
        YQ_OBJECT_DECLARE(MovePosition2I, TachyonCommand)
    public:
        MovePosition2I(TachyonID, const Vector2I&, const Param& p={});
        ~MovePosition2I();
    
        const Vector2I&   position2i() const  { return m_position; }
        
        static void init_info();
        
        int     x() const { return m_position.x; }
        int     y() const { return m_position.y; }
        
    private:
        Vector2I const  m_position;
    };
}
