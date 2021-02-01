create database wordpress character set utf8mb4 collate utf8mb4_general_ci;
grant all privileges on wordpress.* to 'username' @'localhost' identified by 'password';
flush privileges;

CREATE USER 'lusokol'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON *.* TO 'lusokol'@'localhost' WITH GRANT OPTION;
FLUSH PRIVILEGES;
