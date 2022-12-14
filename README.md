# Typing battles

## Overview
Typing battles - is an opensource online service to improve your typing memory in programming languages by competiting with other players.

## How to build
The project consists of two servers: one is written in `C++` and computes the game, the other is written in `Python` and responsible for transfering data between `user` and `C++` server.
In order to build the `C++` run the `make` command:
```
git clone https://github.com/ivysochyn/network-programming-project typing-battles
cd typing-battles
make
```

The resulting `server` binary will be placed in primary project folder.

## How to run
Once the `C++` binary was built, the server can be started to listen.
Run the following command:
```
./server <port>
```

In order to start python server you need to use following command:
```
cd pyserver
python main.py <ip-to-serve> <port> <cpp-server-ip> <cpp-server-port>
```

As python server is running, you can obtain connection to it by openning the `htpp://<ip-to-serve>:<port>` in your browser.

## Docker image

The docker image can be built using following command:
```
# docker build -t flask-server .
```

And runned using:
```
# docker run --network host --rm -v $PWD:/data -u $(id -u):$(id -u) -it flask-server``
```
