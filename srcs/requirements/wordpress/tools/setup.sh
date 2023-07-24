#!/bin/sh

if [ -f ./wp-config.php ]; then
    echo "WordPress is already installed";
else
    echo "WordPress is not installed, installing...";

    wp core download --locale=en_US --allow-root;

    wp config create                        \
        --dbname=$MYSQL_DATABASE            \
        --dbuser=$MYSQL_USER                \
        --dbpass=$MYSQL_PASSWORD            \
        --dbhost=mariadb                    \
        --dbcharset="utf8"                  \
        --dbcollate="utf8_general_ci"       \
        --skip-check                        \
        --allow-root;

    wp core install                         \
        --url=$HOSTNAME                     \
        --title=$WP_TITLE                   \
        --admin_user=$WP_ROOT_USER          \
        --admin_password=$WP_ROOT_PASSWORD  \
        --admin_email=$WP_ROOT_MAIL         \
        --skip-email                        \
        --allow-root;

    wp user create $WP_USER $WP_MAIL --role=author --user_pass=$WP_PASSWORD --allow-root;

    wp theme install blocksy --activate --allow-root;

    wp config set WP_REDIS_HOST "redis" --allow-root;
    wp plugin install redis-cache --activate --allow-root;
    wp redis enable --allow-root;

    echo "WordPress has been installed";
fi;

echo "Starting WordPress...";
exec "$@"