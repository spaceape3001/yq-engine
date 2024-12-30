////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleSpatial³.hpp"
#include <yq/tachyon/api/Spatial³InfoWriter.hpp>
#include <yq/tachyon/commands/spatial/MoveBy³.hpp>
#include <yq/tachyon/commands/spatial/MoveByˣ.hpp>
#include <yq/tachyon/commands/spatial/MoveByʸ.hpp>
#include <yq/tachyon/commands/spatial/MoveByᶻ.hpp>
#include <yq/tachyon/commands/spatial/PitchBy.hpp>
#include <yq/tachyon/commands/spatial/RollBy.hpp>
#include <yq/tachyon/commands/spatial/SetOrientation³.hpp>
#include <yq/tachyon/commands/spatial/SetPosition³.hpp>
#include <yq/tachyon/commands/spatial/SetPositionˣ.hpp>
#include <yq/tachyon/commands/spatial/SetPositionʸ.hpp>
#include <yq/tachyon/commands/spatial/SetPositionᶻ.hpp>
#include <yq/tachyon/commands/spatial/SetScale³.hpp>
#include <yq/tachyon/commands/spatial/SetScaleˣ.hpp>
#include <yq/tachyon/commands/spatial/SetScaleʸ.hpp>
#include <yq/tachyon/commands/spatial/SetScaleᶻ.hpp>
#include <yq/tachyon/commands/spatial/YawBy.hpp>
#include <yq/tensor/Tensor44.hxx>
#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleSpatial³)

namespace yq::tachyon {
    SimpleSpatial³::SimpleSpatial³(const Param&p) : Spatial³(p)
    {
        if(!is_nan(p.position))
            m_position    = p.position;
        if(!is_nan(p.orientation))
            m_orientation = p.orientation;
        if(!is_nan(p.scale))
            m_scale       = p.scale;
    }
    
    SimpleSpatial³::~SimpleSpatial³()
    {
    }    

    
    void    SimpleSpatial³::rotate_by(const Quaternion3D& δQ)
    {
        m_orientation = δQ * m_orientation;
    }
    
    void    SimpleSpatial³::rotate_by(const unit::Radian3D& Δang )
    {
        // rotate_by(rotor(Δang)); // TODO
    }
    
    void    SimpleSpatial³::inflate_by(const Vector3D& δZ)
    {
        m_scale = δZ.emul(m_scale);
    }

    void SimpleSpatial³::on_move³(const MoveBy³&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position += cmd.Δ();
        mark();
    }
    
    void SimpleSpatial³::on_moveˣ(const MoveByˣ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.x += cmd.Δx();
        mark();
    }
    
    void SimpleSpatial³::on_moveʸ(const MoveByʸ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.y += cmd.Δy();
        mark();
    }
    
    void SimpleSpatial³::on_moveᶻ(const MoveByᶻ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.z += cmd.Δz();
        mark();
    }

    void SimpleSpatial³::on_pitch_by(const PitchBy& cmd)
    {
        if(cmd.tachyon() != id())
            return;
         m_orientation = rotor_y(cmd.θ()) * m_orientation;
         mark();
   }
    
    void SimpleSpatial³::on_roll_by(const RollBy& cmd)
    {
        if(cmd.tachyon() != id())
            return;
         m_orientation = rotor_x(cmd.θ()) * m_orientation;
         mark();
    }

    void SimpleSpatial³::on_set_orientation³(const SetOrientation³&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_orientation   = cmd.orientation();
        mark();
    }

    void SimpleSpatial³::on_set_position³(const SetPosition³&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position = cmd.position();
        mark();
    }
    
    void SimpleSpatial³::on_set_positionˣ(const SetPositionˣ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.x = cmd.x();
        mark();
    }
    
    void SimpleSpatial³::on_set_positionʸ(const SetPositionʸ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.y = cmd.y();
        mark();
    }
    
    void SimpleSpatial³::on_set_positionᶻ(const SetPositionᶻ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.z = cmd.z();
        mark();
    }

    void SimpleSpatial³::on_set_scale³(const SetScale³&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_scale = cmd.scale();
        mark();
    }
    
    void SimpleSpatial³::on_set_scaleˣ(const SetScaleˣ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_scale.x = cmd.x();
        mark();
    }
    
    void SimpleSpatial³::on_set_scaleʸ(const SetScaleʸ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_scale.y = cmd.y();
        mark();
    }
    
    void SimpleSpatial³::on_set_scaleᶻ(const SetScaleᶻ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_scale.z = cmd.z();
        mark();
    }

    void SimpleSpatial³::on_yaw_by(const YawBy& cmd)
    {
        if(cmd.tachyon() != id())
            return;
         m_orientation = rotor_z(cmd.θ()) * m_orientation;
         mark();
    }

    Vector3D    SimpleSpatial³::position() const 
    {   
        return m_position;
    }

    void        SimpleSpatial³::position(set_k, const Vector3D&v) 
    {
        m_position      = v;
        mark();
    }
    
    void        SimpleSpatial³::position(set_k, x_k, double x) 
    {
        m_position.x    = x;
        mark();
    }
    
    void        SimpleSpatial³::position(set_k, y_k, double y) 
    {
        m_position.y    = y;
        mark();
    }
    
    void        SimpleSpatial³::position(set_k, z_k, double z) 
    {
        m_position.z        = z;
        mark();
    }
    
    
    void        SimpleSpatial³::position(move_k, const Vector3D&Δ) 
    {
        m_position += Δ;
        mark();
    }

    void        SimpleSpatial³::position(move_k, x_k, double Δx) 
    {
        m_position.x += Δx;
        mark();
    }
    
    void    SimpleSpatial³::position(move_k, y_k, double Δy) 
    {
        m_position.y += Δy;
        mark();
    }
    
    void    SimpleSpatial³::position(move_k, z_k, double Δz) 
    {
        m_position.z += Δz;
        mark();
    }

    void    SimpleSpatial³::set_orientation(const Quaternion3D& Q)
    {
        m_orientation = Q;
        mark();
    }
    
    void    SimpleSpatial³::set_scale(const Vector3D& v)
    {
        m_scale       = v;
        mark();
    }

    void SimpleSpatial³::snap(Spatial³Snap& sn) const
    {
        Spatial³::snap(sn);

        Tensor33D   T       = tensor(m_orientation);
        Tensor33D   T1   = T * diagonal(m_scale);
        Tensor33D   T2   = diagonal(1./m_scale.x, 1./m_scale.y, 1./m_scale.z) * T;
        Vector3D    pos2 = T2 * m_position;
        
        sn.local2domain = Tensor44D(
            T1.xx, T1.xy, T1.xz, m_position.x,
            T1.yx, T1.yy, T1.yz, m_position.y,
            T1.zx, T1.zy, T1.zz, m_position.z,
            0., 0., 0., 1.
        );
        
        sn.domain2local = Tensor44D(
            T2.xx, T2.xy, T2.xz, -pos2.x,
            T2.yx, T2.yy, T2.yz, -pos2.y,
            T2.zx, T2.zy, T2.zz, -pos2.z,
            0., 0., 0., 1.
        );
    }

    void SimpleSpatial³::init_info()
    {
        auto w = writer<SimpleSpatial³>();
        w.interface<IPosition³>();
        w.description("Simple Spatial in ³ dimensions");
        w.slot(&SimpleSpatial³::on_move³);
        w.slot(&SimpleSpatial³::on_moveˣ);
        w.slot(&SimpleSpatial³::on_moveʸ);
        w.slot(&SimpleSpatial³::on_moveᶻ);
        w.slot(&SimpleSpatial³::on_set_orientation³);
        w.slot(&SimpleSpatial³::on_set_position³);
        w.slot(&SimpleSpatial³::on_set_positionˣ);
        w.slot(&SimpleSpatial³::on_set_positionʸ);
        w.slot(&SimpleSpatial³::on_set_positionᶻ);
        w.slot(&SimpleSpatial³::on_set_scale³);
        w.slot(&SimpleSpatial³::on_set_scaleˣ);
        w.slot(&SimpleSpatial³::on_set_scaleʸ);
        w.slot(&SimpleSpatial³::on_set_scaleᶻ);
    }
}
