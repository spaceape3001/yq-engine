////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VqEnums.hpp"
#include <yq-toolbox/basic/Enum.hpp>

namespace yq::tachyon {

        //  TODO: Fold these into tachyon/enum

    YQ_ENUM(VqColorSpaceKHR, , 
        SRGB_NONLINEAR_KHR = 0,
        DISPLAY_P3_NONLINEAR_EXT = 1000104001,
        EXTENDED_SRGB_LINEAR_EXT = 1000104002,
        DISPLAY_P3_LINEAR_EXT = 1000104003,
        DCI_P3_NONLINEAR_EXT = 1000104004,
        BT709_LINEAR_EXT = 1000104005,
        BT709_NONLINEAR_EXT = 1000104006,
        BT2020_LINEAR_EXT = 1000104007,
        HDR10_ST2084_EXT = 1000104008,
        DOLBYVISION_EXT = 1000104009,
        HDR10_HLG_EXT = 1000104010,
        ADOBERGB_LINEAR_EXT = 1000104011,
        ADOBERGB_NONLINEAR_EXT = 1000104012,
        PASS_THROUGH_EXT = 1000104013,
        EXTENDED_SRGB_NONLINEAR_EXT = 1000104014,
        DISPLAY_NATIVE_AMD = 1000213000
    )

    std::string_view to_string_view(VkColorSpaceKHR v)
    {
        int n   = (int) v;
        if(VqColorSpaceKHR::has_value(n))
            return VqColorSpaceKHR(n).key();
        return "(unknown color space)";
    }
    
    YQ_ENUM(VqDebugReportObjectType, , 
        UNKNOWN_EXT = 0,
        INSTANCE_EXT = 1,
        PHYSICAL_DEVICE_EXT = 2,
        DEVICE_EXT = 3,
        QUEUE_EXT = 4,
        SEMAPHORE_EXT = 5,
        COMMAND_BUFFER_EXT = 6,
        FENCE_EXT = 7,
        DEVICE_MEMORY_EXT = 8,
        BUFFER_EXT = 9,
        IMAGE_EXT = 10,
        EVENT_EXT = 11,
        QUERY_POOL_EXT = 12,
        BUFFER_VIEW_EXT = 13,
        IMAGE_VIEW_EXT = 14,
        SHADER_MODULE_EXT = 15,
        PIPELINE_CACHE_EXT = 16,
        PIPELINE_LAYOUT_EXT = 17,
        RENDER_PASS_EXT = 18,
        PIPELINE_EXT = 19,
        DESCRIPTOR_SET_LAYOUT_EXT = 20,
        SAMPLER_EXT = 21,
        DESCRIPTOR_POOL_EXT = 22,
        DESCRIPTOR_SET_EXT = 23,
        FRAMEBUFFER_EXT = 24,
        COMMAND_POOL_EXT = 25,
        SURFACE_KHR_EXT = 26,
        SWAPCHAIN_KHR_EXT = 27,
        DEBUG_REPORT_CALLBACK_EXT_EXT = 28,
        DISPLAY_KHR_EXT = 29,
        DISPLAY_MODE_KHR_EXT = 30,
        VALIDATION_CACHE_EXT_EXT = 33,
        SAMPLER_YCBCR_CONVERSION_EXT = 1000156000,
        DESCRIPTOR_UPDATE_TEMPLATE_EXT = 1000085000,
        CU_MODULE_NVX_EXT = 1000029000,
        CU_FUNCTION_NVX_EXT = 1000029001,
        ACCELERATION_STRUCTURE_KHR_EXT = 1000150000,
        ACCELERATION_STRUCTURE_NV_EXT = 1000165000,
        BUFFER_COLLECTION_FUCHSIA_EXT = 1000366000,
    )
    
    std::string_view                        to_string_view(VkDebugReportObjectTypeEXT v)
    {
        int n   = (int) v;
        if(VqDebugReportObjectType::has_value(n))
            return VqDebugReportObjectType(n).key();
        return "(unknown object_type)";
    }
    
    YQ_ENUM(VqDynamicState, ,
        VIEWPORT = 0,
        SCISSOR = 1,
        LINE_WIDTH = 2,
        DEPTH_BIAS = 3,
        BLEND_CONSTANTS = 4,
        DEPTH_BOUNDS = 5,
        STENCIL_COMPARE_MASK = 6,
        STENCIL_WRITE_MASK = 7,
        STENCIL_REFERENCE = 8,
        CULL_MODE = 1000267000,
        FRONT_FACE = 1000267001,
        PRIMITIVE_TOPOLOGY = 1000267002,
        VIEWPORT_WITH_COUNT = 1000267003,
        SCISSOR_WITH_COUNT = 1000267004,
        VERTEX_INPUT_BINDING_STRIDE = 1000267005,
        DEPTH_TEST_ENABLE = 1000267006,
        DEPTH_WRITE_ENABLE = 1000267007,
        DEPTH_COMPARE_OP = 1000267008,
        DEPTH_BOUNDS_TEST_ENABLE = 1000267009,
        STENCIL_TEST_ENABLE = 1000267010,
        STENCIL_OP = 1000267011,
        RASTERIZER_DISCARD_ENABLE = 1000377001,
        DEPTH_BIAS_ENABLE = 1000377002,
        PRIMITIVE_RESTART_ENABLE = 1000377004,
        VIEWPORT_W_SCALING_NV = 1000087000,
        DISCARD_RECTANGLE_EXT = 1000099000,
        SAMPLE_LOCATIONS_EXT = 1000143000,
        RAY_TRACING_PIPELINE_STACK_SIZE_KHR = 1000347000,
        VIEWPORT_SHADING_RATE_PALETTE_NV = 1000164004,
        VIEWPORT_COARSE_SAMPLE_ORDER_NV = 1000164006,
        EXCLUSIVE_SCISSOR_NV = 1000205001,
        FRAGMENT_SHADING_RATE_KHR = 1000226000,
        LINE_STIPPLE_EXT = 1000259000,
        VERTEX_INPUT_EXT = 1000352000,
        PATCH_CONTROL_POINTS_EXT = 1000377000,
        LOGIC_OP_EXT = 1000377003,
        COLOR_WRITE_ENABLE_EXT = 1000381000
    )
    
    std::string_view                        to_string_view(VkDynamicState v)
    {
        int n   = (int) v;
        if(VqDynamicState::has_value(n))
            return VqDynamicState(n).key();
        return "(unknown object_type)";
    }

#if 0
    YQ_ENUM(VqFormat, ,
        // TAKEN as copy & paste from vulkan_core.h (removing dupes)
    
        UNDEFINED = 0,
        R4G4_UNORM_PACK8 = 1,
        R4G4B4A4_UNORM_PACK16 = 2,
        B4G4R4A4_UNORM_PACK16 = 3,
        R5G6B5_UNORM_PACK16 = 4,
        B5G6R5_UNORM_PACK16 = 5,
        R5G5B5A1_UNORM_PACK16 = 6,
        B5G5R5A1_UNORM_PACK16 = 7,
        A1R5G5B5_UNORM_PACK16 = 8,
        R8_UNORM = 9,
        R8_SNORM = 10,
        R8_USCALED = 11,
        R8_SSCALED = 12,
        R8_UINT = 13,
        R8_SINT = 14,
        R8_SRGB = 15,
        R8G8_UNORM = 16,
        R8G8_SNORM = 17,
        R8G8_USCALED = 18,
        R8G8_SSCALED = 19,
        R8G8_UINT = 20,
        R8G8_SINT = 21,
        R8G8_SRGB = 22,
        R8G8B8_UNORM = 23,
        R8G8B8_SNORM = 24,
        R8G8B8_USCALED = 25,
        R8G8B8_SSCALED = 26,
        R8G8B8_UINT = 27,
        R8G8B8_SINT = 28,
        R8G8B8_SRGB = 29,
        B8G8R8_UNORM = 30,
        B8G8R8_SNORM = 31,
        B8G8R8_USCALED = 32,
        B8G8R8_SSCALED = 33,
        B8G8R8_UINT = 34,
        B8G8R8_SINT = 35,
        B8G8R8_SRGB = 36,
        R8G8B8A8_UNORM = 37,
        R8G8B8A8_SNORM = 38,
        R8G8B8A8_USCALED = 39,
        R8G8B8A8_SSCALED = 40,
        R8G8B8A8_UINT = 41,
        R8G8B8A8_SINT = 42,
        R8G8B8A8_SRGB = 43,
        B8G8R8A8_UNORM = 44,
        B8G8R8A8_SNORM = 45,
        B8G8R8A8_USCALED = 46,
        B8G8R8A8_SSCALED = 47,
        B8G8R8A8_UINT = 48,
        B8G8R8A8_SINT = 49,
        B8G8R8A8_SRGB = 50,
        A8B8G8R8_UNORM_PACK32 = 51,
        A8B8G8R8_SNORM_PACK32 = 52,
        A8B8G8R8_USCALED_PACK32 = 53,
        A8B8G8R8_SSCALED_PACK32 = 54,
        A8B8G8R8_UINT_PACK32 = 55,
        A8B8G8R8_SINT_PACK32 = 56,
        A8B8G8R8_SRGB_PACK32 = 57,
        A2R10G10B10_UNORM_PACK32 = 58,
        A2R10G10B10_SNORM_PACK32 = 59,
        A2R10G10B10_USCALED_PACK32 = 60,
        A2R10G10B10_SSCALED_PACK32 = 61,
        A2R10G10B10_UINT_PACK32 = 62,
        A2R10G10B10_SINT_PACK32 = 63,
        A2B10G10R10_UNORM_PACK32 = 64,
        A2B10G10R10_SNORM_PACK32 = 65,
        A2B10G10R10_USCALED_PACK32 = 66,
        A2B10G10R10_SSCALED_PACK32 = 67,
        A2B10G10R10_UINT_PACK32 = 68,
        A2B10G10R10_SINT_PACK32 = 69,
        R16_UNORM = 70,
        R16_SNORM = 71,
        R16_USCALED = 72,
        R16_SSCALED = 73,
        R16_UINT = 74,
        R16_SINT = 75,
        R16_SFLOAT = 76,
        R16G16_UNORM = 77,
        R16G16_SNORM = 78,
        R16G16_USCALED = 79,
        R16G16_SSCALED = 80,
        R16G16_UINT = 81,
        R16G16_SINT = 82,
        R16G16_SFLOAT = 83,
        R16G16B16_UNORM = 84,
        R16G16B16_SNORM = 85,
        R16G16B16_USCALED = 86,
        R16G16B16_SSCALED = 87,
        R16G16B16_UINT = 88,
        R16G16B16_SINT = 89,
        R16G16B16_SFLOAT = 90,
        R16G16B16A16_UNORM = 91,
        R16G16B16A16_SNORM = 92,
        R16G16B16A16_USCALED = 93,
        R16G16B16A16_SSCALED = 94,
        R16G16B16A16_UINT = 95,
        R16G16B16A16_SINT = 96,
        R16G16B16A16_SFLOAT = 97,
        R32_UINT = 98,
        R32_SINT = 99,
        R32_SFLOAT = 100,
        R32G32_UINT = 101,
        R32G32_SINT = 102,
        R32G32_SFLOAT = 103,
        R32G32B32_UINT = 104,
        R32G32B32_SINT = 105,
        R32G32B32_SFLOAT = 106,
        R32G32B32A32_UINT = 107,
        R32G32B32A32_SINT = 108,
        R32G32B32A32_SFLOAT = 109,
        R64_UINT = 110,
        R64_SINT = 111,
        R64_SFLOAT = 112,
        R64G64_UINT = 113,
        R64G64_SINT = 114,
        R64G64_SFLOAT = 115,
        R64G64B64_UINT = 116,
        R64G64B64_SINT = 117,
        R64G64B64_SFLOAT = 118,
        R64G64B64A64_UINT = 119,
        R64G64B64A64_SINT = 120,
        R64G64B64A64_SFLOAT = 121,
        B10G11R11_UFLOAT_PACK32 = 122,
        E5B9G9R9_UFLOAT_PACK32 = 123,
        D16_UNORM = 124,
        X8_D24_UNORM_PACK32 = 125,
        D32_SFLOAT = 126,
        S8_UINT = 127,
        D16_UNORM_S8_UINT = 128,
        D24_UNORM_S8_UINT = 129,
        D32_SFLOAT_S8_UINT = 130,
        BC1_RGB_UNORM_BLOCK = 131,
        BC1_RGB_SRGB_BLOCK = 132,
        BC1_RGBA_UNORM_BLOCK = 133,
        BC1_RGBA_SRGB_BLOCK = 134,
        BC2_UNORM_BLOCK = 135,
        BC2_SRGB_BLOCK = 136,
        BC3_UNORM_BLOCK = 137,
        BC3_SRGB_BLOCK = 138,
        BC4_UNORM_BLOCK = 139,
        BC4_SNORM_BLOCK = 140,
        BC5_UNORM_BLOCK = 141,
        BC5_SNORM_BLOCK = 142,
        BC6H_UFLOAT_BLOCK = 143,
        BC6H_SFLOAT_BLOCK = 144,
        BC7_UNORM_BLOCK = 145,
        BC7_SRGB_BLOCK = 146,
        ETC2_R8G8B8_UNORM_BLOCK = 147,
        ETC2_R8G8B8_SRGB_BLOCK = 148,
        ETC2_R8G8B8A1_UNORM_BLOCK = 149,
        ETC2_R8G8B8A1_SRGB_BLOCK = 150,
        ETC2_R8G8B8A8_UNORM_BLOCK = 151,
        ETC2_R8G8B8A8_SRGB_BLOCK = 152,
        EAC_R11_UNORM_BLOCK = 153,
        EAC_R11_SNORM_BLOCK = 154,
        EAC_R11G11_UNORM_BLOCK = 155,
        EAC_R11G11_SNORM_BLOCK = 156,
        ASTC_4x4_UNORM_BLOCK = 157,
        ASTC_4x4_SRGB_BLOCK = 158,
        ASTC_5x4_UNORM_BLOCK = 159,
        ASTC_5x4_SRGB_BLOCK = 160,
        ASTC_5x5_UNORM_BLOCK = 161,
        ASTC_5x5_SRGB_BLOCK = 162,
        ASTC_6x5_UNORM_BLOCK = 163,
        ASTC_6x5_SRGB_BLOCK = 164,
        ASTC_6x6_UNORM_BLOCK = 165,
        ASTC_6x6_SRGB_BLOCK = 166,
        ASTC_8x5_UNORM_BLOCK = 167,
        ASTC_8x5_SRGB_BLOCK = 168,
        ASTC_8x6_UNORM_BLOCK = 169,
        ASTC_8x6_SRGB_BLOCK = 170,
        ASTC_8x8_UNORM_BLOCK = 171,
        ASTC_8x8_SRGB_BLOCK = 172,
        ASTC_10x5_UNORM_BLOCK = 173,
        ASTC_10x5_SRGB_BLOCK = 174,
        ASTC_10x6_UNORM_BLOCK = 175,
        ASTC_10x6_SRGB_BLOCK = 176,
        ASTC_10x8_UNORM_BLOCK = 177,
        ASTC_10x8_SRGB_BLOCK = 178,
        ASTC_10x10_UNORM_BLOCK = 179,
        ASTC_10x10_SRGB_BLOCK = 180,
        ASTC_12x10_UNORM_BLOCK = 181,
        ASTC_12x10_SRGB_BLOCK = 182,
        ASTC_12x12_UNORM_BLOCK = 183,
        ASTC_12x12_SRGB_BLOCK = 184,
        G8B8G8R8_422_UNORM = 1000156000,
        B8G8R8G8_422_UNORM = 1000156001,
        G8_B8_R8_3PLANE_420_UNORM = 1000156002,
        G8_B8R8_2PLANE_420_UNORM = 1000156003,
        G8_B8_R8_3PLANE_422_UNORM = 1000156004,
        G8_B8R8_2PLANE_422_UNORM = 1000156005,
        G8_B8_R8_3PLANE_444_UNORM = 1000156006,
        R10X6_UNORM_PACK16 = 1000156007,
        R10X6G10X6_UNORM_2PACK16 = 1000156008,
        R10X6G10X6B10X6A10X6_UNORM_4PACK16 = 1000156009,
        G10X6B10X6G10X6R10X6_422_UNORM_4PACK16 = 1000156010,
        B10X6G10X6R10X6G10X6_422_UNORM_4PACK16 = 1000156011,
        G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16 = 1000156012,
        G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16 = 1000156013,
        G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16 = 1000156014,
        G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16 = 1000156015,
        G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16 = 1000156016,
        R12X4_UNORM_PACK16 = 1000156017,
        R12X4G12X4_UNORM_2PACK16 = 1000156018,
        R12X4G12X4B12X4A12X4_UNORM_4PACK16 = 1000156019,
        G12X4B12X4G12X4R12X4_422_UNORM_4PACK16 = 1000156020,
        B12X4G12X4R12X4G12X4_422_UNORM_4PACK16 = 1000156021,
        G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16 = 1000156022,
        G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16 = 1000156023,
        G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16 = 1000156024,
        G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16 = 1000156025,
        G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16 = 1000156026,
        G16B16G16R16_422_UNORM = 1000156027,
        B16G16R16G16_422_UNORM = 1000156028,
        G16_B16_R16_3PLANE_420_UNORM = 1000156029,
        G16_B16R16_2PLANE_420_UNORM = 1000156030,
        G16_B16_R16_3PLANE_422_UNORM = 1000156031,
        G16_B16R16_2PLANE_422_UNORM = 1000156032,
        G16_B16_R16_3PLANE_444_UNORM = 1000156033,
        G8_B8R8_2PLANE_444_UNORM = 1000330000,
        G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16 = 1000330001,
        G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16 = 1000330002,
        G16_B16R16_2PLANE_444_UNORM = 1000330003,
        A4R4G4B4_UNORM_PACK16 = 1000340000,
        A4B4G4R4_UNORM_PACK16 = 1000340001,
        ASTC_4x4_SFLOAT_BLOCK = 1000066000,
        ASTC_5x4_SFLOAT_BLOCK = 1000066001,
        ASTC_5x5_SFLOAT_BLOCK = 1000066002,
        ASTC_6x5_SFLOAT_BLOCK = 1000066003,
        ASTC_6x6_SFLOAT_BLOCK = 1000066004,
        ASTC_8x5_SFLOAT_BLOCK = 1000066005,
        ASTC_8x6_SFLOAT_BLOCK = 1000066006,
        ASTC_8x8_SFLOAT_BLOCK = 1000066007,
        ASTC_10x5_SFLOAT_BLOCK = 1000066008,
        ASTC_10x6_SFLOAT_BLOCK = 1000066009,
        ASTC_10x8_SFLOAT_BLOCK = 1000066010,
        ASTC_10x10_SFLOAT_BLOCK = 1000066011,
        ASTC_12x10_SFLOAT_BLOCK = 1000066012,
        ASTC_12x12_SFLOAT_BLOCK = 1000066013,
        PVRTC1_2BPP_UNORM_BLOCK_IMG = 1000054000,
        PVRTC1_4BPP_UNORM_BLOCK_IMG = 1000054001,
        PVRTC2_2BPP_UNORM_BLOCK_IMG = 1000054002,
        PVRTC2_4BPP_UNORM_BLOCK_IMG = 1000054003,
        PVRTC1_2BPP_SRGB_BLOCK_IMG = 1000054004,
        PVRTC1_4BPP_SRGB_BLOCK_IMG = 1000054005,
        PVRTC2_2BPP_SRGB_BLOCK_IMG = 1000054006,
        PVRTC2_4BPP_SRGB_BLOCK_IMG = 1000054007
    )
#endif

    std::string_view to_string_view(VkFormat fmt)
    {
        using namespace std::literals::string_view_literals;
        switch(fmt){
        case VK_FORMAT_UNDEFINED:
            return "UNDEFINED"sv;
        case VK_FORMAT_R4G4_UNORM_PACK8:
            return "R4G4_UNORM_PACK8"sv;
        case VK_FORMAT_R4G4B4A4_UNORM_PACK16:
            return "R4G4B4A4_UNORM_PACK16"sv;
        case VK_FORMAT_B4G4R4A4_UNORM_PACK16:
            return "B4G4R4A4_UNORM_PACK16"sv;
        case VK_FORMAT_R5G6B5_UNORM_PACK16:
            return "R5G6B5_UNORM_PACK16"sv;
        case VK_FORMAT_B5G6R5_UNORM_PACK16:
            return "B5G6R5_UNORM_PACK16"sv;
        case VK_FORMAT_R5G5B5A1_UNORM_PACK16:
            return "R5G5B5A1_UNORM_PACK16"sv;
        case VK_FORMAT_B5G5R5A1_UNORM_PACK16:
            return "B5G5R5A1_UNORM_PACK16"sv;
        case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
            return "A1R5G5B5_UNORM_PACK16"sv;
        case VK_FORMAT_R8_UNORM:
            return "R8_UNORM"sv;
        case VK_FORMAT_R8_SNORM:
            return "R8_SNORM"sv;
        case VK_FORMAT_R8_USCALED:
            return "R8_USCALED"sv;
        case VK_FORMAT_R8_SSCALED:
            return "R8_SSCALED"sv;
        case VK_FORMAT_R8_UINT:
            return "R8_UINT"sv;
        case VK_FORMAT_R8_SINT:
            return "R8_SINT"sv;
        case VK_FORMAT_R8_SRGB:
            return "R8_SRGB"sv;
        case VK_FORMAT_R8G8_UNORM:
            return "R8G8_UNORM"sv;
        case VK_FORMAT_R8G8_SNORM:
            return "R8G8_SNORM"sv;
        case VK_FORMAT_R8G8_USCALED:
            return "R8G8_USCALED"sv;
        case VK_FORMAT_R8G8_SSCALED:
            return "R8G8_SSCALED"sv;
        case VK_FORMAT_R8G8_UINT:
            return "R8G8_UINT"sv;
        case VK_FORMAT_R8G8_SINT:
            return "R8G8_SINT"sv;
        case VK_FORMAT_R8G8_SRGB:
            return "R8G8_SRGB"sv;
        case VK_FORMAT_R8G8B8_UNORM:
            return "R8G8B8_UNORM"sv;
        case VK_FORMAT_R8G8B8_SNORM:
            return "R8G8B8_SNORM"sv;
        case VK_FORMAT_R8G8B8_USCALED:
            return "R8G8B8_USCALED"sv;
        case VK_FORMAT_R8G8B8_SSCALED:
            return "R8G8B8_SSCALED"sv;
        case VK_FORMAT_R8G8B8_UINT:
            return "R8G8B8_UINT"sv;
        case VK_FORMAT_R8G8B8_SINT:
            return "R8G8B8_SINT"sv;
        case VK_FORMAT_R8G8B8_SRGB:
            return "R8G8B8_SRGB"sv;
        case VK_FORMAT_B8G8R8_UNORM:
            return "B8G8R8_UNORM"sv;
        case VK_FORMAT_B8G8R8_SNORM:
            return "B8G8R8_SNORM"sv;
        case VK_FORMAT_B8G8R8_USCALED:
            return "B8G8R8_USCALED"sv;
        case VK_FORMAT_B8G8R8_SSCALED:
            return "B8G8R8_SSCALED"sv;
        case VK_FORMAT_B8G8R8_UINT:
            return "B8G8R8_UINT"sv;
        case VK_FORMAT_B8G8R8_SINT:
            return "B8G8R8_SINT"sv;
        case VK_FORMAT_B8G8R8_SRGB:
            return "B8G8R8_SRGB"sv;
        case VK_FORMAT_R8G8B8A8_UNORM:
            return "R8G8B8A8_UNORM"sv;
        case VK_FORMAT_R8G8B8A8_SNORM:
            return "R8G8B8A8_SNORM"sv;
        case VK_FORMAT_R8G8B8A8_USCALED:
            return "R8G8B8A8_USCALED"sv;
        case VK_FORMAT_R8G8B8A8_SSCALED:
            return "R8G8B8A8_SSCALED"sv;
        case VK_FORMAT_R8G8B8A8_UINT:
            return "R8G8B8A8_UINT"sv;
        case VK_FORMAT_R8G8B8A8_SINT:
            return "R8G8B8A8_SINT"sv;
        case VK_FORMAT_R8G8B8A8_SRGB:
            return "R8G8B8A8_SRGB"sv;
        case VK_FORMAT_B8G8R8A8_UNORM:
            return "B8G8R8A8_UNORM"sv;
        case VK_FORMAT_B8G8R8A8_SNORM:
            return "B8G8R8A8_SNORM"sv;
        case VK_FORMAT_B8G8R8A8_USCALED:
            return "B8G8R8A8_USCALED"sv;
        case VK_FORMAT_B8G8R8A8_SSCALED:
            return "B8G8R8A8_SSCALED"sv;
        case VK_FORMAT_B8G8R8A8_UINT:
            return "B8G8R8A8_UINT"sv;
        case VK_FORMAT_B8G8R8A8_SINT:
            return "B8G8R8A8_SINT"sv;
        case VK_FORMAT_B8G8R8A8_SRGB:
            return "B8G8R8A8_SRGB"sv;
        case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
            return "A8B8G8R8_UNORM_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_SNORM_PACK32:
            return "A8B8G8R8_SNORM_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_USCALED_PACK32:
            return "A8B8G8R8_USCALED_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
            return "A8B8G8R8_SSCALED_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_UINT_PACK32:
            return "A8B8G8R8_UINT_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_SINT_PACK32:
            return "A8B8G8R8_SINT_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
            return "A8B8G8R8_SRGB_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
            return "A2R10G10B10_UNORM_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_SNORM_PACK32:
            return "A2R10G10B10_SNORM_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_USCALED_PACK32:
            return "A2R10G10B10_USCALED_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
            return "A2R10G10B10_SSCALED_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_UINT_PACK32:
            return "A2R10G10B10_UINT_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_SINT_PACK32:
            return "A2R10G10B10_SINT_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
            return "A2B10G10R10_UNORM_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_SNORM_PACK32:
            return "A2B10G10R10_SNORM_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_USCALED_PACK32:
            return "A2B10G10R10_USCALED_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
            return "A2B10G10R10_SSCALED_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_UINT_PACK32:
            return "A2B10G10R10_UINT_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_SINT_PACK32:
            return "A2B10G10R10_SINT_PACK32"sv;
        case VK_FORMAT_R16_UNORM:
            return "R16_UNORM"sv;
        case VK_FORMAT_R16_SNORM:
            return "R16_SNORM"sv;
        case VK_FORMAT_R16_USCALED:
            return "R16_USCALED"sv;
        case VK_FORMAT_R16_SSCALED:
            return "R16_SSCALED"sv;
        case VK_FORMAT_R16_UINT:
            return "R16_UINT"sv;
        case VK_FORMAT_R16_SINT:
            return "R16_SINT"sv;
        case VK_FORMAT_R16_SFLOAT:
            return "R16_SFLOAT"sv;
        case VK_FORMAT_R16G16_UNORM:
            return "R16G16_UNORM"sv;
        case VK_FORMAT_R16G16_SNORM:
            return "R16G16_SNORM"sv;
        case VK_FORMAT_R16G16_USCALED:
            return "R16G16_USCALED"sv;
        case VK_FORMAT_R16G16_SSCALED:
            return "R16G16_SSCALED"sv;
        case VK_FORMAT_R16G16_UINT:
            return "R16G16_UINT"sv;
        case VK_FORMAT_R16G16_SINT:
            return "R16G16_SINT"sv;
        case VK_FORMAT_R16G16_SFLOAT:
            return "R16G16_SFLOAT"sv;
        case VK_FORMAT_R16G16B16_UNORM:
            return "R16G16B16_UNORM"sv;
        case VK_FORMAT_R16G16B16_SNORM:
            return "R16G16B16_SNORM"sv;
        case VK_FORMAT_R16G16B16_USCALED:
            return "R16G16B16_USCALED"sv;
        case VK_FORMAT_R16G16B16_SSCALED:
            return "R16G16B16_SSCALED"sv;
        case VK_FORMAT_R16G16B16_UINT:
            return "R16G16B16_UINT"sv;
        case VK_FORMAT_R16G16B16_SINT:
            return "R16G16B16_SINT"sv;
        case VK_FORMAT_R16G16B16_SFLOAT:
            return "R16G16B16_SFLOAT"sv;
        case VK_FORMAT_R16G16B16A16_UNORM:
            return "R16G16B16A16_UNORM"sv;
        case VK_FORMAT_R16G16B16A16_SNORM:
            return "R16G16B16A16_SNORM"sv;
        case VK_FORMAT_R16G16B16A16_USCALED:
            return "R16G16B16A16_USCALED"sv;
        case VK_FORMAT_R16G16B16A16_SSCALED:
            return "R16G16B16A16_SSCALED"sv;
        case VK_FORMAT_R16G16B16A16_UINT:
            return "R16G16B16A16_UINT"sv;
        case VK_FORMAT_R16G16B16A16_SINT:
            return "R16G16B16A16_SINT"sv;
        case VK_FORMAT_R16G16B16A16_SFLOAT:
            return "R16G16B16A16_SFLOAT"sv;
        case VK_FORMAT_R32_UINT:
            return "R32_UINT"sv;
        case VK_FORMAT_R32_SINT:
            return "R32_SINT"sv;
        case VK_FORMAT_R32_SFLOAT:
            return "R32_SFLOAT"sv;
        case VK_FORMAT_R32G32_UINT:
            return "R32G32_UINT"sv;
        case VK_FORMAT_R32G32_SINT:
            return "R32G32_SINT"sv;
        case VK_FORMAT_R32G32_SFLOAT:
            return "R32G32_SFLOAT"sv;
        case VK_FORMAT_R32G32B32_UINT:
            return "R32G32B32_UINT"sv;
        case VK_FORMAT_R32G32B32_SINT:
            return "R32G32B32_SINT"sv;
        case VK_FORMAT_R32G32B32_SFLOAT:
            return "R32G32B32_SFLOAT"sv;
        case VK_FORMAT_R32G32B32A32_UINT:
            return "R32G32B32A32_UINT"sv;
        case VK_FORMAT_R32G32B32A32_SINT:
            return "R32G32B32A32_SINT"sv;
        case VK_FORMAT_R32G32B32A32_SFLOAT:
            return "R32G32B32A32_SFLOAT"sv;
        case VK_FORMAT_R64_UINT:
            return "R64_UINT"sv;
        case VK_FORMAT_R64_SINT:
            return "R64_SINT"sv;
        case VK_FORMAT_R64_SFLOAT:
            return "R64_SFLOAT"sv;
        case VK_FORMAT_R64G64_UINT:
            return "R64G64_UINT"sv;
        case VK_FORMAT_R64G64_SINT:
            return "R64G64_SINT"sv;
        case VK_FORMAT_R64G64_SFLOAT:
            return "R64G64_SFLOAT"sv;
        case VK_FORMAT_R64G64B64_UINT:
            return "R64G64B64_UINT"sv;
        case VK_FORMAT_R64G64B64_SINT:
            return "R64G64B64_SINT"sv;
        case VK_FORMAT_R64G64B64_SFLOAT:
            return "R64G64B64_SFLOAT"sv;
        case VK_FORMAT_R64G64B64A64_UINT:
            return "R64G64B64A64_UINT"sv;
        case VK_FORMAT_R64G64B64A64_SINT:
            return "R64G64B64A64_SINT"sv;
        case VK_FORMAT_R64G64B64A64_SFLOAT:
            return "R64G64B64A64_SFLOAT"sv;
        case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
            return "B10G11R11_UFLOAT_PACK32"sv;
        case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
            return "E5B9G9R9_UFLOAT_PACK32"sv;
        case VK_FORMAT_D16_UNORM:
            return "D16_UNORM"sv;
        case VK_FORMAT_X8_D24_UNORM_PACK32:
            return "X8_D24_UNORM_PACK32"sv;
        case VK_FORMAT_D32_SFLOAT:
            return "D32_SFLOAT"sv;
        case VK_FORMAT_S8_UINT:
            return "S8_UINT"sv;
        case VK_FORMAT_D16_UNORM_S8_UINT:
            return "D16_UNORM_S8_UINT"sv;
        case VK_FORMAT_D24_UNORM_S8_UINT:
            return "D24_UNORM_S8_UINT"sv;
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return "D32_SFLOAT_S8_UINT"sv;
        case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
            return "BC1_RGB_UNORM_BLOCK"sv;
        case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
            return "BC1_RGB_SRGB_BLOCK"sv;
        case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
            return "BC1_RGBA_UNORM_BLOCK"sv;
        case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
            return "BC1_RGBA_SRGB_BLOCK"sv;
        case VK_FORMAT_BC2_UNORM_BLOCK:
            return "BC2_UNORM_BLOCK"sv;
        case VK_FORMAT_BC2_SRGB_BLOCK:
            return "BC2_SRGB_BLOCK"sv;
        case VK_FORMAT_BC3_UNORM_BLOCK:
            return "BC3_UNORM_BLOCK"sv;
        case VK_FORMAT_BC3_SRGB_BLOCK:
            return "BC3_SRGB_BLOCK"sv;
        case VK_FORMAT_BC4_UNORM_BLOCK:
            return "BC4_UNORM_BLOCK"sv;
        case VK_FORMAT_BC4_SNORM_BLOCK:
            return "BC4_SNORM_BLOCK"sv;
        case VK_FORMAT_BC5_UNORM_BLOCK:
            return "BC5_UNORM_BLOCK"sv;
        case VK_FORMAT_BC5_SNORM_BLOCK:
            return "BC5_SNORM_BLOCK"sv;
        case VK_FORMAT_BC6H_UFLOAT_BLOCK:
            return "BC6H_UFLOAT_BLOCK"sv;
        case VK_FORMAT_BC6H_SFLOAT_BLOCK:
            return "BC6H_SFLOAT_BLOCK"sv;
        case VK_FORMAT_BC7_UNORM_BLOCK:
            return "BC7_UNORM_BLOCK"sv;
        case VK_FORMAT_BC7_SRGB_BLOCK:
            return "BC7_SRGB_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
            return "ETC2_R8G8B8_UNORM_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
            return "ETC2_R8G8B8_SRGB_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
            return "ETC2_R8G8B8A1_UNORM_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
            return "ETC2_R8G8B8A1_SRGB_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
            return "ETC2_R8G8B8A8_UNORM_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
            return "ETC2_R8G8B8A8_SRGB_BLOCK"sv;
        case VK_FORMAT_EAC_R11_UNORM_BLOCK:
            return "EAC_R11_UNORM_BLOCK"sv;
        case VK_FORMAT_EAC_R11_SNORM_BLOCK:
            return "EAC_R11_SNORM_BLOCK"sv;
        case VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
            return "EAC_R11G11_UNORM_BLOCK"sv;
        case VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
            return "EAC_R11G11_SNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
            return "ASTC_4x4_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
            return "ASTC_4x4_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
            return "ASTC_5x4_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
            return "ASTC_5x4_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
            return "ASTC_5x5_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
            return "ASTC_5x5_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
            return "ASTC_6x5_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
            return "ASTC_6x5_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
            return "ASTC_6x6_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
            return "ASTC_6x6_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
            return "ASTC_8x5_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
            return "ASTC_8x5_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
            return "ASTC_8x6_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
            return "ASTC_8x6_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
            return "ASTC_8x8_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
            return "ASTC_8x8_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
            return "ASTC_10x5_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
            return "ASTC_10x5_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
            return "ASTC_10x6_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
            return "ASTC_10x6_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
            return "ASTC_10x8_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
            return "ASTC_10x8_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
            return "ASTC_10x10_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
            return "ASTC_10x10_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
            return "ASTC_12x10_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
            return "ASTC_12x10_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
            return "ASTC_12x12_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
            return "ASTC_12x12_SRGB_BLOCK"sv;
        case VK_FORMAT_G8B8G8R8_422_UNORM:
            return "G8B8G8R8_422_UNORM"sv;
        case VK_FORMAT_B8G8R8G8_422_UNORM:
            return "B8G8R8G8_422_UNORM"sv;
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
            return "G8_B8_R8_3PLANE_420_UNORM"sv;
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
            return "G8_B8R8_2PLANE_420_UNORM"sv;
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
            return "G8_B8_R8_3PLANE_422_UNORM"sv;
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
            return "G8_B8R8_2PLANE_422_UNORM"sv;
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
            return "G8_B8_R8_3PLANE_444_UNORM"sv;
        case VK_FORMAT_R10X6_UNORM_PACK16:
            return "R10X6_UNORM_PACK16"sv;
        case VK_FORMAT_R10X6G10X6_UNORM_2PACK16:
            return "R10X6G10X6_UNORM_2PACK16"sv;
        case VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16:
            return "R10X6G10X6B10X6A10X6_UNORM_4PACK16"sv;
        case VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16:
            return "G10X6B10X6G10X6R10X6_422_UNORM_4PACK16"sv;
        case VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16:
            return "B10X6G10X6R10X6G10X6_422_UNORM_4PACK16"sv;
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
            return "G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16"sv;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
            return "G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16"sv;
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
            return "G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16"sv;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
            return "G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16"sv;
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
            return "G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16"sv;
        case VK_FORMAT_R12X4_UNORM_PACK16:
            return "R12X4_UNORM_PACK16"sv;
        case VK_FORMAT_R12X4G12X4_UNORM_2PACK16:
            return "R12X4G12X4_UNORM_2PACK16"sv;
        case VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16:
            return "R12X4G12X4B12X4A12X4_UNORM_4PACK16"sv;
        case VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16:
            return "G12X4B12X4G12X4R12X4_422_UNORM_4PACK16"sv;
        case VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16:
            return "B12X4G12X4R12X4G12X4_422_UNORM_4PACK16"sv;
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
            return "G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16"sv;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
            return "G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16"sv;
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
            return "G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16"sv;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
            return "G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16"sv;
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
            return "G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16"sv;
        case VK_FORMAT_G16B16G16R16_422_UNORM:
            return "G16B16G16R16_422_UNORM"sv;
        case VK_FORMAT_B16G16R16G16_422_UNORM:
            return "B16G16R16G16_422_UNORM"sv;
        case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
            return "G16_B16_R16_3PLANE_420_UNORM"sv;
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
            return "G16_B16R16_2PLANE_420_UNORM"sv;
        case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
            return "G16_B16_R16_3PLANE_422_UNORM"sv;
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
            return "G16_B16R16_2PLANE_422_UNORM"sv;
        case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
            return "G16_B16_R16_3PLANE_444_UNORM"sv;
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM:
            return "G8_B8R8_2PLANE_444_UNORM"sv;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16:
            return "G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16"sv;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16:
            return "G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16"sv;
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM:
            return "G16_B16R16_2PLANE_444_UNORM"sv;
        case VK_FORMAT_A4R4G4B4_UNORM_PACK16:
            return "A4R4G4B4_UNORM_PACK16"sv;
        case VK_FORMAT_A4B4G4R4_UNORM_PACK16:
            return "A4B4G4R4_UNORM_PACK16"sv;
        case VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK:
            return "ASTC_4x4_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK:
            return "ASTC_5x4_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK:
            return "ASTC_5x5_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK:
            return "ASTC_6x5_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK:
            return "ASTC_6x6_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK:
            return "ASTC_8x5_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK:
            return "ASTC_8x6_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK:
            return "ASTC_8x8_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK:
            return "ASTC_10x5_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK:
            return "ASTC_10x6_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK:
            return "ASTC_10x8_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK:
            return "ASTC_10x10_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK:
            return "ASTC_12x10_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK:
            return "ASTC_12x12_SFLOAT_BLOCK"sv;
        case VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG:
            return "PVRTC1_2BPP_UNORM_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG:
            return "PVRTC1_4BPP_UNORM_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG:
            return "PVRTC2_2BPP_UNORM_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG:
            return "PVRTC2_4BPP_UNORM_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
            return "PVRTC1_2BPP_SRGB_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
            return "PVRTC1_4BPP_SRGB_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
            return "PVRTC2_2BPP_SRGB_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
            return "PVRTC2_4BPP_SRGB_BLOCK_IMG"sv;
        case VK_FORMAT_R16G16_SFIXED5_NV:
            return "R16G16_SFIXED5_NV"sv;
        case VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR:
            return "A1B5G5R5_UNORM_PACK16_KHR"sv;
        case VK_FORMAT_A8_UNORM_KHR:
            return "A8_UNORM_KHR"sv;
        default:
            return "Not Listed"sv;
        }

#if 0    
        int n   = (int) fmt;
        if(VqFormat::has_value(n))
            return VqFormat(n).key();
        return "(unknown format)";
#endif
    }
    
    YQ_ENUM(VqPhysicalDeviceType, ,
        Other = 0,
        Integrated = 1,
        Discrete = 2,
        Virtual = 3,
        CPU     = 4
    )

    std::string_view                        to_string_view(VkPhysicalDeviceType v)
    {
        int n   = (int) v;
        if(VqPhysicalDeviceType::has_value(n))
            return VqPhysicalDeviceType(n).key();
        return "(unknown device type)";
    }
}
