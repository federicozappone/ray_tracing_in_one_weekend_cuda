# Ray Tracing in One Weekend

![Render](/assets/images/render.png)

Source code for the short course [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html).

### Building

```
sudo apt install ninja-build
pip install -r requirements.txt

meson setup --buildtype=plain build
ninja -C build
```

### Running the code and viewing the result

```
./build/src/main > assets/images/render.ppm
eog render.ppm
```

### Converting results to jpeg
```
ppmtojpeg assets/images/render.ppm > assets/images/render.jpg
```
