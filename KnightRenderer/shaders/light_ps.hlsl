////////////////////////////////////////////////////////////////////////////////
// Filename: color.ps
////////////////////////////////////////////////////////////////////////////////


/////////////
// GLOBALS //
/////////////
Texture2D shaderTexutre : register(t0);
SamplerState sampleType : register(s0);

cbuffer LightBuffer
{
    float4 ambientColor;
    float4 diffuseColor;
    float3 lightDirection;
    float specularPower;
    float4 specularColor;
};


//////////////
// TYPEDEFS //
//////////////
struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : NORMAL;
    float3 viewDirection : TEXCOORD1;
};


////////////////////////////////////////////////////////////////////////////////
// Pixel Shader
////////////////////////////////////////////////////////////////////////////////
float4 LightPixelShader(PixelInputType input) : SV_TARGET
{
	float4 textureColor;
    float3 lightDir;
    float lightIntensity;
    float4 color;
    float3 reflection;
    float4 specular;
    
    
    // Sample the pixel color from the texture using the sampler at this texture coordinate location.
	textureColor = shaderTexutre.Sample(sampleType, input.tex);

    // Set the default output color to the ambient light value for all pixels.
    color = ambientColor;
    
    // Initialize the specular color.
    specular = float4(0.0f, 0.0f, 0.0f, 0.0f);
    
    // Invert the light direction for calculations.
    lightDir = -lightDirection;
    
    // Calculate the amount of light on this pixel.
    lightIntensity = saturate(dot(input.normal, lightDir));
    
    if (lightIntensity > 0.0f)
    {
        // Determine the final diffuse color based on the diffuse color and the amount of light intensity.
        color += (diffuseColor * lightIntensity);
        
        // Saturate the ambient and diffuse color.
        color = saturate(color);

		// Calculate the reflection vector based on the light intensity, normal vector, and light direction.
        // 这个并不是标准的公式，插入了 lightIntensity，这里用 lightIntensity 影响了 reflection
        reflection = normalize(2.0f * lightIntensity * input.normal - lightDir);

		// Determine the amount of specular light based on the reflection vector, viewing direction, and specular power.
        specular = pow(saturate(dot(reflection, input.viewDirection)), specularPower);
    }
    
    // Multiply the texture pixel and the final diffuse color to get the final pixel color result.
    color = color * textureColor;
    
    // Add the specular component last to the output color.
    color = saturate(color + specular);
    
	return color;
}
