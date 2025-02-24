////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/ASize3.hpp>
#include <ya/commands/spatial/AddSize3.hpp>
#include <ya/commands/spatial/AddSizeX.hpp>
#include <ya/commands/spatial/AddSizeY.hpp>
#include <ya/commands/spatial/AddSizeZ.hpp>
#include <ya/commands/spatial/MultiplySize.hpp>
#include <ya/commands/spatial/MultiplySize3.hpp>
#include <ya/commands/spatial/MultiplySizeX.hpp>
#include <ya/commands/spatial/MultiplySizeY.hpp>
#include <ya/commands/spatial/MultiplySizeZ.hpp>
#include <ya/commands/spatial/SetSize3.hpp>
#include <ya/commands/spatial/SetSizeX.hpp>
#include <ya/commands/spatial/SetSizeY.hpp>
#include <ya/commands/spatial/SetSizeZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize³::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<ISize³>();
        w.property(UNSAFE, "size", &ASize³::m_size).tag(kTag_Save);

        w.slot(UNSAFE, &ASize³::on_set_size3);
        w.slot(UNSAFE, &ASize³::on_set_sizeX);
        w.slot(UNSAFE, &ASize³::on_set_sizeY);
        w.slot(UNSAFE, &ASize³::on_set_sizeZ);

        w.slot(UNSAFE, &ASize³::on_add_size3);
        w.slot(UNSAFE, &ASize³::on_add_sizeX);
        w.slot(UNSAFE, &ASize³::on_add_sizeY);
        w.slot(UNSAFE, &ASize³::on_add_sizeZ);
        
        w.slot(UNSAFE, &ASize³::on_multiply_size);
        w.slot(UNSAFE, &ASize³::on_multiply_size3);
        w.slot(UNSAFE, &ASize³::on_multiply_sizeX);
        w.slot(UNSAFE, &ASize³::on_multiply_sizeY);
        w.slot(UNSAFE, &ASize³::on_multiply_sizeZ);
    }
}
