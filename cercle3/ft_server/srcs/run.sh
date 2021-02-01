#!/bin/bash

service nginx start
service mysql start
service php7.3-fpm start

#phpmyadmin
#wget -c https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz -O - | tar xz -C /var/www
#mv var/www/phpMyAdmin-5.0.2-english var/www/phpmyadmin
#chown -R www-data: /var/www/phpmyadmin

# wordpress
#wget -c https://wordpress.org/latest.tar.gz -O - | tar xz -C /var/www
#chown -R www-data: /var/www/wordpress

#nginx
cp docker/nginxserv /etc/nginx/sites-available/nginxserv
ln -s /etc/nginx/sites-available/nginxserv  /etc/nginx/sites-enabled/nginxserv
rm /etc/nginx/sites-enabled/default

mysql < /docker/database.sql

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt < docker/certificate


service nginx restart

/bin/sh
