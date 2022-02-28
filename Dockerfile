#Download base image ubuntu 20.04
FROM ubuntu:20.04
MAINTAINER Водянкин Кирилл гр. 748

COPY ./script .
RUN apt-get update
RUN apt-get upgrade
RUN apt-get yum
RUN chmod +x ./scpipt
CMD ./script
