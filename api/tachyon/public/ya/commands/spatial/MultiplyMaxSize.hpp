////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMaxSize : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize, SpatialCommand)
    public:
        MultiplyMaxSize(const Header&, double);
        
        static void init_info();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSize(const MultiplyMaxSize&, const Header&);
        ~MultiplyMaxSize();
        MultiplyMaxSize(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyMaxSize(const MultiplyMaxSize&) = delete;
        MultiplyMaxSize(MultiplyMaxSize&&) = delete;
        MultiplyMaxSize& operator=(const MultiplyMaxSize&) = delete;
        MultiplyMaxSize& operator=(MultiplyMaxSize&&) = delete;
    };
}
