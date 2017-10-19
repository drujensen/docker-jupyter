FROM gcr.io/tensorflow/tensorflow:latest-gpu

MAINTAINER Dru Jensen <drujensen@gmail.com>

USER root

ENV GRANT_SUDO=yes

RUN sudo apt-get -y update

RUN sudo apt-get install -y --no-install-recommends apt-transport-https ca-certificates curl software-properties-common

RUN curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - 

RUN sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"

RUN sudo apt-get -y update

RUN sudo apt-get -y --no-install-recommends install docker-ce

RUN pip install bcolz

RUN conda install -c conda-forge theano pygpu keras tensorflow
