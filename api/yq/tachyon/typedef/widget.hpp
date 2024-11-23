////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Widget;
    using WidgetPtr      = Ref<Widget>;
    using WidgetCPtr     = Ref<const Widget>;

    struct WidgetSnap;
    using WidgetSnapPtr  = Ref<WidgetSnap>;
    using WidgetSnapCPtr = Ref<const WidgetSnap>;
    
    struct WidgetData;
    using WidgetDataPtr  = Ref<WidgetData>;
    using WidgetDataCPtr = Ref<const WidgetData>;

    template <class> class ID;
    using WidgetID = ID<Widget>;
}
