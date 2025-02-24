////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/widgets/AbstractSceneWidgetHelper.hpp>
#include <yt/3D/Camera3.hpp>
#include <yt/3D/Camera3Data.hpp>
#include <yt/3D/Rendered3.hpp>
#include <yt/3D/Rendered3Data.hpp>
#include <yt/3D/Scene3.hpp>
#include <yt/3D/Scene3Data.hpp>
#include <yt/3D/Spatial3.hpp>
#include <yt/3D/Spatial3Data.hpp>
#include <yt/api/Frame.hpp>
#include <yt/gfx/PushData.hpp>
#include <yv/ViContext.hpp>
#include <yv/ViRendered.hpp>
#include <yv/Visualizer.hpp>
#include <yv/Visualizer.hxx>
#include <yq/util/AutoReset.hpp>
#include <yq/tensor/Tensor44.hxx>
#include <yt/logging.hpp>
#include <yq/vector/Vector4.hxx>


namespace yq::tachyon {
    AbstractSceneWidgetHelper::AbstractSceneWidgetHelper()
    {
    }
    
    AbstractSceneWidgetHelper::~AbstractSceneWidgetHelper()
    {
    }

    void    AbstractSceneWidgetHelper::_cam_matrix(PushContext&ctx, Camera³ID cam)
    {
        _cam_matrix(ctx.view44, ctx.projection44, ctx.frame, cam);
        ctx.projection      = glm::dmat4(ctx.projection44);
        ctx.view            = glm::dmat4(ctx.view44);
    }

    void    AbstractSceneWidgetHelper::_cam_matrix(Tensor44D& view, Tensor44D& proj, const Frame& frame, Camera³ID cam)
    {
        const Camera³Snap*  camera  = frame.snap(cam);
        if(!camera){
            view            = IDENTITY;
            proj            = IDENTITY;
            return;
        }
        
        proj        = camera->projection;
        const Spatial³Snap* s³ = frame.snap(Spatial³ID(camera -> spatial));
        if(s³){
            view      = s³ -> domain2local;
        } else {
            view      = IDENTITY;
        }
    }
    
    void    AbstractSceneWidgetHelper::_push(PushBuffer&pb, const PushContext&ctx, const RenderedSnap&sn)
    {
        switch(sn.pipeline->push().type){
        case PushConfigType::Full:
            if(sn.self(Type::Rendered³)){
                _push_full(pb, ctx, static_cast<const Rendered³Snap&>(sn));
            } else {
                _push_view(pb, ctx, sn);
            }
            break;
        case PushConfigType::MVP:
            if(sn.self(Type::Rendered³)){
                _push_mvp(pb, ctx, static_cast<const Rendered³Snap&>(sn));
            }
            break;
        case PushConfigType::View:
            _push_view(pb, ctx, sn);
            break;
        case PushConfigType::ViewProj:
            _push_viewproj(pb, ctx, sn);
            break;
        case PushConfigType::View64Proj:
            _push_view64proj(pb, ctx, sn);
            break;
        case PushConfigType::Custom:
            pb  = sn.push;
            break;
        case PushConfigType::None:
        default:
            break;
        }
    }

    void    AbstractSceneWidgetHelper::_push_full(PushBuffer&pb, const PushContext&ctx, const Rendered³Snap& sn)
    {
        StdPushData&    pd  = *pb.create_single<StdPushData>();
        pd.time         = ctx.time;
        pd.gamma        = m_gamma;

        const Spatial³Snap* s³ = ctx.frame.snap(Spatial³ID(sn.spatial));
        if(sn.vm_override){
            if(s³){
                Tensor44D   vm  = comingle(ctx.view44, s³->local2domain, sn.vm_tensor);
                pd.matrix   = glm::dmat4(ctx.projection44 * vm);
            } else {
                Tensor44D   vm  = comingle(ctx.view44, Tensor44D(IDENTITY), sn.vm_tensor);
                pd.matrix   = glm::dmat4(ctx.projection44 * vm);
            }
        } else {
            if(s³){
                pd.matrix   = glm::dmat4(ctx.w2e44 * s³->local2domain);
            } else {
                pd.matrix   = glm::dmat4(ctx.w2e44);
            }
        }
    }
    
    void    AbstractSceneWidgetHelper::_push_mvp(PushBuffer&pb, const PushContext&ctx, const Rendered³Snap& sn)
    {
        static constexpr glm::mat4  I44 = glm::dmat4(Tensor44D(IDENTITY));
    
        StdPushDataMVP&    pd  = *pb.create_single<StdPushDataMVP>();
        pd.time         = ctx.time;
        
        if(sn.camera){  
            Tensor44D   V, P;
            _cam_matrix(V, P, ctx.frame, sn.camera);
            pd.view         = glm::dmat4(V);
            pd.projection   = glm::dmat4(P);
        } else {
            pd.view         = ctx.view;
            pd.projection   = ctx.projection;
        }
        pd.gamma        = m_gamma;
        
        //  gamma/colors/etc
        
        const Spatial³Snap* s³ = ctx.frame.snap(Spatial³ID(sn.spatial));
        if(s³){
            pd.model        = glm::dmat4(s³->local2domain);
        } else {
            pd.model        = I44;
        }
    }

    void    AbstractSceneWidgetHelper::_push_view(PushBuffer&pb, const PushContext&ctx, const RenderedSnap& sn)
    {
        StdPushData&    pd  = *pb.create_single<StdPushData>();
        pd.time         = ctx.time;
        pd.gamma        = m_gamma;
        pd.matrix       = ctx.w2e;
    }

    void    AbstractSceneWidgetHelper::_push_viewproj(PushBuffer&pb, const PushContext&ctx, const RenderedSnap& sn)
    {
        StdPushDataViewProj&    pd  = *pb.create_single<StdPushDataViewProj>();
        pd.time         = ctx.time;
        pd.gamma        = m_gamma;
        if(sn.self(Type::Rendered³) && static_cast<const Rendered³Snap&>(sn).camera){
            Tensor44D   V, P;
            _cam_matrix(V, P, ctx.frame, static_cast<const Rendered³Snap&>(sn).camera);
            pd.view         = glm::dmat4(V);
            pd.projection   = glm::dmat4(P);
        } else {
            pd.view         = ctx.view;
            pd.projection   = ctx.projection;
        }
    }
    
    void    AbstractSceneWidgetHelper::_push_view64proj(PushBuffer&pb, const PushContext&ctx, const RenderedSnap&sn)
    {
        StdPushDataView64Proj&    pd  = *pb.create_single<StdPushDataView64Proj>();
        pd.time         = ctx.time;
        pd.gamma        = m_gamma;
        if(sn.self(Type::Rendered³) && static_cast<const Rendered³Snap&>(sn).camera){
            Tensor44D   V, P;
            _cam_matrix(V, P, ctx.frame, static_cast<const Rendered³Snap&>(sn).camera);
            pd.view         = V;
            pd.projection   = glm::dmat4(P);
        } else {
            pd.view         = ctx.view;
            pd.projection   = ctx.projection;
        }
    }

    SceneID     AbstractSceneWidgetHelper::id(scene_k) const
    {
        if(m_scene(Type::Scene)){
            return { m_scene.id };
        } else
            return {};
    }
    
    Scene³ID    AbstractSceneWidgetHelper::id(scene³_k) const
    {
        if(m_scene(Type::Scene³)){
            return { m_scene.id };
        } else
            return {};
    }
}
