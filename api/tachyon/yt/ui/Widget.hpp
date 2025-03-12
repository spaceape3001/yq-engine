////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/keywords.hpp>
#include <yt/api/Tachyon.hpp>
#include <ya/typedef/commands.hpp>
#include <ya/typedef/events.hpp>
#include <yt/typedef/layout.hpp>
#include <ya/typedef/replies.hpp>
#include <ya/typedef/requests.hpp>
#include <yt/typedef/viewer.hpp>
#include <yt/typedef/widget.hpp>
#include <yt/typedef/camera3.hpp>
#include <yq/typedef/tensor44.hpp>
#include <yq/typedef/vector2.hpp>
#include <yt/typedef/push.hpp>
#include <yt/typedef/rendered.hpp>
#include <yt/typedef/rendered3.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct ViContext;
    class CloseCommand;
    class HideCommand;
    class ShowCommand;
    //class StartupCommand;
    class SetViewer;
    class TitleCommand;
    class Frame;

    class WidgetInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;
        WidgetInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    };
    
    /*! \brief Root something that's drawwable & interactable
    
        It follows ImGui's rules, this is something that is 
        "drawable" and needs some amount of state information.
        
        \note ONE spot in the tree, with one viewer.  
        Need a second view of something?  New widget (though 
        certainly use ref-pointers to data, models, etc to
        reduce overhead!)
    */
    class Widget : public Tachyon {    
        YQ_TACHYON_INFO(WidgetInfo)
        YQ_TACHYON_SNAP(WidgetSnap)
        YQ_TACHYON_DATA(WidgetData)
        YQ_TACHYON_DECLARE(Widget, Tachyon)
    public:
    
        /*
            STARTUP...
            
            This will be automatic, first tick.  Visibility will 
            not be gained until startup occurs.
        */
    
    
        static void init_info();
    
        //! Default constructor
        Widget();
        
        //! Default destructor
        virtual ~Widget();

        /*! \brief Renders ImGui content
        
            This routine is called by the viewer for our widget 
            to properly render ImGui content.  The context
            is all the extra information that may or may
            not be needed.  Default implementation iterates 
            through children, calling their methods recursively. 
        */
        virtual void    imgui(ViContext&);

        /*! \brief Renders Vulkan content
        
            This routine is called by the viewer for our widget to
            properly render Vulkan content.  The context 
            is all the extra information that may or may
            not be needed.  Default implementation iterates
            through children, calling their methods recursively.
        */
        virtual void    vulkan(ViContext&);

        WidgetID   id() const { return WidgetID(UniqueID::id()); }

        bool    is_imgui() const;
        
        using Tachyon::parent;
        
        //! Our parent widget
        Widget*         parent(ptr_k);

        //! Our parent widget
        const Widget*   parent(ptr_k) const;
        
        WidgetID        root() const;

        //! Our root widget
        Widget*         root(ptr_k);

        //! Our root widget
        const Widget*   root(ptr_k) const;
        
        void            set_layout(LayoutPtr);
        
        ViewerID        viewer() const;
        
        //! Our viewer
        Viewer*         viewer(ptr_k);

        //! Our viewer
        const Viewer*   viewer(ptr_k) const ;
        
        virtual Widget* widget_at(const Vector2D&) const;
        
        //! TRUE if we're attached (either as a child-widget or to a viewer)
        bool    attached() const;

        bool        visible() const;

        void        cmd_show();
        void        cmd_hide();

        //! Dimension count to the widget (ie...add dimensions to allow for layout resizing)
        virtual uint8_t dimensions(count_k) const { return 0; }

        virtual Execution  tick(const Context&);

    protected:
        friend class Viewer;
        friend class Layout;
        
        enum class F : uint8_t {
            //ClosePending,
            Visible,
            AutoRender
        };
        using FFlags = Flags<F>;
        
        //bool                    started() const;

        //! Override to accept/reject
        virtual void            close(request_k) { close(ACCEPT); }
        void                    close(accept_k);
        void                    close(reject_k);
        
        
        //! Our viewer
        TypedID                 m_viewer;
        
        //! A string ID for ImGui
        const std::string       m_windowID;
        
        //! A string ID for ImGui
        virtual const char*     imgui_id() const;
        
        FFlags                  m_flags = { F::Visible, F::AutoRender };

        
        //! Called before record, this is the opportunity to 
        //! pass descriptor sets to the graphics card.
        virtual void            prerecord(ViContext&);

        virtual PostAdvice      advise(const Post&) const override;
        
        void                    snap(WidgetSnap&) const;
        
        void    on_close_command(const CloseCommand&);
        void    on_close_request(const CloseRequestCPtr&);
        
        void    on_hide_command(const HideCommand&);
        
        void    on_set_viewer(const SetViewer&);
        void    on_show_command(const ShowCommand&);
        void    on_title_command(const TitleCommand&);
        
        
        #if 0
        virtual void            on(const WidgetChildAdd&) {};
        virtual void            on(const WidgetChildRemove&) {};
        
        //! Called when the user submits a character (could be meta-induced)
        virtual void            on(const KeyCharacter&){}
        virtual void            on(const KeyPress&){}
        virtual void            on(const KeyRelease&){}
        virtual void            on(const KeyRepeat&){}
        
        virtual void            on(const WidgetMove&){}
        virtual void            on(const WidgetResize&){}
        virtual void            on(const WidgetRescale&){}
        virtual void            on(const CloseRequest&){}

        virtual void            on(const MouseMove&) {}
        virtual void            on(const MouseEnter&) {}
        virtual void            on(const MouseLeft&) {}
        virtual void            on(const MousePress&) {}
        virtual void            on(const MouseRelease&) {}
        virtual void            on(const MouseScroll&) {}
        #endif
        
        struct PushContext {
            ViContext&      vi;
            const Frame&    frame;
            Tensor44D       view        = IDENTITY;
            Tensor44D       projection  = IDENTITY;
            RGBA4F          gamma       = { 1., 1., 1., 1. };
            double          time        = 0.;
        };
        
        static void camera_matrix(PushContext&, Camera³ID);
        
        static void camera_matrix(Tensor44D& view, Tensor44D& proj, const Frame&, Camera³ID);
        static void push_buffer(PushBuffer&, const PushContext&, const RenderedSnap&);
        
    private:
        struct R;
        CloseRequestCPtr        m_closeRequest;
        LayoutPtr               m_layout;
        std::vector<R>          m_rendereds;

        static void push_buffer_mvp(PushBuffer&, const PushContext&, const Rendered³Snap&);
        static void push_buffer_full(PushBuffer&, const PushContext&, const Rendered³Snap&);
        static void push_buffer_view(PushBuffer&, const PushContext&, const RenderedSnap&);
        static void push_buffer_viewproj(PushBuffer&, const PushContext&, const RenderedSnap&);
        static void push_buffer_view64proj(PushBuffer&, const PushContext&, const RenderedSnap&);
    };
}
YQ_TYPE_DECLARE(yq::tachyon::WidgetID)
