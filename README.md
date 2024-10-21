## Dependencies
### Vulkan
```bash
sudo apt install vulkan-tools \
&& sudo apt install libvulkan-dev \
&& sudo apt install vulkan-validationlayers-dev spirv-tools
```
Run `vkcube` to make sure that your computer supports vulkan

### GLFW
```bash
sudo apt install libglfw3-dev
```

### GLM
```bash
sudo apt install libglm-dev
```

### Shader Compiler
```bash
wget -P ~/Downloads https://storage.googleapis.com/shaderc/artifacts/prod/graphics_shader_compiler/shaderc/linux/continuous_gcc_release/470/20241009-162246/install.tgz \
&& cd ~/Downloads \
&& tar -xzvf install.tgz \
&& sudo mv install/bin/glslc /usr/local/bin/ \
&& rm -rf install.tgz install
```

### Extra libraries
```bash
sudo apt install libxxf86vm-dev libxi-dev
```
