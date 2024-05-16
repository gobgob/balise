FROM alpine:3.19.1

# Install dependencies
RUN apk update
RUN apk add alpine-sdk
RUN apk add gcc-avr avr-libc

# Set workdir
WORKDIR /app

# Compile program
CMD make

# Build docker image
# docker build -f Dockerfile.makefile . --tag receiver-compile

# Execute unit test
# docker run --rm -it --volume ${PWD}:/app receiver-compile

# Execute bash in docker
# docker run --rm -it --volume ${PWD}:/app --entrypoint sh receiver-compile
