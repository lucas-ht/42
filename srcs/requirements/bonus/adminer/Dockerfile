FROM alpine:3.18

RUN apk update && apk upgrade &&    \
    apk add --no-cache              \
            curl                    \
            mariadb-client          \
                                    \
            php81                   \
            php81-fpm               \
            php81-bcmath            \
            php81-bz2               \
            php81-calendar          \
            php81-ctype             \
            php81-curl              \
            php81-dom               \
            php81-exif              \
            php81-fileinfo          \
            php81-gd                \
            php81-gmp               \
            php81-iconv             \
            php81-imap              \
            php81-intl              \
            php81-json              \
            php81-mbstring          \
            php81-mysqli            \
            php81-mysqlnd           \
            php81-openssl           \
            php81-pcntl             \
            php81-pdo               \
            php81-pdo_mysql         \
            php81-pdo_pgsql         \
            php81-pdo_sqlite        \
            php81-pgsql             \
            php81-phar              \
            php81-posix             \
            php81-session           \
            php81-shmop             \
            php81-simplexml         \
            php81-soap              \
            php81-sockets           \
            php81-sodium            \
            php81-sqlite3           \
            php81-sysvsem           \
            php81-sysvshm           \
            php81-tokenizer         \
            php81-xml               \
            php81-xmlreader         \
            php81-xmlwriter         \
            php81-xsl               \
            php81-zip               \
            php81-zlib              \
                                    \
    && rm -f /var/cache/apk/*

RUN mkdir -p /var/www/html/ && \
    curl -L -o /var/www/html/index.php https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php

ADD ./conf/www.conf /etc/php81/php-fpm.d/www.conf
RUN	adduser -S www && addgroup -S www

EXPOSE 9000

CMD ["/usr/sbin/php-fpm81", "--nodaemonize"]