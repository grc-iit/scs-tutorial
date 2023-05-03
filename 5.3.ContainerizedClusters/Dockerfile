FROM ubuntu:20.04
LABEL maintainer="llogan@hawk.iit.edu"
LABEL version="0.0"
LABEL description="An example docker image"

# Disable Prompt During Packages Installation
ARG DEBIAN_FRONTEND=noninteractive

# Update ubuntu
RUN apt update && apt install

# Install some basic packages
RUN apt install -y \
    openssh-server \
    sudo \
    git

# Enable passwordless SSH

# Start SSHD and wait forever
RUN mkdir /run/sshd
RUN /usr/sbin/sshd
