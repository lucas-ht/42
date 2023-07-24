include ./srcs/.env

WORDPRESS	:=	$(VOLUME)/wordpress/
MARIADB		:=	$(VOLUME)/mariadb/

build: $(WORDPRESS) $(MARIADB)
	@-docker compose -f ./srcs/docker-compose.yml build

up: build
	@-docker compose -f ./srcs/docker-compose.yml up -d

down:
	@-docker compose -f ./srcs/docker-compose.yml down

clean: down
	@-docker compose -f ./srcs/docker-compose.yml down --rmi all --volumes
	@rm -rf $(VOLUME)

logs:
	@-docker compose -f ./srcs/docker-compose.yml logs -f

host:
	@$(shell sudo printf "::1 $(HOSTNAME)\n127.0.0.1 $(HOSTNAME)" >> /etc/hosts)

$(WORDPRESS):
	@mkdir -p $(WORDPRESS)

$(MARIADB):
	@mkdir -p $(MARIADB)

.PHONY: build up down clean logs host
