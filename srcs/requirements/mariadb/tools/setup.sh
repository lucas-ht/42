#!/bin/sh

if [ ! -d "/run/mysqld" ]; then
    mkdir -p /run/mysqld;
fi;

chown -R mysql:mysql /run/mysqld;
chown -R mysql:mysql /var/lib/mysql;

if [ -d /var/lib/mysql/mysql ]; then
    echo "The MySQL data directory already exists, skipping initial DB setup";
else
    echo "The MySQL data directory is empty, initializing DB...";

    mysql_install_db --user=mysql --ldata=/var/lib/mysql > /dev/null;

    /usr/bin/mysqld --user=mysql --bootstrap --verbose=0 --skip-networking=0 --silent-startup --lower_case_table_names=2 << EOF
USE mysql;
FLUSH PRIVILEGES;
DROP DATABASE IF EXISTS test;
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\` CHARACTER SET utf8 COLLATE utf8_general_ci;
GRANT ALL ON \`${MYSQL_DATABASE}\`.* to '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
EOF

    echo "MySQL DB initialized successfully";
fi;

echo "Starting MySQL server...";
exec "$@";
