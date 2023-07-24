FROM alpine:3.18

RUN apk update && apk upgrade &&        \
    apk add --no-cache                  \
            nginx                       \
                                        \
    && rm -f /var/cache/apk/*

ADD ./requirements/nginx/conf/default.conf /etc/nginx/http.d/default.conf

ARG SSL_CRT
ADD ${SSL_CRT} /etc/nginx/ssl/crt.pem

ARG SSL_KEY
ADD ${SSL_KEY} /etc/nginx/ssl/key.pem

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
