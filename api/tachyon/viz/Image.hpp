////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/core/Asset.hpp>
#include <tachyon/core/Memory.hpp>
#include <tachyon/viz/ImageInfo.hpp>

namespace yq::tachyon {
    class Buffer;

    /*! \brief Image (data)
    
        An image is *not* drawable, it's data/asset for the GPU or other 
        render/destination.  Its data may be copied into a pixmap for 
        manipulation.
    */
    class Image : public Asset {
        YQ_OBJECT_DECLARE(Image, Asset)
    public:
    
        //! Cache of images
        static TypedAssetFactory<Image>&    cache();
        
        //! Loads an image by key
        static const Image*                 load(std::string_view);
    
        //! Data for the image
        const Memory      memory;
        
        //! Information for the image
        const ImageInfo   info;
        
        //! Constructor (takes info & data)
        Image(const ImageInfo&, Memory&&);

        //! Returns the size of the memory data
        virtual size_t      data_size() const  override;

    private:
        ~Image();
    };
}
