#!/bin/bash

docker run --rm -it -u $UID -v $(pwd):/var/build:rw -w /var/build/build darkmattercoder/qt-build:5.15.2 build
