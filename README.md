## Install docker

https://docs.docker.com/get-docker/

## Install docker-compose

Follow the guidance from here
https://docs.docker.com/compose/install/

## Bring up SystemC environment

docker-compose up

P/S: In the case that you want to install more packages, please update Dockerfile.
And rebuild container:
  docker-compose up -d --no-deps --build

## Run samples

### Login to docker component

docker-compose run sc bash
cd /samples

All samples are under this directory

### Execute "Hello World"

cd ./hello
make

If below information is shown, it means your environment is ready to go !

---

             SystemC 2.3.0-ASI --- Mar 14 2016 09:14:16
        Copyright (c) 1996-2012 by all Contributors,
        ALL RIGHTS RESERVED

Hello World.

---

### Install VCD viewer

#### Mac OS

Follow this link to setup 
https://cntnr.io/running-guis-with-docker-on-mac-os-x-a14df6a76efc

socat TCP-LISTEN:6000,reuseaddr,fork UNIX-CLIENT:\"$DISPLAY\"

