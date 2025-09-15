# USBemani

## Original README [over here](https://github.com/progmem/usbemani)

## This is a fork of USBemani for *personal use* with my [pi-pico-shield]([https://github.com/Infecta/pi-pico-shield])
  
### ⚠ This mostly serves as a personal note for me in the future and to whoever comes across this repo

### Building USBemani
My fork uses docker as the build environment, on the repo there's a `Dockerfile` and `docker-compose.yml`

You can simply run:
```sh
# Clone repo and go into repo folder
git clone https://github.com/Infecta/usbemani.git && cd usbemani

# Build and run docker build environment
docker compose up -d

# Shell into the container
docker exec -it usbemani_buildenv /bin/bash

# Go to the mounted usbemani directory
cd usbemani # In case it doesn't work. absolute path is /root/usbemani

# Build firmware
make default/infecta/pragmatism

# The compiled firmware will be in /root/usbemani/build (The .uf2 file)
cd build
```
In the terminal while being in the repo's root.
#### How the container works

After bringing up the container the assigned name should be `usbemani_buildenv` and it will mount the root of the repo into `/root/usbemani`

**Q:** Why mount instead of cloning the repo?

**A:** Mostly because I can make immediate code changes outside the container and push changes when I need it.

**Q:** Why docker?

**A:** I don't like cluttering up my main system and using docker makes it easy, consistent and clean because I can bring down the container when I'm done.
*Is it ideal? No clue, but it works and it's what I do. If you have a better solution do send a PR so I can learn*

## FAQ

**Q:** How do I change the name of my PCB

**A:** In `layouts/default/infecta/pragmatism/config.h` look for:
```
#define USB_STRING_VENDOR_USBEMANI  "Infecta"
#define USB_STRING_PRODUCT_USBEMANI "PRAGMATiSM"
```