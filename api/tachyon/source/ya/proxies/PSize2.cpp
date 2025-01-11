////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PSize2.hpp>
#include <ya/commands/MoveSize2I.hpp>
#include <ya/commands/SetSize2I.hpp>

namespace yq::tachyon {
    PSize²::PSize²(const ISize²& i)
    {
        if(i.size2i(DISABLED))
            m_flags |= F::Disabled;
        if(i.size2i(SETTABLE))
            m_flags |= F::Settable;
        if(i.size2i(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PSize²::size2i(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize²::size2i(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize²::size2i(adjustable_k) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PSize²::size2i(set_k, const Size2I& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetSize²(id(), v));
        }
    }
    
    void        PSize²::size2i(adjust_k, const Size2I& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new MoveSize2I(id(), v));
        }
    }
}
