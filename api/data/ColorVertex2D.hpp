////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//  This contains some vertex helpers

#include <math/RGB.hpp>
#include <math/Vector2.hpp>

namespace yq {
    struct ColorVertexData;
    
    /*! \brief Used for encapsulating color and position information
    */
    struct ColorVertex2D {
    
        //! Position
        Vector2D        position;
        
        //! Color
        RGB3U8          color;
        
        //! Equality operator
        constexpr bool operator==(const ColorVertex2D&) const = default;
        
        //! Operator to reduce to color vertex data (GLM)
        operator ColorVertexData() const;
    };
}


