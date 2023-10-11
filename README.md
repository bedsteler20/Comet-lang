# Building

## Linux

### Dependencies
For debian
```bash
sudo apt install gcc meson ninja
```

For fedora
```bash
sudo dnf install gcc meson ninja
```

### Building the code
```bash
mkdir -p build && meson setup build
cd build && meson compile
```
## Windows
**Not yet tested**
### Dependencies
```powershell
winget install -e --id mesonbuild.meson; winget install -e --id ninja.ninja
```
### Building the code
```bash
mkdir -p build && meson setup build
cd build && ninja --backend vs
```

## References
- [Meson setup of Intelij](https://blog.jetbrains.com/clion/2021/01/working-with-meson-in-clion-using-compilation-db/)
- [Meson docs](https://mesonbuild.com/)