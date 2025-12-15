FROM ubuntu:22.04

# Установка переменных для автоматической установки
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Etc/UTC

# Установка зависимостей включая Git (для GoogleTest)
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    && rm -rf /var/lib/apt/lists/*

# Копирование исходного кода
COPY . /project
WORKDIR /project

# Создание директории сборки и сборка проекта
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build .

# Копируем исполняемые файлы в /usr/local/bin для доступности в PATH
RUN cp /project/build/Laboratory_3_exe /usr/local/bin/ && \
    cp /project/build/Laboratory_3_tests /usr/local/bin/

# По умолчанию запускаем тесты
CMD ["Laboratory_3_tests"]