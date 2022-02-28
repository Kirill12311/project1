#Download base image ubuntu 20.04
FROM ubuntu:20.04
# LABEL about the custom image
LABEL maintainer="Водянкин Кирилл"
LABEL version="0.1"
LABEL description="This is custom Docker Image for \
the PHP-FPM and Nginx Services."
# Update Ubuntu Software repository
RUN apt update
# Install nginx, php-fpm and supervisord from ubuntu repository
RUN apt install -y nginx php-fpm supervisor && \
rm -rf /var/lib/apt/lists/* && \
apt clean

