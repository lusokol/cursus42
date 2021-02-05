#!/bin/bash

sed -i 's/skip-networking/#skip-networking/g' /etc/my.cnf.d/mariadb-server.cnf
/usr/bin/mysql_install_db --user=mysql --datadir="/var/lib/mysql" 
/usr/bin/mysqld_safe --datadir="/var/lib/mysql" 