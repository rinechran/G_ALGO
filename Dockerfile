FROM ubuntu:18.04

RUN apt update
RUN apt install -y cmake gcc g++


COPY . /app


WORKDIR /app

RUN ls -al
RUN mkdir build && cd build

RUN cmake .. && \
	make 
