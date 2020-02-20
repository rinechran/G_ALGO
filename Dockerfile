FROM ubuntu:18.04

RUN apt update
RUN apt install -y cmake gcc g++


COPY . /app


WORKDIR /app

RUN mkdir build 
WORKDIR /app/tests
RUN ls -al

WORKDIR /app/build

RUN cmake .. && make
