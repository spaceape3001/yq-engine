////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/asset/Asset.hpp>
#include <tachyon/asset/AssetInfoWriter.hpp>
#include <basic/DelayInit.hpp>
#include <basic/TextUtils.hpp>
#include <io/FileResolver.hpp>
#include <YqEngineConfig.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Asset)

namespace yq {
    namespace tachyon {
    
        namespace {
            FileResolver    make_asset_search_path()
            {
                std::string_view        dd(build::data_directory());
                
                FileResolver    ret;
                vsplit(dd, ';', [&](std::string_view x){
                    ret.add_path(dd);
                });
                return ret;
            }
        }

        //  If done, binary Cache will be SQLite based....
    
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        AssetInfo::AssetInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
            ObjectInfo(zName, base, sl)
        {
            set_option(ASSET);
        }
        

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const FileResolver&      Asset::resolver()
        {
            static FileResolver ret = make_asset_search_path();
            return ret;
        }
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Asset::Asset()
        {
        }
        
        Asset::~Asset()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        YQ_INVOKE(
            [[maybe_unused]] auto res = writer<Asset>();
        )
    }
}
