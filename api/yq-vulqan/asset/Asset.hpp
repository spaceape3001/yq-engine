////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Object.hpp>
#include <yq-toolbox/basic/UniqueID.hpp>
#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/container/Set.hpp>
#include <yq-toolbox/basic/SizeTimestamp.hpp>

#include <atomic>
#include <filesystem>

namespace yq {
    class FileResolver;
}

namespace yq::tachyon {
    class AssetFactory;

    /*! \brief General asset information
    
        This is the information to the particular asset.
    */
    class AssetInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;

        AssetInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());
        
        //! Loads the asset from native binary format (whatever that is)
        //virtual Ref<Asset>  load_binary(const std::filesystem::path&) { return nullptr; }
        
    protected:
    };
    
    /*! \brief An asset of the graphics engine
    
        An asset (here) is something that can be loaded by the engine, and used in some predefined fashion.  
        (ie, texture, shader, sounds, etc)  
        
        \note Some overlap with  the asset-library also exists, predefined cameras & shapes -- TBD
        
        \note Once an asset has been sent to the rest of the system, it's presumed to be READ-ONLY.  
            Any further modifications shall require a clone and modifications of THAT
        
    */
    class Asset : public Object, public UniqueID, public RefCount {
        YQ_OBJECT_INFO(AssetInfo)
        YQ_OBJECT_DECLARE(Asset, Object)
    public:
        virtual size_t                  data_size() const = 0;
        
        //! Only works if cached, otherwise empty
        const std::filesystem::path&    filepath() const { return m_filepath; }
        
        //! Saves data to native binary format (whatever that is)
        //virtual bool        save_binary(const std::filesystem::path&) const = 0;
        
        static const FileResolver&      resolver();
        
        //static const path_vector_t&             search_path();
        //static const std::filesystem::path&     binary_root();
        //static std::filesystem::path            resolve(const std::filesystem::path&);
        //static std::filesystem::path            binary_path(const std::filesystem::path&);
        
        /*! Searches the given vector for the specified file
        
            \note An ABSOLUTE file will auto-return itself.
            
            This first checks the relative against the current working directory, returns if that file exists.
            Otherwise, it'll march through the paths, doing the same check.
        
            \param[in]  paths   Directories to search
            \param[in]  file    Given filepath
            \return filepath if absolute or detected, empty otherwise
        */
        //static std::filesystem::path            search(const path_vector_t& paths, const std::filesystem::path& file);
    
    protected:
        friend class AssetFactory;
        
        Asset();
        Asset(const std::filesystem::path&);
        virtual ~Asset();
    private:
        std::filesystem::path           m_filepath;
    };
}
