////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition³ : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetPosition³, TachyonCommand)
    public:
        SetPosition³(TachyonID, const Vector3D&, const Param& p={});
        ~SetPosition³();
    
        const Vector3D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        
    private:
        Vector3D const  m_position;
    };
}
