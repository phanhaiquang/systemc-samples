HOST_DISPLAY = $(shell ipconfig getifaddr en1)

all: setup_host run

setup_host:
	@echo ${HOST_DISPLAY}
	@xhost + ${HOST_DISPLAY}
	@echo "DISPLAY=${HOST_DISPLAY}:0" > .env
	@socat TCP-LISTEN:6000,reuseaddr,fork UNIX-CLIENT:\"$$DISPLAY\" &

run:
	@docker-compose run sc bash

