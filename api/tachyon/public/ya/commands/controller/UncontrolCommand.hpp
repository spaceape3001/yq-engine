////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ControllerCommand.hpp>
#include <yt/api/TypedID.hpp>

namespace yq::tachyon {
    class UncontrolCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(UncontrolCommand, ControllerCommand)
    public:
    
        UncontrolCommand(const Header&, TypedID);
        
        TypedID    tachyon() const { return m_tachyon; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();

    protected:
        UncontrolCommand(const UncontrolCommand&, const Header&);
        virtual ~UncontrolCommand();

    private:
        TypedID const  m_tachyon;
        
        UncontrolCommand(const UncontrolCommand&) = delete;
        UncontrolCommand(UncontrolCommand&&) = delete;
        UncontrolCommand& operator=(const UncontrolCommand&) = delete;
        UncontrolCommand& operator=(UncontrolCommand&&) = delete;
    };
}
