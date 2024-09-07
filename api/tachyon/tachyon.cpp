////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    Vulqan is the adapter to the vulkan driver.  Even though there's a lot of overlap, these
    are our C++ adapters for it.
*/

#include "Application.ipp"
#include "Pipeline.ipp"
#include "PipelineUtils.ipp"
#include "PipelineBuilder.ipp"
#include "PipelineConfig.ipp"
#include "Render3D.ipp"
#include "Rendered.ipp"
#include "Viewer.ipp"
#include "Window.ipp"

#include "rendered/ImageQuad2.ipp"
#include "rendered/Quadrilateral.ipp"
#include "rendered/Tetrahedron.ipp"
#include "rendered/Triangle.ipp"

#include "widget/Scene3DWidget.ipp"


#include <yq-toolbox/shape/AxBox2.hxx>
#include <yq-toolbox/shape/Rectangle2.hxx>
#include <yq-toolbox/shape/Size2.hxx>
#include <yq-toolbox/tensor/Tensor44.hxx>
#include <yq-toolbox/vector/Vector2.hxx>
#include <yq-toolbox/vector/Vector3.hxx>


