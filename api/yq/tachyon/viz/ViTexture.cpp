////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViTexture.hpp"

#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Raster.hpp>
#include <yq/tachyon/api/RasterInfo.hpp>
#include <yq/tachyon/api/Texture.hpp>
#include <yq/tachyon/v/VqStructs.hpp>
#include <yq/tachyon/viz/ViImage.hpp>
#include <yq/tachyon/viz/ViLogging.hpp>
#include <yq/tachyon/viz/ViSampler.hpp>
#include <yq/tachyon/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    namespace errors {
        using texture_bad_image                 = error_db::entry<"Texture's image is bad">;
        using texture_bad_sampler               = error_db::entry<"Texture's sampler is bad">;
        using texture_bad_state                 = error_db::entry<"Texture is in a bad state">;
        using texture_cant_create_image_view    = error_db::entry<"Texture is unable to create image view">;
        using texture_existing                  = error_db::entry<"Texture already created">;
        using texture_image_null_pointer        = error_db::entry<"Texture's image is a null pointer">;
        using texture_sampler_null_pointer      = error_db::entry<"Texture's sampler is a null pointer">;
        using texture_null_pointer              = error_db::entry<"Texture is a null pointer">;
    }

    ViTexture::ViTexture()
    {
    }
    
    ViTexture::ViTexture(ViVisualizer&viz, const Texture&tex)
    {
        if(viz.device()){
            std::error_code ec  = _init(viz, tex);
            if(ec != std::error_code()){
                _kill();
            }
        }
        
    }
    
    ViTexture::ViTexture(ViVisualizer& viz, const ViImageCPtr&img, const ViSamplerCPtr&sam, const TextureInfo& info)
    {
        if(viz.device() && img && img->valid() && sam && sam->valid()){
            std::error_code ec  = _init(viz, img, sam, info);
            if(ec != std::error_code()){
                _kill();
            }
        }
    }

    ViTexture::~ViTexture()
    {
        kill();
    }
    
    std::error_code     ViTexture::_init(ViVisualizer&viz, const Texture&tex)
    {
        m_viz   = &viz;
        
        if(!tex.image){
            vizWarning << "ViTexture() -- image is NULL!";
            return errors::texture_image_null_pointer();
        }
        if(!tex.sampler){
            vizWarning << "ViTexture() -- sampler is NULL!";
            return errors::texture_sampler_null_pointer();
        }

        ViImageCPtr img  = viz.image_create(*tex.image);
        if(!img){
            vizWarning << "ViTexture() -- cannot import image!";
            return errors::texture_bad_image();
        }
        
        ViSamplerCPtr sampler  = viz.sampler_create(*tex.sampler);
        if(!sampler){
            vizWarning << "ViTexture() -- cannot import sampler!";
            return errors::texture_bad_sampler();
        }
        
        m_id        = tex.id();
        return _init(viz, img, sampler, tex.info); 
    }
    
    std::error_code     ViTexture::_init(ViVisualizer&viz, const ViImageCPtr& image, const ViSamplerCPtr& sampler, const TextureInfo& texInfo)
    {
        m_viz       = &viz;

        m_image     = image;
        m_sampler   = sampler;
    
        VqImageViewCreateInfo       info;
        const RasterInfo&            imgInfo  = image->info();

        m_extents  = { 
            .width          = (uint32_t) imgInfo.size.x,
            .height         = (uint32_t) imgInfo.size.y,
            .depth          = (uint32_t) imgInfo.size.z
        };

        info.image          = image -> image();
        info.flags  = texInfo.imageViewFlags.value();
        
        if(texInfo.imageViewType){
            info.viewType   = (VkImageViewType) (*texInfo.imageViewType).value();
        } else {
            switch(imgInfo.type){
            case RasterType::Is1D:
                info.viewType   = VK_IMAGE_VIEW_TYPE_1D;
                break;
            case RasterType::Is2D:
                info.viewType   = VK_IMAGE_VIEW_TYPE_2D;
                break;
            case RasterType::Is3D:
                info.viewType   = VK_IMAGE_VIEW_TYPE_3D;
                break;
            default:
                info.viewType   = VK_IMAGE_VIEW_TYPE_2D;
                break;
            }
        }

        if(texInfo.format){
            info.format = (VkFormat) (*texInfo.format).value();
        } else {
            info.format = (VkFormat) imgInfo.format.value();
        }
        
        info.components = {
            .r = (VkComponentSwizzle) texInfo.swizzle.red.value(),
            .g = (VkComponentSwizzle) texInfo.swizzle.green.value(),
            .b = (VkComponentSwizzle) texInfo.swizzle.blue.value(),
            .a = (VkComponentSwizzle) texInfo.swizzle.alpha.value()
        };

        info.subresourceRange.aspectMask        = (VkImageAspectFlags) texInfo.aspect.value();

        info.subresourceRange.baseMipLevel      = texInfo.baseMipLevel;
        info.subresourceRange.levelCount        = texInfo.levelCount;
        info.subresourceRange.baseArrayLayer    = texInfo.baseArrayLayer;
        info.subresourceRange.layerCount        = texInfo.layerCount;

        VkResult res = vkCreateImageView(viz.device(), &info, nullptr, &m_imageView);
        if(res != VK_SUCCESS){
            vizWarning << "ViTexture() -- cannot create image view.  VkResult " << (int32_t) res;
            return errors::texture_cant_create_image_view();
        }
        
        return {};
    }
    
    void                ViTexture::_kill()
    {
        if(m_viz && m_viz->device() && m_imageView){
            vkDestroyImageView(m_viz->device(), m_imageView, nullptr);
            m_imageView = nullptr;
        }
        
        m_viz       = nullptr;
        m_imageView = nullptr;
        m_sampler   = {};
        m_image     = {};
        m_id        = 0ULL;
    }

    bool                ViTexture::consistent() const
    {
        return m_viz ? (m_viz->device() && m_image && m_image->valid() && m_sampler && m_sampler->valid()) :
            (!m_image && !m_sampler && !m_imageView);
    }

    VkExtent3D          ViTexture::extents() const
    {
        return m_extents;
    }
    
    VkImage             ViTexture::image() const
    {
        if(m_image)
            return m_image -> image();
        return nullptr;
    }
    
    VkImageView         ViTexture::image_view() const
    {
        return m_imageView;
    }
    
    std::error_code     ViTexture::init(ViVisualizer&viz, const Texture&tex)
    {
        if(m_viz){
            if(!consistent()){
                return errors::texture_bad_state();
            }
            return errors::texture_existing();
        }
        if(!viz.device())
            return errors::vulkan_uninitialized();
        std::error_code     ec  = _init(viz, tex);
        if(ec != std::error_code()){
            _kill();
        }
        return ec;
    }
    
    void                ViTexture::kill()
    {
        _kill();
    }
    
    VkSampler           ViTexture::sampler() const
    {
        if(m_sampler)
            return m_sampler -> sampler();
        return nullptr;
    }
    
    bool                ViTexture::valid() const
    {
        return m_viz && m_viz->device() && m_image && m_image->valid() && m_sampler && m_sampler -> valid();
    }
}
