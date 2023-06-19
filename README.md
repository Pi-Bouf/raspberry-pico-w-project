# Raspberry Pico Project

## Installation (first build)
```
git clone https://github.com/Pi-Bouf/raspberry-pico-w-project.git --recursive
export PICO_SDK_PATH=~/Path To the freshly cloned repository/pico-sdk
mkdir build
cd build
cmake ..
make -j8
```

- Start your raspberry on BOOTSEL mode (press button `BOOTSEL` on top and plug USB).
- Copy & paste file name *.uf2 on the folder opened on Raspberry
- The raspberry will restart by itself, good job ! 🔥🔥


### Slow build ?
That's normal, it's because of pimoroni examples ! Open `pimoroni-pico/CMakeLists.txt` and remove/comment `add_subdirectory(examples)`.