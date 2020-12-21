# CPURasterizer

Efficient CPU based rasterizer

CPU implementation of a very efficient rasterizer which utilizes `AVX2` instructions and lock-free multi-threading programming. Using tiled rendering the program consumes 8 pixels at the same time, which together with `std::execution` threading library makes it very fast and robust. The viewer of the project is a very simple OpenGL applicatoin which renders a texture to a quad. The texture is generated by the CPU `Renderer.h` class. The pipeline contains most of the modern GPU rasterizers stages including:

```
- Vertex Transformation
- Clipping
- Rasterization
- Perspective Corrected Interpolation
- Fragment Shading
- Depth Testing
```

Except rasterization pipeine the project contains serveral additional features:   

- Tiled rendering using AVX2 (2x4 pixels tile)
- Shadow maps
- Texture sampling
- OpenGL viewer (only texture rendering)
- C++17 (`std::execution` etc.)

### Performance

All tests were done on CPU i4790k with 4 cores

| Scene         | Triangles | MSAA | FPS |
| ------------- |-----------|------|-----|
| Cornell box   | 36        |  1x  | 60  |
| Coffee cart   | 27000     |  1x  | 60  |
| Panther       | 2000000   |  1x  |  8  |

### How to run

All dependencies needed for the project can be downloaded using `install.bat` script. The project has `Visual Studio 2019` solution.

### Assets

The scene description and assets are taken from [GLSL-PathTracer](https://github.com/knightcrawler25/GLSL-PathTracer) project [4]. The whole dataset can be downloaded from [link](https://drive.google.com/file/d/1UFMMoVb5uB7WIvCeHOfQ2dCQSxNMXluB/view).

Download the assets folder and place it in `PBRVulkan/Assets/Scenes/`. The folder structure has to be as follows:

```
PBRVulkan/Assets/Scenes/
    bedroom/
    coffee_cart/
    HDR/
    bedroom.scene
    coffee_cart.scene
    ...
```

### References/Credits
[0] [Optimizing the basic rasterizer](https://fgiesen.wordpress.com/2013/02/10/optimizing-the-basic-rasterizer/)  
[1] [Rasterization on larrabee](https://www.drdobbs.com/parallel/rasterization-on-larrabee/217200602)  
[2] [Rasterization practical implementation](https://www.scratchapixel.com/lessons/3d-basic-rendering/rasterization-practical-implementation/rasterization-practical-implementation)  
[3] [EDXRaster](https://github.com/behindthepixels/EDXRaster)
