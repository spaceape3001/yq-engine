////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq-vulqan/texture/Texture.hpp>

namespace yq::tachyon {
    Texture::Texture(ImageCPtr img, const ImageViewInfo& ivi, const SamplerInfo& si) : image(img), view(ivi), sampler(si)
    {
    }
    
    Texture::~Texture()
    {
    }
}
