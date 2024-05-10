#version 460
#extension GL_EXT_ray_tracing : enable
#extension GL_GOOGLE_include_directive : require
#extension GL_EXT_nonuniform_qualifier : require
#extension GL_EXT_buffer_reference2 : require
#extension GL_EXT_scalar_block_layout : require
#extension GL_EXT_shader_explicit_arithmetic_types_int64 : require

layout(location = 0) rayPayloadInEXT vec3 hit_value;
hitAttributeEXT vec2 attribs;

#include "bufferreferences.glsl"
#include "geometrytypes.glsl"

layout(set = 1, binding = 1) uniform sampler2D base_color_sampler;

void main() {
    // 16-bit
    Triangle tri = UnpackTriangle(gl_PrimitiveID);
    vec4 base_color = texture(base_color_sampler, tri.uv);
    hit_value = base_color.rgb;
}