FROM alpine:3.18

RUN apk update && apk upgrade &&        \
    apk add --no-cache                  \
            mariadb                     \
            mariadb-client              \
            mariadb-server-utils        \
                                        \
    && rm -f /var/cache/apk/*

ADD ./tools/setup.sh /tmp/setup.sh
RUN chmod +x /tmp/setup.sh
ENTRYPOINT ["/tmp/setup.sh"]

EXPOSE 3306

CMD [                                   \
    "/usr/bin/mysqld",                  \
    "--user=mysql",                     \
    "--console",                        \
    "--silent-startup",                 \
    "--skip-networking=0",              \
    "--lower_case_table_names=2"        \
]
