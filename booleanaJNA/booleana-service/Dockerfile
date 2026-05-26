FROM eclipse-temurin:21-jdk AS native-builder

RUN apt-get update && \
    apt-get install -y gcc binutils && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /native

COPY native/booleana.h .
COPY native/booleana.c .

RUN gcc -shared -fPIC -O2 -o libbooleana.so booleana.c

RUN echo "=== Tabla de símbolos de libbooleana.so ===" && \
    nm -D libbooleana.so | grep " T "

FROM maven:3.9-eclipse-temurin-21 AS java-builder

WORKDIR /app

COPY pom.xml .
RUN mvn dependency:go-offline -q

COPY src ./src
RUN mvn clean package -DskipTests -q

FROM eclipse-temurin:21-jre

COPY --from=native-builder /native/libbooleana.so /usr/local/lib/libbooleana.so
RUN ldconfig

COPY --from=java-builder /app/target/booleana-service-*.jar /app/app.jar

EXPOSE 8080

ENTRYPOINT ["java", "-Djna.library.path=/usr/local/lib", "-jar", "/app/app.jar"]