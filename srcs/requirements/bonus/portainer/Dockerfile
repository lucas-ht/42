FROM alpine:3.18

RUN apk update && apk upgrade &&        \
    apk add --no-cache                  \
            bind-tools                  \
            curl                        \
            tar                         \
                                        \
    && rm -f /var/cache/apk/*

RUN curl -sSL https://github.com/portainer/portainer/releases/download/2.18.4/portainer-2.18.4-linux-amd64.tar.gz | \
    tar -xzo -C /usr/local

EXPOSE 9000

ENTRYPOINT [                                                                    \
    "/usr/local/portainer/portainer",                                           \
    "--log-level=ERROR"                                                         \
]
