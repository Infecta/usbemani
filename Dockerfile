# Start from Ubuntu LTS base
FROM ubuntu:22.04

# Prevent interactive prompts during package installs
ENV DEBIAN_FRONTEND=noninteractive

# Update apt repo and install basic tools
RUN apt update && \
    apt install -y git make cmake curl tar bzip2 software-properties-common && \
    add-apt-repository ppa:deadsnakes/ppa && apt update && \
    apt install -y python3 python3-pip && \
    rm -rf /var/lib/apt/lists/* # Space saving operation (Deletes cached package index files)

# Set working Directory
WORKDIR /root

# Download and install pico toolchain
RUN curl --location 'https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2' --output gcc-arm-none-eabi-toolchain.tar
RUN mkdir /opt/gcc-arm-none-eabi
RUN tar -C /opt/gcc-arm-none-eabi/ -xf gcc-arm-none-eabi-toolchain.tar --strip-components 1

# Commit toolchain to PATH
RUN echo 'export PATH=$PATH:/opt/gcc-arm-none-eabi/bin' >> /root/.profile
# Discovered build errors if when clean building
RUN echo "PICO_TOOLCHAIN_PATH=/opt/gcc-arm-none-eabi/bin/" >> /root/.profile

# Might as well make it look nice when you log in right?
# I couldn't figure out how to do a single-liner.
RUN echo "echo ================================" >> /root/.bashrc
RUN echo "echo **usbemani-buildenv**" >> /root/.bashrc
RUN echo "echo ================================" >> /root/.bashrc
RUN echo "echo Welcome!" >> /root/.bashrc
RUN echo "echo I assume you're reading or have read the documentation" >> /root/.bashrc
RUN echo "echo https://github.com/Infecta/usbemani" >> /root/.bashrc
RUN echo "echo If not it's 'make default/infecta/pragmatism'" >> /root/.bashrc
RUN echo "echo ================================" >> /root/.bashrc
RUN echo "echo \n" >> /root/.bashrc

# Delete pico toolchain tarball
RUN rm /root/gcc-arm-none-eabi-toolchain.tar

# Set default working directory when user shells into the container
WORKDIR /root/usbemani

# Keep container running with bash by default
CMD ["/bin/bash"]

