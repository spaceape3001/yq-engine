////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/asset/Texture.hpp>
#include <tachyon/asset/AssetFactory.hpp>
#include <tachyon/asset/AssetInfoWriter.hpp>

namespace yq {
    namespace tachyon {
        TypedAssetFactory<Texture>&  Texture::cache()
        {
            static TypedAssetFactory<Texture>   s_ret;
            return s_ret;
        }

        const Texture*       Texture::load(std::string_view pp)
        {
            return cache().load(pp);
        }

        ////////////////////////////////////////////////////////////////////////////////

        Texture::Texture()
        {
        }
        
        Texture::~Texture()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        
        namespace {
            void    reg_texture()
            {
                auto ti = writer<Texture>();
                ti.description("Texture Asset");
            }

            YQ_INVOKE(reg_texture();)
        }
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Texture)

