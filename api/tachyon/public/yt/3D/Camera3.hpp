////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/3D.hpp>
#include <yt/scene/Camera.hpp>
#include <yt/typedef/camera3.hpp>
#include <yt/typedef/spatial3.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    
    class CameraSetScreen;

    class Camera³Info : public CameraInfo {
    public:
    
        template <typename> class Writer;
        
        Camera³Info(std::string_view, CameraInfo&, const std::source_location& sl = std::source_location::current());
    protected:
        ~Camera³Info();
    };
    
    class Camera³ : public Camera, public ③ {
        YQ_TACHYON_INFO(Camera³Info)
        YQ_TACHYON_SNAP(Camera³Snap)
        YQ_TACHYON_DATA(Camera³Data)
        YQ_TACHYON_DECLARE(Camera³, Camera)
    public:
    
        struct Param : public Camera::Param {
            // setting *ANY* of these creates a simple spatial (3D)
        
            Vector3D        position        = NAN;
            Quaternion3D    orientation     = NAN;
            Vector3D        scale           = NAN;
        };
    
        static void init_info();
    
        Camera³ID id() const { return Camera³ID(UniqueID::id()); }

        using Camera::mark;
    
    protected:
        Camera³(const Param&);
        ~Camera³();
        
        void finalize(Camera³Data&) const;
        void snap(Camera³Snap&) const;
        
        //  TODO... make this clever with multiple clients?
        Rectangle2D     m_screen;
        
        using Tachyon::mail;
        using Tachyon::send;
        using Camera::id;
        
    private:
        void    on_set_screen(const CameraSetScreen&);
    };
}
