FROM jupyter/datascience-notebook

MAINTAINER Dru Jensen <drujensen@gmail.com>

RUN pip install bcolz

RUN conda install -c conda-forge theano pygpu keras tensorflow
