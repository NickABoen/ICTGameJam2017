// In UV, Texture, Sampler
// Essentially the function of this is to clamp the UV
// Or we might just use a render target

// round(uv * PixelWidth) / PixelWidth

// UV ScreenSize

float2 OutUV = float2(round(UV.x * ScreenSize.x) / ScreenSize.x, round(UV.y * ScreenSize.y) / ScreenSize.y);
return OutUV;
