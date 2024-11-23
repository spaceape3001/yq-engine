////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TypedID.hpp"
#include "Tachyon.hpp"

namespace yq::tachyon {

    TypedID::TypedID(const Tachyon&t) : id(t.UniqueID::id()), types(t.metaInfo().types()) 
    {
    }
    
    TypedID::TypedID(const Tachyon*t) : id(t ? t->UniqueID::id() : 0ULL), types(t ? t->metaInfo().types() : Types())
    {
    }
}
