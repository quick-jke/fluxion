#!/bin/bash

IMAGE_NAME="qfluxion"

# Запуск контейнера
docker run --rm -it \
  -v "$(pwd)":/workspace \
  "$IMAGE_NAME" "$@" 
  