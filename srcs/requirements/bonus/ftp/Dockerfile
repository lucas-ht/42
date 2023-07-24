FROM alpine:3.18

RUN apk update && apk upgrade &&        \
    apk add --no-cache                  \
            vsftpd                      \
                                        \
    && rm -f /var/cache/apk/*

ADD ./conf/vsftpd.conf /tmp/vsftpd.conf

ADD ./tools/setup.sh /tmp/setup.sh
RUN chmod +x /tmp/setup.sh
ENTRYPOINT ["/tmp/setup.sh"]

EXPOSE 21

CMD ["/usr/sbin/vsftpd", "/etc/vsftpd/vsftpd.conf"]