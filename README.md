# macfuse4j
Java library with JNI native library bindings for macFUSE https://osxfuse.github.io
## How to build
### JNI library (libmacfuse4j.dylib)
- Install CMake
    - You can download it from [here](https://cmake.org/download/)
- Install macFUSE
    - You can download it from [here](https://osxfuse.github.io)
- Open command prompt in the project directory and run the following commands:
    - `/Applications/CMake.app/Contents/bin/cmake -H./native -B./native/build`
    - `/Applications/CMake.app/Contents/bin/cmake --build ./native/build --config Release`
    - `cp ./native/build/libmacfuse4j.dylib ./src/main/resources/one/papachi/macfuse4j`
### Java library (macfuse4j-x.y.z.jar)
- Install JDK 17
    - You can download it from [here](https://www.oracle.com/java/technologies/downloads/).
- Install maven
    - You can download it from [here](https://maven.apache.org/download.cgi).
- Open command prompt in the project directory and run the following commands:
    - `mvn install`
## How to use
If you are using maven as your build tool, you can reference the library in your `pom.xml`
```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
  <modelVersion>4.0.0</modelVersion>

  <groupId>one.papachi</groupId>
  <artifactId>example</artifactId>
  <version>1.0.0</version>

  <properties>
    <maven.compiler.source>17</maven.compiler.source>
    <maven.compiler.target>17</maven.compiler.target>
  </properties>

  <dependencies>
    <dependency>
      <groupId>one.papachi</groupId>
      <artifactId>macfuse4j</artifactId>
      <version>1.0.0</version>
    </dependency>
  </dependencies>

</project>
```
