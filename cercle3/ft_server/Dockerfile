FROM debian:buster

MAINTAINER Lucas Sokol <lusokol@student.42.fr>
# MaJ de la liste des paquets
RUN apt-get -y update -q \
# MaJ des paquets installés
	&& apt-get -y upgrade -q \
# installation de Nginx
	&& apt-get -y install nginx -q \
# installation de mysql
	&& apt-get -y install mariadb-server -q \
# installation de phpmyadmin
	&& apt-get -y install php7.3-fpm php7.3-mysql -q \
# installation du programme de telechargement (wget)
	&& apt-get -y install wget -q

RUN wget -q -c https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-english.tar.gz -O - | tar xz -C /var/www \
	&& mv var/www/phpMyAdmin-4.9.2-english var/www/phpmyadmin \
	&& chown -R www-data: /var/www/phpmyadmin

RUN wget -q -c https://wordpress.org/latest.tar.gz -O - | tar xz -C /var/www \
	&& chown -R www-data: /var/www/wordpress

ENV TEST on

COPY ./srcs/* docker/

RUN chmod 777 /docker/run.sh

CMD bash /docker/run.sh

EXPOSE 80 443
