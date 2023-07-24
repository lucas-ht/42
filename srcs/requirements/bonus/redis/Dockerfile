FROM alpine:3.18

RUN apk update && apk upgrade &&        \
    apk add --no-cache                  \
            redis                       \
                                        \
    && rm -f /var/cache/apk/*

ADD ./conf/redis.conf /etc/redis.conf

EXPOSE 6379

ENTRYPOINT ["redis-server", "/etc/redis.conf"]