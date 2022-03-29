FROM mysql:latest

ENV MYSQL_DATABASE "42Labs"
ENV MYSQL_ROOT_PASSWORD "sqlpw"

COPY ./sql-scripts/ /docker-entrypoint-initdb.d/