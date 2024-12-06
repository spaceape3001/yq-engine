////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition3I.hpp>

namespace yq::tachyon {
    class PPosition3I : public Proxy, public IPosition3I  /* TODO: public IPosition3D, public IPosition3, public IPosition */ {
    public:
    
        Vector3I    position3i() const override {  return m_position;  }
        bool        position3i(disabled_t) const override;
        bool        position3i(settable_t) const override;
        bool        position3i(adjustable_t) const override;
        
        void        position3i(set_t, const Vector3I&) override;
        void        position3i(adjust_t, const Vector3I&) override;

        PPosition3I(const IPosition3I& i);

    private:
        Vector3I        m_position;
    };
}

