# Start from Ubuntu LTS base
FROM ubuntu:22.04

# Prevent interactive prompts during package installs
ENV DEBIAN_FRONTEND=noninteractive

# Update apt and install basic tools
RUN apt update && apt upgrade -y && \
    apt install -y git make cmake curl tar bzip2 software-properties-common && \
    add-apt-repository ppa:deadsnakes/ppa && apt update \
    apt install python3 python3-pip && \
    rm -rf /var/lib/apt/lists/* # Space saving operation (Deletes cached package index files)

# Set working Directory
WORKDIR /root

# Download and install pico toolchain
RUN curl --location 'https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2' --output gcc-arm-none-eabi-toolchain.tar
RUN mkdir /opt/gcc-arm-none-eabi
RUN tar -C /opt/gcc-arm-none-eabi/ -xf gcc-arm-none-eabi-toolchain.tar --strip-components 1

# Commit toolchain to PATH
RUN echo 'export PATH=$PATH:/opt/gcc-arm-none-eabi/bin' >> /root/.profile

# Keep container running with bash by default
CMD ["/bin/bash"]

