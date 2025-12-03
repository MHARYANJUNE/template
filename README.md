# my-app

A simple GTK4/libadwaita application built with C++.

## Prerequisites

Before building this application, ensure you have the following dependencies installed:

- **Meson** (build system)
- **Ninja** (build backend)
- **GCC/G++** (C++ compiler with C++17 support)
- **libadwaita-1** (GNOME library)
- **GTK4** (required by libadwaita)

### Installing Dependencies

#### On Ubuntu/Debian:
```bash
sudo apt install meson ninja-build build-essential libadwaita-1-dev
```

#### On Fedora:
```bash
sudo dnf install meson ninja-build gcc-c++ libadwaita-devel
```

#### On Arch Linux:
```bash
sudo pacman -S meson ninja base-devel libadwaita
```

## Building the Application

1. **Clone the repository:**
   ```bash
   git clone https://github.com/MHARYANJUNE/template.git
   cd template
   ```

2. **Set up the build directory:**
   ```bash
   meson setup build_template
   ```

3. **Compile the application:**
   ```bash
   meson compile -C build_template
   ```

4. **Run the application:**
   ```bash
   ./build_template/my-app
   ```

## Installing the Application

To install the application system-wide:

```bash
sudo meson install -C build_template
```

After installation, you can run the application from anywhere:
```bash
my-app
```

## Project Structure

```
template/
├── main.cpp           # Main application entry point
├── meson.build        # Build configuration
└── README.md          # This file
```

## Development

To reconfigure or clean the build:

```bash
# Reconfigure
meson setup --reconfigure build_template

# Clean build
rm -rf build_template
meson setup build_template
```

## License

[Add your license information here]

## Contributing

[Add contribution guidelines here]
