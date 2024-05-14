#version 330 core

out vec4 fragColor;
in vec3 fragNormal;
in vec3 fragPosition;

//lighting
uniform vec3 lightPosition;
uniform vec3 lightAmbient;
uniform vec3 lightDiffuse;
uniform vec3 lightSpecular;
uniform vec3 lightColor;

//material parameters
uniform vec3 albedo;
uniform float metallic;
uniform float roughness;
uniform float ao;

//texture

varying vec2 TexCoords;
uniform int textureLoaded;
uniform sampler2D texture1;
uniform sampler2D texture2;

uniform vec3 camPos;

const float PI = 3.14159265359;

float distributionGGX(vec3 N, vec3 H, float roughness)
{
    float a = roughness*roughness;
    float a2 = a*a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH*NdotH;



    float nom   = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);

    denom = PI * denom * denom;


    return nom / max(denom, 0.0001); // prevent divide by zero for roughness=0.0 and NdotH=1.0

}

float geometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r*r) / 8.0;

    float nom   = NdotV;
    float denom = NdotV * (1.0 - k) + k;

    return nom / denom;
}

float geometrySmith(vec3 N, vec3 V, vec3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = geometrySchlickGGX(NdotV, roughness);
    float ggx1 = geometrySchlickGGX(NdotL, roughness);

    return ggx1 * ggx2;
}

vec3 fresnelSchlick(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(1.0 - cosTheta, 5.0);
}

void main() {
    vec3 N = normalize(fragNormal);
    vec3 V = normalize(camPos - fragPosition);

    // calcutate reflectance at normal incidence; if dia-electric (like plastic) use F0 = 0.04
    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);

    // reflectance equation
    vec3 Lo = vec3(0.0);

    // calculate per-light radiance
    vec3 L = normalize(lightPosition - fragPosition);
    vec3 H = normalize(V + L);
    float distance = length(lightPosition - fragPosition);
float attenuation = 1.0 / (distance * distance);
    vec3 radiance = lightColor * attenuation;

    // cook-torrance brdf
    float NDF = distributionGGX(N, H, roughness);
    float G   = geometrySmith(N, V, L, roughness);
    vec3 F    = fresnelSchlick(clamp(dot(H, V), 0.0, 1.0), F0);

    vec3 nominator = NDF * G * F;
    float denominator = 4 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0);
    vec3 specular = nominator / max(denominator, 0.001);

    // kS is equal to Fresnel
    vec3 kS = F;
    // for energy conservation, the diffuse and specular light can't
    // be above 1.0 (unless the surface emits light); to preserve this
    // relationship the diffuse component (kD) should equal 1.0 - kS.
    vec3 kD = vec3(1.0) - kS;
    // multiply kD by the inverse metalness such that only non-metals
    // have diffuse lighting, or a linear blend if partly metal (pure metals
    // have no diffuse light).
    kD *= 1.0 - metallic;

    // scale light by NdotL
    float NdotL = max(dot(N, L), 0.0);

    // add to outgoing radiance Lo
    Lo += (kD * albedo / PI + specular) * radiance * NdotL;


    // ambient lighting (note that the next IBL tutorial will replace
    // this ambient lighting model)
    vec3 ambient = lightAmbient * albedo * ao;
    vec3 color = ambient + Lo;

    // HDR tonemapping
    color = color / (color + vec3(1.0));

    // gamma correct
    color = pow(color, vec3(1.0/2.2));

    if(textureLoaded == 1){
        vec4 texColor1 = texture(texture1, TexCoords);
        vec4 texColor2 = texture(texture2, TexCoords);
        vec4 finalColor = mix(texColor1, texColor2, 0.5); // mix the colors of the two textures
        color = color * vec3(finalColor);

    }

    fragColor = vec4(color, 1.0);

    //vec4 texColor = texture(albedoMap, TexCoords);
}

