#!/bin/bash

until mysql
do
	echo "NOT_YET"
done

mysql -u root < db.sql
wget --no-check-certificate https://raw.githubusercontent.com/skurudo/phpmyadmin-fixer/master/pma.sh && chmod +x pma.sh && ./pma.sh
#mysql wordpress < wordpress.sql