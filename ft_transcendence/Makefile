DOCKER_ID := $(shell docker ps -aq)
DOCKER_IMAGE_ID := $(shell docker images -q)
DOCKER_VOLUME := $(shell docker volume ls -q)
PWD := $(shell pwd)

FRONTEND_VOL_PATH := $(PWD)/Transcendence-FE/front/srcs
BACKEND_VOL_PATH := $(PWD)/Transcendence-BE/srcs/backend/srcs
USERS_VOL_PATH := $(PWD)/Transcendence-BE/srcs/user-manager/srcs
GAME_VOL_PATH := $(PWD)/Transcendence-BE/srcs/game/srcs

all:
	sed -i '' 's|^\(FRONTEND_VOL_PATH\).*|FRONTEND_VOL_PATH=$(FRONTEND_VOL_PATH)|' "./.env"
	sed -i '' 's|^\(BACKEND_VOL_PATH\).*|BACKEND_VOL_PATH=$(BACKEND_VOL_PATH)|' './.env'
	sed -i '' 's|^\(USERS_VOL_PATH\).*|USERS_VOL_PATH=$(USERS_VOL_PATH)|' './.env'
	sed -i '' 's|^\(GAME_VOL_PATH\).*|GAME_VOL_PATH=$(GAME_VOL_PATH)|' './.env'

	docker compose -f ./compose.yaml up -d

up:
	docker compose -f ./compose.yaml up -d

down:
	docker compose -f ./compose.yaml down

re: fclean
	make all

fclean:
	$(if $(DOCKER_ID), docker rm -f $(DOCKER_ID))
	$(if $(DOCKER_VOLUME), docker volume rm $(DOCKER_VOLUME))
	docker rmi -f user-manager backend game nginx
	rm -f ./Transcendence-BE/srcs/backend/srcs/users/migrations/0* \
	./Transcendence-BE/srcs/user-manager/srcs/users/migrations/0* \
	./Transcendence-BE/srcs/game/srcs/users/migrations/0*

.PHONY: all up down re fclean