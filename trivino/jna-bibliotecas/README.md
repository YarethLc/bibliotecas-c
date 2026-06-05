# JNA Bibliotecas C — Combinatoria y Conjuntos

Proyecto Maven que expone las bibliotecas C `libcombinatorio.so` y `libconjuntos.so`
a Java mediante **JNA (Java Native Access)**, sin necesidad de escribir código JNI.

## Estructura del proyecto

```
jna-bibliotecas/
├── pom.xml
├── src/
│   └── main/
│       ├── c/
│       │   ├── combinatoria/
│       │   │   ├── combinatoria.h
│       │   │   └── combinatoria.c
│       │   └── conjuntos/
│       │       ├── conjuntos.h
│       │       └── conjuntos.c
│       ├── java/com/bibliotecas/
│       │   ├── combinatoria/
│       │   │   ├── CombinatoriaLibrary.java   ← interfaz JNA
│       │   │   └── CombinatoriaService.java   ← API Java amigable
│       │   ├── conjuntos/
│       │   │   ├── ConjuntosLibrary.java      ← interfaz JNA
│       │   │   └── ConjuntosService.java      ← API Java amigable
│       │   └── demo/
│       │       └── MainDemo.java
│       └── resources/
│           └── natives/
│               └── linux-x86-64/
│                   ├── libcombinatorio.so
│                   └── libconjuntos.so
```

## Paso 1 — Compilar las bibliotecas C

```bash
# Combinatoria
cd src/main/c/combinatoria
gcc -shared -fPIC -o libcombinatorio.so combinatoria.c
cp libcombinatorio.so ../../resources/natives/linux-x86-64/

# Conjuntos
cd ../conjuntos
gcc -shared -fPIC -o libconjuntos.so conjuntos.c
cp libconjuntos.so ../../resources/natives/linux-x86-64/
```

> En Windows: usa MinGW y genera `.dll` en lugar de `.so`.

## Paso 2 — Configurar java.library.path

JNA necesita encontrar los `.so` en tiempo de ejecución. Hay tres formas:

### Opción A — Copiar al directorio del sistema (Linux)
```bash
sudo cp src/main/resources/natives/linux-x86-64/*.so /usr/local/lib/
sudo ldconfig
```

### Opción B — Variable de entorno
```bash
export LD_LIBRARY_PATH=$PWD/src/main/resources/natives/linux-x86-64:$LD_LIBRARY_PATH
```

### Opción C — Propiedad del sistema al ejecutar Maven
```bash
mvn exec:java -Djna.library.path=src/main/resources/natives/linux-x86-64
```

### Opción D — Ruta explícita por biblioteca
```bash
mvn exec:java \
  -Dcombinatorio.lib=src/main/resources/natives/linux-x86-64/libcombinatorio.so \
  -Dconjuntos.lib=src/main/resources/natives/linux-x86-64/libconjuntos.so
```

## Paso 3 — Compilar y ejecutar

```bash
# Compilar el proyecto
mvn compile

# Ejecutar la demo
mvn exec:java -Djna.library.path=src/main/resources/natives/linux-x86-64

# Generar JAR ejecutable
mvn package
java -Djna.library.path=src/main/resources/natives/linux-x86-64 \
     -jar target/jna-bibliotecas-1.0-SNAPSHOT-jar-with-dependencies.jar
```

## Uso en código Java

```java
// Combinatoria
CombinatoriaService comb = new CombinatoriaService();
long fact = comb.factorial(10);                    // 3628800
long perm = comb.permutacion(5, 2);               // 20
long comb2 = comb.combinacion(10, 3);             // 120
long permRep = comb.permutacionRepeticion(3, 4);  // 81
long combRep = comb.combinacionRepeticion(5, 3);  // 35

// Conjuntos
ConjuntosService conj = new ConjuntosService();
int[] A = {1, 2, 3, 4, 5};
int[] B = {3, 4, 5, 6, 7};

boolean pertenece  = conj.pertenece(A, 3);           // true
int[]   union      = conj.union(A, B);                // [1,2,3,4,5,6,7]
int[]   inter      = conj.interseccion(A, B);         // [3,4,5]
int[]   dif        = conj.diferencia(A, B);           // [1,2]
int[]   difSim     = conj.diferenciaSimetrica(A, B);  // [1,2,6,7]
boolean subconj    = conj.esSubconjunto(new int[]{3,4}, A); // true
```

## Cómo funciona JNA

```
Java código  →  CombinatoriaLibrary (interfaz JNA)
                       ↓  Native.load("combinatorio")
              libcombinatorio.so  (código C compilado)
```

- **No hay código JNI** ni archivos `.h` generados por `javah`.
- JNA convierte automáticamente `long` Java ↔ `long` C (64-bit en Linux).
- Los `int[]` Java se pasan como punteros `int*` en C.
- Los arrays resultado se recortan con `Arrays.copyOf` al tamaño real.

## Dependencia Maven

```xml
<dependency>
    <groupId>net.java.dev.jna</groupId>
    <artifactId>jna</artifactId>
    <version>5.14.0</version>
</dependency>
```
