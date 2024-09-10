////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViBufferObject.hpp"

#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/memory/Buffer.hpp>
#include <yq-vulqan/pipeline/PipelineConfig.hpp>
#include <yq-vulqan/viz/ViBuffer.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    bool    ViBufferObject::update(ViVisualizer& viz, const BaseBOConfig&cfg, const void* p)
    {
        do {
            if(!cfg.fetch)
                return false;
            if(p ? (cfg.activity == DataActivity::COMMON) : (cfg.activity != DataActivity::COMMON))
                return false;
            if(!buffer)                                 // LOAD
                break;
            if(cfg.activity != DataActivity::DYNAMIC)   // LOAD
                break;
            if(!cfg.revision)
                return false;
            
            uint64_t    n   = cfg.revision(p);
            if(n == rev)
                return false;
            rev    = n;
        } while(false);
        
        BufferCPtr      c   = cfg.fetch(p);
        if(!c){     //  shouldn't really happen....
            vqWarning << "EMPTY BUFFER DETECTED!";
            return false;
        }
        
        ViBufferCPtr     xvb    = viz.buffer_create(*c);
        if(xvb && xvb->valid()){
            buffer  = xvb -> buffer();
            count   = c->memory.count();
            return true;
        }
        
        return false;
    }
}
