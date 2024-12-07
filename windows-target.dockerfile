FROM debian:latest

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y make mingw-w64

COPY makefile /app/
COPY src /app/src
COPY inc /app/inc
RUN cd /app && TARGET_NAME=libnidaqmx.dll CC=x86_64-w64-mingw32-gcc make

