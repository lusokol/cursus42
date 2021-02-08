#!/bin/bash

#sed -i 's/skip-networking/#skip-networking/g' /etc/my.cnf.d/mariadb-server.cnf
/usr/bin/mysql_install_db --user=root 
/usr/bin/mysqld --user=root --skip-networking=0