////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/Event.hpp>
#include <tachyon/keywords.hpp>
//#include <tbb/spin_rw_mutex.h> // if we need it

namespace yq::tachyon {
    /*! \brief Receiver of events
    
        This is what takes in events
    */
    class EventSocket {
    public:

        virtual std::string_view    description() const;
        virtual std::string_view    name() const;
        
        void    subscribe(pull_t, EventProducer&);
        void    unsubscribe(pull_t, EventProducer&);
        void    unsubscribe(pull_t);

    protected:
        friend class EventProducer;

        EventSocket();
        ~EventSocket();
        
        virtual void  handle(Event&) = 0;

    private:
        bool    _has(EventProducer*) const;
        void    _subscribe(EventProducer*);
        void    _unsubscribe(EventProducer*);
    
        //mutable tbb::spin_rw_mutex  m_mutex;
        std::vector<EventProducer*> m_producers;
    };
}
