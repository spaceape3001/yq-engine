////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Quadrilateral.hpp"

#include <yq/shape/QuadrilateralData.hpp>
#include <yq/shape/QuadrilateralData.hpp>
#include <yq/shape/shape_utils.hpp>
#include <yq/vector/Vector3.hxx>

#include <yq/tachyon/api/Rendered³InfoWriter.hpp>
#include <yq/tachyon/api/Shader.hpp>


namespace yq::tachyon {
    void Quadrilateral³::init_info()
    {
        static IB1<uint16_t> kIndices({ 0, 1, 2, 2, 3, 0 });
    
        auto w = writer<Quadrilateral³>();
        
        {
            auto& p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&Quadrilateral³::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.index(kIndices, DataActivity::COMMON);
            p.push_full();
        }
    }

    Quadrilateral³::Quadrilateral³(const QuadrilateralData<ColorVertex2D>&quad)
    {
        m_vertex = { quad.a, quad.b, quad.c, quad.d};
    }
    
    Quadrilateral³::~Quadrilateral³()
    {
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Quadrilateral³)
