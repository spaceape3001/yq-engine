////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyScale : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyScale, SpatialCommand)
    public:
        MultiplyScale(const Header&, double);
        
        static void init_info();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScale(const MultiplyScale&, const Header&);
        ~MultiplyScale();
        MultiplyScale(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyScale(const MultiplyScale&) = delete;
        MultiplyScale(MultiplyScale&&) = delete;
        MultiplyScale& operator=(const MultiplyScale&) = delete;
        MultiplyScale& operator=(MultiplyScale&&) = delete;
    };
}
