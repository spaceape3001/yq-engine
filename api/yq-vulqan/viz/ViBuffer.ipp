////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViBuffer.hpp"

#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/memory/Buffer.hpp>
#include <yq-vulqan/memory/Memory.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    ViBuffer::ViBuffer()
    {
    }
    
    ViBuffer::~ViBuffer()
    {
        kill();
    }

    ViBuffer::ViBuffer(ViVisualizer&viz, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu)
    {
        if(viz.device() && cb){
            if(_allocate(viz, cb, buf, vmu) != std::error_code()){
                _kill();
                _wipe();
            }
        }
    }
    
    ViBuffer::ViBuffer(ViVisualizer&viz, const Memory& v, VkBufferUsageFlags buf, const ViBufferOptions& opts)
    {
        if(viz.device() && v.bytes()){
            if(_create(viz, v, buf, opts) != std::error_code()){
                _kill();
                _wipe();
            }
        }
    }
    
    ViBuffer::ViBuffer(ViVisualizer&viz, const Buffer& v, const ViBufferOptions& opts)
    {
        if(viz.device() && v.memory.bytes()){
            if(_create(viz, v, opts) != std::error_code()){
                _kill();
                _wipe();
            }
        }
    }

    std::error_code ViBuffer::_allocate(ViVisualizer&viz, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu)
    {
        VqBufferCreateInfo  bufferInfo;
        bufferInfo.size         = (uint32_t) cb;
        bufferInfo.usage        = buf & VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM;
        
        VmaAllocationCreateInfo vmaallocInfo = {};
        vmaallocInfo.usage = vmu;
        VmaAllocationInfo   vai;
        if(vmaCreateBuffer(viz.allocator(), &bufferInfo, &vmaallocInfo, &m_buffer, &m_allocation, &vai) != VK_SUCCESS)
            return errors::INSUFFICIENT_GPU_MEMORY();

        m_size  = cb;
        m_viz   = &viz;
        return std::error_code();
    }
    
    std::error_code ViBuffer::_create(ViVisualizer&viz, const Memory& v, VkBufferUsageFlags buf, const ViBufferOptions& opts)
    {
        std::error_code     ec  = _allocate(viz, v.bytes(), buf, opts.usage);
        if(ec)
            return ec;
        if(vmaMapMemory(m_viz->allocator(), m_allocation, &m_data) != VK_SUCCESS)
            return errors::CANT_MAP_BUFFER_MEMORY();
        memcpy(m_data, v.data(), v.bytes());
        if(!opts.mapped){
            vmaUnmapMemory(m_viz->allocator(), m_allocation);
            m_data  = nullptr;
        }
        return {};
    }
    
    std::error_code ViBuffer::_create(ViVisualizer&viz, const Buffer& v, const ViBufferOptions& opts)
    {
        return _create(viz, v.memory, v.usage, opts);
    }

    void            ViBuffer::_kill()
    {
        if(m_data){
            vmaUnmapMemory(m_viz->allocator(), m_allocation);
            m_data  = nullptr;
        }
        if(m_allocation){
            vmaDestroyBuffer(m_viz->allocator(), m_buffer, m_allocation);
        }
    }

    void                ViBuffer::_wipe()
    {
        m_buffer        = nullptr;
        m_allocation    = nullptr;
        m_viz           = nullptr;
        m_size          = 0;
        m_data          = nullptr;
    }

    std::error_code     ViBuffer::allocate(ViVisualizer&viz, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu)
    {
        if(m_viz || m_buffer || m_allocation)
            return errors::EXISTING_BUFFER();
        if(m_data)
            return errors::BAD_STATE_BUFFER();
        if(!cb)
            return errors::SKIPPING_ZERO_SIZED_BUFFER();
        
        std::error_code ec =  _allocate(viz, cb, buf, vmu);
        if(ec != std::error_code())
            _kill();
        return ec;
    }
    
    bool                ViBuffer::consistent() const
    {
        return m_viz ? (m_allocation && m_buffer && m_viz -> device()) : (!m_allocation && !m_buffer);
    }

    std::error_code     ViBuffer::create(ViVisualizer&viz, const Memory& v, VkBufferUsageFlags buf, const ViBufferOptions&opts)
    {
        if(m_viz || m_buffer || m_allocation)
            return errors::EXISTING_BUFFER();
        if(m_data)
            return errors::BAD_STATE_BUFFER();
        if(!v.bytes())
            return errors::SKIPPING_ZERO_SIZED_BUFFER();
        
        std::error_code ec = _create(viz, v, buf, opts);
        if(ec != std::error_code())
            _kill();
        return ec;
    }
    
    std::error_code     ViBuffer::create(ViVisualizer&viz, const Buffer& v, const ViBufferOptions&opts)
    {
        if(m_viz || m_buffer || m_allocation)
            return errors::EXISTING_BUFFER();
        if(m_data)
            return errors::BAD_STATE_BUFFER();
        if(!v.memory.bytes())
            return errors::SKIPPING_ZERO_SIZED_BUFFER();

        std::error_code ec = _create(viz, v, opts);
        if(ec != std::error_code())
            _kill();
        return ec;
    }
    
    void                ViBuffer::kill()
    {
        if(valid()){
            _kill();
        }
        _wipe();
    }

    std::error_code     ViBuffer::map()
    {
        if(!valid())
            return errors::UNINITIALIZED_BUFFER();
        if(!m_data){
            if(vmaMapMemory(m_viz->allocator(), m_allocation, &m_data) != VK_SUCCESS){
                m_data  = nullptr;
                return errors::CANT_MAP_BUFFER_MEMORY();
            }
        }
        return {};
    }
    
    std::error_code     ViBuffer::unmap()
    {
        if(!valid())
            return errors::UNINITIALIZED_BUFFER();
        if(m_data){
            vmaUnmapMemory(m_viz->allocator(), m_allocation);
            m_data  = nullptr;
        }
        return {};
    }

    bool                ViBuffer::valid() const
    {
        return m_viz && m_allocation && m_buffer && m_viz -> device();
    }

}

