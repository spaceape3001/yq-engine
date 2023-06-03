////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Ref.hpp>
#include <tachyon/gpu/Visualizer.hpp>
#include <tachyon/host/Window.hpp>
#include <basic/Flags.hpp>

struct ImGuiContext;

namespace yq {
    class Object;
}

namespace yq::tachyon {
    class Widget;
    
    class Viewer : public Window, public Visualizer {
        friend class Application;
    public:

    
    
        /*! \brief Creates the viewer
        */
        Viewer();
        virtual ~Viewer();
        
        /*! \brief Creates & initializes viewer 
        
            \note This one throws a std::error_code if problems occur
        */
        Viewer(const ViewerCreateInfo&vci, Widget*);
        
        /*! \brief Initializes the viewer
            
            Initializes the viewer to render specified top-level widget
        */
        std::error_code     initialize(const ViewerCreateInfo&vci, Widget*);
        
        //! Runs the draw sequence
        std::error_code     draw(ViContext&);
        std::error_code     draw();
        
        //! Time (in seconds) of last draw call
        double              draw_time() const { return m_drawTime; }
        
        //! Current frame number
        uint64_t            frame_number() const { return tick(); }
        
        bool                render_paused() const { return m_paused; }
        void                set_render_paused(bool);
        
        void                cmd_pause();
        void                cmd_unpause();
        
        
        void                set_widget(Widget*, bool fDestroyOld=true);
        
    protected:
        virtual void        window_framebuffer_resized(const Size2I&) override;

        virtual void        prerecord(ViContext&) override;
        
    private:
        void                record(ViContext&) override;

        Widget*                 m_widget        = nullptr;
        ImGuiContext*           m_imgui         = nullptr;
        double                  m_drawTime      = 0;
        bool                    m_paused        = false;
        bool                    m_zeroSize      = false;
        std::vector<Widget*>    m_delete;
        
        void                purge_deleted();
        
        virtual void        kill_window() { kill(); }
        void                kill();
    };
}
