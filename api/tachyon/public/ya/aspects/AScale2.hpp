////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/IScale2.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddScale²;
    class AddScaleˣ;
    class AddScaleʸ;
    class MultiplyScale;
    class MultiplyScale²;
    class MultiplyScaleˣ;
    class MultiplyScaleʸ;
    class SetScale²;
    class SetScaleˣ;
    class SetScaleʸ;

    class AScale² : public IScale², private Tachyon::Helper {
    public:
    
        //!  Basic scale in the 2D space
        Vector2D        scale() const override { return m_scale; }
        
        double          scale(x_k) const { return m_scale.x; }
        double          scale(y_k) const { return m_scale.y; }

        //!  Set scale the scale (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    scale(set_k, const Vector2D&) override;
        void            scale(set_k, x_k, double) override;
        void            scale(set_k, y_k, double) override;
        
        //!  Move the scale (ie set to scale + delta)
        void            scale(add_k, const Vector2D&) override;
        void            scale(add_k, x_k, double) override;
        void            scale(add_k, y_k, double) override;

        void            scale(multiply_k, double) override;
        void            scale(multiply_k, const Vector2D&) override;
        void            scale(multiply_k, x_k, double) override;
        void            scale(multiply_k, y_k, double) override;
        
        bool            scale(disabled_k) const { return false; }
        bool            scale(settable_k) const { return true; }
        bool            scale(addable_k) const { return true; }
        bool            scale(multipliable_k) const { return true; }

        const Vector2D& scale(ref_k) const { return m_scale; }

    protected:
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        AScale²();
        virtual ~AScale²();
        
    private:
        void        on_set_scale2(const SetScale²&);
        void        on_set_scaleX(const SetScaleˣ&);
        void        on_set_scaleY(const SetScaleʸ&);

        void        on_add_scale2(const AddScale²&);
        void        on_add_scaleX(const AddScaleˣ&);
        void        on_add_scaleY(const AddScaleʸ&);
        
        void        on_multiply_scale(const MultiplyScale&);
        void        on_multiply_scale2(const MultiplyScale²&);
        void        on_multiply_scaleX(const MultiplyScaleˣ&);
        void        on_multiply_scaleY(const MultiplyScaleʸ&);

        Vector2D    m_scale = ONE;
    };

}
