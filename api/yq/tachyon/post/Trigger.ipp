////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Trigger.hpp"
#include "TriggerInfoWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::Trigger)

namespace yq::tachyon {
    TriggerInfo::TriggerInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(zName, base, sl)
    {
        set(Flag::TRIGGER);
    }
    
    Trigger::Trigger(const Param& p) : Filter(p)
    {
    }
    
    Trigger::~Trigger()
    {
    }

    TriggerResult    Trigger::check(const Post& pp) const
    {
        return metaInfo().accept(*this, pp);
    }

    MismatchPolicy  Trigger::mismatch() const
    {
        return m_mismatch(MismatchType::InPost) ? MismatchPolicy::Accept : MismatchPolicy::Reject;
    }

    bool    Trigger::passed(const Post& pp) const
    {
        FilterResult    chk  = check(pp);
        if(auto p = std::get_if<bool>(&chk))
            return *p;
        if(auto p = std::get_if<MismatchFlags>(&chk))
            return (*p - m_mismatch) == MismatchFlags();
        return false;   // should never hit here
    }

    void Trigger::init_info()
    {
        auto w = writer<Trigger>();
        w.description("Abstract Post Trigger");
    }
}
