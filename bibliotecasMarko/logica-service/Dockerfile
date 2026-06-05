# ════════════════════════════════════════════════════════════════════
# ETAPA 1 — Compilar la biblioteca dinámica C
# ════════════════════════════════════════════════════════════════════
FROM eclipse-temurin:21-jdk AS native-builder

RUN apt-get update && \
    apt-get install -y gcc binutils && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /native

# Copiar fuentes C de la biblioteca de lógica
COPY native/logica.h .
COPY native/logica.c .

# Compilar la biblioteca dinámica
RUN gcc -shared -fPIC -O2 -o liblogica.so logica.c

# Verificar símbolos exportados
RUN echo "=== Tabla de símbolos de liblogica.so ===" && \
    nm -D liblogica.so | grep " T "


# ════════════════════════════════════════════════════════════════════
# ETAPA 2 — Compilar el microservicio Spring Boot
# ════════════════════════════════════════════════════════════════════
FROM maven:3.9-eclipse-temurin-21 AS java-builder

WORKDIR /app

COPY pom.xml .
RUN mvn dependency:go-offline -q

COPY src ./src
RUN mvn clean package -DskipTests -q


# ════════════════════════════════════════════════════════════════════
# ETAPA 3 — Imagen final
# ════════════════════════════════════════════════════════════════════
FROM eclipse-temurin:21-jre

# Copiar la biblioteca nativa compilada
COPY --from=native-builder /native/liblogica.so /usr/local/lib/liblogica.so

RUN ldconfig

# Copiar el JAR generado
COPY --from=java-builder /app/target/logica-service-*.jar /app/app.jar

EXPOSE 8080

ENTRYPOINT ["java", \
            "-Djna.library.path=/usr/local/lib", \
            "-jar", "/app/app.jar"]
