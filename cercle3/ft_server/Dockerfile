FROM debian:buster

MAINTAINER Lucas Sokol <lusokol@student.42.fr>

RUN apt-get update \
    && apt-get install -y \
        nginx

COPY nginx.conf /etc/nginx/nginx.conf
COPY static-html-directory /usr/share/nginx/html

COPY service_start.sh /home/docker/script/service_start.sh
RUN chmod 744 /home/docker/script/service_start.sh

EXPOSE 80 443
#ENTRYPOINT /home/docker/script/service_start.sh
#WORKDIR /home/docker
