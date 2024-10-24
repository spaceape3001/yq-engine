////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/Event.hpp>
#include <vector>
#include <atomic>
//#include <tbb/spin_rw_mutex.h> // if we need it
#include <tachyon/keywords.hpp>

namespace yq::tachyon {

    /*! \brief Eventable thing
        
        Combines what had previously been producers & sockets, instead,
        everything has this capability
    */
    class Eventable {
    public:

        void        subscribe(push_t, Eventable&);
        void        subscribe(pull_t, Eventable&);

        void        unsubscribe(push_t, Eventable&);
        void        unsubscribe(pull_t, Eventable&);
        
        void        unsubscribe(push_t);
        void        unsubscribe(pull_t);
        
        void        unsubscribe(Eventable&);

        virtual std::string_view    name() const;
        virtual std::string_view    description() const;
        
        //! Total number of events generated by this producer
        uint64_t    events_generated() const;

    protected:

        void            publish(EventPtr);
        virtual void    handle(Event&){}

        template <SomeEvent E>
        E&              publish(E* ep, ref_t)
        {
            assert(ep);
            publish(ep);
            return *ep;
        }

        template <SomeEvent E>
        E&              publish(E* ep, reference_t)
        {
            assert(ep);
            publish(ep);
            return *ep;
        }

        template <SomeEvent E>
        E*              publish(E* ep, pointer_t)
        {
            assert(ep);
            publish(ep);
            return ep;
        }

        Eventable();
        ~Eventable();
    
    private:
        
        friend class EventManager;

        struct Thread;
        static Thread&              thread();

        //mutable tbb::spin_rw_mutex  m_mutex;
        std::vector<Eventable*>     m_sockets;      //!< Those that have subscribed to us
        std::vector<Eventable*>     m_producers;    //!< Those that we are subscribers to
        std::atomic<uint64_t>       m_count{0};
        
        bool    _has(EventSocket*) const;
        void    _subscribe(pull_t, Eventable*);
        void    _subscribe(push_t, Eventable*);
        void    _unsubscribe(pull_t, Eventable*);
        void    _unsubscribe(push_t, Eventable*);
    };
}
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
    };
}
