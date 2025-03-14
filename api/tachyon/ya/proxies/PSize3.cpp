////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PSize3.hpp>
#include <ya/commands/size/AddSize3.hpp>
#include <ya/commands/size/AddSizeX.hpp>
#include <ya/commands/size/AddSizeY.hpp>
#include <ya/commands/size/AddSizeZ.hpp>
#include <ya/commands/size/MultiplySize.hpp>
#include <ya/commands/size/MultiplySize3.hpp>
#include <ya/commands/size/MultiplySizeX.hpp>
#include <ya/commands/size/MultiplySizeY.hpp>
#include <ya/commands/size/MultiplySizeZ.hpp>
#include <ya/commands/size/SetSize3.hpp>
#include <ya/commands/size/SetSizeX.hpp>
#include <ya/commands/size/SetSizeY.hpp>
#include <ya/commands/size/SetSizeZ.hpp>

namespace yq::tachyon {
    PSize³::PSize³(const ISize³& i) : m_size(i.size())
    {
        if(i.size(DISABLED))
            m_flags |= F::Disabled;
        if(i.size(SETTABLE))
            m_flags |= F::Settable;
        if(i.size(ADDABLE))
            m_flags |= F::Addable;
        if(i.size(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PSize³::~PSize³()
    {
    }

    bool        PSize³::size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize³::size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize³::size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PSize³::size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PSize³::size(set_k, const Size3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSize³({.target=object()}, v));
        }
    }

    void        PSize³::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣ({.target=object()}, x));
        }
    }
    
    void        PSize³::size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeʸ({.target=object()}, y));
        }
    }
    
    void        PSize³::size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeᶻ({.target=object()}, z));
        }
    }

    void        PSize³::size(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize³({.target=object()}, Δ));
        }
    }

    void        PSize³::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣ({.target=object()}, Δx));
        }
    }

    void        PSize³::size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeʸ({.target=object()}, Δy));
        }
    }

    void        PSize³::size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeᶻ({.target=object()}, Δz));
        }
    }

    void        PSize³::size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize({.target=object()}, Δ));
        }
    }

    void        PSize³::size(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize³({.target=object()}, Δ));
        }
    }

    void        PSize³::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣ({.target=object()}, Δx));
        }
    }

    void        PSize³::size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeʸ({.target=object()}, Δy));
        }
    }

    void        PSize³::size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeᶻ({.target=object()}, Δz));
        }
    }
}
