FROM ubuntu:18.04

RUN apt update
RUN apt install -y cmake gcc g++


COPY . /app


WORKDIR /app

RUN mkdir build && cd build

RUN cmake .. && \
	make 


