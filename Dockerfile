FROM ubuntu:18.04

RUN apt update
RUN apt install -y cmake gcc g++

RUN mkdir build && cd build
RUN cmake ..
RUN make