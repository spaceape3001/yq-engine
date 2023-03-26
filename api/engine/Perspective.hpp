////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <engine/preamble.hpp>
#include <engine/Camera.hpp>
#include <math/shape/Rectangle2.hpp>
#include <math/color/RGB.hpp>
#include <optional>

namespace yq {
    namespace engine {
        struct Perspective {
            // Only the camera shall be required
            CameraCPtr                  camera;
            std::optional<RGB3F>        background;
            std::optional<Rectangle2D>  screen;
            Tristate                    wireframe   = Tristate::NO;
        };
    }
}
