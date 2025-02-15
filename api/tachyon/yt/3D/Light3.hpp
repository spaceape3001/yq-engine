////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/3D.hpp>
#include <yt/scene/Light.hpp>
#include <yt/typedef/light3.hpp>
#include <yt/typedef/spatial3.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class Light³Info : public LightInfo {
    public:
    
        template <typename> class Writer;
        
        Light³Info(std::string_view, LightInfo&, const std::source_location& sl = std::source_location::current());
    protected:
        ~Light³Info();
    };
    
    class Light³ : public Light, public ③ {
        YQ_TACHYON_INFO(Light³Info)
        YQ_TACHYON_SNAP(Light³Snap)
        YQ_TACHYON_DATA(Light³Data)
        YQ_TACHYON_DECLARE(Light³, Light)
    public:
    
        struct Param : public Light::Param {
            // setting *ANY* of these creates a simple spatial (3D)
        
            Vector3D        position        = NAN;
            Quaternion3D    orientation     = NAN;
            Vector3D        scale           = NAN;
        };
    
        static void init_info();
    
        Light³ID id() const { return Light³ID(UniqueID::id()); }
        
        using Light::mark;
    
    protected:
        Light³(const Param&);
        ~Light³();
        
        void finalize(Light³Data&) const;
        void snap(Light³Snap&) const;

        using Tachyon::mail;
        using Tachyon::send;
    };
}

YQ_TYPE_DECLARE(yq::tachyon::Light³ID)
