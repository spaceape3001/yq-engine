////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/ISize1.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddSize¹;
    class AddSizeˣ;
    class MultiplySize;
    class MultiplySize¹;
    class MultiplySizeˣ;
    class SetSize¹;
    class SetSizeˣ;

    class ASize¹ : public ISize¹, private Tachyon::Helper {
    public:
    
        //!  Basic size in the 1D space
        Size1D          size() const override { return m_size; }
        
        //!  Set size the size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    size(set_k, const Size1D&) override;
        void            size(set_k, x_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void            size(add_k, const Vector1D&) override;
        void            size(add_k, x_k, double) override;

        void            size(multiply_k, double) override;
        void            size(multiply_k, const Vector1D&) override;
        void            size(multiply_k, x_k, double) override;
        
        bool            size(disabled_k) const { return false; }
        bool            size(settable_k) const { return true; }
        bool            size(addable_k) const { return true; }
        bool            size(multipliable_k) const { return true; }

    protected:
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        ASize¹();
        virtual ~ASize¹();
        
    private:
        void        on_set_size1(const SetSize¹&);
        void        on_set_sizeX(const SetSizeˣ&);

        void        on_add_size1(const AddSize¹&);
        void        on_add_sizeX(const AddSizeˣ&);
        
        void        on_multiply_size(const MultiplySize&);
        void        on_multiply_size1(const MultiplySize¹&);
        void        on_multiply_sizeX(const MultiplySizeˣ&);

        Size1D      m_size = ONE;
    };

}
