FROM debian:bullseye
RUN apt-get update \
    && env DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    python3 \
    python3-pip \
    g++ \
    gcc \
    make \
    && apt-get autoremove && apt-get clean && rm -rf /var/lib/apt/lists/*
COPY requirements.txt requirements.txt
RUN pip3 install -r requirements.txt

RUN useradd -u 1000 flask-server
RUN mkdir /home/flask-server
RUN chown flask-server:flask-server /home/flask-server
