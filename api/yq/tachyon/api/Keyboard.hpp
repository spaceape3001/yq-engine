////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/keyboard.hpp>

namespace yq::tachyon {

    class Keyboard;
    
    /*! \brief Keyboard Information
    
        Information for keyboards.
    */
    class KeyboardInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all keyboard informations
        static const std::vector<const KeyboardInfo*>&    all();
        
        //! Standard constructor for the camera information
        KeyboardInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*
        Right *now*, the keyboard is assumed to be simple....
    */

    /*! \brief A keyboard
    */
    class Keyboard : public Tachyon {
        YQ_TACHYON_INFO(KeyboardInfo);
        YQ_TACHYON_DATA(KeyboardData)
        YQ_TACHYON_SNAP(KeyboardSnap)
        YQ_TACHYON_DECLARE(Keyboard, Tachyon)
    public:    
    
        /*
            We *MIGHT* want to divide up the camera into position, 
            lens, etc... or that's a later development on a dedicated
            camera.  (class DynamicKeyboard, StandardKeyboard, etc???)
        */
    
    
        //! Name of this camera's instance
        std::string_view    name() const { return m_name; }
        
        //! Getter for the property system
        const std::string&  get_name() const { return m_name; }
        
        //! Sets the camera's name
        void                set_name(const std::string&);

        static void init_info();

        KeyboardID            id() const { return KeyboardID(UniqueID::id()); }

    protected:
    
        void        snap(KeyboardSnap&) const;
        //virtual void    receive(const post::PostCPtr&) override;
        virtual PostAdvice  advise(const Post&) const override;

        //! Default constructor
        Keyboard(const Param&p = {});
        
        //! Default destructor
        ~Keyboard();
        
    private:
        std::string         m_name;
    };

}
