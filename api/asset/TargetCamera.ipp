////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TargetCamera.hpp"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_projection.hpp>

namespace yq {
    namespace asset {
        TargetCamera::TargetCamera() : 
            m_position({0., 0., -10.}),
            m_target({0., 0., 0.}),
            m_up({0., 1., 0.}),
            m_fov(70_deg),
            m_near(0.1),
            m_far(20.)
        {
        }
        
        TargetCamera::~TargetCamera()
        {
        }
        
        glm::dmat4  TargetCamera::projection_matrix(const Size2D&sz) const
        {
            glm::dmat4 ret =  glm::perspective(
                                    (double) glm::radians(m_fov.value), 
                                    (double) sz.width() / (double) sz.height(),
                                    m_near, m_far
            );
            ret[1][1] *= -1;
            return ret;
        }

        void        TargetCamera::set_far(double v)
        {
            m_far   = v;
        }
        
        void        TargetCamera::set_near(double v)
        {
            m_near  = v;
        }
        
        
        void        TargetCamera::set_position(const Vector3D&v)
        {
            m_position    = v;
        }
        
        void        TargetCamera::set_fov(Degree v)
        {
            m_fov = v;
        }

        void        TargetCamera::set_target(const Vector3D&v)
        {
            m_target    = v;
        }
        
        void        TargetCamera::set_up(const Vector3D& v)
        {
            m_up        = v;
        }

        glm::dmat4  TargetCamera::view_matrix() const
        {
            return glm::lookAt((glm::dvec3) m_position, (glm::dvec3) m_target, (glm::dvec3) m_up);
        }

        glm::dmat4  TargetCamera::world2screen(const Params&p) const
        {
            return projection_matrix(p.screen) * view_matrix();
        }
    }
}
YQ_OBJECT_IMPLEMENT(yq::asset::TargetCamera)
