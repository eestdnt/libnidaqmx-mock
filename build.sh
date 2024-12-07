#!/bin/bash
PROJECT_NAME=libnidaqmx-mock

PLATFORM=$1
if [[ -z $PLATFORM ]];
then
    PLATFORM=linux
fi

if [[ "$PLATFORM" = "windows" ]];
then
    docker build -t $PROJECT_NAME-image -f windows-target.dockerfile .
    img_id=$(docker create $PROJECT_NAME-image)
    mkdir -p build/bin/
    docker cp $img_id:/app/build/bin/libnidaqmx.dll build/bin/
    docker rm -v $img_id
elif [[ "$PLATFORM" = "linux" ]];
then
    make
fi
