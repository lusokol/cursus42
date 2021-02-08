DELETE FROM mysql.user WHERE user='';
CREATE USER 'admin'@'%' IDENTIFIED BY 'password';
CREATE DATABASE wordpress;
GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'%';
DROP DATABASE test;
FLUSH PRIVILEGES;