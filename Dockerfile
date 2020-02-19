FROM ubuntu:18.04

RUN apt update
RUN apt install -y cmake gcc g++

RUN mkdir build && cd build
RUN ls -al
RUN cmake ..
RUN make