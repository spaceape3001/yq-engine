////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/os/Cursor.hpp>
#include <yt/os/CursorData.hpp>
#include <yt/os/CursorInfoWriter.hpp>
#include <yt/msg/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    struct CursorInfo::Repo {
        std::vector<const CursorInfo*> all;
    };
    
    CursorInfo::Repo& CursorInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const CursorInfo*>&    CursorInfo::all()
    {
        return repo().all;
    }

    CursorInfo::CursorInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Type::Cursor);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Cursor::Cursor(const Param& p) : Tachyon(p)
    {
    }

    Cursor::~Cursor()
    {
    }

    void Cursor::snap(CursorSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Cursor::init_info()
    {
        auto w   = writer<Cursor>();
        w.abstract();
        w.description("Cursor, thing that can spin");

        auto wt = writer<CursorID>();
        wt.description("Cursor Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Cursor)
YQ_TYPE_IMPLEMENT(yq::tachyon::CursorID)
