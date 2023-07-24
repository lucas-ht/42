FROM alpine:3.18

RUN apk update && apk upgrade &&        \
    apk add --no-cache                  \
            python3                     \
            py3-pip                     \
                                        \
    && rm -f /var/cache/apk/*

ADD ./conf/requirements.txt requirements.txt
RUN pip install -r requirements.txt

ADD ./app /var/www/app/
WORKDIR /var/www/app/

EXPOSE 8000

ENTRYPOINT [                            \
    "python3",                          \
    "-m",                               \
    "flask",                            \
    "run",                              \
    "--host=0.0.0.0",                   \
    "--port=8000"                       \
]