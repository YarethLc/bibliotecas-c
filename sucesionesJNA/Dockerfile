# ════════════════════════════════════════════════════════════════════
# ETAPA 1 — Compilar la biblioteca dinámica C (sucesiones)
# ════════════════════════════════════════════════════════════════════
FROM eclipse-temurin:21-jdk AS native-builder

# Instalar GCC y binutils (nm para verificar tabla de símbolos)
RUN apt-get update && \
    apt-get install -y gcc binutils && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /native

# Copiar los fuentes C
COPY matops-service/native/sucesiones.h .
COPY matops-service/native/sucesiones.c .

# Compilar la biblioteca dinámica
# -shared : produce un .so (shared object)
# -fPIC   : Position Independent Code (obligatorio para .so)
# -O2     : optimización nivel 2
# -lm     : enlaza con libm (para pow, sqrt, etc.)
RUN gcc -shared -fPIC -O2 -o libsucesiones.so sucesiones.c -lm

# Verificar que la biblioteca se compiló correctamente
RUN echo "=== Tabla de símbolos de libsucesiones.so ===" && \
    nm -D libsucesiones.so | grep " T "


# ════════════════════════════════════════════════════════════════════
# ETAPA 2 — Compilar el microservicio Spring Boot
# ════════════════════════════════════════════════════════════════════
FROM maven:3.9-eclipse-temurin-21 AS java-builder

WORKDIR /app

# Descargar dependencias primero (capa cacheada si pom.xml no cambia)
COPY matops-service/pom.xml ./matops-service/pom.xml
WORKDIR /app/matops-service
RUN mvn dependency:go-offline -q

# Compilar el proyecto
COPY matops-service/src ./src
RUN mvn clean package -DskipTests -q


# ════════════════════════════════════════════════════════════════════
# ETAPA 3 — Imagen de producción (solo JRE + biblioteca + JAR)
# ════════════════════════════════════════════════════════════════════
FROM eclipse-temurin:21-jre

# Copiar la biblioteca nativa desde la etapa 1
COPY --from=native-builder /native/libsucesiones.so /usr/local/lib/libsucesiones.so

# Actualizar caché del enlazador dinámico (ldconfig lee /usr/local/lib)
RUN ldconfig

# Copiar el JAR desde la etapa 2
COPY --from=java-builder /app/matops-service/target/matops-service-*.jar /app/app.jar

EXPOSE 8080

# -Djna.library.path: le dice a JNA dónde buscar libsucesiones.so
ENTRYPOINT ["java", \
            "-Djna.library.path=/usr/local/lib", \
            "-jar", "/app/app.jar"]